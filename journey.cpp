#include "journey.h"
#include "ui_journey.h"
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QRandomGenerator>

Journey::Journey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Journey)
{
    ui->setupUi(this);
    timer = new QTimer(this);  // constructor takes parent
    connect(timer, SIGNAL(timeout()),
            this, SLOT(mytimer()));
    timer->start(1000);  // update every 1 sec
    
    // Initialize the booking button as disabled
    ui->pushButton_bookTicket->setEnabled(false);
}

Journey::~Journey()
{
    delete ui;
}

TicketQueryResult Journey::queryTickets(const TicketQueryRequest& request)
{
    TicketQueryResult result;
    result.success = false;
    result.total = 0;
    
    QFile file(":/fare.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        result.message = "Could not open fare data file";
        return result;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");

    // Skip header line
    QString header = in.readLine();
    
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        // Remove BOM if present
        if (line.startsWith(QChar(0xFEFF)))
            line.remove(0, 1);

        QStringList parts = line.split(',');
        if (parts.size() < 5) continue;

        QString fromStation = parts.at(0).trimmed();
        QString toStation = parts.at(1).trimmed();
        QString fareStr = parts.at(2).trimmed();
        QString trainId = parts.at(3).trimmed();
        QString departTime = parts.at(4).trimmed();

        // Filter by from and to stations
        if (fromStation == request.fromStation && toStation == request.toStation) {
            TicketInfo ticket;
            ticket.trainNumber = "G" + trainId;
            ticket.departTime = departTime;
            
            // Calculate arrival time (approximate - add 4 hours)
            QTime departQTime = QTime::fromString(departTime, "hh:mm");
            QTime arrivalQTime = departQTime.addSecs(4 * 3600); // Add 4 hours
            ticket.arriveTime = arrivalQTime.toString("hh:mm");
            
            ticket.price = fareStr.toDouble();
            ticket.availableSeats = 30 + (QRandomGenerator::global()->generate() % 50); // Random seats 30-79
            
            result.tickets.append(ticket);
        }
    }
    
    result.total = result.tickets.size();
    if (result.total > 0) {
        result.success = true;
        result.message = QString("Found %1 tickets").arg(result.total);
    } else {
        result.message = "No tickets found for the selected route";
    }
    
    return result;
}

TicketBookingResult Journey::bookTicket(const TicketBookingRequest& request)
{
    TicketBookingResult result;
    result.success = false;
    
    // Validate required fields
    if (request.trainNumber.isEmpty() || request.passengerName.isEmpty() || 
        request.passengerId.isEmpty() || request.fromStation.isEmpty() || 
        request.toStation.isEmpty()) {
        result.message = "Missing required booking information";
        return result;
    }
    
    // Generate order ID
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    result.orderId = timestamp + QString::number(QRandomGenerator::global()->generate() % 1000);
    
    // Generate coach and seat number
    result.coachNo = QString(QChar('A' + (QRandomGenerator::global()->generate() % 9)));
    result.seatNo = QString::number(1 + QRandomGenerator::global()->generate() % 60) + 
                   QString(QChar('A' + (QRandomGenerator::global()->generate() % 6)));
    
    // For simplicity, always succeed if validation passes
    result.success = true;
    result.message = "Booking successful";
    
    // Generate a simple QR code placeholder (base64 encoded string)
    QByteArray qrData = QString("Train:%1|From:%2|To:%3|Date:%4|Passenger:%5|Order:%6")
                        .arg(request.trainNumber)
                        .arg(request.fromStation)
                        .arg(request.toStation)
                        .arg(request.departDate)
                        .arg(request.passengerName)
                        .arg(result.orderId)
                        .toUtf8();
    result.qrCode = qrData.toBase64();
    
    return result;
}

void Journey::on_pushButton_queryTickets_clicked()
{
    QString fromStation = ui->textEdit->toPlainText().trimmed();
    QString toStation = ui->textEdit_2->toPlainText().trimmed();
    QString journeyDate = ui->dateEdit->text();
    
    if (fromStation.isEmpty() || toStation.isEmpty()) {
        QMessageBox::warning(this, "Error!", "Please enter both From and To stations");
        return;
    }
    
    if (fromStation == toStation) {
        QMessageBox::warning(this, "Error!", "From and To stations cannot be the same");
        return;
    }
    
    // Create query request
    TicketQueryRequest request;
    request.fromStation = fromStation;
    request.toStation = toStation;
    request.journeyDate = journeyDate;
    request.sortBy = "departTime";
    request.page = 1;
    request.pageSize = 20;
    
    // Query tickets
    lastQueryResult = queryTickets(request);
    
    // Update UI
    ui->listWidget_tickets->clear();
    
    if (lastQueryResult.success) {
        for (const TicketInfo& ticket : lastQueryResult.tickets) {
            QString ticketText = QString("%1 | %2-%3 | ¥%4 | %5 seats")
                                .arg(ticket.trainNumber)
                                .arg(ticket.departTime)
                                .arg(ticket.arriveTime)
                                .arg(ticket.price)
                                .arg(ticket.availableSeats);
            
            QListWidgetItem* item = new QListWidgetItem(ticketText);
            item->setData(Qt::UserRole, QVariant::fromValue(ticket));
            ui->listWidget_tickets->addItem(item);
        }
        
        ui->pushButton_bookTicket->setEnabled(false); // Enable after selection
        QMessageBox::information(this, "Query Result", lastQueryResult.message);
    } else {
        QMessageBox::warning(this, "Query Failed", lastQueryResult.message);
    }
}

void Journey::on_listWidget_tickets_itemClicked()
{
    QListWidgetItem* currentItem = ui->listWidget_tickets->currentItem();
    if (currentItem) {
        selectedTicket = currentItem->data(Qt::UserRole).value<TicketInfo>();
        ui->pushButton_bookTicket->setEnabled(true);
    }
}

void Journey::mytimer()
{
    QTime time = QTime::currentTime();
    QString timeTxt = time.toString();
    ui->label_time->setText(timeTxt);
}

void Journey::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}


void Journey::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About",
                       "This is a Railway Reservation System \n"
                       "developed for the OOP project.\n\n"
                       "Tools & Technologies used:\n"
                       "C++\n"
                       "Qt\n\n"
                       "Developers:\n"
                       "\n"
                       "\n"
                       "");
}

void Journey::on_actionQuit_triggered()
{
    QApplication::quit();
}

void Journey::on_actionHome_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void Journey::on_pushButton_bookTicket_clicked()
{
    QString passengerName = ui->lineEdit_PassengerName->text().trimmed();
    QString passengerId = ui->lineEdit_PassengerID->text().trimmed();
    QString fromStation = ui->textEdit->toPlainText().trimmed();
    QString toStation = ui->textEdit_2->toPlainText().trimmed();
    QString journeyDate = ui->dateEdit->text();
    
    // Validate input
    if (passengerName.isEmpty()) {
        QMessageBox::warning(this, "Error!", "Please enter passenger name");
        return;
    }
    
    if (passengerId.isEmpty()) {
        QMessageBox::warning(this, "Error!", "Please enter passenger ID");
        return;
    }
    
    if (selectedTicket.trainNumber.isEmpty()) {
        QMessageBox::warning(this, "Error!", "Please select a ticket first");
        return;
    }
    
    // Create booking request
    TicketBookingRequest request;
    request.trainNumber = selectedTicket.trainNumber;
    request.departDate = journeyDate;
    request.fromStation = fromStation;
    request.toStation = toStation;
    request.passengerName = passengerName;
    request.passengerId = passengerId;
    request.seatType = "二等座";
    request.paymentToken = "";
    
    // Book the ticket
    TicketBookingResult result = bookTicket(request);
    
    if (result.success) {
        QMessageBox::information(this,
                                 "Booking Successful",
                                 "Hello " + passengerName + "!\n"
                                 "Your ticket is confirmed.\n\n"
                                 "Details:\n"
                                 "Train: " + selectedTicket.trainNumber + "\n"
                                 "From: " + fromStation + "\n"
                                 "To: " + toStation + "\n"
                                 "Date: " + journeyDate + "\n"
                                 "Depart: " + selectedTicket.departTime + "\n"
                                 "Arrive: " + selectedTicket.arriveTime + "\n"
                                 "Cost: ¥" + QString::number(selectedTicket.price) + "\n"
                                 "Order ID: " + result.orderId + "\n"
                                 "Coach: " + result.coachNo + "\n"
                                 "Seat: " + result.seatNo + "\n"
                                 "Passenger: " + passengerName + "\n"
                                 "ID: " + passengerId);
        
        // Clear form after successful booking
        ui->lineEdit_PassengerName->clear();
        ui->lineEdit_PassengerID->clear();
        ui->listWidget_tickets->clear();
        ui->pushButton_bookTicket->setEnabled(false);
        selectedTicket = TicketInfo();
        
    } else {
        QMessageBox::warning(this, "Booking Failed", result.message);
    }
}

void Journey::on_dateEdit_dateChanged(const QDate &date)
{
    // 如果不需要对日期变化做特殊处理，就留空或把新日期显示到某个 label 上
    Q_UNUSED(date);
}

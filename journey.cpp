#include "journey.h"
#include "ui_journey.h"
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <QString>
#include <QDebug>

Journey::Journey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Journey)
{
    ui->setupUi(this);
    timer = new QTimer(this);  // constructor takes parent
    connect(timer, SIGNAL(timeout()),
            this, SLOT(mytimer()));
    timer->start(1000);  // update every 1 sec
}

Journey::~Journey()
{
    delete ui;
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
    QFile file(":/fare.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");  // 确保跟文件编码一致

    QList<QString> fromList, toList, fareList;
    // 跳过首行
    QString header = in.readLine();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        // 如果有 BOM，需要去掉：
        if (line.startsWith(QChar(0xFEFF)))
            line.remove(0, 1);

        QStringList parts = line.split(',');
        if (parts.size() < 3) continue;

        fromList.append(parts.at(0).trimmed());
        toList.append(parts.at(1).trimmed());
        fareList.append(parts.at(2).trimmed());
    }

    // 后面获取 fromStation/toStation 的方式不变：
    QString fromStation = ui->textEdit->toPlainText().trimmed();
    QString toStation   = ui->textEdit_2->toPlainText().trimmed();

    if(fromStation == "----" ||
            toStation == "----")
        QMessageBox::warning(this, "Error!", "Please select From and To stations");

    else if (fromStation == toStation)
        QMessageBox::warning(this, "Error!", "From to To stations can\'t be same.");

    else {


        /*
         * l1 = ("a", "b", "d", "c", "d", "b")
         * l2 = ("b", "a", "b", "b", "a", "c")
         * l3 = (2, 4, 3, 5, 4, 5)  // fare
         * if index of inputs in l1 and l2 are same then fare will be the value at that index in l3
         * if "d" and "a" are input then index will be 5 hence fare will be the value corresponding to index 5 in l3 i.e. 4
         * */

        QString cost;
        int id = -1;
        for (int i = 0; i < fromList.size(); ++i) {
            if (fromList[i].trimmed() == fromStation && toList[i].trimmed() == toStation) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            QMessageBox::warning(this, "Error!", "No fare found for the selected stations.");
            return;
        }
        cost = fareList.at(id);

        qDebug() << "fromStation: " << fromStation
                 << ", toStation: " << toStation
                 << ", id: " << id
                 << ", cost: " << cost;

        QMessageBox::information(this,
                                 "Ticket booked",
                                 "Hello " +
                                 ui->lineEdit_PassengerName->text() +
                                 "!\nYour ticket from " +
                                 fromStation +
                                 " to " +
                                 toStation +
                                 " on " +
                                 ui->dateEdit->text() +
                                 " is confirmed.\n"
                                 "Cost: ￥" + cost +
                                 "\n\nDetails:\n" +
                                 "Passenger Name: " + ui->lineEdit_PassengerName->text() +
                                 "\nFrom: " + fromStation +
                                 "\nDate of Journey: " + ui->dateEdit->text() +
                                 "\nTo: " + toStation +
                                 "\nCoach No: " +
                                 QString(QChar('A' + (rand() % 9))) +  // random character
                                 QString::number(rand() % 9)  // random number
                                 );
    }
}

void Journey::on_dateEdit_dateChanged(const QDate &date)
{
    // 如果不需要对日期变化做特殊处理，就留空或把新日期显示到某个 label 上
    Q_UNUSED(date);
}

#ifndef JOURNEY_H
#define JOURNEY_H

#include <QMainWindow>
#include <QDialog>
#include <QTimer>
#include <QDate>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

// Data structures for ticket query and booking
struct TicketInfo {
    QString trainNumber;
    QString departTime;
    QString arriveTime;
    int availableSeats;
    double price;
};

struct TicketQueryRequest {
    QString fromStation;
    QString toStation;
    QString journeyDate;
    QString sortBy;
    int page = 1;
    int pageSize = 20;
};

struct TicketQueryResult {
    bool success;
    QString message;
    int total;
    QList<TicketInfo> tickets;
};

struct TicketBookingRequest {
    QString trainNumber;
    QString departDate;
    QString fromStation;
    QString toStation;
    QString passengerName;
    QString passengerId;
    QString seatType;
    QString paymentToken;
};

struct TicketBookingResult {
    bool success;
    QString message;
    QString orderId;
    QString coachNo;
    QString seatNo;
    QString qrCode;
};

// Register types for QVariant
Q_DECLARE_METATYPE(TicketInfo)

namespace Ui {
class Journey;
}

class Journey : public QMainWindow
{
    Q_OBJECT

public:
    explicit Journey(QWidget *parent = 0);
    ~Journey();

    // Query and booking methods
    TicketQueryResult queryTickets(const TicketQueryRequest& request);
    TicketBookingResult bookTicket(const TicketBookingRequest& request);

public slots:
    void mytimer();

private slots:
    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionHome_triggered();

    void on_pushButton_bookTicket_clicked();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_queryTickets_clicked();

    void on_listWidget_tickets_itemClicked();

private:
    Ui::Journey *ui;
    QTimer *timer;
    TicketQueryResult lastQueryResult;
    TicketInfo selectedTicket;
};

#endif // JOURNEY_H

#include "journey.h"
#include "ui_journey.h"
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <QString>
#include <QDebug>


#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QComboBox>
#include <QMessageBox>

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


void Journey::on_pushButton_queryTicket_clicked()
{
    /*
    QFile file(":/fare.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << file.errorString();
        return;
    }

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);  // 确保跟文件编码一致

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
    */
    // 后面获取 fromStation/toStation 的方式不变：
    //QString fromStation = ui->textEdit->toPlainText().trimmed();
    //QString toStation   = ui->textEdit_2->toPlainText().trimmed();
    /*
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

    /*
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
        */


    //new query function
    // 获取 fromStation/toStation/date,准备构建查询url
    QString from = ui->textEdit->toPlainText().trimmed();
    QString to   = ui->textEdit_2->toPlainText().trimmed();
    QString date = ui->dateEdit->date().toString("yyyy-MM-dd");

    // 构造请求
    QNetworkAccessManager *manager = new QNetworkAccessManager(this); // 创建网络管理器，负责发送 HTTP 请求

    // 设置请求的 URL 和参数
    QUrl url("http://127.0.0.1:8080/train"); // 后端查询接口地址
    QUrlQuery query;
    query.addQueryItem("from", from);   // 添加出发地参数
    query.addQueryItem("to", to);       // 添加目的地参数
    query.addQueryItem("date", date);   // 添加日期参数
    url.setQuery(query);                // 将参数拼接到 URL

    QNetworkRequest request(url);       // 创建请求对象
    QNetworkReply *reply = manager->get(request); // 发送 GET 请求，返回结果 reply

    // 当请求完成时，处理返回结果
    connect(reply, &QNetworkReply::finished, this, [=]() {
        QByteArray res = reply->readAll(); // 读取返回的数据
        QJsonDocument doc = QJsonDocument::fromJson(res); // 解析为 JSON 文档

        // 检查返回数据是否为 JSON 数组（即多条车次信息）
        if (!doc.isArray()) {
            QMessageBox::warning(this, "错误", "返回数据格式不正确"); // 格式错误时弹窗提示
            reply->deleteLater();   // 释放 reply 对象
            manager->deleteLater(); // 释放 manager 对象
            return;
        }

        QJsonArray arr = doc.array(); // 获取 JSON 数组
        ui->listWidget_trains->clear(); // 清空之前的列表内容

        // 遍历每一条车次信息，添加到列表
        for (const QJsonValue &v : arr) {
            QJsonObject obj = v.toObject(); // 转换为 JSON 对象
            // 拼接显示内容，比如 "G123 | 12:00 | 北京 | 350元"
            QString item = QString("%1 | %2 | %3 | %4元")
                               .arg(obj.value("trainid").toString())   // 车次ID
                               .arg(obj.value("time").toString())      // 发车时间
                               .arg(obj.value("depart").toString())    // 出发地
                               .arg(obj.value("price").toDouble());    // 票价

            QListWidgetItem *listItem = new QListWidgetItem(item); // 创建列表项
            listItem->setData(Qt::UserRole, obj.value("trainid").toString()); // 用于存储车次ID（方便后续使用）
            ui->listWidget_trains->addItem(listItem); // 添加到 QListWidget
        }
        reply->deleteLater();   // 释放 reply 对象
        manager->deleteLater(); // 释放 manager 对象
    });
}

void Journey::on_dateEdit_dateChanged(const QDate &date)
{
    // 如果不需要对日期变化做特殊处理，就留空或把新日期显示到某个 label 上
    Q_UNUSED(date);
}

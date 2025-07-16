/********************************************************************************
** Form generated from reading UI file 'journey.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNEY_H
#define UI_JOURNEY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Journey
{
public:
    QAction *actionHome;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QLabel *label_time;
    QPushButton *pushButton_queryTicket;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_PassengerName;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Journey)
    {
        if (Journey->objectName().isEmpty())
            Journey->setObjectName("Journey");
        Journey->resize(548, 478);
        actionHome = new QAction(Journey);
        actionHome->setObjectName("actionHome");
        actionQuit = new QAction(Journey);
        actionQuit->setObjectName("actionQuit");
        actionAbout = new QAction(Journey);
        actionAbout->setObjectName("actionAbout");
        actionAbout_Qt = new QAction(Journey);
        actionAbout_Qt->setObjectName("actionAbout_Qt");
        centralwidget = new QWidget(Journey);
        centralwidget->setObjectName("centralwidget");
        label_time = new QLabel(centralwidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(180, 20, 63, 20));
        QFont font;
        font.setBold(true);
        label_time->setFont(font);
        pushButton_queryTicket = new QPushButton(centralwidget);
        pushButton_queryTicket->setObjectName("pushButton_queryTicket");
        pushButton_queryTicket->setGeometry(QRect(70, 130, 81, 28));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 160, 212, 171));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        lineEdit_PassengerName = new QLineEdit(layoutWidget);
        lineEdit_PassengerName->setObjectName("lineEdit_PassengerName");

        horizontalLayout_4->addWidget(lineEdit_PassengerName);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        textEdit_2 = new QTextEdit(layoutWidget);
        textEdit_2->setObjectName("textEdit_2");

        horizontalLayout_2->addWidget(textEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        Journey->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Journey);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 548, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        Journey->setMenuBar(menubar);
        statusbar = new QStatusBar(Journey);
        statusbar->setObjectName("statusbar");
        Journey->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label_4->setBuddy(lineEdit_PassengerName);
        label_3->setBuddy(dateEdit);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionHome);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(Journey);

        QMetaObject::connectSlotsByName(Journey);
    } // setupUi

    void retranslateUi(QMainWindow *Journey)
    {
        Journey->setWindowTitle(QCoreApplication::translate("Journey", "Railway Reservation System", nullptr));
        actionHome->setText(QCoreApplication::translate("Journey", "Home", nullptr));
        actionQuit->setText(QCoreApplication::translate("Journey", "Quit", nullptr));
        actionAbout->setText(QCoreApplication::translate("Journey", "About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("Journey", "About Qt", nullptr));
        label_time->setText(QString());
        pushButton_queryTicket->setText(QCoreApplication::translate("Journey", "Query Ticket", nullptr));
        label_4->setText(QCoreApplication::translate("Journey", "Name", nullptr));
        label->setText(QCoreApplication::translate("Journey", "From", nullptr));
        label_2->setText(QCoreApplication::translate("Journey", "To", nullptr));
        label_3->setText(QCoreApplication::translate("Journey", "Date", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Journey", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Journey", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Journey: public Ui_Journey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNEY_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionReport_bug;
    QAction *actionReport_Bug;
    QWidget *centralWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextPassenger;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName("actionAbout_Qt");
        actionReport_bug = new QAction(MainWindow);
        actionReport_bug->setObjectName("actionReport_bug");
        actionReport_Bug = new QAction(MainWindow);
        actionReport_Bug->setObjectName("actionReport_Bug");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 10, 201, 51));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("text-align: center;"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 80, 201, 104));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");

        horizontalLayout_7->addWidget(lineEdit_username);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(lineEdit_password);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        nextPassenger = new QPushButton(layoutWidget);
        nextPassenger->setObjectName("nextPassenger");

        horizontalLayout_9->addWidget(nextPassenger);


        verticalLayout_3->addLayout(horizontalLayout_9);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
        label_6->setBuddy(lineEdit_username);
        label_7->setBuddy(lineEdit_password);
#endif // QT_CONFIG(shortcut)

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addSeparator();
        menuHelp->addAction(actionReport_Bug);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Railway Reservation System", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionReport_bug->setText(QCoreApplication::translate("MainWindow", "Report Bug", nullptr));
        actionReport_Bug->setText(QCoreApplication::translate("MainWindow", "Report Bug", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome\n"
"to\n"
"Railway Reservation System", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        nextPassenger->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

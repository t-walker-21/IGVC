/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *speedLevel;
    QPushButton *stopButton;
    QSlider *steerPosition;
    QLabel *steerLabel;
    QLabel *speedLabel;
    QPushButton *portClt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(420, 358);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        speedLevel = new QSlider(centralWidget);
        speedLevel->setObjectName(QString::fromUtf8("speedLevel"));
        speedLevel->setGeometry(QRect(320, 80, 16, 160));
        speedLevel->setMinimum(0);
        speedLevel->setMaximum(4);
        speedLevel->setOrientation(Qt::Vertical);
        speedLevel->setTickInterval(1);
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(10, 200, 71, 91));
        steerPosition = new QSlider(centralWidget);
        steerPosition->setObjectName(QString::fromUtf8("steerPosition"));
        steerPosition->setGeometry(QRect(70, 40, 251, 16));
        steerPosition->setMaximum(4);
        steerPosition->setOrientation(Qt::Horizontal);
        steerLabel = new QLabel(centralWidget);
        steerLabel->setObjectName(QString::fromUtf8("steerLabel"));
        steerLabel->setGeometry(QRect(140, 20, 121, 20));
        speedLabel = new QLabel(centralWidget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setGeometry(QRect(208, 160, 101, 20));
        portClt = new QPushButton(centralWidget);
        portClt->setObjectName(QString::fromUtf8("portClt"));
        portClt->setGeometry(QRect(120, 270, 141, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "STOP", 0, QApplication::UnicodeUTF8));
        steerLabel->setText(QApplication::translate("MainWindow", "SteerPos", 0, QApplication::UnicodeUTF8));
        speedLabel->setText(QApplication::translate("MainWindow", "SpeedLevel", 0, QApplication::UnicodeUTF8));
        portClt->setText(QApplication::translate("MainWindow", "Open Serial Port", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

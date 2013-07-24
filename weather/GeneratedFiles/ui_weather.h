/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weatherClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *weatherClass)
    {
        if (weatherClass->objectName().isEmpty())
            weatherClass->setObjectName(QString::fromUtf8("weatherClass"));
        weatherClass->resize(600, 400);
        menuBar = new QMenuBar(weatherClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        weatherClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(weatherClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        weatherClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(weatherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        weatherClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(weatherClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        weatherClass->setStatusBar(statusBar);

        retranslateUi(weatherClass);

        QMetaObject::connectSlotsByName(weatherClass);
    } // setupUi

    void retranslateUi(QMainWindow *weatherClass)
    {
        weatherClass->setWindowTitle(QApplication::translate("weatherClass", "weather", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class weatherClass: public Ui_weatherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H

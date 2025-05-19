/********************************************************************************
** Form generated from reading UI file 'SLT_Application.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLT_APPLICATION_H
#define UI_SLT_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SLT_ApplicationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SLT_ApplicationClass)
    {
        if (SLT_ApplicationClass->objectName().isEmpty())
            SLT_ApplicationClass->setObjectName("SLT_ApplicationClass");
        SLT_ApplicationClass->resize(600, 400);
        menuBar = new QMenuBar(SLT_ApplicationClass);
        menuBar->setObjectName("menuBar");
        SLT_ApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SLT_ApplicationClass);
        mainToolBar->setObjectName("mainToolBar");
        SLT_ApplicationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SLT_ApplicationClass);
        centralWidget->setObjectName("centralWidget");
        SLT_ApplicationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SLT_ApplicationClass);
        statusBar->setObjectName("statusBar");
        SLT_ApplicationClass->setStatusBar(statusBar);

        retranslateUi(SLT_ApplicationClass);

        QMetaObject::connectSlotsByName(SLT_ApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SLT_ApplicationClass)
    {
        SLT_ApplicationClass->setWindowTitle(QCoreApplication::translate("SLT_ApplicationClass", "SLT_Application", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SLT_ApplicationClass: public Ui_SLT_ApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLT_APPLICATION_H

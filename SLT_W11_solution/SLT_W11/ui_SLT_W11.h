/********************************************************************************
** Form generated from reading UI file 'SLT_W11.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLT_W11_H
#define UI_SLT_W11_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SLT_W11Class
{
public:
    QAction *actionAddAssessor;
    QAction *actionManageAssessor;
    QAction *actionAddClient;
    QAction *actionManageClient;
    QAction *actionAddCaseProfile;
    QAction *actionManageCaseProfiles;
    QAction *actionManageForms;
    QAction *actionGenerateForms;
    QAction *actionSettings;
    QAction *actionSystemInfo;
    QAction *actionBackup;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menuAssessor;
    QMenu *menuClient;
    QMenu *menuCaseProfile;
    QMenu *menuForms;
    QMenu *menuAdminPanel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SLT_W11Class)
    {
        if (SLT_W11Class->objectName().isEmpty())
            SLT_W11Class->setObjectName("SLT_W11Class");
        SLT_W11Class->resize(1237, 874);
        actionAddAssessor = new QAction(SLT_W11Class);
        actionAddAssessor->setObjectName("actionAddAssessor");
        actionManageAssessor = new QAction(SLT_W11Class);
        actionManageAssessor->setObjectName("actionManageAssessor");
        actionAddClient = new QAction(SLT_W11Class);
        actionAddClient->setObjectName("actionAddClient");
        actionManageClient = new QAction(SLT_W11Class);
        actionManageClient->setObjectName("actionManageClient");
        actionAddCaseProfile = new QAction(SLT_W11Class);
        actionAddCaseProfile->setObjectName("actionAddCaseProfile");
        actionManageCaseProfiles = new QAction(SLT_W11Class);
        actionManageCaseProfiles->setObjectName("actionManageCaseProfiles");
        actionManageForms = new QAction(SLT_W11Class);
        actionManageForms->setObjectName("actionManageForms");
        actionGenerateForms = new QAction(SLT_W11Class);
        actionGenerateForms->setObjectName("actionGenerateForms");
        actionSettings = new QAction(SLT_W11Class);
        actionSettings->setObjectName("actionSettings");
        actionSystemInfo = new QAction(SLT_W11Class);
        actionSystemInfo->setObjectName("actionSystemInfo");
        actionBackup = new QAction(SLT_W11Class);
        actionBackup->setObjectName("actionBackup");
        centralWidget = new QWidget(SLT_W11Class);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        SLT_W11Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SLT_W11Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1237, 33));
        menuAssessor = new QMenu(menuBar);
        menuAssessor->setObjectName("menuAssessor");
        menuClient = new QMenu(menuBar);
        menuClient->setObjectName("menuClient");
        menuCaseProfile = new QMenu(menuBar);
        menuCaseProfile->setObjectName("menuCaseProfile");
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName("menuForms");
        menuAdminPanel = new QMenu(menuBar);
        menuAdminPanel->setObjectName("menuAdminPanel");
        SLT_W11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SLT_W11Class);
        mainToolBar->setObjectName("mainToolBar");
        SLT_W11Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SLT_W11Class);
        statusBar->setObjectName("statusBar");
        SLT_W11Class->setStatusBar(statusBar);

        menuBar->addAction(menuAssessor->menuAction());
        menuBar->addAction(menuClient->menuAction());
        menuBar->addAction(menuCaseProfile->menuAction());
        menuBar->addAction(menuForms->menuAction());
        menuBar->addAction(menuAdminPanel->menuAction());
        menuAssessor->addAction(actionAddAssessor);
        menuAssessor->addAction(actionManageAssessor);
        menuClient->addAction(actionAddClient);
        menuClient->addAction(actionManageClient);
        menuCaseProfile->addAction(actionAddCaseProfile);
        menuCaseProfile->addAction(actionManageCaseProfiles);
        menuForms->addAction(actionManageForms);
        menuForms->addAction(actionGenerateForms);
        menuAdminPanel->addAction(actionSettings);
        menuAdminPanel->addAction(actionSystemInfo);
        menuAdminPanel->addAction(actionBackup);

        retranslateUi(SLT_W11Class);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SLT_W11Class);
    } // setupUi

    void retranslateUi(QMainWindow *SLT_W11Class)
    {
        SLT_W11Class->setWindowTitle(QCoreApplication::translate("SLT_W11Class", "SLT_W11", nullptr));
        actionAddAssessor->setText(QCoreApplication::translate("SLT_W11Class", "Add new assessor", nullptr));
        actionManageAssessor->setText(QCoreApplication::translate("SLT_W11Class", "Manage assessor profile", nullptr));
        actionAddClient->setText(QCoreApplication::translate("SLT_W11Class", "Add new Client", nullptr));
        actionManageClient->setText(QCoreApplication::translate("SLT_W11Class", "Manage client profile", nullptr));
        actionAddCaseProfile->setText(QCoreApplication::translate("SLT_W11Class", "Create a new profile", nullptr));
        actionManageCaseProfiles->setText(QCoreApplication::translate("SLT_W11Class", "Manage case profile", nullptr));
        actionManageForms->setText(QCoreApplication::translate("SLT_W11Class", "Manage forms", nullptr));
        actionGenerateForms->setText(QCoreApplication::translate("SLT_W11Class", "Generate forms", nullptr));
        actionSettings->setText(QCoreApplication::translate("SLT_W11Class", "Settings", nullptr));
        actionSystemInfo->setText(QCoreApplication::translate("SLT_W11Class", "System Info", nullptr));
        actionBackup->setText(QCoreApplication::translate("SLT_W11Class", "Backup", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SLT_W11Class", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SLT_W11Class", "Tab 2", nullptr));
        menuAssessor->setTitle(QCoreApplication::translate("SLT_W11Class", "Assessor", nullptr));
        menuClient->setTitle(QCoreApplication::translate("SLT_W11Class", "Client", nullptr));
        menuCaseProfile->setTitle(QCoreApplication::translate("SLT_W11Class", "Case Profile", nullptr));
        menuForms->setTitle(QCoreApplication::translate("SLT_W11Class", "Forms", nullptr));
        menuAdminPanel->setTitle(QCoreApplication::translate("SLT_W11Class", "Administrative Panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SLT_W11Class: public Ui_SLT_W11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLT_W11_H

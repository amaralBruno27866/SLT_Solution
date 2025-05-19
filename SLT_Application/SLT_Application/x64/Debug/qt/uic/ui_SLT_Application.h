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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SLT_ApplicationClass
{
public:
    QAction *actionAdd_a_new_assessor;
    QAction *actionManage_assessor;
    QAction *actionAdd_a_new_client;
    QAction *actionManger_client;
    QAction *actionCreate_a_new_case_profile;
    QAction *actionManage_case_profile;
    QAction *actionView_forms;
    QAction *actionMange_forms;
    QAction *actionGenerate_forms;
    QAction *actionMange_Database;
    QAction *actionMain_user;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuAssessor;
    QMenu *menuClient;
    QMenu *menuCase_Profile;
    QMenu *menuForms;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SLT_ApplicationClass)
    {
        if (SLT_ApplicationClass->objectName().isEmpty())
            SLT_ApplicationClass->setObjectName("SLT_ApplicationClass");
        SLT_ApplicationClass->resize(758, 519);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SLT_ApplicationClass->sizePolicy().hasHeightForWidth());
        SLT_ApplicationClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        SLT_ApplicationClass->setFont(font);
        actionAdd_a_new_assessor = new QAction(SLT_ApplicationClass);
        actionAdd_a_new_assessor->setObjectName("actionAdd_a_new_assessor");
        QFont font1;
        actionAdd_a_new_assessor->setFont(font1);
        actionManage_assessor = new QAction(SLT_ApplicationClass);
        actionManage_assessor->setObjectName("actionManage_assessor");
        actionManage_assessor->setFont(font1);
        actionAdd_a_new_client = new QAction(SLT_ApplicationClass);
        actionAdd_a_new_client->setObjectName("actionAdd_a_new_client");
        actionAdd_a_new_client->setFont(font1);
        actionManger_client = new QAction(SLT_ApplicationClass);
        actionManger_client->setObjectName("actionManger_client");
        actionManger_client->setFont(font1);
        actionCreate_a_new_case_profile = new QAction(SLT_ApplicationClass);
        actionCreate_a_new_case_profile->setObjectName("actionCreate_a_new_case_profile");
        actionCreate_a_new_case_profile->setFont(font1);
        actionManage_case_profile = new QAction(SLT_ApplicationClass);
        actionManage_case_profile->setObjectName("actionManage_case_profile");
        actionManage_case_profile->setFont(font1);
        actionView_forms = new QAction(SLT_ApplicationClass);
        actionView_forms->setObjectName("actionView_forms");
        actionView_forms->setFont(font1);
        actionMange_forms = new QAction(SLT_ApplicationClass);
        actionMange_forms->setObjectName("actionMange_forms");
        actionMange_forms->setFont(font1);
        actionGenerate_forms = new QAction(SLT_ApplicationClass);
        actionGenerate_forms->setObjectName("actionGenerate_forms");
        actionGenerate_forms->setFont(font1);
        actionMange_Database = new QAction(SLT_ApplicationClass);
        actionMange_Database->setObjectName("actionMange_Database");
        actionMange_Database->setFont(font1);
        actionMain_user = new QAction(SLT_ApplicationClass);
        actionMain_user->setObjectName("actionMain_user");
        actionMain_user->setFont(font1);
        centralWidget = new QWidget(SLT_ApplicationClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setFont(font);
        SLT_ApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SLT_ApplicationClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 758, 33));
        menuBar->setFont(font);
        menuAssessor = new QMenu(menuBar);
        menuAssessor->setObjectName("menuAssessor");
        menuAssessor->setFont(font);
        menuClient = new QMenu(menuBar);
        menuClient->setObjectName("menuClient");
        menuClient->setFont(font);
        menuCase_Profile = new QMenu(menuBar);
        menuCase_Profile->setObjectName("menuCase_Profile");
        menuCase_Profile->setFont(font);
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName("menuForms");
        menuForms->setFont(font);
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName("menuSettings");
        menuSettings->setFont(font);
        SLT_ApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SLT_ApplicationClass);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setFont(font);
        SLT_ApplicationClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SLT_ApplicationClass);
        statusBar->setObjectName("statusBar");
        statusBar->setFont(font);
        SLT_ApplicationClass->setStatusBar(statusBar);

        menuBar->addAction(menuAssessor->menuAction());
        menuBar->addAction(menuClient->menuAction());
        menuBar->addAction(menuCase_Profile->menuAction());
        menuBar->addAction(menuForms->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuAssessor->addAction(actionAdd_a_new_assessor);
        menuAssessor->addAction(actionManage_assessor);
        menuClient->addAction(actionAdd_a_new_client);
        menuClient->addAction(actionManger_client);
        menuCase_Profile->addAction(actionCreate_a_new_case_profile);
        menuCase_Profile->addAction(actionManage_case_profile);
        menuForms->addAction(actionView_forms);
        menuForms->addAction(actionMange_forms);
        menuForms->addAction(actionGenerate_forms);
        menuSettings->addAction(actionMange_Database);
        menuSettings->addAction(actionMain_user);

        retranslateUi(SLT_ApplicationClass);

        QMetaObject::connectSlotsByName(SLT_ApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SLT_ApplicationClass)
    {
        SLT_ApplicationClass->setWindowTitle(QCoreApplication::translate("SLT_ApplicationClass", "SLT_Application", nullptr));
        actionAdd_a_new_assessor->setText(QCoreApplication::translate("SLT_ApplicationClass", "Add a new assessor", nullptr));
        actionManage_assessor->setText(QCoreApplication::translate("SLT_ApplicationClass", "Manage assessor", nullptr));
        actionAdd_a_new_client->setText(QCoreApplication::translate("SLT_ApplicationClass", "Add a new client", nullptr));
        actionManger_client->setText(QCoreApplication::translate("SLT_ApplicationClass", "Manage client", nullptr));
        actionCreate_a_new_case_profile->setText(QCoreApplication::translate("SLT_ApplicationClass", "Create a new case profile", nullptr));
        actionManage_case_profile->setText(QCoreApplication::translate("SLT_ApplicationClass", "Manage case profile", nullptr));
        actionView_forms->setText(QCoreApplication::translate("SLT_ApplicationClass", "View forms", nullptr));
        actionMange_forms->setText(QCoreApplication::translate("SLT_ApplicationClass", "Mange forms", nullptr));
        actionGenerate_forms->setText(QCoreApplication::translate("SLT_ApplicationClass", "Generate forms", nullptr));
        actionMange_Database->setText(QCoreApplication::translate("SLT_ApplicationClass", "Mange Database", nullptr));
        actionMain_user->setText(QCoreApplication::translate("SLT_ApplicationClass", "Main user", nullptr));
        menuAssessor->setTitle(QCoreApplication::translate("SLT_ApplicationClass", "Assessor", nullptr));
        menuClient->setTitle(QCoreApplication::translate("SLT_ApplicationClass", "Client", nullptr));
        menuCase_Profile->setTitle(QCoreApplication::translate("SLT_ApplicationClass", "Case Profile", nullptr));
        menuForms->setTitle(QCoreApplication::translate("SLT_ApplicationClass", "Forms", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("SLT_ApplicationClass", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SLT_ApplicationClass: public Ui_SLT_ApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLT_APPLICATION_H

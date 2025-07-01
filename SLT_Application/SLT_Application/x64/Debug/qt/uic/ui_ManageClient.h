/********************************************************************************
** Form generated from reading UI file 'ManageClient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGECLIENT_H
#define UI_MANAGECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageClient
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *btRefresh;
    QGroupBox *searchBox;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *searchLineEdit;
    QToolButton *btSearch;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ManageClient)
    {
        if (ManageClient->objectName().isEmpty())
            ManageClient->setObjectName("ManageClient");
        ManageClient->resize(1186, 872);
        verticalLayout = new QVBoxLayout(ManageClient);
        verticalLayout->setObjectName("verticalLayout");
        btRefresh = new QToolButton(ManageClient);
        btRefresh->setObjectName("btRefresh");
        btRefresh->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #00008B;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    width: 100px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #0000FF\n"
"}\n"
""));

        verticalLayout->addWidget(btRefresh);

        searchBox = new QGroupBox(ManageClient);
        searchBox->setObjectName("searchBox");
        verticalLayout_2 = new QVBoxLayout(searchBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        searchLineEdit = new QLineEdit(searchBox);
        searchLineEdit->setObjectName("searchLineEdit");

        verticalLayout_2->addWidget(searchLineEdit);

        btSearch = new QToolButton(searchBox);
        btSearch->setObjectName("btSearch");
        btSearch->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    width: 100px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #5cd65c;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btSearch);


        verticalLayout->addWidget(searchBox);

        tableWidget = new QTableWidget(ManageClient);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setDefaultSectionSize(180);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ManageClient);

        QMetaObject::connectSlotsByName(ManageClient);
    } // setupUi

    void retranslateUi(QWidget *ManageClient)
    {
        ManageClient->setWindowTitle(QCoreApplication::translate("ManageClient", "Form", nullptr));
        btRefresh->setText(QCoreApplication::translate("ManageClient", "Refresh", nullptr));
        searchBox->setTitle(QCoreApplication::translate("ManageClient", "Search", nullptr));
        btSearch->setText(QCoreApplication::translate("ManageClient", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageClient", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageClient", "Lastname", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageClient", "Firstname", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageClient", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageClient", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageClient", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageClient: public Ui_ManageClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGECLIENT_H

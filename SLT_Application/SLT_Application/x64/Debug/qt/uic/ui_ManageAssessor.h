/********************************************************************************
** Form generated from reading UI file 'ManageAssessor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEASSESSOR_H
#define UI_MANAGEASSESSOR_H

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

class Ui_ManageAssessor
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *searchBox;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *searchLineEdit;
    QToolButton *btSearch;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ManageAssessor)
    {
        if (ManageAssessor->objectName().isEmpty())
            ManageAssessor->setObjectName("ManageAssessor");
        ManageAssessor->resize(717, 505);
        verticalLayout = new QVBoxLayout(ManageAssessor);
        verticalLayout->setObjectName("verticalLayout");
        searchBox = new QGroupBox(ManageAssessor);
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

        tableWidget = new QTableWidget(ManageAssessor);
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
        tableWidget->setColumnCount(6);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ManageAssessor);

        QMetaObject::connectSlotsByName(ManageAssessor);
    } // setupUi

    void retranslateUi(QWidget *ManageAssessor)
    {
        ManageAssessor->setWindowTitle(QCoreApplication::translate("ManageAssessor", "Form", nullptr));
        searchBox->setTitle(QCoreApplication::translate("ManageAssessor", "Search", nullptr));
        btSearch->setText(QCoreApplication::translate("ManageAssessor", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageAssessor", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageAssessor", "Lastname", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageAssessor", "Firstname", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageAssessor", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageAssessor", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageAssessor", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageAssessor: public Ui_ManageAssessor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEASSESSOR_H

/********************************************************************************
** Form generated from reading UI file 'MyCases.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCASES_H
#define UI_MYCASES_H

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

class Ui_MyCases
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QToolButton *btSearch;
    QTableWidget *myCasesList;

    void setupUi(QWidget *MyCases)
    {
        if (MyCases->objectName().isEmpty())
            MyCases->setObjectName("MyCases");
        MyCases->resize(717, 507);
        verticalLayout = new QVBoxLayout(MyCases);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(MyCases);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        btSearch = new QToolButton(groupBox);
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


        verticalLayout->addWidget(groupBox);

        myCasesList = new QTableWidget(MyCases);
        if (myCasesList->columnCount() < 6)
            myCasesList->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        myCasesList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        myCasesList->setObjectName("myCasesList");

        verticalLayout->addWidget(myCasesList);


        retranslateUi(MyCases);

        QMetaObject::connectSlotsByName(MyCases);
    } // setupUi

    void retranslateUi(QWidget *MyCases)
    {
        MyCases->setWindowTitle(QCoreApplication::translate("MyCases", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MyCases", "Search", nullptr));
        btSearch->setText(QCoreApplication::translate("MyCases", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = myCasesList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MyCases", "Case ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = myCasesList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MyCases", "Client Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = myCasesList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MyCases", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = myCasesList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MyCases", "Created at", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = myCasesList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MyCases", "Modified at", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = myCasesList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MyCases", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyCases: public Ui_MyCases {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCASES_H

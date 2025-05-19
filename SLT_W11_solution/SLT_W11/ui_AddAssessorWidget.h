/********************************************************************************
** Form generated from reading UI file 'AddAssessorWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDASSESSORWIDGET_H
#define UI_ADDASSESSORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gb_basic_information;
    QVBoxLayout *verticalLayout;
    QGroupBox *gb_personal_info;
    QFormLayout *formLayout;
    QLabel *LB_fullname;
    QLineEdit *LnEd_fullname;
    QLabel *LB_email;
    QLineEdit *LnEd_email;
    QLabel *LB_phone;
    QLineEdit *LnEd_phone;
    QGroupBox *gb_address;
    QFormLayout *formLayout_2;
    QLabel *LB_street;
    QLineEdit *LnEd_street;
    QLabel *LB_city;
    QLineEdit *LnEd_city;
    QLabel *LB_province;
    QComboBox *CB_province;
    QLabel *LB_postal_code;
    QLineEdit *LnEd_postal_code;
    QHBoxLayout *button_area_assessor_register;
    QToolButton *bt_register;
    QToolButton *bt_cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(633, 361);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gb_basic_information = new QGroupBox(Form);
        gb_basic_information->setObjectName("gb_basic_information");
        gb_basic_information->setMaximumSize(QSize(700, 16777215));
        verticalLayout = new QVBoxLayout(gb_basic_information);
        verticalLayout->setObjectName("verticalLayout");
        gb_personal_info = new QGroupBox(gb_basic_information);
        gb_personal_info->setObjectName("gb_personal_info");
        formLayout = new QFormLayout(gb_personal_info);
        formLayout->setObjectName("formLayout");
        LB_fullname = new QLabel(gb_personal_info);
        LB_fullname->setObjectName("LB_fullname");

        formLayout->setWidget(0, QFormLayout::LabelRole, LB_fullname);

        LnEd_fullname = new QLineEdit(gb_personal_info);
        LnEd_fullname->setObjectName("LnEd_fullname");
        LnEd_fullname->setMaximumSize(QSize(500, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, LnEd_fullname);

        LB_email = new QLabel(gb_personal_info);
        LB_email->setObjectName("LB_email");

        formLayout->setWidget(1, QFormLayout::LabelRole, LB_email);

        LnEd_email = new QLineEdit(gb_personal_info);
        LnEd_email->setObjectName("LnEd_email");
        LnEd_email->setMaximumSize(QSize(500, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, LnEd_email);

        LB_phone = new QLabel(gb_personal_info);
        LB_phone->setObjectName("LB_phone");

        formLayout->setWidget(2, QFormLayout::LabelRole, LB_phone);

        LnEd_phone = new QLineEdit(gb_personal_info);
        LnEd_phone->setObjectName("LnEd_phone");
        LnEd_phone->setMaximumSize(QSize(500, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, LnEd_phone);


        verticalLayout->addWidget(gb_personal_info);

        gb_address = new QGroupBox(gb_basic_information);
        gb_address->setObjectName("gb_address");
        formLayout_2 = new QFormLayout(gb_address);
        formLayout_2->setObjectName("formLayout_2");
        LB_street = new QLabel(gb_address);
        LB_street->setObjectName("LB_street");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, LB_street);

        LnEd_street = new QLineEdit(gb_address);
        LnEd_street->setObjectName("LnEd_street");
        LnEd_street->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, LnEd_street);

        LB_city = new QLabel(gb_address);
        LB_city->setObjectName("LB_city");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, LB_city);

        LnEd_city = new QLineEdit(gb_address);
        LnEd_city->setObjectName("LnEd_city");
        LnEd_city->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, LnEd_city);

        LB_province = new QLabel(gb_address);
        LB_province->setObjectName("LB_province");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, LB_province);

        CB_province = new QComboBox(gb_address);
        CB_province->setObjectName("CB_province");
        CB_province->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, CB_province);

        LB_postal_code = new QLabel(gb_address);
        LB_postal_code->setObjectName("LB_postal_code");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, LB_postal_code);

        LnEd_postal_code = new QLineEdit(gb_address);
        LnEd_postal_code->setObjectName("LnEd_postal_code");
        LnEd_postal_code->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, LnEd_postal_code);


        verticalLayout->addWidget(gb_address);

        button_area_assessor_register = new QHBoxLayout();
        button_area_assessor_register->setObjectName("button_area_assessor_register");
        bt_register = new QToolButton(gb_basic_information);
        bt_register->setObjectName("bt_register");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bt_register->sizePolicy().hasHeightForWidth());
        bt_register->setSizePolicy(sizePolicy1);
        bt_register->setBaseSize(QSize(150, 50));
        bt_register->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #28a745; \n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #5cd65c;  \n"
"}\n"
""));

        button_area_assessor_register->addWidget(bt_register);

        bt_cancel = new QToolButton(gb_basic_information);
        bt_cancel->setObjectName("bt_cancel");
        sizePolicy1.setHeightForWidth(bt_cancel->sizePolicy().hasHeightForWidth());
        bt_cancel->setSizePolicy(sizePolicy1);
        bt_cancel->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #dc3545;  \n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #ff4d4d;   \n"
"}\n"
""));

        button_area_assessor_register->addWidget(bt_cancel);


        verticalLayout->addLayout(button_area_assessor_register);


        verticalLayout_2->addWidget(gb_basic_information);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        gb_basic_information->setTitle(QCoreApplication::translate("Form", "Basic Information", nullptr));
        gb_personal_info->setTitle(QCoreApplication::translate("Form", "Personal Information", nullptr));
        LB_fullname->setText(QCoreApplication::translate("Form", "Fullname", nullptr));
        LB_email->setText(QCoreApplication::translate("Form", "Email", nullptr));
        LB_phone->setText(QCoreApplication::translate("Form", "Phone", nullptr));
        gb_address->setTitle(QCoreApplication::translate("Form", "Address", nullptr));
        LB_street->setText(QCoreApplication::translate("Form", "Street", nullptr));
        LB_city->setText(QCoreApplication::translate("Form", "City", nullptr));
        LB_province->setText(QCoreApplication::translate("Form", "Province", nullptr));
        LB_postal_code->setText(QCoreApplication::translate("Form", "Postal Code", nullptr));
        bt_register->setText(QCoreApplication::translate("Form", "Register", nullptr));
        bt_cancel->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDASSESSORWIDGET_H

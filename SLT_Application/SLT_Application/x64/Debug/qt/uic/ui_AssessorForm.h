/********************************************************************************
** Form generated from reading UI file 'AssessorForm.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSESSORFORM_H
#define UI_ASSESSORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *personalInformationBox;
    QFormLayout *formLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineedit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *phoneNumberLabel;
    QLineEdit *phoneNumberLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QGroupBox *addressBox;
    QFormLayout *formLayout_2;
    QLabel *streetLabel;
    QLineEdit *streetLineEdit;
    QLabel *cityLabel;
    QLineEdit *cityLineEdit;
    QLabel *label;
    QComboBox *provinceCbBox;
    QLabel *postalCodeLabel;
    QLineEdit *postalCodeLineEdit;
    QHBoxLayout *btArea;
    QSpacerItem *horizontalSpacer;
    QToolButton *btRegister;
    QToolButton *btCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(458, 359);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        personalInformationBox = new QGroupBox(Form);
        personalInformationBox->setObjectName("personalInformationBox");
        formLayout = new QFormLayout(personalInformationBox);
        formLayout->setObjectName("formLayout");
        firstNameLabel = new QLabel(personalInformationBox);
        firstNameLabel->setObjectName("firstNameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineedit = new QLineEdit(personalInformationBox);
        firstNameLineedit->setObjectName("firstNameLineedit");

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameLineedit);

        lastNameLabel = new QLabel(personalInformationBox);
        lastNameLabel->setObjectName("lastNameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(personalInformationBox);
        lastNameLineEdit->setObjectName("lastNameLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameLineEdit);

        phoneNumberLabel = new QLabel(personalInformationBox);
        phoneNumberLabel->setObjectName("phoneNumberLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, phoneNumberLabel);

        phoneNumberLineEdit = new QLineEdit(personalInformationBox);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneNumberLineEdit);

        emailLabel = new QLabel(personalInformationBox);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(personalInformationBox);
        emailLineEdit->setObjectName("emailLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, emailLineEdit);


        verticalLayout->addWidget(personalInformationBox);

        addressBox = new QGroupBox(Form);
        addressBox->setObjectName("addressBox");
        formLayout_2 = new QFormLayout(addressBox);
        formLayout_2->setObjectName("formLayout_2");
        streetLabel = new QLabel(addressBox);
        streetLabel->setObjectName("streetLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, streetLabel);

        streetLineEdit = new QLineEdit(addressBox);
        streetLineEdit->setObjectName("streetLineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, streetLineEdit);

        cityLabel = new QLabel(addressBox);
        cityLabel->setObjectName("cityLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, cityLabel);

        cityLineEdit = new QLineEdit(addressBox);
        cityLineEdit->setObjectName("cityLineEdit");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cityLineEdit);

        label = new QLabel(addressBox);
        label->setObjectName("label");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label);

        provinceCbBox = new QComboBox(addressBox);
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->addItem(QString());
        provinceCbBox->setObjectName("provinceCbBox");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, provinceCbBox);

        postalCodeLabel = new QLabel(addressBox);
        postalCodeLabel->setObjectName("postalCodeLabel");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, postalCodeLabel);

        postalCodeLineEdit = new QLineEdit(addressBox);
        postalCodeLineEdit->setObjectName("postalCodeLineEdit");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, postalCodeLineEdit);


        verticalLayout->addWidget(addressBox);

        btArea = new QHBoxLayout();
        btArea->setObjectName("btArea");
        btArea->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btArea->addItem(horizontalSpacer);

        btRegister = new QToolButton(Form);
        btRegister->setObjectName("btRegister");
        btRegister->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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

        btArea->addWidget(btRegister);

        btCancel = new QToolButton(Form);
        btCancel->setObjectName("btCancel");
        btCancel->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #dc3545;   /* Vermelho escuro */\n"
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
"    background-color: #ff4d4d;   /* Vermelho claro no hover */\n"
"}\n"
""));

        btArea->addWidget(btCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btArea->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(btArea);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        personalInformationBox->setTitle(QCoreApplication::translate("Form", "Personal Information", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("Form", "Firstname", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("Form", "Lastname", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("Form", "Phone number", nullptr));
        emailLabel->setText(QCoreApplication::translate("Form", "Email", nullptr));
        addressBox->setTitle(QCoreApplication::translate("Form", "Address", nullptr));
        streetLabel->setText(QCoreApplication::translate("Form", "Street", nullptr));
        cityLabel->setText(QCoreApplication::translate("Form", "City", nullptr));
        label->setText(QCoreApplication::translate("Form", "Province", nullptr));
        provinceCbBox->setItemText(0, QCoreApplication::translate("Form", "N/A", nullptr));
        provinceCbBox->setItemText(1, QCoreApplication::translate("Form", "Alberta (AB)", nullptr));
        provinceCbBox->setItemText(2, QCoreApplication::translate("Form", "British Columbia (BC)", nullptr));
        provinceCbBox->setItemText(3, QCoreApplication::translate("Form", "Manitoba (MB)", nullptr));
        provinceCbBox->setItemText(4, QCoreApplication::translate("Form", "New Brunswick (NB)", nullptr));
        provinceCbBox->setItemText(5, QCoreApplication::translate("Form", "Newfoundland and Labrador (NL)", nullptr));
        provinceCbBox->setItemText(6, QCoreApplication::translate("Form", "Nova Scotia (NS)", nullptr));
        provinceCbBox->setItemText(7, QCoreApplication::translate("Form", "Ontario (ON)", nullptr));
        provinceCbBox->setItemText(8, QCoreApplication::translate("Form", "Prince Edward Island (PE) ", nullptr));
        provinceCbBox->setItemText(9, QCoreApplication::translate("Form", "Quebec (QC)", nullptr));
        provinceCbBox->setItemText(10, QCoreApplication::translate("Form", "Saskatchewan (SK)", nullptr));
        provinceCbBox->setItemText(11, QCoreApplication::translate("Form", "Northwest Territories (NT)", nullptr));
        provinceCbBox->setItemText(12, QCoreApplication::translate("Form", "Nunavut (NU)", nullptr));
        provinceCbBox->setItemText(13, QCoreApplication::translate("Form", "Yukon (YT)", nullptr));

        postalCodeLabel->setText(QCoreApplication::translate("Form", "Postal Code", nullptr));
        btRegister->setText(QCoreApplication::translate("Form", "Register", nullptr));
        btCancel->setText(QCoreApplication::translate("Form", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSESSORFORM_H

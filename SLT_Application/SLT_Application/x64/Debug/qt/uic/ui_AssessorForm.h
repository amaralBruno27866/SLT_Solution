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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *firstNameEdLine;
    QLabel *lastNameLabel;
    QLineEdit *lastNameEdLine;
    QLabel *phoneNumberLabel;
    QLineEdit *phoneNumberEdLine;
    QLabel *emailLabel;
    QLineEdit *emailEdLine;
    QGroupBox *addressBox;
    QFormLayout *formLayout_2;
    QLabel *streetLabel;
    QLineEdit *streetEdLine;
    QLabel *cityLabel;
    QLineEdit *cityEdLine;
    QLabel *label;
    QComboBox *provinceCbBox;
    QLabel *postalCodeLabel;
    QLineEdit *postalCodeEdLine;
    QToolButton *btRegister;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(708, 533);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        personalInformationBox = new QGroupBox(Form);
        personalInformationBox->setObjectName("personalInformationBox");
        formLayout = new QFormLayout(personalInformationBox);
        formLayout->setObjectName("formLayout");
        firstNameLabel = new QLabel(personalInformationBox);
        firstNameLabel->setObjectName("firstNameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameEdLine = new QLineEdit(personalInformationBox);
        firstNameEdLine->setObjectName("firstNameEdLine");

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameEdLine);

        lastNameLabel = new QLabel(personalInformationBox);
        lastNameLabel->setObjectName("lastNameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameEdLine = new QLineEdit(personalInformationBox);
        lastNameEdLine->setObjectName("lastNameEdLine");

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameEdLine);

        phoneNumberLabel = new QLabel(personalInformationBox);
        phoneNumberLabel->setObjectName("phoneNumberLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, phoneNumberLabel);

        phoneNumberEdLine = new QLineEdit(personalInformationBox);
        phoneNumberEdLine->setObjectName("phoneNumberEdLine");

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneNumberEdLine);

        emailLabel = new QLabel(personalInformationBox);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, emailLabel);

        emailEdLine = new QLineEdit(personalInformationBox);
        emailEdLine->setObjectName("emailEdLine");

        formLayout->setWidget(3, QFormLayout::FieldRole, emailEdLine);


        verticalLayout->addWidget(personalInformationBox);

        addressBox = new QGroupBox(Form);
        addressBox->setObjectName("addressBox");
        formLayout_2 = new QFormLayout(addressBox);
        formLayout_2->setObjectName("formLayout_2");
        streetLabel = new QLabel(addressBox);
        streetLabel->setObjectName("streetLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, streetLabel);

        streetEdLine = new QLineEdit(addressBox);
        streetEdLine->setObjectName("streetEdLine");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, streetEdLine);

        cityLabel = new QLabel(addressBox);
        cityLabel->setObjectName("cityLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, cityLabel);

        cityEdLine = new QLineEdit(addressBox);
        cityEdLine->setObjectName("cityEdLine");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cityEdLine);

        label = new QLabel(addressBox);
        label->setObjectName("label");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label);

        provinceCbBox = new QComboBox(addressBox);
        provinceCbBox->setObjectName("provinceCbBox");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, provinceCbBox);

        postalCodeLabel = new QLabel(addressBox);
        postalCodeLabel->setObjectName("postalCodeLabel");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, postalCodeLabel);

        postalCodeEdLine = new QLineEdit(addressBox);
        postalCodeEdLine->setObjectName("postalCodeEdLine");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, postalCodeEdLine);


        verticalLayout->addWidget(addressBox);

        btRegister = new QToolButton(Form);
        btRegister->setObjectName("btRegister");

        verticalLayout->addWidget(btRegister);


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
        postalCodeLabel->setText(QCoreApplication::translate("Form", "Postal Code", nullptr));
        btRegister->setText(QCoreApplication::translate("Form", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSESSORFORM_H

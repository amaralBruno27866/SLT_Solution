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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssessorForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *page_title;
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
    QFrame *frameCreationModification;
    QFormLayout *formLayout_3;
    QLineEdit *createdAtLineEdit;
    QLabel *ModifiedAtLabel;
    QLineEdit *modifiedAtLineEdit;
    QLabel *CreatedAtLabel;
    QHBoxLayout *btArea;
    QSpacerItem *horizontalSpacer;
    QToolButton *btRegister;
    QToolButton *btMyCases;
    QToolButton *btCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AssessorForm)
    {
        if (AssessorForm->objectName().isEmpty())
            AssessorForm->setObjectName("AssessorForm");
        AssessorForm->resize(698, 470);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AssessorForm->sizePolicy().hasHeightForWidth());
        AssessorForm->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(AssessorForm);
        verticalLayout->setObjectName("verticalLayout");
        page_title = new QLabel(AssessorForm);
        page_title->setObjectName("page_title");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        page_title->setFont(font);
        page_title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(page_title);

        personalInformationBox = new QGroupBox(AssessorForm);
        personalInformationBox->setObjectName("personalInformationBox");
        QFont font1;
        font1.setPointSize(9);
        personalInformationBox->setFont(font1);
        formLayout = new QFormLayout(personalInformationBox);
        formLayout->setObjectName("formLayout");
        firstNameLabel = new QLabel(personalInformationBox);
        firstNameLabel->setObjectName("firstNameLabel");
        firstNameLabel->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineedit = new QLineEdit(personalInformationBox);
        firstNameLineedit->setObjectName("firstNameLineedit");
        firstNameLineedit->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameLineedit);

        lastNameLabel = new QLabel(personalInformationBox);
        lastNameLabel->setObjectName("lastNameLabel");
        lastNameLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameLineEdit = new QLineEdit(personalInformationBox);
        lastNameLineEdit->setObjectName("lastNameLineEdit");
        lastNameLineEdit->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameLineEdit);

        phoneNumberLabel = new QLabel(personalInformationBox);
        phoneNumberLabel->setObjectName("phoneNumberLabel");
        phoneNumberLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, phoneNumberLabel);

        phoneNumberLineEdit = new QLineEdit(personalInformationBox);
        phoneNumberLineEdit->setObjectName("phoneNumberLineEdit");
        phoneNumberLineEdit->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, phoneNumberLineEdit);

        emailLabel = new QLabel(personalInformationBox);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(personalInformationBox);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setFont(font1);

        formLayout->setWidget(3, QFormLayout::FieldRole, emailLineEdit);


        verticalLayout->addWidget(personalInformationBox);

        addressBox = new QGroupBox(AssessorForm);
        addressBox->setObjectName("addressBox");
        addressBox->setFont(font1);
        formLayout_2 = new QFormLayout(addressBox);
        formLayout_2->setObjectName("formLayout_2");
        streetLabel = new QLabel(addressBox);
        streetLabel->setObjectName("streetLabel");
        streetLabel->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, streetLabel);

        streetLineEdit = new QLineEdit(addressBox);
        streetLineEdit->setObjectName("streetLineEdit");
        streetLineEdit->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, streetLineEdit);

        cityLabel = new QLabel(addressBox);
        cityLabel->setObjectName("cityLabel");
        cityLabel->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, cityLabel);

        cityLineEdit = new QLineEdit(addressBox);
        cityLineEdit->setObjectName("cityLineEdit");
        cityLineEdit->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cityLineEdit);

        label = new QLabel(addressBox);
        label->setObjectName("label");
        label->setFont(font1);

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
        provinceCbBox->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, provinceCbBox);

        postalCodeLabel = new QLabel(addressBox);
        postalCodeLabel->setObjectName("postalCodeLabel");
        postalCodeLabel->setFont(font1);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, postalCodeLabel);

        postalCodeLineEdit = new QLineEdit(addressBox);
        postalCodeLineEdit->setObjectName("postalCodeLineEdit");
        postalCodeLineEdit->setFont(font1);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, postalCodeLineEdit);


        verticalLayout->addWidget(addressBox);

        frameCreationModification = new QFrame(AssessorForm);
        frameCreationModification->setObjectName("frameCreationModification");
        frameCreationModification->setFrameShape(QFrame::Shape::StyledPanel);
        frameCreationModification->setFrameShadow(QFrame::Shadow::Raised);
        formLayout_3 = new QFormLayout(frameCreationModification);
        formLayout_3->setObjectName("formLayout_3");
        createdAtLineEdit = new QLineEdit(frameCreationModification);
        createdAtLineEdit->setObjectName("createdAtLineEdit");
        createdAtLineEdit->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, createdAtLineEdit);

        ModifiedAtLabel = new QLabel(frameCreationModification);
        ModifiedAtLabel->setObjectName("ModifiedAtLabel");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ModifiedAtLabel);

        modifiedAtLineEdit = new QLineEdit(frameCreationModification);
        modifiedAtLineEdit->setObjectName("modifiedAtLineEdit");
        modifiedAtLineEdit->setReadOnly(true);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, modifiedAtLineEdit);

        CreatedAtLabel = new QLabel(frameCreationModification);
        CreatedAtLabel->setObjectName("CreatedAtLabel");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, CreatedAtLabel);


        verticalLayout->addWidget(frameCreationModification);

        btArea = new QHBoxLayout();
        btArea->setObjectName("btArea");
        btArea->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btArea->addItem(horizontalSpacer);

        btRegister = new QToolButton(AssessorForm);
        btRegister->setObjectName("btRegister");
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        btRegister->setFont(font2);
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

        btMyCases = new QToolButton(AssessorForm);
        btMyCases->setObjectName("btMyCases");
        btMyCases->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #2b93e9;\n"
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
"    background-color: #2b29e9;\n"
"}"));

        btArea->addWidget(btMyCases);

        btCancel = new QToolButton(AssessorForm);
        btCancel->setObjectName("btCancel");
        btCancel->setFont(font2);
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


        retranslateUi(AssessorForm);

        QMetaObject::connectSlotsByName(AssessorForm);
    } // setupUi

    void retranslateUi(QWidget *AssessorForm)
    {
        AssessorForm->setWindowTitle(QCoreApplication::translate("AssessorForm", "Form", nullptr));
        page_title->setText(QCoreApplication::translate("AssessorForm", "Page Title", nullptr));
        personalInformationBox->setTitle(QCoreApplication::translate("AssessorForm", "Personal Information", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("AssessorForm", "First name", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("AssessorForm", "Last name", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("AssessorForm", "Phone number", nullptr));
        emailLabel->setText(QCoreApplication::translate("AssessorForm", "Email", nullptr));
        addressBox->setTitle(QCoreApplication::translate("AssessorForm", "Address", nullptr));
        streetLabel->setText(QCoreApplication::translate("AssessorForm", "Street", nullptr));
        cityLabel->setText(QCoreApplication::translate("AssessorForm", "City", nullptr));
        label->setText(QCoreApplication::translate("AssessorForm", "Province", nullptr));
        provinceCbBox->setItemText(0, QCoreApplication::translate("AssessorForm", "N/A", nullptr));
        provinceCbBox->setItemText(1, QCoreApplication::translate("AssessorForm", "Alberta (AB)", nullptr));
        provinceCbBox->setItemText(2, QCoreApplication::translate("AssessorForm", "British Columbia (BC)", nullptr));
        provinceCbBox->setItemText(3, QCoreApplication::translate("AssessorForm", "Manitoba (MB)", nullptr));
        provinceCbBox->setItemText(4, QCoreApplication::translate("AssessorForm", "New Brunswick (NB)", nullptr));
        provinceCbBox->setItemText(5, QCoreApplication::translate("AssessorForm", "Newfoundland and Labrador (NL)", nullptr));
        provinceCbBox->setItemText(6, QCoreApplication::translate("AssessorForm", "Nova Scotia (NS)", nullptr));
        provinceCbBox->setItemText(7, QCoreApplication::translate("AssessorForm", "Ontario (ON)", nullptr));
        provinceCbBox->setItemText(8, QCoreApplication::translate("AssessorForm", "Prince Edward Island (PE) ", nullptr));
        provinceCbBox->setItemText(9, QCoreApplication::translate("AssessorForm", "Quebec (QC)", nullptr));
        provinceCbBox->setItemText(10, QCoreApplication::translate("AssessorForm", "Saskatchewan (SK)", nullptr));
        provinceCbBox->setItemText(11, QCoreApplication::translate("AssessorForm", "Northwest Territories (NT)", nullptr));
        provinceCbBox->setItemText(12, QCoreApplication::translate("AssessorForm", "Nunavut (NU)", nullptr));
        provinceCbBox->setItemText(13, QCoreApplication::translate("AssessorForm", "Yukon (YT)", nullptr));

        postalCodeLabel->setText(QCoreApplication::translate("AssessorForm", "Postal Code", nullptr));
        ModifiedAtLabel->setText(QCoreApplication::translate("AssessorForm", "Modified at", nullptr));
        CreatedAtLabel->setText(QCoreApplication::translate("AssessorForm", "Created at", nullptr));
        btRegister->setText(QCoreApplication::translate("AssessorForm", "Register", nullptr));
        btMyCases->setText(QCoreApplication::translate("AssessorForm", "My Cases", nullptr));
        btCancel->setText(QCoreApplication::translate("AssessorForm", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssessorForm: public Ui_AssessorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSESSORFORM_H

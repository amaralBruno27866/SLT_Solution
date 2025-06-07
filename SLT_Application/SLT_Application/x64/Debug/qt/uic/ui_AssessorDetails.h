/********************************************************************************
** Form generated from reading UI file 'AssessorDetails.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSESSORDETAILS_H
#define UI_ASSESSORDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssessorDetails
{
public:

    void setupUi(QWidget *AssessorDetails)
    {
        if (AssessorDetails->objectName().isEmpty())
            AssessorDetails->setObjectName("AssessorDetails");
        AssessorDetails->resize(693, 508);

        retranslateUi(AssessorDetails);

        QMetaObject::connectSlotsByName(AssessorDetails);
    } // setupUi

    void retranslateUi(QWidget *AssessorDetails)
    {
        AssessorDetails->setWindowTitle(QCoreApplication::translate("AssessorDetails", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssessorDetails: public Ui_AssessorDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSESSORDETAILS_H

/********************************************************************************
** Form generated from reading UI file 'ActionButtons.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONBUTTONS_H
#define UI_ACTIONBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_actionButtons
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *btView;
    QToolButton *btEdit;
    QToolButton *btDelete;

    void setupUi(QWidget *actionButtons)
    {
        if (actionButtons->objectName().isEmpty())
            actionButtons->setObjectName("actionButtons");
        actionButtons->resize(550, 69);
        horizontalLayout = new QHBoxLayout(actionButtons);
        horizontalLayout->setObjectName("horizontalLayout");
        btView = new QToolButton(actionButtons);
        btView->setObjectName("btView");
        btView->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    width: 32px;\n"
"    height: 32px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #5cd65c;\n"
"}"));
        btView->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btView);

        btEdit = new QToolButton(actionButtons);
        btEdit->setObjectName("btEdit");
        btEdit->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #00008B;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    width: 32px;\n"
"    height: 32px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #0000FF\n"
"}"));
        btEdit->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btEdit);

        btDelete = new QToolButton(actionButtons);
        btDelete->setObjectName("btDelete");
        btDelete->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #ff5100;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"    width: 32px;\n"
"    height: 32px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #ff5168;\n"
"}"));
        btDelete->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btDelete);


        retranslateUi(actionButtons);

        QMetaObject::connectSlotsByName(actionButtons);
    } // setupUi

    void retranslateUi(QWidget *actionButtons)
    {
        actionButtons->setWindowTitle(QCoreApplication::translate("actionButtons", "Form", nullptr));
        btView->setText(QCoreApplication::translate("actionButtons", "View", nullptr));
        btEdit->setText(QCoreApplication::translate("actionButtons", "Edit", nullptr));
        btDelete->setText(QCoreApplication::translate("actionButtons", "Del", nullptr));
    } // retranslateUi

};

namespace Ui {
    class actionButtons: public Ui_actionButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONBUTTONS_H

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
#include <QtGui/QIcon>
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
"    background-color: #44b2f8;\n"
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
"    background-color: #44f8f8;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraWeb));
        btView->setIcon(icon);
        btView->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btView);

        btEdit = new QToolButton(actionButtons);
        btEdit->setObjectName("btEdit");
        btEdit->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #ffbb46;\n"
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
"    background-color: #ffe936;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("mail-message-new")));
        btEdit->setIcon(icon1);
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
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        btDelete->setIcon(icon2);
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
        btDelete->setText(QCoreApplication::translate("actionButtons", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class actionButtons: public Ui_actionButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONBUTTONS_H

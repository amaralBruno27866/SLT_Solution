#pragma once

#include <QWidget>
#include "ui_AssessorForm.h"

class AssessorForm : public QWidget
{
    Q_OBJECT

public:
    explicit AssessorForm(QWidget* parent = nullptr)
        : QWidget(parent)
    {
        ui.setupUi(this);
    }

private:
    Ui::Form ui;
};
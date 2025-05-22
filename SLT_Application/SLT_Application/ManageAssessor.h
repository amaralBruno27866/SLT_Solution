#pragma once

#include <QWidget>
#include "ui_ManageAssessor.h"

class ManageAssessor : public QWidget
{
    Q_OBJECT

public:
    explicit ManageAssessor(QWidget* parent = nullptr);

private:
    Ui::ManageAssessor ui;
};
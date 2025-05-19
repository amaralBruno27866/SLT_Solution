#pragma once

#include <QtWidgets/QMainWindow>
#include "x64/Debug/qt/uic/ui_SLT_W11.h"

class SLT_W11 : public QMainWindow
{
    Q_OBJECT

public:
    SLT_W11(QWidget* parent = nullptr);
    ~SLT_W11();

private:
    Ui::SLT_W11Class ui; // This now works because the definition is included
};

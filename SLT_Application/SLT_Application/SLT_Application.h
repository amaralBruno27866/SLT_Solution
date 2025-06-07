#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SLT_Application.h"

namespace silver {
    class SLT_Application : public QMainWindow
    {
        Q_OBJECT

    public:
        SLT_Application(QWidget* parent = nullptr);
        ~SLT_Application();

    private:
        Ui::SLT_ApplicationClass ui;

    private slots:
        void on_actionAdd_a_new_assessor_triggered();
        void on_actionManage_assessor_triggered();
    };
}

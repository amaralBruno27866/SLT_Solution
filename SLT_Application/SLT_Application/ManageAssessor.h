#pragma once

#include <QWidget>
#include "ui_ManageAssessor.h"

#include "Assessor.h"

namespace silver {
    class ManageAssessor : public QWidget
    {
        Q_OBJECT

    public:
        explicit ManageAssessor(QWidget* parent = nullptr);
        ManageAssessor(const ManageAssessor&) = delete;
        ManageAssessor& operator=(const ManageAssessor&) = delete;
        void loadAssessors();
        void addAssessor();
        void editAssessor(int id);
		void viewAssessorDetails(int id);
        void deleteAssessor(int id);
        void searchAssessors(const QString& filter);
        void handleSelectionChanged();
        void showError(const QString& message);
        void showSuccess(const QString& message);

    private:
        Ui::ManageAssessor ui;
    };
}

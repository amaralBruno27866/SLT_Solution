#include "ManageAssessor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "Utils.h"
#include "Assessor.h"

namespace silver {
    ManageAssessor::ManageAssessor(QWidget* parent)
        : QWidget(parent)
    {
        ui.setupUi(this);

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("clinic.db");

        if (!db.open()) {
            qDebug() << "Error opening database:" << db.lastError().text();
        }
        else {
            QSqlQuery query;
            bool ok = query.exec(
                "CREATE TABLE IF NOT EXISTS assessor ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "lastname TEXT,"
                "firstname TEXT,"
                "email TEXT,"
                "phone TEXT)"
            );
            if (!ok) {
                qDebug() << "Erro ao criar tabela:" << query.lastError().text();
            }
        }
    }
    void ManageAssessor::loadAssessors()
    {
		// Clear the table widget before loading new data
        ui.tableWidget->setRowCount(0);

		// Check if the database is open
        QSqlDatabase db = QSqlDatabase::database();
        if (!db.isOpen()) {
            showError("Database is not open.");
            return;
        }

		// Query to load assessors
        QSqlQuery query(db);
        if (!query.exec("SELECT id, lastname, firstname, email, phone FROM assessor")) {
            showError("Failed to load assessors: " + query.lastError().text());
			return;
        }

		// Populate the table widget with assessor data
        int row = 0;
        while (query.next()) {
            ui.tableWidget->insertRow(row);
			ui.tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui.tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Last Name
            ui.tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // First Name
            ui.tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Email
            ui.tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Phone
			ui.tableWidget->setItem(row, 5, new QTableWidgetItem("")); // Actions (View/Edit/Delete)
			row++;
        }
    }

    void ManageAssessor::addAssessor()
    {
        // Create the form dor adding a new assessor
        Assessor* form = new Assessor(this);

        // When the form was closed, reload the assessors list
        connect(form, &QWidget::destroyed, this, [this]() {
            this->loadAssessors();
        });

		// Sequence for showing the form
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setWindowFlag(Qt::Window);
        form->setFixedSize(500, 400);
        form->show();
    }

    void ManageAssessor::editAssessor()
    {
    }
    
    void ManageAssessor::viewAssessorDetails()
    {
    }
    
    void ManageAssessor::deleteAssessor()
    {
    }
    
    void ManageAssessor::searchAssessors(const QString& filter)
    {
    }
    
    void ManageAssessor::handleSelectionChanged()
    {
    }
    
    void ManageAssessor::showError(const QString& message)
    {
    }
    
    void ManageAssessor::showSuccess(const QString& message)
    {
    }
}

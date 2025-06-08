#include "ManageAssessor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "Utils.h"
#include "Assessor.h"
#include "ActionButtons.h"
#include <QMessageBox>

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

            ActionButtons* actions = new ActionButtons();
            ui.tableWidget->setCellWidget(row, 5, actions);

            int id = query.value(0).toInt();
            connect(actions->viewButton(), &QToolButton::clicked, this, [this, id]() {
                this->viewAssessorDetails(id);
            });
            connect(actions->editButton(), &QToolButton::clicked, this, [this, id]() {
                this->editAssessor(id);
            });
            connect(actions->deleteButton(), &QToolButton::clicked, this, [this, id]() {
                this->deleteAssessor(id);
            });

			row++;
        }
    }

    void ManageAssessor::addAssessor()
    {
        // Create the form for adding a new assessor
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

    void ManageAssessor::editAssessor(int id)
    {
		// Create the form for editing an existing assessor
        Assessor* form = new Assessor(this);
        form->setMode(Assessor::FormMode::Edit);
        form->setId(id);
        form->loadFormData();

        connect(form, &QWidget::destroyed, this, [this]() {
            utils::reloadList(this, &ManageAssessor::loadAssessors);
        });

        utils::showForm(form);
    }
    
    void ManageAssessor::viewAssessorDetails(int id)
    {
        Assessor* form = new Assessor(this);
        form->setMode(Assessor::FormMode::Detail);
		form->setId(id);
        form->loadFormData();

        utils::showForm(form);
    }
    
    void ManageAssessor::deleteAssessor(int id)
    {
        // User confirmation dialog
        QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Confirm Deletion",
            "Are you sure you want to delete this assessor?",
            QMessageBox::Yes | QMessageBox::No
        );

        if (reply != QMessageBox::Yes) {
            return;
        }

        // Open database
        QSqlDatabase db = QSqlDatabase::database();
        if (!db.isOpen()) {
            showError("Database is not open.");
            return;
        }

        // Execute the delete query
        QSqlQuery query(db);
        query.prepare("DELETE FROM assessor WHERE id = ?");
        query.addBindValue(id);

        if (!query.exec()) {
            showError("Failed to delete assessor: " + query.lastError().text());
            return;
        }

        showSuccess("Assessor deleted successfully.");
        utils::reloadList(this, &ManageAssessor::loadAssessors);
    }
    
    void ManageAssessor::searchAssessors(const QString& filter)
    {
        ui.tableWidget->setRowCount(0);

        QString trimmed = filter.trimmed();
        if (trimmed.isEmpty()) {
            loadAssessors();
            return;
        }

        QSqlDatabase db = QSqlDatabase::database();
        if (!db.isOpen()) {
            showError("Database is not open.");
            return;
        }

        bool isNumber = false;
        int id = trimmed.toInt(&isNumber);

        QString sql = "SELECT id, lastname, firstname, email, phone FROM assessor WHERE ";
        QStringList conditions;
        QList<QVariant> params;

        if (isNumber) {
            conditions << "id = ?";
            params << id;
        }

        conditions << "firstname LIKE ?";
        params << "%" + trimmed + "%";
		conditions << "lastname LIKE ?";
		params << "%" + trimmed + "%";
        conditions << "phone LIKE ?";
		params << "%" + trimmed + "%";

		sql += conditions.join(" OR ");

        QSqlQuery query(db);
        query.prepare(sql);
        for (const QVariant& param : params) {
			query.addBindValue(param);
        }

        if (!query.exec()) {
            showError("Failed to search assessors: " + query.lastError().text());
			return;
        }

        int row = 0;
        while (query.next()) {
            ui.tableWidget->insertRow(row);
            ui.tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui.tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Last Name
            ui.tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // First Name
            ui.tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Email
            ui.tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Phone

            ActionButtons* actions = new ActionButtons();
            ui.tableWidget->setCellWidget(row, 5, actions);

            int id = query.value(0).toInt();
            connect(actions->viewButton(), &QToolButton::clicked, this, [this, id]() {
                this->viewAssessorDetails(id);
            });
            connect(actions->editButton(), &QToolButton::clicked, this, [this, id]() {
                this->editAssessor(id);
            });
            connect(actions->deleteButton(), &QToolButton::clicked, this, [this, id]() {
                this->deleteAssessor(id);
			});

            row++;
        }
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

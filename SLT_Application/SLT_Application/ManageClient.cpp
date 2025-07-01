#include "ManageClient.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

#include "Utils.h"
#include "Client.h"
#include "ActionButtons.h"

namespace silver {
	ManageClient::ManageClient(QWidget* parent)
		: QWidget(parent)
	{
		ui.setupUi(this);

		QSqlDatabase db = QSqlDatabase::database();

		connect(ui.btRefresh, &QToolButton::clicked, this, [this]() {
			this->loadClient();
		});

		connect(ui.btSearch, &QToolButton::clicked, this, [this]() {
			this->searchClients(ui.searchLineEdit->text());
		});

		connect(ui.searchLineEdit, &QLineEdit::returnPressed, this, [this]() {
			this->searchClients(ui.searchLineEdit->text());
		});

		if (!db.open()) {
			qDebug() << "Error opening database:" << db.lastError().text();
		}
		else {
			QSqlQuery query;
			bool ok = query.exec(
				"CREATE TABLE IF NOT EXISTS client ("
				"id INTEGER PRIMARY KEY AUTOINCREMENT,"
				"lastname TEXT,"
				"firstname TEXT,"
				"email TEXT,"
				"phone TEXT)"
			);
			if (!ok) {
				qDebug() << "Error creating table:" << query.lastError().text();
			}
		}

		loadClient();
	}

	void ManageClient::loadClient()
	{
		// Clear the table widget before loding new data
		ui.tableWidget->setRowCount(0);

		// Check if the database is open
		QSqlDatabase db = QSqlDatabase::database();
		if (!db.isOpen()) {
			showError("Database is not open.");
			return;
		}

		// Query to load clients
		QSqlQuery query(db);
		if (!query.exec("SELECT id, lastname, firstname, email, phone FROM client")) {
			showError("Failed to load clients: " + query.lastError().text());
			return;
		}

		// Populate the table widget with client data
		int row = 0;
		while (query.exec()) {
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
				this->viewClientDetails(id);
				}
			);

			connect(actions->editButton(), &QToolButton::clicked, this, [this, id]() {
				this->editClient(id);
			});

			connect(actions->deleteButton(), &QToolButton::clicked, this, [this, id]() {
				this->deleteClient(id);
			});

			row++;
		}
	}

	void ManageClient::addClient()
	{
		//Create the form for adding a new client
		Client* form = new Client(this);

		// When the form was closed, reload the clients list
		connect(form, &Client::destroyed, this, [this]() {
			this->loadClient();
		});

		// Sequence for showing the form
		form->setAttribute(Qt::WA_DeleteOnClose);
		form->setWindowFlag(Qt::Window);
		form->setFixedSize(980, 620);
		form->show();
	}

	void ManageClient::editClient(int id)
	{
		// Create the form for editing an existing client
		Client* form = new Client(this);
		form->setMode(Client::FormMode::Edit);
		form->setId(id);
		form->loadFormData();

		connect(form, &Client::destroyed, this, [this]() {
			utils::reloadList(this, &ManageClient::loadClient);
		});

		utils::showForm(form);
	}

	void ManageClient::viewClientDetails(int id)
	{
		Client* form = new Client(this);
		form->setMode(Client::FormMode::Detail);
		form->setId(id);
		form->loadFormData();

		utils::showForm(form);
	}

	void ManageClient::deleteClient(int id)
	{
		// User confirmation dialog
		QMessageBox::StandardButton reply = QMessageBox::question(
			this,
			"Confirm Deletion",
			"Are you sure you want to delete this client?",
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
		// Delete address first
		QSqlQuery addressQuery(db);
		addressQuery.prepare("DELETE FROM address WHERE client_id = ?");
		addressQuery.addBindValue(id);
		if (!addressQuery.exec()) {
			showError("Failed to delete address: " + addressQuery.lastError().text());
			return;
		}

		// Delete the client
		QSqlQuery query(db);
		query.prepare("DELETE FROM client WHERE id = ?");
		query.addBindValue(id);
		if (!query.exec()) {
			showError("Failed to delete client: " + query.lastError().text());
			return;
		}

		if (!query.exec()) {
			showError("Failed to delete client: " + query.lastError().text());
			return;
		}

		showSuccess("Client deleted successfully.");
		utils::reloadList(this, &ManageClient::loadClient);
	}

	void ManageClient::searchClients(const QString& filter)
	{
		ui.tableWidget->setRowCount(0);

		QString trimmed = filter.trimmed();
		if (trimmed.isEmpty()) {
			loadClient();
			return;
		}

		QSqlDatabase db = QSqlDatabase::database();
		if (!db.isOpen()) {
			showError("Database is not open.");
			return;
		}

		bool isNumber = false;
		int id = trimmed.toInt(&isNumber);

		QString sql = "SELECT id, lastname, firstname, email, phone FROM client WHERE ";
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

		sql += conditions.join(" OR ");

		QSqlQuery query(db);
		query.prepare(sql);
		for (const QVariant& param : params) {
			query.addBindValue(param);
		}

		if (!query.exec()) {
			showError("Failed to search clients: " + query.lastError().text());
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
				this->viewClientDetails(id);
				});

			connect(actions->editButton(), &QToolButton::clicked, this, [this, id]() {
				this->editClient(id);
				});

			connect(actions->deleteButton(), &QToolButton::clicked, this, [this, id]() {
				this->deleteClient(id);
				});

			row++;
		}
	}

	void ManageClient::showError(const QString& message)
	{
		QMessageBox::critical(this, tr("Error"), message);
	}

	void ManageClient::showSuccess(const QString& message)
	{
		QMessageBox::information(this, tr("Success"), message);
	}
}
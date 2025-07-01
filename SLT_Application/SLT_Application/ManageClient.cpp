#include "ManageClient.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "Utils.h"
#include "Client.h"
#include "ActionButtons.h"
#include <QMessageBox>

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
}
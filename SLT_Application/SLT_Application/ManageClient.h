#pragma once

#include <QWidget>
#include "ui_ManageClient.h"

#include "Assessor.h"

namespace silver {
	class ManageClient : public QWidget
	{
		Q_OBJECT

	public:
		explicit ManageClient(QWidget* parent = nullptr);
		ManageClient(const ManageClient&) = delete;
		ManageClient& operator=(const ManageClient&) = delete;
		void loadClient();
		void addClient();
		void editClient(int id);
		void viewClientDetails(int id);
		void deleteClient(int id);
		void searchClients(const QString& filter);
		void showError(const QString& message);
		void showSuccess(const QString& message);

	private:
		Ui::ManageClient ui;
	};
}

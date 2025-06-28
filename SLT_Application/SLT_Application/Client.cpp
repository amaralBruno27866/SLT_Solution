#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>
#include <QDateTime>
#include <sstream>

#include "Utils.h"
#include "Client.h"

using namespace std;
namespace silver {
	Client::Client(QWidget* parent)
		: QWidget(parent),
		m_id(0),
		m_firstName(),
		m_lastName(),
		m_email(),
		m_phone(),
		m_address(),
		m_createdAt(),
		m_modifiedAt()
	{
		ui.setupUi(this);

		// Connect the click signal to register button
		connect(ui.btRegister, &QToolButton::clicked, this, &Client::handleFormSubmission);
		connect(ui.btCancel, &QToolButton::clicked, this, &Client::handleFormCancellation);
		
		setMode(FormMode::Create); // Default mode is Create
	}

	Client::Client(
		int id, 
		const QString& firstName, 
		const QString& lastName, 
		const QString& email, 
		const QString& phone, 
		const Address& address, 
		const QString& createdAt, 
		const QString& modifiedAt,
		FormMode mode) : QWidget(nullptr),
		m_id(id),
		m_firstName(firstName),
		m_lastName(lastName),
		m_email(email),
		m_phone(phone),
		m_address(address),
		m_createdAt(createdAt),
		m_modifiedAt(modifiedAt)
	{
		ui.setupUi(this);
		setMode(mode);
	}

	Client::Client(const Client& other)
		: QWidget(other.parentWidget()),
		m_id(other.m_id),
		m_firstName(other.m_firstName),
		m_lastName(other.m_lastName),
		m_email(other.m_email),
		m_phone(other.m_phone),
		m_address(other.m_address),
		m_createdAt(other.m_createdAt),
		m_modifiedAt(other.m_modifiedAt)
	{
		ui.setupUi(this);
	}

	Client& Client::operator=(const Client& other)
	{
		if (this != &other) {
			m_id = other.m_id;
			m_firstName = other.m_firstName;
			m_lastName = other.m_lastName;
			m_email = other.m_email;
			m_phone = other.m_phone;
			m_address = other.m_address;
			m_createdAt = other.m_createdAt;
			m_modifiedAt = other.m_modifiedAt;
		}
		return *this;
	}

	Client::~Client() = default;

	int Client::getId() const 
	{
		return m_id;
	}

	QString Client::getFirstName() const 
	{
		return m_firstName;
	}

	QString Client::getLastName() const 
	{
		return m_lastName;
	}

	QString Client::getEmail() const 
	{
		return m_email;
	}

	QString Client::getPhone() const 
	{
		return m_phone;
	}

	QString Client::getCreatedAt() const 
	{
		return m_createdAt;
	}

	QString Client::getModifiedAt() const 
	{
		return m_modifiedAt;
	}

	Address Client::getAddress() const 
	{
		return m_address;
	}

	void Client::setId(int id) 
	{
		m_id = id;
	}

	void Client::setFirstName(const QString& firstName) 
	{
		string trimmed = utils::trim(firstName.toStdString());
		m_firstName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}

	void Client::setLastName(const QString& lastName) 
	{
		string trimmed = utils::trim(lastName.toStdString());
		m_lastName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}

	void Client::setEmail(const QString& email)
	{
		string trimmed = utils::trim(email.toStdString());
		if (utils::isValidEmail(trimmed)) {
			m_email = QString::fromStdString(trimmed);
		}
		else {
			m_email.clear();
		}
	}

	void Client::setPhone(const QString& phone)
	{
		string trimmed = utils::trim(phone.toStdString());
		if (utils::isValidPhoneNumber(trimmed)) {
			m_phone = QString::fromStdString(trimmed);
		}
		else {
			m_phone.clear();
		}
	}

	void Client::setCreatedAt(const QString& createdAt)
	{
		m_createdAt = createdAt;
	}

	void Client::setModifiedAt(const QString& modifiedAt)
	{
		m_modifiedAt = modifiedAt;
	}

	void Client::setAddress(const Address& address)
	{
		m_address = address;
	}

	void Client::clearForm()
	{
		m_firstName.clear();
		m_lastName.clear();
		m_email.clear();
		m_phone.clear();
		m_createdAt.clear();
		m_modifiedAt.clear();
		m_address = Address();

		// Personal information section
		if (ui.firstNameLineedit) ui.firstNameLineedit->clear();
		if (ui.lastNameLineEdit) ui.lastNameLineEdit->clear();
		if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->clear();
		if (ui.emailLineEdit) ui.emailLineEdit->clear();

		// Address information section
		if (ui.streetLineEdit) ui.streetLineEdit->clear();
		if (ui.cityLineEdit) ui.cityLineEdit->clear();
		if (ui.provinceCbBox) ui.provinceCbBox->setCurrentIndex(0);
		if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->clear();
	}

	void Client::saveFormData()
	{
		setFirstName(ui.firstNameLineedit ? ui.firstNameLineedit->text() : "");
		setLastName(ui.lastNameLineEdit ? ui.lastNameLineEdit->text() : "");
		setPhone(ui.phoneNumberLineEdit ? utils::formatPhoneNumber(ui.phoneNumberLineEdit->text()) : "");
		setEmail(ui.emailLineEdit ? ui.emailLineEdit->text() : "");

		string street = ui.streetLineEdit ? ui.streetLineEdit->text().toStdString() : "";
		string city = ui.cityLineEdit ? ui.cityLineEdit->text().toStdString() : "";
		string province = ui.provinceCbBox ? ui.provinceCbBox->currentText().toStdString() : "";
		string postalCode = ui.postalCodeLineEdit ? ui.postalCodeLineEdit->text().toStdString() : "";

		Address addr;
		addr.setStreet(street);
		addr.setCity(city);
		addr.setProvince(province);
		addr.setPostalCode(postalCode);
		setAddress(addr);

		QSqlDatabase db = QSqlDatabase::database();
		if (!db.isOpen()) {
			QMessageBox::warning(this, "Database Error", "Database is not open.");
			return;
		}

		QString now = QDateTime::currentDateTime().toString(Qt::ISODate);

		if (m_id == 0) {
			// Insert a new client
			m_createdAt = now;
			m_modifiedAt = now;

			QSqlQuery query(db);
			query.prepare(R"(
				INSERT INTO client (
					firstname, lastname, phone, email, created_at, modified_at
				) VALUES (
					:firstname, :lastname, :phone, :email, :created_at, :modified_at
				)
			)");
			query.bindValue(":firstname", m_firstName);
			query.bindValue(":lastname", m_lastName);
			query.bindValue(":phone", m_phone);
			query.bindValue(":email", m_email);
			query.bindValue(":created_at", m_createdAt);
			query.bindValue(":modified_at", m_modifiedAt);

			if (!query.exec()) {
				QMessageBox::critical(this, "Database Error", query.lastError().text());
				return;
			}

			m_id = query.lastInsertId().toInt();

			// Insert a new address
			QSqlQuery addressQuery(db);
			addressQuery.prepare(R"(
				INSERT INTO address (
					client_id, street, city, province, postal_code, created_at, modified_at
				) VALUES (
					:client_id, :street, :city, :province, :postal_code, :created_at, :modified_at
				)
			)");

			addressQuery.bindValue(":client_id", m_id);
			addressQuery.bindValue(":street", QString::fromStdString(m_address.getStreet()));
			addressQuery.bindValue(":city", QString::fromStdString(m_address.getCity()));
			addressQuery.bindValue(":province", QString::fromStdString(m_address.getProvince()));
			addressQuery.bindValue(":postal_code", QString::fromStdString(m_address.getPostalCode()));
			addressQuery.bindValue(":created_at", m_createdAt);
			addressQuery.bindValue(":modified_at", m_modifiedAt);

			if (!addressQuery.exec()) {
				QMessageBox::critical(this, "Database Error", addressQuery.lastError().text());
			}
			else {
				QMessageBox::information(this, "Success", "Client and address saved successfully!");
			}
		}
		else {
			m_modifiedAt = now;

			QSqlQuery checkClientQuery(db);
			checkClientQuery.prepare("SELECT COUNT(*) FROM client WHERE id = :id");
			checkClientQuery.bindValue(":id", m_id);
			checkClientQuery.exec();
			checkClientQuery.next();

			// Check if the client exists
			int clientCount = checkClientQuery.value(0).toInt();

			if (clientCount == 0) {
				QMessageBox::warning(this, "Update Error", "Client not found in the database.");
				return;
			}

			// Update client
			QSqlQuery query(db);
			query.prepare(R"(
				UPDATE client SET
					firstname = :firstname,
					lastname = :lastname,
					phone = :phone,
					email = :email,
					modified_at = :modified_at
				WHERE id = :id
			)");
			query.bindValue(":firstname", m_firstName);
			query.bindValue(":lastname", m_lastName);
			query.bindValue(":phone", m_phone);
			query.bindValue(":email", m_email);
			query.bindValue(":modified_at", m_modifiedAt);
			query.bindValue(":id", m_id);

			if (!query.exec()) {
				QMessageBox::critical(this, "Database Error", query.lastError().text());
				return;
			}

			QSqlQuery checkAddressQuery(db);
			checkAddressQuery.prepare("SELECT COUNT(*) FROM address WHERE client_id = :client_id");
			checkAddressQuery.bindValue(":client_id", m_id);
			checkAddressQuery.exec();
			checkAddressQuery.next();

			// Check if address exists
			int addressCount = checkAddressQuery.value(0).toInt();

			if (addressCount > 0) {
				// Update address
				QSqlQuery addressQuery(db);
				addressQuery.prepare(R"(
					UPDATE address SET
						street = :street,
						city = :city,
						province = :province,
						postal_code = :postal_code,
						modified_at = :modified_at
					WHERE client_id = :client_id
				)");
				addressQuery.bindValue(":street", QString::fromStdString(m_address.getStreet()));
				addressQuery.bindValue(":city", QString::fromStdString(m_address.getCity()));
				addressQuery.bindValue(":province", QString::fromStdString(m_address.getProvince()));
				addressQuery.bindValue(":postal_code", QString::fromStdString(m_address.getPostalCode()));
				addressQuery.bindValue(":modified_at", m_modifiedAt);
				addressQuery.bindValue(":client_id", m_id);

				if (!addressQuery.exec()) {
					QMessageBox::critical(this, "Database Error", addressQuery.lastError().text());
				}
				else {
					QMessageBox::information(this, "Success", "Client and address updated successfully!");
				}
			}
			else {
				// Insert address
				QSqlQuery addressQuery(db);
				addressQuery.prepare(R"(
					INSERT INTO address (
						client_id, street, city, province, postal_code, created_at, modified_at
					) VALUES (
						:client_id, :street, :city, :province, :postal_code, :created_at, :modified_at
					)
				)");
				addressQuery.bindValue(":client_id", m_id);
				addressQuery.bindValue(":street", QString::fromStdString(m_address.getStreet()));
				addressQuery.bindValue(":city", QString::fromStdString(m_address.getCity()));
				addressQuery.bindValue(":province", QString::fromStdString(m_address.getProvince()));
				addressQuery.bindValue(":postal_code", QString::fromStdString(m_address.getPostalCode()));
				addressQuery.bindValue(":created_at", m_createdAt);
				addressQuery.bindValue(":modified_at", m_modifiedAt);

				if (!addressQuery.exec()) {
					QMessageBox::critical(this, "Database Error", addressQuery.lastError().text());
				}
				else {
					QMessageBox::information(this, "Success", "Client and address updated successfully!");
				}
			}
		}
		clearForm();
	}

	void Client::loadFormData()
	{
		if (m_id <= 0) {
			QMessageBox::warning(this, "Load Error", "Client ID is not set. Cannot load data.");
			return;
		}

		QSqlDatabase db = QSqlDatabase::database();
		if (!db.isOpen()) {
			QMessageBox::warning(this, "Database Error", "Database is not open.");
			return;
		}

		QSqlQuery query(db);
		query.prepare(R"(
			SELECT c.firstname, c.lastname, c.phone, c.email, c.created_at, c.modified_at,
				   ad.street, ad.city, ad.province, ad.postal_code
			FROM client c
			LEFT JOIN address ad ON ad.client_id = c.id
			WHERE c.id = ?
		)");
		query.addBindValue(m_id);

		if (!query.exec() || !query.next()) {
			QMessageBox::critical(this, "Database Error", query.lastError().text());
			return;
		}

		setFirstName(query.value(0).toString());
		setLastName(query.value(1).toString());
		setPhone(query.value(2).toString());
		setEmail(query.value(3).toString());
		setCreatedAt(query.value(4).toString());
		setModifiedAt(query.value(5).toString());

		Address addr;
		addr.setStreet(query.value(6).toString().toStdString());
		addr.setCity(query.value(7).toString().toStdString());
		addr.setProvince(query.value(8).toString().toStdString());
		addr.setPostalCode(query.value(9).toString().toStdString());
		setAddress(addr);

		// Update the UI elements
		if (ui.firstNameLineedit) ui.firstNameLineedit->setText(m_firstName);
		if (ui.lastNameLineEdit) ui.lastNameLineEdit->setText(m_lastName);
		if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setText(m_phone);
		if (ui.emailLineEdit) ui.emailLineEdit->setText(m_email);

		if (ui.streetLineEdit) ui.streetLineEdit->setText(QString::fromStdString(m_address.getStreet()));
		if (ui.cityLineEdit) ui.cityLineEdit->setText(QString::fromStdString(m_address.getCity()));
		if (ui.provinceCbBox) {
			QString dbProvince = QString::fromStdString(m_address.getProvince()).trimmed();
			int idx = -1;
			for (int i = 0; i < ui.provinceCbBox->count(); ++i) {
				QString item = ui.provinceCbBox->itemText(i);
				if (item.contains(dbProvince, Qt::CaseInsensitive)) {
					idx = i;
					break;
				}
			}
			ui.provinceCbBox->setCurrentIndex(idx >= 0 ? idx : 0);
		}
		if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setText(QString::fromStdString(m_address.getPostalCode()));

		if (ui.createdAtLineEdit) ui.createdAtLineEdit->setText(m_createdAt);
		if (ui.modifiedAtLineEdit) ui.modifiedAtLineEdit->setText(m_modifiedAt);
	}

	void Client::displayForm()
	{
		loadFormData();
		this->show();
	}

	void Client::handleFormSubmission()
	{
		updateModelFromUI();

		if (handleFormValidation()) {
			saveFormData();
		}
		else {
			QMessageBox::warning(this, "Validation Error", "Please correct the errors in the form.");
		}
	}

	void Client::handleFormCancellation()
	{
		clearForm();
		this->close();
		QMessageBox::information(this, "Cancelled", "Client registration has been cancelled.");
	}

	void Client::handleFormReset()
	{
		clearForm();
		m_id = 0; // Reset ID to indicate new entry
		QMessageBox::information(this, "Reset", "Form has been reset. You can now enter a new client.");
	}

	bool Client::handleFormValidation()
	{
		QStringList errors;

		// Validate first name
		if (m_firstName.trimmed().isEmpty()) {
			errors << "First name is required.";
		}

		// Validate last name
		if (m_lastName.trimmed().isEmpty()) {
			errors << "Last name is required.";
		}

		// Validate email
		if (m_email.trimmed().isEmpty()) {
			errors << "Email is required.";
		}
		else if (!utils::isValidEmail(m_email.toStdString())) {
			errors << "Email format is invalid.";
		}

		// Validate phone number
		if (m_phone.trimmed().isEmpty()) {
			errors << "Phone number is required.";
		}
		else if (!utils::isValidPhoneNumber(m_phone.toStdString())) {
			errors << "Phone number format is invalid.";
		}

		// Validate address
		if (QString::fromStdString(m_address.getStreet()).trimmed().isEmpty()) {
			errors << "Street is required.";
		}

		// Validate city
		if (QString::fromStdString(m_address.getCity()).trimmed().isEmpty()) {
			errors << "City is required.";
		}

		// Validate province
		if (QString::fromStdString(m_address.getProvince()).trimmed().isEmpty() ||
			QString::fromStdString(m_address.getProvince()) == "N/A") {
			errors << "Province is required.";
		}

		// Validate postal code
		if (QString::fromStdString(m_address.getPostalCode()).trimmed().isEmpty()) {
			errors << "Postal code is required.";
		}
		else if (!Address::isValidPostalCode(m_address.getPostalCode())) {
			errors << "Postal code is invalid.";
		}

		// Exibe mensagens de erro, se houver
		if (!errors.isEmpty()) {
			QMessageBox::warning(this, "Validation Error", errors.join("\n"));
			return false;
		}
		return true;
	}

	void Client::setMode(FormMode mode)
	{
		m_mode = mode;

		switch (mode) {
		case FormMode::Create:
			if (ui.page_title) ui.page_title->setText("Create Client");
			if (ui.btRegister) ui.btRegister->setVisible(true);
			if (ui.btRegister) ui.btRegister->setText("Register");
			if (ui.btCancel) ui.btCancel->setVisible(true);
			if (ui.btMyCases) ui.btMyCases->setVisible(false);

			// Turn available fields for creation
			if (ui.firstNameLineedit) ui.firstNameLineedit->setEnabled(true);
			if (ui.lastNameLineEdit) ui.lastNameLineEdit->setEnabled(true);
			if (ui.emailLineEdit) ui.emailLineEdit->setEnabled(true);
			if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setEnabled(true);
			if (ui.streetLineEdit) ui.streetLineEdit->setEnabled(true);
			if (ui.cityLineEdit) ui.cityLineEdit->setEnabled(true);
			if (ui.provinceCbBox) ui.provinceCbBox->setEnabled(true);
			if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setEnabled(true);

			break;
		case FormMode::Edit:
			if (ui.page_title) ui.page_title->setText("Edit Client");
			if (ui.btRegister) ui.btRegister->setVisible(true);
			if (ui.btRegister) ui.btRegister->setText("Save");
			if (ui.btCancel) ui.btCancel->setVisible(true);
			if (ui.btMyCases) ui.btMyCases->setVisible(false);

			// Turn available fields for editing
			if (ui.firstNameLineedit) ui.firstNameLineedit->setEnabled(true);
			if (ui.lastNameLineEdit) ui.lastNameLineEdit->setEnabled(true);
			if (ui.emailLineEdit) ui.emailLineEdit->setEnabled(true);
			if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setEnabled(true);
			if (ui.streetLineEdit) ui.streetLineEdit->setEnabled(true);
			if (ui.cityLineEdit) ui.cityLineEdit->setEnabled(true);
			if (ui.provinceCbBox) ui.provinceCbBox->setEnabled(true);
			if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setEnabled(true);

			break;
		case FormMode::Detail:
			if (ui.page_title) ui.page_title->setText("Client Details");
			if (ui.btRegister) ui.btRegister->setVisible(false);
			if (ui.btCancel) ui.btCancel->setVisible(false);
			if (ui.btMyCases) ui.btMyCases->setText("My Forms");
			if (ui.btMyCases) ui.btMyCases->setVisible(true);

			// Turn unavailable fields for edition
			if (ui.firstNameLineedit) ui.firstNameLineedit->setEnabled(false);
			if (ui.lastNameLineEdit) ui.lastNameLineEdit->setEnabled(false);
			if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setEnabled(false);
			if (ui.emailLineEdit) ui.emailLineEdit->setEnabled(false);
			if (ui.streetLineEdit) ui.streetLineEdit->setEnabled(false);
			if (ui.cityLineEdit) ui.cityLineEdit->setEnabled(false);
			if (ui.provinceCbBox) {
				int idx = ui.provinceCbBox->findText(QString::fromStdString(m_address.getProvince()));
				ui.provinceCbBox->setCurrentIndex(idx >= 0 ? idx : 0);
			}
			if (ui.provinceCbBox) ui.provinceCbBox->setEnabled(false);
			if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setEnabled(false);

			// Change txt of the cancel button to "Close"
			if (ui.btCancel) ui.btCancel->setText("Close");

			break;
		}
	}

	void Client::updateModelFromUI()
	{
		setFirstName(ui.firstNameLineedit ? ui.firstNameLineedit->text() : "");
		setLastName(ui.lastNameLineEdit ? ui.lastNameLineEdit->text() : "");
		setPhone(ui.phoneNumberLineEdit ? ui.phoneNumberLineEdit->text() : "");
		setEmail(ui.emailLineEdit ? ui.emailLineEdit->text() : "");

		string street = ui.streetLineEdit ? ui.streetLineEdit->text().toStdString() : "";
		string city = ui.cityLineEdit ? ui.cityLineEdit->text().toStdString() : "";
		string province = ui.provinceCbBox ? ui.provinceCbBox->currentText().toStdString() : "";
		string postalCode = ui.postalCodeLineEdit ? ui.postalCodeLineEdit->text().toStdString() : "";

		Address addr;
		addr.setStreet(street);
		addr.setCity(city);
		addr.setProvince(province);
		addr.setPostalCode(postalCode);
		setAddress(addr);
	}

	ostream& operator<<(ostream& os, const Client& form)
	{
		os << "Client ID: " << form.getId() << endl;
		os << "First Name: " << form.getFirstName().toStdString() << endl;
		os << "Last Name: " << form.getLastName().toStdString() << endl;
		os << "Email: " << form.getEmail().toStdString() << endl;
		os << "Phone: " << form.getPhone().toStdString() << endl;
		os << "Address: " << form.getAddress().toString() << endl;
		os << "Created At: " << form.getCreatedAt().toStdString() << endl;
		os << "Modified At: " << form.getModifiedAt().toStdString() << endl;
		
		return os;
	}

	istream& operator>>(istream& is, Client& form)
	{
		int id = 0;
		string firstName, lastName, email, phone;
		string street, city, province, postalCode;
		string createdAt, modifiedAt;

		// Read each field in one line
		string line;

		// ID
		if (getline(is, line)) {
			auto pos = line.find(':');
			if (pos != string::npos) {
				id = stoi(line.substr(pos + 1));
			}
			else {
				id = 0;
			}
		}

		// First name
		if (getline(is, line)) {
			auto pos = line.find(':');
			firstName = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Last name
		if (getline(is, line)) {
			auto pos = line.find(':');
			lastName = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Email
		if (getline(is, line)) {
			auto pos = line.find(':');
			email = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Phone
		if (getline(is, line)) {
			auto pos = line.find(':');
			phone = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Created At
		if (getline(is, line)) {
			auto pos = line.find(':');
			createdAt = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Modified At
		if (getline(is, line)) {
			auto pos = line.find(':');
			modifiedAt = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Street
		if (getline(is, line)) {
			auto pos = line.find(':');
			street = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// City
		if (getline(is, line)) {
			auto pos = line.find(':');
			city = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Province
		if (getline(is, line)) {
			auto pos = line.find(':');
			province = (pos != string::npos) ? line.substr(pos + 1) : "";
		}
		else {
			province = "N/A";
		}

		// PostalCode
		if (getline(is, line)) {
			auto pos = line.find(':');
			postalCode = (pos != string::npos) ? line.substr(pos + 1) : "";
		}

		// Set fields in the form
		form.setId(id);
		form.setFirstName(QString::fromStdString(firstName));
		form.setLastName(QString::fromStdString(lastName));
		form.setEmail(QString::fromStdString(email));
		form.setPhone(QString::fromStdString(phone));
		form.setCreatedAt(QString::fromStdString(createdAt));
		form.setModifiedAt(QString::fromStdString(modifiedAt));
		form.setAddress(Address(0, 0, street, city, province, postalCode));

		return is;
	}
}

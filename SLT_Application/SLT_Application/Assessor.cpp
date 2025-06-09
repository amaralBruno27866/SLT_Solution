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
#include "Assessor.h"

using namespace std;
namespace silver {
	Assessor::Assessor(QWidget* parent)
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

		// Conect the click signal to register button
		connect(ui.btRegister, &QToolButton::clicked, this, &Assessor::handleFormSubmission);
	}
	
	Assessor::Assessor(
		int id, 
		const QString& firstName, 
		const QString& lastName, 
		const QString& email, 
		const QString& phone, 
		const Address& address, 
		const QString& createdAt, 
		const QString& modifiedAt) : QWidget(nullptr),
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
	}
	
	Assessor::Assessor(const Assessor& other)
		: QWidget(nullptr),
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
	
	Assessor& Assessor::operator=(const Assessor& other)
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
	
	Assessor::~Assessor() = default;
	
	int Assessor::getId() const
	{
		return m_id;
	}

	QString Assessor::getFirstName() const
	{
		return m_firstName;
	}
	
	QString Assessor::getLastName() const
	{
		return m_lastName;
	}
	
	QString Assessor::getEmail() const
	{
		return m_email;
	}
	
	QString Assessor::getPhone() const
	{
		return m_phone;
	}

	QString Assessor::getCreatedAt() const
	{
		return m_createdAt;
	}

	QString Assessor::getModifiedAt() const
	{
		return m_modifiedAt;
	}
	
	Address Assessor::getAddress() const
	{
		return m_address;
	}
	
	void Assessor::setId(int id)
	{
		m_id = id;
	}

	void Assessor::setFirstName(const QString& firstName)
	{
		string trimmed = utils::trim(firstName.toStdString());
		m_firstName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}
	
	void Assessor::setLastName(const QString& lastName)
	{
		string trimmed = utils::trim(lastName.toStdString());
		m_lastName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}
	
	void Assessor::setEmail(const QString& email)
	{
		string trimmed = utils::trim(email.toStdString());
		if (utils::isValidEmail(trimmed)) {
			m_email = QString::fromStdString(trimmed);
		}
		else {
			m_email.clear();
		}
	}
	
	void Assessor::setPhone(const QString& phone)
	{
		string trimmed = utils::trim(phone.toStdString());
		if(utils::isValidPhoneNumber(trimmed)) {
			m_phone = QString::fromStdString(trimmed);
		}
		else {
			m_phone.clear();
		}
	}

	void Assessor::setCreatedAt(const QString& createdAt)
	{
		m_createdAt = createdAt;
	}

	void Assessor::setModifiedAt(const QString& modifiedAt)
	{
		m_modifiedAt = modifiedAt;
	}
	
	void Assessor::setAddress(const Address& address)
	{
		m_address = address;
	}
	
	void Assessor::clearForm()
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
		if (ui.provinceCbBox) ui.provinceCbBox->setCurrentIndex(0); // Select "N/A"
		if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->clear();
	}
	
	void Assessor::saveFormData()
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

		QSqlDatabase db = QSqlDatabase::database("silverLiningTherapyDB");
		if (!db.isOpen()) {
			QMessageBox::warning(this, "Database Error", "Database is not open.");
			return;
		}

		QString now = QDateTime::currentDateTime().toString(Qt::ISODate);

		if (m_id == 0) {

			// Generate a new record
			m_createdAt = now;
			m_modifiedAt = now;

			QSqlQuery query(db);
			query.prepare(R"(
            INSERT INTO assessors (
                first_name, last_name, email, phone, street, city, province, postal_code, created_at, modified_at
            ) VALUES (
                :first_name, :last_name, :email, :phone, :street, :city, :province, :postal_code, :created_at, :modified_at
            )
        )");
			query.addBindValue(m_firstName);
			query.addBindValue(m_lastName);
			query.addBindValue(m_email);
			query.addBindValue(m_phone);
			query.addBindValue(QString::fromStdString(m_address.getStreet()));
			query.addBindValue(QString::fromStdString(m_address.getCity()));
			query.addBindValue(QString::fromStdString(m_address.getProvince()));
			query.addBindValue(QString::fromStdString(m_address.getPostalCode()));
			query.addBindValue(m_createdAt);
			query.addBindValue(m_modifiedAt);

			if (!query.exec()) {
				QMessageBox::critical(this, "Database Error", query.lastError().text());
			}
			else {
				m_id = query.lastInsertId().toInt();
				QMessageBox::information(this, "Success", "Assessor registered successfully!");
			}
		}
		else {
			
			// Updatate existing record
			m_modifiedAt = now;

			QSqlQuery query(db);
			query.prepare(R"(
            UPDATE assessors SET
                first_name = :first_name,
                last_name = :last_name,
                email = :email,
                phone = :phone,
                street = :street,
                city = :city,
                province = :province,
                postal_code = :postal_code,
                modified_at = :modified_at
            WHERE id = :id
        )");
			query.addBindValue(m_firstName);
			query.addBindValue(m_lastName);
			query.addBindValue(m_email);
			query.addBindValue(m_phone);
			query.addBindValue(QString::fromStdString(m_address.getStreet()));
			query.addBindValue(QString::fromStdString(m_address.getCity()));
			query.addBindValue(QString::fromStdString(m_address.getProvince()));
			query.addBindValue(QString::fromStdString(m_address.getPostalCode()));
			query.addBindValue(m_modifiedAt);
			query.addBindValue(m_id);

			if (!query.exec()) {
				QMessageBox::critical(this, "Database Error", query.lastError().text());
			}
			else {
				QMessageBox::information(this, "Success", "Assessor updated successfully!");
			}
		}
	}
	
	void Assessor::loadFormData() 
	{
		if (m_id <= 0) {
			QMessageBox::warning(this, "Load Error", "No valid assessor ID set for loading");
			return;
		}

		QSqlDatabase db = QSqlDatabase::database("silverLiningTherapyDB");
		if (!db.isOpen()) {
			QMessageBox::warning(this, "Database Error", "Database is not open.");
			return;
		}

		QSqlQuery query(db);
		query.prepare(R"(
        SELECT first_name, last_name, email, phone, street, city, province, postal_code
        FROM assessors
        WHERE id = ?
		)");
		query.addBindValue(m_id);

		if (!query.exec() || !query.next()) {
			QMessageBox::warning(this, "Load Error", "Assessor not found in the database.");
			return;
		}

		// Update the internal attributes
		setFirstName(query.value(0).toString());
		setLastName(query.value(1).toString());
		setEmail(query.value(2).toString());
		setPhone(query.value(3).toString());

		Address addr;
		addr.setStreet(query.value(4).toString().toStdString());
		addr.setCity(query.value(5).toString().toStdString());
		addr.setProvince(query.value(6).toString().toStdString());
		addr.setPostalCode(query.value(7).toString().toStdString());
		setAddress(addr);

		// Update the UI elements
		if (ui.firstNameLineedit) ui.firstNameLineedit->setText(m_firstName);
		if (ui.lastNameLineEdit) ui.lastNameLineEdit->setText(m_lastName);
		if (ui.emailLineEdit) ui.emailLineEdit->setText(m_email);
		if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setText(m_phone);

		if (ui.streetLineEdit) ui.streetLineEdit->setText(QString::fromStdString(m_address.getStreet()));
		if (ui.cityLineEdit) ui.cityLineEdit->setText(QString::fromStdString(m_address.getCity()));
		if (ui.provinceCbBox) {
			int idx = ui.provinceCbBox->findText(QString::fromStdString(m_address.getProvince()));
			ui.provinceCbBox->setCurrentIndex(idx >= 0 ? idx : 0); // Default to "N/A" if not found
		}
		if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setText(QString::fromStdString(m_address.getPostalCode()));
	}
	
	void Assessor::displayForm()
	{
		loadFormData();
		this->show();
	}
	
	void Assessor::handleFormSubmission()
	{
		handleFormValidation();

		if (!m_firstName.isEmpty() && !m_lastName.isEmpty() && !m_email.isEmpty() && !m_phone.isEmpty()) {
			saveFormData();
		}
		else {
			QMessageBox::warning(this, "Validation Error", "Please fill all required fields with valid data.");
		}
	}
	
	void Assessor::handleFormCancellation()
	{
		clearForm();
		this->close();
		QMessageBox::information(this, "Cancelled", "Assessor registration has been cancelled.");
	}
	
	void Assessor::handleFormReset()
	{
		clearForm();
		m_id = 0; // Reset ID to indicate new entry
		QMessageBox::information(this, "Reset", "Form has been reset. You can now enter a new assessor.");
	}
	
	void Assessor::handleFormValidation()
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
		}
	}

	void Assessor::setMode(FormMode mode)
	{
		m_mode = mode;

		if (ui.frameCreationModification)
			ui.frameCreationModification->setVisible(mode == FormMode::Detail);

		switch (mode) {
		case FormMode::Create:
			if (ui.page_title) ui.page_title->setText("Create Assessor");
			if (ui.btRegister) ui.btRegister->setVisible(true);
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
			if (ui.page_title) ui.page_title->setText("Edit Assessor");
			if (ui.btRegister) ui.btRegister->setVisible(true);
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
		case FormMode::Detail:
			if (ui.page_title) ui.page_title->setText("Assessor Details");
			if (ui.btRegister) ui.btRegister->setVisible(false);
			if (ui.btCancel) ui.btCancel->setVisible(true);
			if (ui.btMyCases) ui.btMyCases->setVisible(true);

			// Turn unavailable fields for edition
			if (ui.firstNameLineedit) ui.firstNameLineedit->setEnabled(false);
			if (ui.lastNameLineEdit) ui.lastNameLineEdit->setEnabled(false);
			if (ui.phoneNumberLineEdit) ui.phoneNumberLineEdit->setEnabled(false);
			if (ui.emailLineEdit) ui.emailLineEdit->setEnabled(false);
			if (ui.streetLineEdit) ui.streetLineEdit->setEnabled(false);
			if (ui.cityLineEdit) ui.cityLineEdit->setEnabled(false);
			if (ui.provinceCbBox) ui.provinceCbBox->setEnabled(false);
			if (ui.postalCodeLineEdit) ui.postalCodeLineEdit->setEnabled(false);

			// Change txt of the cancel button to "Close"
			if (ui.btCancel) ui.btCancel->setText("Close");
			
			break;
		}
	}
	
	ostream& operator<<(ostream& os, const Assessor& form)
	{
		os << "Assessor ID: " << form.getId() << endl;
		os << "First Name: " << form.getFirstName().toStdString() << endl;
		os << "Last Name: " << form.getLastName().toStdString() << endl;
		os << "Email: " << form.getEmail().toStdString() << endl;
		os << "Phone: " << form.getPhone().toStdString() << endl;
		os << "Address: " << form.getAddress().toString() << endl;
		os << "Created At: " << form.getCreatedAt().toStdString() << endl;
		os << "Modified At: " << form.getModifiedAt().toStdString() << endl;
		
		return os;
	}
	
	istream& operator>>(istream& is, Assessor& form)
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
		form.setAddress(Address(street, city, province, postalCode));

		return is;
	}
}
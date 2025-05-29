#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>

#include "Utils.h"
#include "AssessorForm.h"

using namespace std;
namespace silver {
	AssessorForm::AssessorForm(QWidget* parent)
		: QWidget(parent),
		m_id(0),
		m_firstName(),
		m_lastName(),
		m_email(),
		m_phone(),
		m_address()
	{
		ui.setupUi(this);

		// Conect the click signal to register button
		connect(ui.btRegister, &QToolButton::clicked, this, &AssessorForm::handleFormSubmission);
	}
	
	AssessorForm::AssessorForm() : AssessorForm(nullptr){}
	
	AssessorForm::AssessorForm(int id, const QString& firstName, const QString& lastName, const QString& email, const QString& phone, const Address& address)
		: QWidget(nullptr),
		m_id(id),
		m_firstName(firstName),
		m_lastName(lastName),
		m_email(email),
		m_phone(phone),
		m_address(address)
	{
		ui.setupUi(this);
	}
	
	AssessorForm::AssessorForm(const AssessorForm& other)
		: QWidget(nullptr),
		m_id(other.m_id),
		m_firstName(other.m_firstName),
		m_lastName(other.m_lastName),
		m_email(other.m_email),
		m_phone(other.m_phone),
		m_address(other.m_address)
	{
		ui.setupUi(this);
	}
	
	AssessorForm& AssessorForm::operator=(const AssessorForm& other)
	{
		if (this != &other) {
			m_id = other.m_id;
			m_firstName = other.m_firstName;
			m_lastName = other.m_lastName;
			m_email = other.m_email;
			m_phone = other.m_phone;
			m_address = other.m_address;
		}
		return *this;
	}
	
	AssessorForm::~AssessorForm() = default;
	
	int AssessorForm::getId() const
	{
		return m_id;
	}

	QString AssessorForm::getFirstName() const
	{
		return m_firstName;
	}
	
	QString AssessorForm::getLastName() const
	{
		return m_lastName;
	}
	
	QString AssessorForm::getEmail() const
	{
		return m_email;
	}
	
	QString AssessorForm::getPhone() const
	{
		return m_phone;
	}
	
	Address AssessorForm::getAddress() const
	{
		return m_address;
	}
	
	void AssessorForm::setId(int id)
	{
		m_id = id;
	}

	void AssessorForm::setFirstName(const QString& firstName)
	{
		string trimmed = utils::trim(firstName.toStdString());
		m_firstName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}
	
	void AssessorForm::setLastName(const QString& lastName)
	{
		string trimmed = utils::trim(lastName.toStdString());
		m_lastName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}
	
	void AssessorForm::setEmail(const QString& email)
	{
		string trimmed = utils::trim(email.toStdString());
		if (utils::isValidEmail(trimmed)) {
			m_email = QString::fromStdString(trimmed);
		}
		else {
			m_email.clear();
		}
	}
	
	void AssessorForm::setPhone(const QString& phone)
	{
		string trimmed = utils::trim(phone.toStdString());
		if(utils::isValidPhoneNumber(trimmed)) {
			m_phone = QString::fromStdString(trimmed);
		}
		else {
			m_phone.clear();
		}
	}
	
	void AssessorForm::setAddress(const Address& address)
	{
		m_address = address;
	}
	
	void AssessorForm::clearForm()
	{
		m_firstName.clear();
		m_lastName.clear();
		m_email.clear();
		m_phone.clear();
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
	
	void AssessorForm::saveFormData()
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

		// Persist the data to the database
		QSqlDatabase db = QSqlDatabase::database("silverLiningTherapyDB");
		if (!db.isOpen()) {
			QMessageBox::warning(this, "Database Error", "Database is not open.");
			return;
		}

		QSqlQuery query(db);
		query.prepare(R"(
			INSERT INTO assessors (first_name, last_name, email, phone, street, city, province, postal_code)
			VALUES (:first_name, :last_name, :email, :phone, :street, :city, :province, :postal_code)
		)");
		query.addBindValue(m_firstName);
		query.addBindValue(m_lastName);
		query.addBindValue(m_email);
		query.addBindValue(m_phone);
		query.addBindValue(QString::fromStdString(m_address.getStreet()));
		query.addBindValue(QString::fromStdString(m_address.getCity()));
		query.addBindValue(QString::fromStdString(m_address.getProvince()));
		query.addBindValue(QString::fromStdString(m_address.getPostalCode()));

		if (!query.exec()) {
			QMessageBox::critical(this, "Database Error", query.lastError().text());
		} else {
			m_id = query.lastInsertId().toInt();
			QMessageBox::information(this, "Success", "Assessor registered successfully!");
		}
	}
	
	void AssessorForm::loadFormData()
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
	
	void AssessorForm::displayForm()
	{
		loadFormData();
		this->show();
	}
	
	void AssessorForm::handleFormSubmission()
	{
		handleFormValidation();

		if (!m_firstName.isEmpty() && !m_lastName.isEmpty() && !m_email.isEmpty() && !m_phone.isEmpty()) {
			saveFormData();
		}
		else {
			QMessageBox::warning(this, "Validation Error", "Please fill all required fields with valid data.");
		}
	}
	
	void AssessorForm::handleFormCancellation()
	{
		clearForm();
		this->close();
		QMessageBox::information(this, "Cancelled", "Assessor registration has been cancelled.");
	}
	
	void AssessorForm::handleFormReset()
	{
		clearForm();
		m_id = 0; // Reset ID to indicate new entry
		QMessageBox::information(this, "Reset", "Form has been reset. You can now enter a new assessor.");
	}
	
	void AssessorForm::handleFormValidation()
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
	
	ostream& operator<<(ostream& os, const AssessorForm& form)
	{
		// TODO: insert return statement here
	}
	
	istream& operator>>(istream& is, AssessorForm& form)
	{
		// TODO: insert return statement here
	}
}
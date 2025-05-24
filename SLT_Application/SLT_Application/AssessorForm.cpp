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
	}
	
	void AssessorForm::displayForm()
	{
	}
	
	void AssessorForm::handleFormSubmission()
	{
	}
	
	void AssessorForm::handleFormCancellation()
	{
	}
	
	void AssessorForm::handleFormReset()
	{
	}
	
	void AssessorForm::handleFormValidation()
	{
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
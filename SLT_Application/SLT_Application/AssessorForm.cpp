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
		m_firstName(),
		m_lastName(),
		m_email(),
		m_phone(),
		m_address()
	{
		ui.setupUi(this);
	}
	
	AssessorForm::AssessorForm() : AssessorForm(nullptr){}
	
	AssessorForm::AssessorForm(const QString& firstName, const QString& lastName, const QString& email, const QString& phone, const Address& address)
		: QWidget(nullptr),
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
			m_firstName = other.m_firstName;
			m_lastName = other.m_lastName;
			m_email = other.m_email;
			m_phone = other.m_phone;
			m_address = other.m_address;
		}
		return *this;
	}
	
	AssessorForm::~AssessorForm() = default;
	
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
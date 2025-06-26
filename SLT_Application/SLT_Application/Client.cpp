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

	int Client::getId() const {
		return m_id;
	}

	QString Client::getFirstName() const {
		return m_firstName;
	}

	QString Client::getLastName() const {
		return m_lastName;
	}

	QString Client::getEmail() const {
		return m_email;
	}

	QString Client::getPhone() const {
		return m_phone;
	}

	QString Client::getCreatedAt() const {
		return m_createdAt;
	}

	QString Client::getModifiedAt() const {
		return m_modifiedAt;
	}

	Address Client::getAddress() const {
		return m_address;
	}

	void Client::setId(int id) {
		m_id = id;
	}

	void Client::setFirstName(const QString& firstName) {
		string trimmed = utils::trim(firstName.toStdString());
		m_firstName = QString::fromStdString(utils::capitalizeWords(trimmed));
	}
}

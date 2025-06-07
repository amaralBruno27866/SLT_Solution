#ifndef ASSESSORFORM_H
#define ASSESSORFORM_H

#include <QWidget>
#include <QString>
#include "ui_AssessorForm.h"
#include "Address.h"

using namespace std;
namespace silver {

class Assessor : public QWidget {
    Q_OBJECT

private:
    Ui::AssessorForm ui;

	int m_id;

    QString m_firstName;
	QString m_lastName;
	QString m_email;
	QString m_phone;
	Address m_address;

public:
    explicit Assessor(QWidget* parent = nullptr);

	Assessor(int id, const QString& firstName, const QString& lastName, const QString& email, const QString& phone, const Address& address);

	// Copy constructos and assignment
	Assessor(const Assessor& other);
	Assessor& operator=(const Assessor& other);

	// Destructor
	~Assessor() override;

	// Getters
	int getId() const;
	QString getFirstName() const;
	QString getLastName() const;
	QString getEmail() const;
	QString getPhone() const;
	Address getAddress() const;

	// Setters
	void setId(int id);
	void setFirstName(const QString& firstName);
	void setLastName(const QString& lastName);
	void setEmail(const QString& email);
	void setPhone(const QString& phone);
	void setAddress(const Address& address);

	// Function to clear the form
	void clearForm();

	// Function to save the form data
	void saveFormData();

	// Function to load the form data
	void loadFormData();

	// Function to display the form
	void displayForm();

	// Function to handle form submission
	void handleFormSubmission();

	// Function to handle form cancellation
	void handleFormCancellation();

	// Function to handle form reset
	void handleFormReset();

	// Function to handle form validation
	void handleFormValidation();

	// Stream methods
	ostream& display(ostream& os) const;
	istream& read(istream& is);
};

	// Stream operators
	ostream& operator<<(ostream& os, const Assessor& form);
	istream& operator>>(istream& is, Assessor& form);

} // namespace silver

#endif // ASSESSORFORM_H

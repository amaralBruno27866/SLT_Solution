#ifndef ASSESSORFORM_H
#define ASSESSORFORM_H

#include <QWidget>
#include <QString>
#include "ui_AssessorForm.h"
#include "Address.h"

using namespace std;
namespace silver {

class AssessorForm : public QWidget {
    Q_OBJECT

private:
    Ui::AssessorForm ui;

    QString m_firstName;
	QString m_lastName;
	QString m_email;
	QString m_phone;
	Address m_address;

public:
    explicit AssessorForm(QWidget* parent = nullptr);

	AssessorForm();
	AssessorForm(const QString& firstName, const QString& lastName, const QString& email, const QString& phone, const Address& address);

	// Copy constructos and assignment
	AssessorForm(const AssessorForm& other);
	AssessorForm& operator=(const AssessorForm& other);

	// Destructor
	~AssessorForm() override;

	// Getters
	QString getFirstName() const;
	QString getLastName() const;
	QString getEmail() const;
	QString getPhone() const;
	Address getAddress() const;

	// Setters
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
	ostream& operator<<(ostream& os, const AssessorForm& form);
	istream& operator>>(istream& is, AssessorForm& form);

} // namespace silver

#endif // ASSESSORFORM_H

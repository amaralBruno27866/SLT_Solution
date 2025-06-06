#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
#include "Utils.h"

using namespace std;
namespace silver {
	class Address {
	private:
		string m_street;
		string m_city;
		string m_province;
		string m_postalCode;
	public:
		Address();
		Address(const string& street, const string& city, const string& province, const string& postalCode);

		// Copy constructor and assignment
		Address(const Address&);
		Address& operator=(const Address&);

		// Destructor
		~Address();

		// Getters
		const string& getStreet() const;
		const string& getCity() const;
		const string& getProvince() const;
		const string& getPostalCode() const;

		// Setters
		void setStreet(const string& street);
		void setCity(const string& city);
		void setProvince(const string& province);
		void setPostalCode(const string& postalCode);

		// String representation
		string toString();

		// Postal code helpers
		static bool isValidPostalCode(const string& code);
		static string formatPostalCode(const string& code);

		// Stream methods
		ostream& display(ostream& os) const;
		istream& read(istream& is);
	};

	// Stream operators
	ostream& operator<<(ostream& os, const Address& addr);
	istream& operator>>(istream& is, Address& addr);

} // namespace silver

#endif // !ADDRESS_H



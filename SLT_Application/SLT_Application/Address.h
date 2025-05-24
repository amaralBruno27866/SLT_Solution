#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
#include "Utils.h"

namespace silver {
	class Address {
	private:
		std::string m_street;
		std::string m_city;
		std::string m_province;
		std::string m_postalCode;
	public:
		Address();
		Address(const std::string& street, const std::string& city, const std::string& province, const std::string& postalCode);

		// Copy constructor and assignment
		Address(const Address&);
		Address& operator=(const Address&);

		// Destructor
		~Address();

		// Getters
		const std::string& getStreet() const;
		const std::string& getCity() const;
		const std::string& getProvince() const;
		const std::string& getPostalCode() const;

		// Setters
		void setStreet(const std::string& street);
		void setCity(const std::string& city);
		void setProvince(const std::string& province);
		void setPostalCode(const std::string& postalCode);

		// String representation
		std::string toString();

		// Postal code helpers
		static bool isValidPostalCode(const std::string& code);
		static std::string formatPostalCode(const std::string& code);

		// Stream methods
		std::ostream& display(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	// Stream operators
	std::ostream& operator<<(std::ostream& os, const Address& addr);
	std::istream& operator>>(std::istream& is, Address& addr);

} // namespace silver

#endif // !ADDRESS_H



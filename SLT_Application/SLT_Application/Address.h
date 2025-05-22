#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>

namespace slt {
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
		Address(const Address&) = default;
		Address& operator=(const Address&) = default;

		// Destructor
		~Address() = default;

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
		std::string toString() const;

		// Stream methods
		std::ostream& display(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	// Stream operators
	std::ostream& operator<<(std::ostream& os, const Address& addr);
	std::istream& operator>>(std::istream& is, Address& addr);

} // namespace slt

#endif // !ADDRESS_H



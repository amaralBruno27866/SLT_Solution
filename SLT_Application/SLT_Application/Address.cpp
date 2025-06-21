#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <regex>
#include "Address.h"
#include "Utils.h"

using namespace std;
namespace silver {

    Address::Address()
        : m_id(0), m_assessorId(0), m_street(), m_city(), m_province(), m_postalCode() { }

    Address::Address(
        const int id,
        const int assessorId,
        const string& street, 
        const string& city, 
        const string& province, 
        const string& postalCode)
        : m_id(id), m_assessorId(assessorId), m_street(street), m_city(city), m_province(province), m_postalCode(postalCode) { }

    Address::Address(const Address& other)
        : m_id(other.m_id), m_assessorId(other.m_assessorId), m_street(other.m_street), m_city(other.m_city), m_province(other.m_province), m_postalCode(other.m_postalCode) { }

    Address& Address::operator=(const Address& other)
    {
        if (this != &other) {
            m_id = other.m_id;
            m_assessorId = other.m_assessorId;
            m_street = other.m_street;
            m_city = other.m_city;
            m_province = other.m_province;
            m_postalCode = other.m_postalCode;
        }
        return *this;
    }

    Address::~Address() = default;

    const int& Address::getId() const { return m_id; }
    const int& Address::getAssessorId() const { return m_assessorId; }
    const string& Address::getStreet() const { return m_street; }
    const string& Address::getCity() const { return m_city; }
    const string& Address::getProvince() const { return m_province; }
    const string& Address::getPostalCode() const { return m_postalCode; }

    void Address::setId(int id) {
        m_id = id;
    }

    void Address::setAssessorId(int assessorId) {
        m_assessorId = assessorId;
    }

    void Address::setStreet(const string& street) {
        m_street = utils::trim(utils::toUpper(street));
    }
    void Address::setCity(const string& city) {
        m_city = utils::trim(utils::toUpper(city));
    }
    void Address::setProvince(const string& province) {
        m_province = utils::trim(utils::toUpper(province));
    }
    void Address::setPostalCode(const string& postalCode) {
        string code = utils::toUpper(utils::trim(postalCode));
        if (isValidPostalCode(code)) {
            m_postalCode = formatPostalCode(code);
        }
        else {
            m_postalCode = "";
        }
    }

    string Address::toString()
    {
        string temp;
        for (char c : m_postalCode) {
            if (!isspace(static_cast<unsigned char>(c)))
                temp += toupper(static_cast<unsigned char>(c));
        }
        if (temp.size() != 7)
            return "";

        temp.insert(3, " ");
        return temp;
    }

    bool Address::isValidPostalCode(const string& code)
    {
        static const std::regex pattern("^[A-Z][0-9][A-Z] [0-9][A-Z][0-9]$");
        string formatted = formatPostalCode(code);
        return std::regex_match(formatted, pattern);
    }

    string Address::formatPostalCode(const string& code)
    {
        // Remove the spaces
        string formattedCode = utils::removeSpaces(code);
		// Convert to uppercase
        formattedCode = utils::toUpper(formattedCode);
		// Insert space after the third character if it needs it
        if (formattedCode.length() == 6) {
            formattedCode.insert(3, " ");
        }
        // If there is already a space in the correct position, keep it
        else if (formattedCode.length() == 7 && formattedCode[3] != ' ') {
            formattedCode = formattedCode.substr(0, 3) + " " + formattedCode.substr(3);
        }
        return formattedCode;
    }

    ostream& Address::display(ostream& os) const
    {
        os << m_street << ", " << m_city << ", " << m_province << ", " << m_postalCode;
        return os;
    }

    istream& Address::read(istream& is)
    {
        getline(is, m_street, ',');
        if (!is) return is;
        if (!m_street.empty() && m_street[0] == ' ') m_street.erase(0, 1);

        getline(is, m_city, ',');
        if (!is) return is;
        if (!m_city.empty() && m_city[0] == ' ') m_city.erase(0, 1);

        getline(is, m_province, ',');
        if (!is) return is;
        if (!m_province.empty() && m_province[0] == ' ') m_province.erase(0, 1);

        getline(is, m_postalCode);
        if (!m_postalCode.empty() && m_postalCode[0] == ' ') m_postalCode.erase(0, 1);

        return is;
    }

    ostream& operator<<(ostream& os, const Address& addr)
    {
        return addr.display(os);
    }

    istream& operator>>(istream& is, Address& addr)
    {
        return addr.read(is);
    }
}

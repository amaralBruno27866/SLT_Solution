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
        : m_street(), m_city(), m_province(), m_postalCode() {}

    Address::Address(const std::string& street, const std::string& city, const std::string& province, const std::string& postalCode)
        : m_street(street), m_city(city), m_province(province), m_postalCode(postalCode) {}

    Address::Address(const Address& other)
        : m_street(other.m_street), m_city(other.m_city), m_province(other.m_province), m_postalCode(other.m_postalCode) {}

    Address& Address::operator=(const Address& other)
    {
        if (this != &other) {
            m_street = other.m_street;
            m_city = other.m_city;
            m_province = other.m_province;
            m_postalCode = other.m_postalCode;
        }
        return *this;
    }

    Address::~Address() = default;

    const string& Address::getStreet() const { return m_street; }
    const string& Address::getCity() const { return m_city; }
    const string& Address::getProvince() const { return m_province; }
    const string& Address::getPostalCode() const { return m_postalCode; }

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
        // Remove espaços e converte para maiúsculo
        string temp;
        for (char c : m_postalCode) {
            if (!isspace(static_cast<unsigned char>(c)))
                temp += toupper(static_cast<unsigned char>(c));
        }
        // Deve ter 7 caracteres após remoção dos espaços
        if (temp.size() != 7)
            return "";

        // Insere espaço após o terceiro caractere
        temp.insert(3, " ");
        return temp;
    }

    bool Address::isValidPostalCode(const string& code)
    {
        // Formato: A1B 2C3 (letra, número, letra, espaço, número, letra, número)
        static const std::regex pattern("^[A-Z][0-9][A-Z] [0-9][A-Z][0-9]$");
        string formatted = formatPostalCode(code);
        return std::regex_match(formatted, pattern);
    }

    string Address::formatPostalCode(const string& code)
    {
        string formattedCode = utils::trim(code);

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
        // Remove leading space if present
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <regex>
#include "Address.h"

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

    const std::string& Address::getStreet() const { return m_street; }
    const std::string& Address::getCity() const { return m_city; }
    const std::string& Address::getProvince() const { return m_province; }
    const std::string& Address::getPostalCode() const { return m_postalCode; }

    void Address::setStreet(const std::string& street) { m_street = street; }
    void Address::setCity(const std::string& city) { m_city = city; }
    void Address::setProvince(const std::string& province) { m_province = province; }
    void Address::setPostalCode(const std::string& postalCode) { m_postalCode = postalCode; }

    std::string Address::toString()
    {
        // Remove espaços e converte para maiúsculo
        std::string temp;
        for (char c : m_postalCode) {
            if (!std::isspace(static_cast<unsigned char>(c)))
                temp += std::toupper(static_cast<unsigned char>(c));
        }
        // Deve ter 6 caracteres após remoção dos espaços
        if (temp.size() != 6)
            return "";

        // Insere espaço após o terceiro caractere
        temp.insert(3, " ");
        return temp;
    }

    bool Address::isValidPostalCode(const std::string& code)
    {
        // Formato: A1B 2C3 (letra, número, letra, espaço, número, letra, número)
        static const std::regex pattern("^[A-Z][0-9][A-Z] [0-9][A-Z][0-9]$");
        std::string formatted = formatPostalCode(code);
        return std::regex_match(formatted, pattern);
    }

    std::string Address::formatPostalCode(const std::string& code)
    {
        return std::string();
    }

    std::ostream& Address::display(std::ostream& os) const
    {
        os << m_street << ", " << m_city << ", " << m_province << ", " << m_postalCode;
        return os;
    }

    std::istream& Address::read(std::istream& is)
    {
        std::getline(is, m_street, ',');
        if (!is) return is;
        // Remove leading space if present
        if (!m_street.empty() && m_street[0] == ' ') m_street.erase(0, 1);

        std::getline(is, m_city, ',');
        if (!is) return is;
        if (!m_city.empty() && m_city[0] == ' ') m_city.erase(0, 1);

        std::getline(is, m_province, ',');
        if (!is) return is;
        if (!m_province.empty() && m_province[0] == ' ') m_province.erase(0, 1);

        std::getline(is, m_postalCode);
        if (!m_postalCode.empty() && m_postalCode[0] == ' ') m_postalCode.erase(0, 1);

        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Address& addr)
    {
        return addr.display(os);
    }

    std::istream& operator>>(std::istream& is, Address& addr)
    {
        return addr.read(is);
    }

}

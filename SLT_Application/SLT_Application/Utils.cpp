#include "Utils.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <regex>
#include <QRegularExpression>

namespace utils {

	std::string toUpper(const std::string& str)
	{
		std::string result = str;
		std::transform(result.begin(), result.end(), result.begin(), ::toupper);
		return result;
	}

	std::string trim(const std::string& str)
	{
		auto start = str.begin();
		while (start != str.end() && std::isspace(static_cast<unsigned char>(*start))) ++start;
		auto end = str.end();
		do {
			--end;
		} while (end != start && std::isspace(static_cast<unsigned char>(*end)));
		return (start <= end) ? std::string(start, end + 1) : std::string();
	}

	std::string removeSpaces(const std::string& str)
	{
		std::string result;
		for (char c : str) {
			if (!std::isspace(static_cast<unsigned char>(c)))
				result += c;
		}
		return result;
	}

	bool isValidEmail(const std::string& email)
	{
		static const std::regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
		return std::regex_match(email, pattern);
	}

	bool isValidPhoneNumber(const std::string& phone)
	{
		std::string digits;
		for (char c : phone) {
			if (std::isdigit(static_cast<unsigned char>(c)))
				digits += c;
		}
		return digits.length() == 10 || digits.length() == 11;
	}

	std::string capitalizeWords(const std::string& str)
	{
		std::string result = str;
		bool newWord = true;
		for (size_t i = 0; i < result.length(); ++i) {
			if (std::isspace(static_cast<unsigned char>(result[i]))) {
				newWord = true;
			} else if (newWord) {
				result[i] = std::toupper(static_cast<unsigned char>(result[i]));
				newWord = false;
			} else {
				result[i] = std::tolower(static_cast<unsigned char>(result[i]));
			}
		}
		return result;
	}

	std::string replaceAll(std::string str, const std::string& from, const std::string& to)
	{
		if (from.empty()) return str;
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
		return str;
	}

	QString formatPhoneNumber(const QString& phone)
	{
		QString digits = phone;
		digits.remove(QRegularExpression("[^0-9]"));
		if (digits.length() == 10) {
			return QString("(%1) %2-%3")
				.arg(digits.mid(0, 3))
				.arg(digits.mid(3, 3))
				.arg(digits.mid(6, 4));
		}

		return phone;
	}
}
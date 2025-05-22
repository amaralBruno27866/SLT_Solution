#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>

namespace utils {

// Converte uma string para mai�sculas
inline std::string toUpper(const std::string& str);

// Remove espa�os do in�cio e fim
inline std::string trim(const std::string& str);

// Remove todos os espa�os da string
inline std::string removeSpaces(const std::string& str);

// Valida e-mail (formato simples)
bool isValidEmail(const std::string& email);

// Valida telefone (apenas d�gitos, tamanho 10 ou 11)
bool isValidPhoneNumber(const std::string& phone);

// Capitaliza a primeira letra de cada palavra
inline std::string capitalizeWords(const std::string& str);

// Substitui todas as ocorr�ncias de 'from' por 'to'
inline std::string replaceAll(std::string str, const std::string& from, const std::string& to);

} // namespace utils

#endif // UTILS_H

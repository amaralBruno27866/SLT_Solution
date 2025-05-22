#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>

namespace utils {

// Converte uma string para maiúsculas
inline std::string toUpper(const std::string& str);

// Remove espaços do início e fim
inline std::string trim(const std::string& str);

// Remove todos os espaços da string
inline std::string removeSpaces(const std::string& str);

// Valida e-mail (formato simples)
bool isValidEmail(const std::string& email);

// Valida telefone (apenas dígitos, tamanho 10 ou 11)
bool isValidPhoneNumber(const std::string& phone);

// Capitaliza a primeira letra de cada palavra
inline std::string capitalizeWords(const std::string& str);

// Substitui todas as ocorrências de 'from' por 'to'
inline std::string replaceAll(std::string str, const std::string& from, const std::string& to);

} // namespace utils

#endif // UTILS_H

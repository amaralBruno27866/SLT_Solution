#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>
#include <QtCore/Qt>
#include <QWidget>

namespace utils {

    std::string toUpper(const std::string& str);
    std::string trim(const std::string& str);
    std::string removeSpaces(const std::string& str);
    bool isValidEmail(const std::string& email);
    bool isValidPhoneNumber(const std::string& phone);
    std::string capitalizeWords(const std::string& str);
    std::string replaceAll(std::string str, const std::string& from, const std::string& to);

    template<typename T>
    void reloadList(T* obj, void (T::* method)()) {
        if (obj && method) {
            (obj->*method)();
        }
    }

    template<typename T>
    void showForm(T* form, int width = 500, int height = 400) {
        if (!form) return;
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setWindowFlag(Qt::Window);
        form->setFixedSize(width, height);
        form->show();
    }

}

#endif // UTILS_H

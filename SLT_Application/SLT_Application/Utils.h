#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <algorithm>
#include <QtCore/Qt>
#include <QWidget>

using namespace std;
namespace utils {

    constexpr int DEFAULT_WINDOW_WIDTH = 1280;
    constexpr int DEFAULT_WINDOW_HEIGHT = 720;
    constexpr int DEFAULT_FORM_WIDTH = 980;
    constexpr int DEFAULT_FORM_HEIGHT = 620;

    string toUpper(const string& str);
    string trim(const string& str);
    string removeSpaces(const string& str);
    bool isValidEmail(const string& email);
    bool isValidPhoneNumber(const string& phone);
    string capitalizeWords(const string& str);
    string replaceAll(string str, const string& from, const string& to);
	QString formatPhoneNumber(const QString& phone);

    template<typename T>
    void reloadList(T* obj, void (T::* method)()) {
        if (obj && method) {
            (obj->*method)();
        }
    }

    template<typename T>
    void showForm(T* form, int width = utils::DEFAULT_FORM_WIDTH, int height = utils::DEFAULT_FORM_HEIGHT) {
        if (!form) return;
        form->setAttribute(Qt::WA_DeleteOnClose);
        form->setWindowFlag(Qt::Window);
        form->setFixedSize(width, height);
        form->show();
    }
}

#endif // UTILS_H

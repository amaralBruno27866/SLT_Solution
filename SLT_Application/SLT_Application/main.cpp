#include "SLT_Application.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- Create the databse columns ---
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("clinic.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return 1;
    }
    QSqlQuery query(db);

    // Table ASSESSOR
    bool ok = query.exec(
        "CREATE TABLE IF NOT EXISTS assessor ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "lastname TEXT,"
        "firstname TEXT,"
        "email TEXT,"
        "phone TEXT,"
        "created_at TEXT,"
        "modified_at TEXT"
        ")"
    );
    if (!ok) {
        QMessageBox::critical(nullptr, "Database Error", query.lastError().text());
        return 1;
    }

    // Model of table
    ok = query.exec(
        "CREATE TABLE IF NOT EXISTS address ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "assessor_id INTEGER,"
        "street TEXT,"
        "city TEXT,"
        "province TEXT,"
        "postal_code TEXT,"
        "created_at TEXT,"
        "modified_at TEXT,"
        "FOREIGN KEY(assessor_id) REFERENCES assessor(id))"
    );
    if (!ok) {
        QMessageBox::critical(nullptr, "Database Error", query.lastError().text());
        return 1;
    }
    // --- End of database creation ---

    silver::SLT_Application w;
    w.show();
    return a.exec();
}

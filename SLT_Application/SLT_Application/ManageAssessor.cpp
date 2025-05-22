#include "ManageAssessor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ManageAssessor::ManageAssessor(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("clinic.db");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    }
    else {
        QSqlQuery query;
        bool ok = query.exec(
            "CREATE TABLE IF NOT EXISTS assessor ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "lastname TEXT,"
            "firstname TEXT,"
            "email TEXT,"
            "phone TEXT)"
        );
        if (!ok) {
            qDebug() << "Erro ao criar tabela:" << query.lastError().text();
        }
    }
}
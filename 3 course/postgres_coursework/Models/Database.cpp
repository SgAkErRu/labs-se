#include "Database.h"
#include <cmath>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "StringTools.h"
#include "Errors.h"

using namespace StringTools;

// подключение к БД
void Database::setConnection(std::string_view db_name, std::string_view login, std::string_view password)
{
    db.setDatabaseName(db_name.cbegin());
    db.setHostName(hostname);
    db.setPort(port);
    db.setUserName(login.cbegin());
    db.setPassword(password.cbegin());

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Ошибка", Errors::msg(db.lastError()));
    }
    else connected = true;
}

bool Database::isConnected() const
{
    return connected;
}

void Database::exec()
{
    if (!query.exec())
        QMessageBox::critical(nullptr,"Ошибка", Errors::msg(query.lastError()));
}

void Database::exec(const QString &str)
{
    if (!query.exec(str))
        QMessageBox::critical(nullptr,"Ошибка", Errors::msg(query.lastError()));
}

void Database::execWithDisplay(const QString &str)
{
    if (!query.exec(str))
    {
        QMessageBox::critical(nullptr,"Ошибка", Errors::msg(query.lastError()));
    }
    else
    {
        model->setQuery(query);
    }
    qDebug() << query.lastError();
}

bool Database::first()
{
    return query.first();
}

bool Database::next()
{
    return query.next();
}

QVariant Database::value(int i)
{
    return query.value(i);
}

void Database::prepare(const QString &str)
{
    if (!query.prepare(str))
        QMessageBox::critical(nullptr,"Ошибка", Errors::msg(query.lastError().nativeErrorCode()));
}

void Database::bindValue(const QString &placeholder, const QVariant &val)
{
    query.bindValue(placeholder,val);
}

std::map<int, QString> Database::getAttributesList(const QString& str)
{
    this->exec(str);
    std::map<int, QString> map;
    while (query.next())
    {
        map[query.value(0).toInt()] = query.value(1).toString();
    }
    return map;
}
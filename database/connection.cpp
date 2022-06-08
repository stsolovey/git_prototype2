#include "connection.h"

Connection::Connection(QObject *parent) : QObject(parent)
{
    openDataBase();
}
Connection::~Connection()
{
    closeDataBase();
}
bool Connection::openDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("******.mdb.yandexcloud.net");
    db.setPort(6432);
    db.setDatabaseName("yaPsSql");
    db.setUserName("******");
    db.setPassword("********");
    if (!db.open()) {
        qDebug() << "Ошибка БД" <<  db.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Соединение с БД установлено!";
        return true;
    }
}

void Connection::closeDataBase()
{
    db.close();
}

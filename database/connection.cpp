#include "connection.h"

Connection::Connection(QObject *parent) : QObject(parent)
{
    qDebug() << "Connection constructor is working";
    openDataBase();
}
Connection::~Connection()
{
    closeDataBase();
}
bool Connection::openDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("rc1b-6fuig7zk82eezg7l.mdb.yandexcloud.net");
    db.setPort(6432);
    db.setDatabaseName("yaPsSql");
    db.setUserName("user1");
    db.setPassword("12345678");
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

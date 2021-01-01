#ifndef GETLESSON_H
#define GETLESSON_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


class GetQuery: public QObject
{
    Q_OBJECT

public:
    QSqlQuery query;
    GetQuery(QObject *parent = 0);
    QSqlQuery get(QString);
};

#endif // GETLESSON_H

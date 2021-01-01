#ifndef GETLESSON_H
#define GETLESSON_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include "lesson/task2.h"


class GetQuery: public QObject
{
    Q_OBJECT

public:
    QSqlQuery query;
    GetQuery(QObject *parent = 0);
    //QSqlQuery get(QString);
    void addLessonStatistic(QVector<Task2> stat);
};

#endif // GETLESSON_H

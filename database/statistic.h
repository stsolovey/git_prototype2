#ifndef GETLESSON_H
#define GETLESSON_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include "lesson/task2.h"
#include "lesson/task3.h"


class Statistic: public QObject
{
    Q_OBJECT

public:
    QSqlQuery query;
    Statistic(QObject *parent = 0);
    //QSqlQuery get(QString);
    void addLessonStatistic(QVector<Task2> stat);
    void addLessonStatistic2(QVector<Task2> statistic);
};

#endif // GETLESSON_H

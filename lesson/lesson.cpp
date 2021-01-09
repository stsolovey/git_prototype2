#include "lesson.h"
#include <QDebug>
#include <QSqlError>

Lesson::Lesson(QObject *parent) : QObject(parent)
{
}

QVector<Task> Lesson::getLesson(int id_category)
{
    QSqlQuery query;
    QString course_table {"ru_en_sentences"};
    QString statistic_table {"user_slusla_sentences_stat"};
    QString queryString = QString(
                                  "SELECT %1.* "
                                  "FROM %1 "
                                  "LEFT JOIN %2 "
                                   "ON %1.\"﻿id\" = %2.sentence "
                                  "WHERE id_cat = %3 "
        "ORDER BY number_of_repetitions asc, right_answers asc, wrong_answers desc, ru_en_sentences.\"﻿id\" asc;"
                                  );
    
    query.exec(queryString
                   .arg(course_table)
                   .arg(statistic_table)
                   .arg(id_category)
               );

    qDebug() << "queryString: " << queryString
                                       .arg(course_table)
                                       .arg(statistic_table)
                                       .arg(id_category);

    int i = 0;
    while(query.next() and ++i < 5)
    {
        tasks << Task{
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),

            1
        };
    }
    return tasks;
}

#include "lesson.h"
#include <QDebug>
#include <QSqlError>

Lesson::Lesson(QObject *parent) : QObject(parent)
{
}

QVector<Task> Lesson::getLesson(int id_category)
{
    QSqlQuery query;
    QString queryString = QString("SELECT * FROM ru_en_sentences "
                                  "WHERE id_cat = %1");
    query.exec(queryString.arg(id_category));
    qDebug() << "queryString: " << queryString.arg(id_category);
    //while(query.next()) qDebug() << query.value(1).toString();
    int i = 0;
    while(query.next() and ++i < 5)
    {
        tasks << Task{
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toInt(),
            1
        };

    }
    /*
     * lesson << Task{1, "I am a boy."}
     *        << Task{1, "She is a girl."}
     *        << Task{1, "It rains."};
    */
    return tasks;
}

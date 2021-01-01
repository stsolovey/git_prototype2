#include "getquery.h"
#include <QString>

GetQuery::GetQuery(QObject *parent) : QObject(parent)
{

}

/*QSqlQuery GetQuery::get(QString str)
{
    query.exec(str);
    return query;
     qDebug() << "queryString.arg("")";
}*/

void GetQuery::addLessonStatistic(QVector<Task2> stat)
{

    QSqlQuery query;
    QString queryString(
    "INSERT INTO public.user_slusla_stat (direction, course, category, sentence, type_of_exercise, rating) "
    "VALUES ( %1, %2, %3, %4, %5, %6)");
    for (auto a : stat)
    {
        query.exec(queryString.arg(a.direction())
                              .arg(a.course())
                              .arg(a.category())
                              .arg(a.sentence())
                              .arg(a.type())
                              .arg(a.rating()));
    }
}


/*int m_id;
int m_direction;
int m_course;
int m_category;
int m_sentence;
int m_type;
int m_rating;*/

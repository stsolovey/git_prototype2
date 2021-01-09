#include "statistic.h"
#include <QString>
#include <QDebug>
#include <QSqlError>




Statistic::Statistic(QObject *parent) : QObject(parent)
{

}



void Statistic::addLessonStatistic(QVector<Task2> stat)
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
                              .arg(a.answer_status()));
    }
}
void Statistic::addLessonStatistic2(QVector<Task2> statistic)
{
    QList<Task3> task3List;
    Task3 t3;
    //qDebug() << "addLessonStatistic2 is working";
    int right_answers{0};
    int wrong_answers{0};
    QSqlQuery query;
    QString queryString(
       "UPDATE public.user_slusla_sentences_stat "
        "SET "
        "right_answers = right_answers + %5, "
        "wrong_answers = wrong_answers + %6 "
        "WHERE direction = %1 "
        "AND course = %2 "
        "AND sentence = %3 "
        "AND type_of_exercise = %4 ;"
        );
    for (auto a : statistic)
    {
        t3 = Task3 {a.direction(), a.course(), a.sentence(), a.type()};
        if(!task3List.contains(t3)){
                 task3List.append(t3);
                 qDebug() << "t3 appended";
        }

        if (a.answer_status())
        {
            right_answers=1;
            wrong_answers=0;
        }else
        {
            right_answers=0;
            wrong_answers=1;
        }
        query.exec(queryString
                       .arg(a.direction()) //%1
                       .arg(a.course()) //%2
                   .arg(a.sentence()) //%3
                   .arg(a.type()) //%4
                   .arg(right_answers) //%5
                   .arg(wrong_answers) //%6
                   );
        //qDebug() << "last error1: " << query.lastError();
    }
    queryString =
        "UPDATE public.user_slusla_sentences_stat "
        "SET number_of_repetitions = number_of_repetitions + 1 "

        "WHERE direction = %1 "
        "AND course = %2 "
        "AND sentence = %3 "
        "AND type_of_exercise = %4 ;"
        ;
    for (auto a : task3List)
    {
        query.exec(queryString
                       .arg(a.direction())
                       .arg(a.course())
                       .arg(a.sentence())
                       .arg(a.type_of_exercise())
                   );
        qDebug() << queryString
                        .arg(a.direction())
                        .arg(a.course())
                        .arg(a.sentence())
                        .arg(a.type_of_exercise());
        //qDebug() << "last error2: " << query.lastError();
    }

}

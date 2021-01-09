#include "rebuildsentencestatcombinations.h"
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
RebuildSentenceStatCombinations::RebuildSentenceStatCombinations()
{
    qDebug() << "RebuildSentenceStatCombinations constructor is working.";
    QSqlQuery querySentId;
    QSqlQuery querySentStatId;
    QSqlQuery queryInsert;
    //QList<int> directionId;
    //QList<int> courseId;
    QList<int> sentId;
    QList<int> sentStatId;

    QString queryStringSentId = "SELECT * FROM public.ru_en_sentences";
    QString queryStringSentStatId = "SELECT sentence FROM public.user_slusla_sentences_stat";
    QString insertString;

    querySentId.exec(queryStringSentId);
    querySentStatId.exec(queryStringSentStatId);
    qDebug() << "querySentId.lastError " << querySentId.lastError();
    qDebug() << "querySentStatId.lastError " << querySentStatId.lastError();
    while (querySentId.next())
    {
        qDebug() << "query.value(0).toInt() " << querySentId.value(0).toInt();
        sentId.append(querySentId.value(0).toInt());
    }

    while (querySentStatId.next())
    {
        qDebug() << "query.value(0).toInt() " << querySentStatId.value(0).toInt();
        sentStatId.append(querySentStatId.value(0).toInt());
    }

    for (auto a : sentId)
    {
        qDebug() << "a: " << a;
        if (sentStatId.contains(a)) //sentId.removeAt(sentId.indexOf(a));
            ;
        else
        {
            insertString = "INSERT INTO "
                           "public.user_slusla_sentences_stat "
                           "(direction, course, sentence, type_of_exercise, number_of_repetitions, right_answers, wrong_answers) "
                           "VALUES(1,1,%1,1, 0, 0, 0) ";
            qDebug() << "insertString.arg(a): " << insertString.arg(a);
            queryInsert.exec(insertString.arg(a));
            qDebug() << "queryInsert.lastError " << queryInsert.lastError();
        }

    }
}

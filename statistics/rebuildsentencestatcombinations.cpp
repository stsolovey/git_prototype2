#include "rebuildsentencestatcombinations.h"
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
RebuildSentenceStatCombinations::RebuildSentenceStatCombinations()
{
    qDebug() << "RebuildSentenceStatCombinations constructor is working.";
    QSqlQuery queryWithAllSentences;
    QSqlQuery queryWithAllSentencesFromStatisticTable;
    QSqlQuery queryInsert;

    //QList<int> directionId;
    //QList<int> courseId;
    QList<int> listWithIdOfAllSentences;
    QList<int> listWithIdOfAllSentencesFromStatisticTable;
    int userId = 13;
    QString queryStringWithAllSentences = "SELECT * FROM public.ru_en_sentences";
    QString queryStringWithAllSentencesFromUserStatisticTable = "SELECT sentence FROM public.user_slusla_sentences_stat where userid = %1";
    QString insertString;

    queryWithAllSentences.exec(queryStringWithAllSentences);
    queryWithAllSentencesFromStatisticTable.exec(queryStringWithAllSentencesFromUserStatisticTable.arg(userId));
    qDebug() << "querySentId.lastError " << queryWithAllSentences.lastError();
    qDebug() << "querySentStatId.lastError " << queryWithAllSentencesFromStatisticTable.lastError();
    while (queryWithAllSentences.next())
    {
        qDebug() << "query.value(0).toInt() " << queryWithAllSentences.value(0).toInt();
        listWithIdOfAllSentences.append(queryWithAllSentences.value(0).toInt());
    }

    while (queryWithAllSentencesFromStatisticTable.next())
    {
        qDebug() << "query.value(0).toInt() " << queryWithAllSentencesFromStatisticTable.value(0).toInt();
        listWithIdOfAllSentencesFromStatisticTable.append(queryWithAllSentencesFromStatisticTable.value(0).toInt());
    }

    for (auto sentenceIdFromListOfAllStentences : listWithIdOfAllSentences)
    {
        qDebug() << "a: " << sentenceIdFromListOfAllStentences;
        if (listWithIdOfAllSentencesFromStatisticTable.contains(sentenceIdFromListOfAllStentences)) //sentId.removeAt(sentId.indexOf(a));
            ;
        else
        {
            insertString = "INSERT INTO "
                           "public.user_slusla_sentences_stat "
                           "(direction, course, sentence, type_of_exercise, number_of_repetitions, right_answers, wrong_answers, userid) "
                           "VALUES(1,1,%1,1, 0, 0, 0, %2) ";
            qDebug() << "insertString.arg(a): " << insertString.arg(sentenceIdFromListOfAllStentences);
            queryInsert.exec(insertString.arg(sentenceIdFromListOfAllStentences).arg(userId));
            qDebug() << "queryInsert.lastError " << queryInsert.lastError();
        }

    }
}

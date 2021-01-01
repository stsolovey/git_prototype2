#ifndef LESSON_H
#define LESSON_H

#include <QObject>
#include <QSqlQuery>
#include "task.h"


class Lesson : public QObject
{
    Q_OBJECT
public:
    explicit Lesson(QObject *parent = nullptr);
    int lessonId;

    QVector<Task> tasks;
    QVector<Task> tempLesson;
    QVector<Task> getLesson(int id_category);
signals:

};

#endif // LESSON_H

/*
     typedef struct Lesson {
        int lessonId;
        QString lessonName;
        //QStringList wordsOfTheExercise;
    }Lesson;
    typedef struct Task {
        int typeOfTheExercise;
        QString textOfTheExercise;
        //QStringList wordsOfTheExercise;
    }Task;
 * */

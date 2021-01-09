#include "appcore.h"
#include <QDebug>
#include <QSqlQuery>
#include "lesson/lesson.h"
#include "database/statistic.h"
AppCore::AppCore(QObject* parent) : QObject(parent)
{
    userId = 1;
    userName = "NameOfUser";
    actualDirection = "ru_en";
    exerciseNumber = 0;
}
AppCore::~AppCore()
{
    qDebug() << "AppCore destructor is working";
}

void AppCore::createClass(int id_category)
{

    m_progressBarValue = 0;
    points = 15;
    Lesson ls;

    lesson = ls.getLesson(id_category);
    lesson_lenght = lesson.length();
    emit sendLessonInfo(lesson.length());
}

void AppCore::correctClass(int index)
{
    lesson.remove(exerciseNumber);
}



void AppCore:: askUserName(){
    emit sendUserName(userName);
}

void AppCore::askActualDirection()
{
    emit sendActualDirection(actualDirection);
}



void AppCore::askForClass(int id_category)
{
    //qDebug() << "section: " << id_category; // что за секция, где это?
    statistic.clear();
    createClass(id_category);
}

void AppCore::askForExercise()
{

    if (lesson.length())
        emit sendExercise(lesson.at(exerciseNumber).exercise_type, lesson.at(exerciseNumber).exercise_text);
    else
    {
        qDebug() << "You can not ask for exercise because lesson.length() is " << lesson.length();
    }
}

void AppCore::checkAnswer(QString answer)
{
    //qDebug() << "START exerciseNumber " << exerciseNumber;
    //qDebug() << "START lesson.length() " << lesson.length();
    //qDebug() << "START lesson_lenght " << lesson_lenght << Qt::endl;
    Task2 t2;
    t2.setDirection(1);
    t2.setCourse(1);
    t2.setSentence(lesson.at(exerciseNumber).exercise_id);
    t2.setType(1);
    bool answer_status;

    if (answer == "1" or answer == lesson.at(exerciseNumber).exercise_translation)
    {
        answer_status = true;
        correctClass(exerciseNumber);
        if(exerciseNumber == lesson.length())
            exerciseNumber = 0;
        emit sendReview(true, "You're right!");
        emit sendProgressBarValue(++m_progressBarValue);
        lesson_lenght--;

    }
    else
    {
        answer_status = false;

        emit sendReview(false, "Your answer: " + answer + "\nRight answer: " + lesson.at(exerciseNumber).exercise_translation);
        if(exerciseNumber == lesson.length() or lesson.length() == 1)
            exerciseNumber = 0;
        else
            exerciseNumber++;
    }

    t2.setAnswer_status(answer_status);
    statistic.append( t2);

    if (lesson_lenght==0)
    {
        emit endOfTheLesson("You earned " +  QString::number(points) + " XP");
        Statistic s;
        s.addLessonStatistic2(statistic);
    }

    //qDebug() << "END exerciseNumber " << exerciseNumber;
    //qDebug() << "END lesson.length() " << lesson.length();
    //qDebug() << "END lesson_lenght " << lesson_lenght << Qt::endl;
}

void AppCore::addLessonStatistic(QVector<Task2> stat)
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

void AppCore::rebuildStatSentences()
{
    RebuildSentenceStatCombinations r;
}

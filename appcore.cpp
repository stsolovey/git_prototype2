#include "appcore.h"
#include <QDebug>
#include <QSqlQuery>
#include "lesson/lesson.h"
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
    qDebug() << "section: " << id_category; // что за секция, где это?
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
    int staticticRate;
    qDebug() << "lesson.at(exerciseNumber).exercise_text" << lesson.at(exerciseNumber).exercise_text;
    qDebug() << "lesson.at(exerciseNumber).exercise_translation" << lesson.at(exerciseNumber).exercise_translation;
    qDebug() << "answer" << answer;
    if (answer=="1" or answer == lesson.at(exerciseNumber).exercise_translation)
    {
        staticticRate = 1;
        correctClass(exerciseNumber);
        emit sendReview(true, "You're right!");
        emit sendProgressBarValue(++m_progressBarValue);
    }
    else
    {
        staticticRate = -2;
        emit sendReview(false, "Your answer: " + answer + "\nRight answer: " + lesson.at(exerciseNumber).exercise_translation);
    }

    statistic.append(Task2{1,1,1,1,1,staticticRate});

    if (lesson.length()==0)
    {
        emit endOfTheLesson("You earned " +  QString::number(points) + " XP");
        addLessonStatistic(statistic);
    }
    else if (exerciseNumber<lesson.length()-1)
        ++exerciseNumber;
    else
        exerciseNumber=0;
    qDebug() << "exerciseNumber " << exerciseNumber;
    qDebug() << "lesson.length() " << lesson.length();
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
                       .arg(a.rating()));
    }
}

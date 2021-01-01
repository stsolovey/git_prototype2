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
    //QSqlQuery query;
    /*GetQuery gq;
    query = gq.get("SELECT * FROM ru_en_categories");
    while(query.next()) qDebug() << query.value(1).toString();*/
    qDebug() << "appCoreConstructor is working ";

}

void AppCore::createClass(int id_category)
{

    m_progressBarValue = 0;
    points = 15;
    Lesson ls;

    //lesson << Task{1, "I am a boy."} << Task{1, "She is a girl."} << Task{1, "It rains."};
    lesson = ls.getLesson(id_category);
    //qDebug() << "void AppCore::createClass(int id_category) lesson.length(): " << lesson.length();
    emit sendLessonInfo(lesson.length());
}

void AppCore::correctClass(int index)
{
    lesson.remove(exerciseNumber);
}


void AppCore::answerGiven(QString textOfTheExercise, QString answerString)
{
    if (textOfTheExercise == answerString)
        emit rightAnswer("Excelent");
    else
        emit wrongAnswer("you wrong");
}

void AppCore:: askUserName(){
    emit sendUserName(userName);
}

void AppCore::askActualDirection()
{
    emit sendActualDirection(actualDirection);
}

void AppCore::askForCourse()
{

}

void AppCore::askForClass(int id_category)
{
    qDebug() << "section: " << id_category; // что за секция, где это?
    createClass(id_category);
}

void AppCore::askForExercise()
{
    if (lesson.length())
        emit sendExercise(lesson.at(exerciseNumber).exercise_type, lesson.at(exerciseNumber).exercise_text);
    else
    {
        emit endOfTheLesson("You earned " +  QString::number(points) + " XP");
    }
}

void AppCore::checkAnswer(QString answer)
{
    if (answer=="1")
    {
        correctClass(exerciseNumber);
        emit sendReview(true, "You're right!");
        emit sendProgressBarValue(++m_progressBarValue);
    }
    else
    {
        emit sendReview(false, "Wrong! Your answer: - " + answer + " - You should write - " + lesson.at(exerciseNumber).exercise_text + " -");
    }

    if (lesson.length()==0)
        ;
    else if (exerciseNumber<lesson.length()-1)
        ++exerciseNumber;
    else
        exerciseNumber=0;
    qDebug() << "exerciseNumber " << exerciseNumber;
    qDebug() << "lesson.length() " << lesson.length();


}

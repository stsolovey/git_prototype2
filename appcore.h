#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QVector>
#include "lesson/lesson.h"
#include "statistics/rebuildsentencestatcombinations.h"
class AppCore : public QObject
{
    Q_OBJECT

public:
    AppCore(QObject *parent = nullptr);
    ~AppCore();
    void createClass(int id_category);
    void correctClass(int index);
    void setTasksLeft(int tLeft);
private:
    int m_progressBarValue;
    int userId;
    int exerciseNumber;
    int points;
    int lesson_lenght;

    QString userName;
    QString actualDirection;

    QVector<Task> lesson;
    //QVector<Task> tempLesson;

    QVector<Task2> statistic;
    void addLessonStatistic(QVector<Task2> stat);

signals:
    void sendProgressBarValue(int progressBarValue);
    void rightAnswer(QString rightAns);
    void wrongAnswer(QString wrongAns);
    void sendUserName(QString userName);
    void sendActualDirection(QString actualDirection);
    void sendCourse();
    void sendExercise(int typeOfTheExercise, QString textOfTheExercise);
    void sendLessonInfo(int lessonLenght);
    void sendReview(bool value, QString message);
    void endOfTheLesson(QString);
public slots:

    void rebuildStatSentences();
    void askUserName();
    void askActualDirection();
    void askForClass(int id_category);
    void askForExercise();
    void checkAnswer(QString answer);
};

#endif // APPCORE_H

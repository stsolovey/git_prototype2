#include "appcore.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSettings>
#include <QCoreApplication>

AppCore::AppCore(QObject* parent) : QObject(parent)
{
    Connection cn;
    userId = 1;
    userName = "NameOfUser";
    actualDirection = "ru_en";
    exerciseNumber = 0;
    qDebug() << "AppCore constructor is working";

    readConfig();
    //rebuildStatSentences();
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
    Q_UNUSED(index)
    lesson.remove(exerciseNumber);
}



void AppCore::createDefaultAccount()
{
    GenerateRandomUsername gru;
    qDebug() << gru.generate();
}

void AppCore::askForClass(int id_category)
{
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
}

void AppCore::userRegistration(int age, QString login, QString email, QString password)
{

    qDebug() << "age " << age << "login" << login << "email" << email << "password" << password;
    UserRegisterData urd(age, login, email, password);
    CreateAccount ca;
    ca.create(urd);
    //if (ca.create(urd))
}

void AppCore::userLogin(QString enteredLogin, QString enteredPassword)
{
    UserLogin ul;
    bool value{ul.login(enteredLogin, enteredPassword)};
    emit attemptToLogin(value);
}

void AppCore::checkEmail(QString email)
{
    EmailValidate ev;
    if (ev.validate(email))
    {
        emit emailValidation(true);
        qDebug() << "emails is valid" << true;
        CheckIfUserExists cifue;
        if (cifue.checkIfEmailExists(email))
        {
            emit emailExists(true);
            qDebug() << "email exists" << true;
        }
        else
        {
            emit emailExists(false);
            qDebug() << "email does not exist" << false;
        }
    }
    else
    {
        emit emailValidation(false);
        qDebug() << "emails is invalid" << false;
    }
}

void AppCore::checkLogin(QString login)
{
    LoginValidate lv;
    if (lv.validate(login))
    {
        emit loginValidation(true);
        qDebug() << "login is valid" << true;
        CheckIfUserExists ciue;
        if(ciue.checkIfLoginExists(login))
        {
            emit loginExists(true);
            qDebug() << "login exists" << true;
        }
        else
        {
            emit loginExists(false);
            qDebug() << "login does not exist" << false;
        }
    }
    else
    {
        emit loginValidation(false);
        qDebug() << "login is not valid" << false;
    }
}

void AppCore::checkPassword(QString password)
{
    PasswordValidate pv;
    if (pv.validate(password))
    {
        emit passwordValidation(true);
        qDebug() << "password is valid";
    }
    else
    {
        emit passwordValidation(false);
        qDebug() << "pass is invalid";
    }
}

void AppCore::authentification(QString loginFromUserInput, QString passwordFromUserInput)
{
    Authentification auth;
    auth.setUserLoginFromUserInput(loginFromUserInput);
    auth.setPasswordFromUserInput(passwordFromUserInput);
    auth.setPasswordFromDatabase();
    auth.checkIfAuthentificationSucceed();
    emit resultOfAutentification(auth.getAuthentificationSucceed());
    qDebug() << "AuthentificationSucceed " << auth.getAuthentificationSucceed() << Qt::endl;
    if (auth.getAuthentificationSucceed())
        authorisation(auth);
}

void AppCore::authorisation(Authentification auth)
{
    AccessCode accessCode;
    userName = auth.getUserLoginFromUserInput();
    accessCode.setUserLogin(auth.getUserLoginFromUserInput());

    //accessCode.generateAccessCode();
    qDebug() << "access code is written: " << accessCode.writeGeneratedAccessCode();
}

void AppCore::compareAccessCodeFromFileAndFromDataBaseSlot()
{
    AccessCode accessCode;
    accessCode.setUserLogin(userName);
    bool result = accessCode.compareAccessCodeFromFileAndFromDataBase();
    qDebug() << "result " << result;
    emit resultOfAccessCodeFromDeviceAndFromDatabaseComparision(result);
}



void AppCore::readConfig()
{
    QSettings settings(qApp->applicationDirPath()+"/settings.ini",QSettings::IniFormat);
    settings.beginGroup("Settings");
    {
        userName = settings.value("userName", "userName").toString();
        //actualDirection = settings.value("actualDirection", "actualDirection").toString();
    }
    settings.endGroup();
}

void AppCore::writeConfig()
{
    QSettings settings(qApp->applicationDirPath()+"/settings.ini",QSettings::IniFormat);
    settings.beginGroup("Settings");
    {
        settings.setValue("userName", userName);
        //settings.setValue("actualDirection", "actualDirection");
    }
    settings.endGroup();
}

void AppCore::rebuildStatSentences()
{
    RebuildSentenceStatCombinations r;
}

#include "unittest.h"
#include <QDebug>
#include <QString>

UnitTest::UnitTest(QObject* parent) : QObject(parent)
{

}

void UnitTest::accessCodeGenerate()
{
    AccessCodeGenerate acg;
    qDebug() << acg.generate();
    qDebug() << "hello";
}

void UnitTest::accessCodeRead()
{
    AccessCodeRead acr;
    acr.readAccessCodeFromFile();
}

void UnitTest::accessCodeWrite()
{
    AccessCodeGenerate acg;
    AccessCodeWrite acw;
    acw.writeAccessCodeToFile(acg.generate());
}

void UnitTest::stringToMd5()
{
    StringToMd5 stmd5;
    qDebug() << stmd5.convert("Rammstein");
}

void UnitTest::accessCodeWriteToDataBase(QString login, QString code)
{
    AccessCodeWrite acw;
    acw.writeAccessCodeToDataBase(login, code);
}

void UnitTest::writeGeneratedAccessCode()
{

}

void UnitTest::authentification(QString loginFromUserInput, QString passwordFromUserInput)
{
    Authentification auth;
    auth.setUserLoginFromUserInput(loginFromUserInput);
    auth.setPasswordFromUserInput(passwordFromUserInput);
    auth.setPasswordFromDatabase();
    auth.checkIfAuthentificationSucceed();
    qDebug() << "AuthentificationSucceed " << auth.getAuthentificationSucceed() << Qt::endl;
    if (auth.getAuthentificationSucceed())
        authorisation(auth);
}

void UnitTest::authorisation(Authentification auth)
{
    AccessCode accessCode;
    accessCode.setUserLogin(auth.getUserLoginFromUserInput());
    accessCode.generateAccessCode();
    qDebug() << "access code is written: " << accessCode.writeGeneratedAccessCode();
}

void UnitTest::compareAccessCodeFromFileAndFromDataBaseUnitTest()
{
    AccessCode accessCode;
    qDebug() << accessCode.compareAccessCodeFromFileAndFromDataBase();
}

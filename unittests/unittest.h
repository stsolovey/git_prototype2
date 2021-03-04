#ifndef UNITTEST_H
#define UNITTEST_H
#include <QObject>

#include "auth/accesscode.h"
#include "auth/accesscodegenerate.h"
#include "auth/accesscoderead.h"
#include "auth/accesscodewrite.h"
#include "auth/authentification.h"
#include "auth/stringtomd5.h"


class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest(QObject *parent = nullptr);

signals:
public slots:
    void accessCodeGenerate();
    void accessCodeRead();
    void accessCodeWrite();
    void stringToMd5();
    void accessCodeWriteToDataBase(QString login, QString code);
    void writeGeneratedAccessCode();
    void authentification(QString loginFromUserInput, QString passwordFromUserInput);
    void authorisation(Authentification auth);
    void compareAccessCodeFromFileAndFromDataBaseUnitTest();
};

#endif // UNITTEST_H

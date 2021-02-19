#ifndef UNITTEST_H
#define UNITTEST_H
#include <QObject>
#include "auth/accesscodegenerate.h"
#include "auth/accesscoderead.h"
#include "auth/accesscodewrite.h"
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
};

#endif // UNITTEST_H

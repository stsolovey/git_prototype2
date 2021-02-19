#include "unittest.h"
#include <QDebug>

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

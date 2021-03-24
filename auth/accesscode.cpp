#include "accesscode.h"
#include <QDebug>
#include <QSqlError>
#include <QSettings>
#include <QCoreApplication>

AccessCode::AccessCode()
{
    readConfig();
}
bool AccessCode::writeGeneratedAccessCode()
{
    generateAccessCode();
    bool flag1 = writeGeneratedAccessCodeToFile();
    bool flag2 = writeGeneragedAccessCodeToDatabase();
    writeConfig();
    return flag1 & flag2;
}
void AccessCode::generateAccessCode()
{
    generatedAccessCode.clear();
    for (int i = 0; i < 40; i++)
        generatedAccessCode.append(alphanum.at(rg.global()->bounded(lenOfAlphanum)));
}

bool AccessCode::compareAccessCodeFromFileAndFromDataBase()
{
    readAccessCodeFromFile();
    readAccessCodeFromDatabase();

    if (accessCodeFromFile!="" and accessCodeFromDataBase!=""){
        bool flag = accessCodeFromFile == accessCodeFromDataBase;
        return flag;
    }
    else
        return false;
}

bool AccessCode::readAccessCodeFromFile()
{
    if (!chekIfFileWithAccessCodeExistsOnUsersDevice())
        return false;
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Can't open the file dat 3435";
        return false;
    }
    QTextStream in(&file);
    accessCodeFromFile.clear();
    while (!in.atEnd())
        accessCodeFromFile = in.readLine();
    qDebug() << "readAccessCodeFromFile" << accessCodeFromFile;
    file.close();
    return accessCodeFromFile.length();
}

bool AccessCode::readAccessCodeFromDatabase()
{
    accessCodeFromDataBase.clear();
    QString queryString{"SELECT device_accesskey "
                        "FROM public.user_login_table "
                        "WHERE user_login = \'%1\';"};
    query.exec(queryString.arg(userLogin));
    query.next();
    setAccessCodeFromDataBase(query.value(0).toString());
    return accessCodeFromDataBase.length();
}

bool AccessCode::writeGeneratedAccessCodeToFile()
{
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)) return false;
    QTextStream out(&file);
    out << generatedAccessCode << Qt::endl;
    file.close();


    return true;
}

bool AccessCode::writeGeneragedAccessCodeToDatabase()
{
    QString queryString1{"UPDATE public.user_login_table "
                         "SET device_accesskey = \'%1\' "
                         "WHERE user_login = \'%2\';  "};
    bool flag1 = query.exec(queryString1.arg(generatedAccessCode, userLogin));
    qDebug() << query.lastError();
    return flag1;


}



bool AccessCode::chekIfFileWithAccessCodeExistsOnUsersDevice()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    else
    {
        file.close();
        return true;
    }
}



QString AccessCode::getAccessCodeFromFile() const
{
    return accessCodeFromFile;
}
QString AccessCode::getUserLogin() const
{
    return userLogin;
}

void AccessCode::setUserLogin(const QString &value)
{
    userLogin = value;
}
QString AccessCode::getGeneratedAccessCode() const
{
    return generatedAccessCode;
}

QString AccessCode::getAccessCodeFromDataBase() const
{
    return accessCodeFromDataBase;
}

void AccessCode::setAccessCodeFromDataBase(const QString &value)
{
    accessCodeFromDataBase = value;
}


void AccessCode::readConfig()
{
    QSettings settings(qApp->applicationDirPath()+"/settings.ini",QSettings::IniFormat);
    settings.beginGroup("Settings");
    {
        userLogin = settings.value("userName", "userName").toString();
    }
    settings.endGroup();
}
void AccessCode::writeConfig()
{
    QSettings settings(qApp->applicationDirPath()+"/settings.ini",QSettings::IniFormat);
    settings.beginGroup("Settings");
    {
        settings.setValue("accessCode", generatedAccessCode);
    }
    settings.endGroup();
}

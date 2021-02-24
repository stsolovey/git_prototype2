#include "accesscode.h"

AccessCode::AccessCode()
{   
}
bool AccessCode::writeGeneratedAccessCode()
{
    generateAccessCode();
    return writeGeneratedAccessCodeToFile() && writeGeneragedAccessCodeToDatabase();
}
void AccessCode::generateAccessCode()
{
    generatedAccessCode.clear();
    for (int i = 0; i < 40; i++)
        generatedAccessCode.append(alphanum.at(rg.global()->bounded(lenOfAlphanum)));
}

bool AccessCode::readAccessCodeFromFile()
{
    if (!chekIfFileWithAccessCodeExistsOnUsersDevice())
        return false;

    QTextStream in(&file);
    accessCodeFromFile.clear();
    while (!in.atEnd())
        accessCodeFromFile = in.readLine();
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
    if(!file.open(QIODevice::ReadWrite)) return false;
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
    return query.exec(queryString1.arg(generatedAccessCode, userLogin));
}

bool AccessCode::compareAccessCodeFromFileAndFromDataBase()
{
    readAccessCodeFromFile();
    readAccessCodeFromDatabase();
    return accessCodeFromFile == accessCodeFromDataBase;
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

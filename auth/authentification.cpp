#include "authentification.h"
#include "stringtomd5.h"
#include <QSqlQuery>
#include <QVariant>

bool Authentification::getAuthentificationSucceed() const
{
    return authentificationSucceed;
}

QString Authentification::getUserLoginFromUserInput() const
{
    return userLoginFromUserInput;
}

Authentification::Authentification()
{

}

void Authentification::checkIfAuthentificationSucceed()
{
    StringToMd5 stringToMd5;
    authentificationSucceed = stringToMd5.convert(passwordFromUserInput) == passwordFromDatabase;
}

void Authentification::setUserLoginFromUserInput(const QString &value)
{
    userLoginFromUserInput = value;
}

void Authentification::setPasswordFromUserInput(const QString &value)
{
    passwordFromUserInput = value;
}

void Authentification::setPasswordFromDatabase()
{
    QString queryString{"SELECT user_auth_key "
                        "FROM public.user_login_table "
                        "WHERE user_login = \'%1\' ;"};
    QSqlQuery query;
    query.exec(queryString.arg(userLoginFromUserInput));
    query.next();

    passwordFromDatabase = query.value(0).toString();
}

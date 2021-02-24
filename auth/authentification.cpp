#include "authentification.h"
#include "stringtomd5.h"

bool Authentification::getAuthentificationSucceed() const
{
    return authentificationSucceed;
}

Authentification::Authentification()
{

}

void Authentification::checkIfAuthentificationSucceed()
{
    StringToMd5 stringToMd5;
    authentificationSucceed = (
        (userLoginFromUserInput == userLoginFromDatabase) &&
        (stringToMd5.convert(passwordFromUserInput)  == passwordFromDatabase)
        );
}




void Authentification::setUserLoginFromUserInput(const QString &value)
{
    userLoginFromUserInput = value;
}

void Authentification::setPasswordFromUserInput(const QString &value)
{
    passwordFromUserInput = value;
}

void Authentification::setUserLoginFromDatabase(const QString &value)
{
    userLoginFromDatabase = value;
}

void Authentification::setPasswordFromDatabase(const QString &value)
{
    passwordFromDatabase = value;
}

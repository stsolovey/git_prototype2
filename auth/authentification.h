#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <QString>

class Authentification
{
    QString userLoginFromUserInput;
    QString passwordFromUserInput;
    QString userLoginFromDatabase;
    QString passwordFromDatabase;
    bool authentificationSucceed;
public:
    Authentification();
    void checkIfAuthentificationSucceed();

    void setUserLoginFromUserInput(const QString &value);
    void setPasswordFromUserInput(const QString &value);
    void setUserLoginFromDatabase(const QString &value);
    void setPasswordFromDatabase(const QString &value);

    bool getAuthentificationSucceed() const;
};

#endif // AUTHENTIFICATION_H

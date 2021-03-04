#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <QString>


class Authentification
{
    QString userLoginFromUserInput;
    QString passwordFromUserInput;
    QString passwordFromDatabase;
    bool authentificationSucceed;
public:
    Authentification();
    void checkIfAuthentificationSucceed();

    void setUserLoginFromUserInput(const QString &value);
    void setPasswordFromUserInput(const QString &value);
    void setPasswordFromDatabase();

    bool getAuthentificationSucceed() const;
    QString getUserLoginFromUserInput() const;
};

#endif // AUTHENTIFICATION_H

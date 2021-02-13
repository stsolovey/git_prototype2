#ifndef USERREGISTERDATA_H
#define USERREGISTERDATA_H
#include <QString>

class UserRegisterData
{
    int m_age;
    QString m_login;
    QString m_email;
    QString m_pass;
public:
    UserRegisterData();
    UserRegisterData(int age, QString login, QString email, QString pass);

    int age() const;
    QString login() const;
    QString email() const;
    QString pass() const;

};

#endif // USERREGISTERDATA_H

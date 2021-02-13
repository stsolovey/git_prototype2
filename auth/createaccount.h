#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H
#include <QString>
#include "userregisterdata.h"

class CreateAccount
{
    int m_age;
    QString m_login;
    QString m_email;
    QString m_pass;

public:
    CreateAccount();

    bool create(UserRegisterData urd);
};

#endif // CREATEACCOUNT_H

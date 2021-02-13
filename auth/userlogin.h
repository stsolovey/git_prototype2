#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <QString>

class UserLogin
{
public:
    UserLogin();
    bool login(QString enteredLogin, QString enteredPass);
};

#endif // USERLOGIN_H

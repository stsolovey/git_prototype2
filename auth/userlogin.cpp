#include "userlogin.h"
#include <QSqlQuery>
#include <QVariant>
#include "auth/checkifuserexists.h"
#include <QDebug>

UserLogin::UserLogin()
{
    qDebug() << "UserLogin constructor is working";
}

bool UserLogin::login(QString enteredLogin, QString enteredPass)
{
    CheckIfUserExists ciue;
    if (!ciue.checkIfLoginExists(enteredLogin))
        return false;


    QSqlQuery query;
    QString queryString{"SELECT user_login, user_auth_key, device_accesskey "
                        "FROM user_login_table "
                        "WHERE user_login = " + enteredLogin + ";"};
    query.exec(queryString);
    if (query.value(1).toString() == enteredPass)
        return true;
    else
        return false;
}

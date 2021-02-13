#include "createaccount.h"
#include <QSqlQuery>
#include <QDebug>
#include "auth/stringtomd5.h"

CreateAccount::CreateAccount()
{

}


bool CreateAccount::create(UserRegisterData urd)
{
    QStringToMd5 stringToMd5;
    QSqlQuery query;

    QString user_login{urd.login()};
    QString user_name{urd.login()};
    QString user_auth_key{stringToMd5.convert(urd.pass())};
    QString user_email{urd.email()};
    QString queryString {"INSERT INTO user_login_table "
                        "(user_login, user_name, user_auth_key, user_email) "
                        "VALUES (\'%1\', \'%2\', \'%3\', \'%4\')"};
    qDebug() << queryString.arg(user_login, user_login, user_auth_key, user_email);
    qDebug() << query.exec(queryString.arg(user_login, user_login, user_auth_key, user_email));
    return 1;
}






#include "createaccount.h"
#include <QSqlQuery>
#include <QDebug>

CreateAccount::CreateAccount()
{

}


bool CreateAccount::create(UserRegisterData urd)
{
    QSqlQuery query;
    QString user_login{urd.login()};
    QString user_name{urd.login()};
    QString user_auth_key{urd.pass()};
    QString user_email{urd.email()};
    QString queryString {"INSERT INTO user_login_table "
                        "(column1, column2, column3, ...) "};

}






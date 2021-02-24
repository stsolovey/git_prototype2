#include "checkifuserexists.h"
#include <QSqlQuery>
#include <QDebug>

CheckIfUserExists::CheckIfUserExists()
{
    //qDebug() << "CheckIfUserExists constructor";
}

bool CheckIfUserExists::checkIfLoginExists(QString login)
{
    QSqlQuery query;
    QString queryString;
    bool ok;
    queryString = "SELECT * "
                  "FROM user_login_table "
                  "WHERE user_login = \'%1\';";
    ok = query.exec(queryString.arg(login));
    return ok && query.next();
}
bool CheckIfUserExists::checkIfEmailExists(QString email)
{
    QSqlQuery query;
    QString queryString;
    bool ok;
    queryString = "SELECT * "
                  "FROM user_login_table "
                  "WHERE user_email = \'%1\';";
    ok = query.exec(queryString.arg(email));
    if (ok && query.next()){
        return true;
    }
    else{
        return false;
    }
}


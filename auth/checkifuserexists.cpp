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
    //qDebug() << "queryString " << queryString.arg(login);
    ok = query.exec(queryString.arg(login));
    if (ok && query.next()){
        //qDebug() << "ok";
        //qDebug() << query.next();
        return true;
    }
    else{
        //qDebug() << "not ok";
        //qDebug() << query.next();
        return false;
    }
}
bool CheckIfUserExists::checkIfEmailExists(QString email)
{
    QSqlQuery query;
    QString queryString;
    bool ok;
    queryString = "SELECT * "
                  "FROM user_login_table "
                  "WHERE user_email = \'%1\';";
    //qDebug() << "queryString " << queryString.arg(email);
    ok = query.exec(queryString.arg(email));
    if (ok && query.next()){
        //qDebug() << "ok";
        //qDebug() << query.next();
        return true;
    }
    else{
        //qDebug() << "not ok";
        //qDebug() << query.next();
        return false;
    }
}


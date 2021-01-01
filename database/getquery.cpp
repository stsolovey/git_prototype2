#include "getquery.h"

GetQuery::GetQuery(QObject *parent) : QObject(parent)
{

}

QSqlQuery GetQuery::get(QString str)
{
    query.exec(str);
    return query;
}

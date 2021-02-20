#ifndef ISDATABASEENTRYEXISTS_H
#define ISDATABASEENTRYEXISTS_H
#include <QString>
#include <QSqlQuery>

class IsDataBaseEntryExists
{
    QSqlQuery query;
public:
    IsDataBaseEntryExists();
    bool check(QString queryString);
};

#endif // ISDATABASEENTRYEXISTS_H

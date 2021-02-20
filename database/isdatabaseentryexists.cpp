#include "isdatabaseentryexists.h"

IsDataBaseEntryExists::IsDataBaseEntryExists()
{

}


bool IsDataBaseEntryExists::check(QString queryString)
{
    bool ok;
    ok = query.exec(queryString);
    if (ok && query.next()) {
        return true;
    }
    else {
        return false;
    }
}

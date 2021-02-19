#include "sourceandencriptedstringscompare.h"
#include "auth/stringtomd5.h"

SourceAndEncriptedStringsCompare::SourceAndEncriptedStringsCompare()
{

}

bool SourceAndEncriptedStringsCompare::compare(QString sourceString, QString encriptedString)
{
    StringToMd5 stmd5;
    if (stmd5.convert(sourceString)==encriptedString)
        return true;
    else
        return false;
}

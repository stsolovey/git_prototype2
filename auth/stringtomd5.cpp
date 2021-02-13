#include "stringtomd5.h"
#include <QCryptographicHash>

stringToMd5::stringToMd5()
{

}

QString stringToMd5::convert(QString str)
{
    return QString(QCryptographicHash::hash( ( qPrintable(str) ),QCryptographicHash::Md5).toHex());
}



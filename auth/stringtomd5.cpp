#include "stringtomd5.h"
#include <QCryptographicHash>

QStringToMd5::QStringToMd5()
{

}

QString QStringToMd5::convert(QString str)
{
    return QString(QCryptographicHash::hash( ( qPrintable(str) ),QCryptographicHash::Md5).toHex());
}



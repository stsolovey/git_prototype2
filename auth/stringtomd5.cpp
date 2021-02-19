#include "stringtomd5.h"
#include <QCryptographicHash>
#include <QDebug>

StringToMd5::StringToMd5()
{
    qDebug() << "UserLogin constructor is working";
}

QString StringToMd5::convert(QString str)
{
    return QString(QCryptographicHash::hash( ( qPrintable(str) ),QCryptographicHash::Md5).toHex());
}



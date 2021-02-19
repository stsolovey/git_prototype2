#ifndef READACCESSCODE_H
#define READACCESSCODE_H
#include <QString>
#include <QFile>
#include <QTextStream>

class AccessCodeRead
{
    QFile file{"accsscd.dat"};
    QString m_code;
public:
    AccessCodeRead();
    bool isFileExist();
    bool isAccessCodeExists();
    QString readAccessCodeFromFile();
    QString getAccessCode() const;
};
#endif // READACCESSCODE_H

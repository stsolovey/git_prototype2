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
    bool isAccessCodeExistsInFile();
    bool isAccessCodeExistsInDataBase();
    QString readAccessCodeFromFile();
    //QString readAccessCodeFromDatabase();
    QString getAccessCode() const;
};
#endif // READACCESSCODE_H

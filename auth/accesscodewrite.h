#ifndef ACCESSCODEWRITE_H
#define ACCESSCODEWRITE_H
#include <QString>
#include <QFile>

class AccessCodeWrite
{
    QFile file{"accsscd.dat"};
    QString m_code;
public:
    AccessCodeWrite();
    AccessCodeWrite(QString code);
    bool writeAccessCodeToFile();
    bool writeAccessCodeToFile(QString code);
    bool writeAccessCodeToDataBase(QString login, QString code);
    QString getCode() const;
    void setCode(const QString &code);
};

#endif // ACCESSCODEWRITE_H

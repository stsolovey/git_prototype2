#ifndef ACCESSCODE_H
#define ACCESSCODE_H
#include <QString>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>

class AccessCode
{
    QFile file{"accsscd.dat"};
    QString alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString userLogin;
    QString generatedAccessCode;
    QString accessCodeFromFile;
    QString accessCodeFromDataBase;
    int lenOfAlphanum = alphanum.length();
    QRandomGenerator rg;
    QSqlQuery query;
public:
    AccessCode();
    void generateAccessCode();
    bool chekIfFileWithAccessCodeExistsOnUsersDevice();
    bool isAccessCodeExistsInDataBase();
    bool readAccessCodeFromFile();
    bool readAccessCodeFromDatabase();
    bool writeGeneratedAccessCode();
    bool writeGeneratedAccessCodeToFile();
    bool writeGeneragedAccessCodeToDatabase();
    bool compareAccessCodeFromFileAndFromDataBase();

    QString getAccessCodeFromFile() const;
    QString getUserLogin() const;
    QString getGeneratedAccessCode() const;
    QString getAccessCodeFromDataBase() const;
    void setUserLogin(const QString &value);
    void setAccessCodeFromDataBase(const QString &value);


    void readConfig();
    void writeConfig();
};

#endif // ACCESSCODE_H





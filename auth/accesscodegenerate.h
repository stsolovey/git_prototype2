#ifndef ACCESSCODEGENERATE_H
#define ACCESSCODEGENERATE_H
#include <QString>
#include <QRandomGenerator>

class AccessCodeGenerate
{
    QString alphanum = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString m_code;
    int lenOfAlphanum = alphanum.length();
    QRandomGenerator rg;
public:
    AccessCodeGenerate();
    QString generate();
};

#endif // ACCESSCODEGENERATE_H

#include "accesscodewrite.h"
#include <QTextStream>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQuery>

AccessCodeWrite::AccessCodeWrite()
{
}

AccessCodeWrite::AccessCodeWrite(QString code) :
    m_code(code)
{

}

bool AccessCodeWrite::writeAccessCodeToFile()
{
    if(file.open(QIODevice::ReadWrite))
    {
    QTextStream out(&file);
    out << getCode() << Qt::endl;
    file.close();
    return true;
    }
    else
        return false;
}

bool AccessCodeWrite::writeAccessCodeToFile(QString code)
{
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream out(&file);
        out << code << Qt::endl;
        file.close();
        qDebug() << code << "true" << file.fileName();
        return true;
    }
    else
    {
        qDebug() << "false";
        return false;
    }
}

bool AccessCodeWrite::writeAccessCodeToDataBase(QString login, QString code)
{
    QSqlQuery query;
    QString queryString1{"UPDATE public.user_login_table "
                         "SET device_accesskey = \'%1\' "
                         "WHERE user_login = \'%2\';  "};
    return query.exec(queryString1.arg(code, login));
}

QString AccessCodeWrite::getCode() const
{
    return m_code;
}

void AccessCodeWrite::setCode(const QString &code)
{
    m_code = code;
}



#include "accesscoderead.h"
#include <QDebug>

AccessCodeRead::AccessCodeRead()
{
}

bool AccessCodeRead::isFileExist()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    else
    {
        file.close();
        return true;
    }
}

bool AccessCodeRead::isAccessCodeExists()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    else
    {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            m_code = in.readLine();
        }
        if (m_code.length())
        {
            file.close();
            return true;
        }
        else
            return false;
    }
}

QString AccessCodeRead::readAccessCodeFromFile()
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";
    else
    {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd())
        {
            line = in.readLine();
        }
        if (line.length())
        {
            file.close();
            return line;
        }
        else
            return "";
    }
}

QString AccessCodeRead::getAccessCode() const
{
    return m_code;
}

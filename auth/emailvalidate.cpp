#include "emailvalidate.h"
#include <QRegExp>
#include <QDebug>

EmailValidate::EmailValidate()
{

}

bool EmailValidate::validate(QString email)
{
    QRegExp mailRegExpChecker("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailRegExpChecker.setCaseSensitivity(Qt::CaseInsensitive);
    mailRegExpChecker.setPatternSyntax(QRegExp::RegExp);
    return mailRegExpChecker.exactMatch(email);
}

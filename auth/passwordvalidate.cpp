#include "passwordvalidate.h"
#include <QRegExp>
PasswordValidate::PasswordValidate()
{

}

bool PasswordValidate::validate(QString password)
{
    QRegExp passRegExpChecker("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{6,}");
    passRegExpChecker.setCaseSensitivity(Qt::CaseInsensitive);
    passRegExpChecker.setPatternSyntax(QRegExp::RegExp);
    return passRegExpChecker.exactMatch(password);
}

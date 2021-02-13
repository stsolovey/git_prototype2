#ifndef RANDOMLETTERSANDNUMBERS_H
#define RANDOMLETTERSANDNUMBERS_H
#include <QChar>
#include <QString>
#include <QRandomGenerator>

class RandomLettersAndNumbers
{
    QString letters{"aeiouybcdfghjklmnpqrstvwxzAEIOUYBCDFGHJKLMNPQRSTVWXZ"};
    QRandomGenerator rg;
    int value{0};
    int LBound{0};
    int UBound{0};
public:
    RandomLettersAndNumbers();
    QChar UpperCaseVowel();
    QChar LowerCaseVowel();
    QChar UpperCaseConsonant();
    QChar LowerCaseConsoant();
    QChar randomLetter(int LBnd, int UBnd);
};

#endif // RANDOMLETTERSANDNUMBERS_H

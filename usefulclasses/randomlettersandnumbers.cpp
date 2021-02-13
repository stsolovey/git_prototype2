#include "randomlettersandnumbers.h"


RandomLettersAndNumbers::RandomLettersAndNumbers()
{

}
QChar RandomLettersAndNumbers::LowerCaseVowel()
{
    LBound = 0;
    UBound = 6;
    return randomLetter(LBound, UBound);
}

QChar RandomLettersAndNumbers::LowerCaseConsoant()
{
    LBound = 6;
    UBound = 26;
    return randomLetter(LBound, UBound);
}
QChar RandomLettersAndNumbers::UpperCaseVowel()
{
    LBound = 26;
    UBound = 32;

    return randomLetter(LBound, UBound);
}

QChar RandomLettersAndNumbers::UpperCaseConsonant()
{
    LBound = 32;
    UBound = 52;
    return randomLetter(LBound, UBound);
}


QChar RandomLettersAndNumbers::randomLetter(int LBnd, int UBnd)
{
    value = rg.global()->bounded(LBnd, UBnd);
    return letters.at(value);
}

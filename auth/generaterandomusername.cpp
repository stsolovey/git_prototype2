#include "generaterandomusername.h"
#include <QRandomGenerator>
#include <QString>
#include <QVector>
#include "usefulclasses/randomlettersandnumbers.h"

GenerateRandomUsername::GenerateRandomUsername()
{

}

QString GenerateRandomUsername::generate()
{
    QString name;
    QRandomGenerator rg;
    RandomLettersAndNumbers rlan;

    int consonantFirst = rg.global()->bounded(0, 2);
    int value = rg.global()->bounded(3, 6);

    if (consonantFirst)
    {
        name.push_back(rlan.UpperCaseConsonant());
        for (int i = 1; i < value; i++)
        {
            name.push_back(rlan.LowerCaseVowel());
            name.push_back(rlan.LowerCaseConsoant());
        }
    }
    else
    {
        name.push_back(rlan.UpperCaseVowel());
        for (int i = 1; i < value; i++)
        {
            name.push_back(rlan.LowerCaseConsoant());
            name.push_back(rlan.LowerCaseVowel());
        }
    }
    return name;
}

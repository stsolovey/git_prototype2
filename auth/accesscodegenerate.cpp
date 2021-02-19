#include "accesscodegenerate.h"

AccessCodeGenerate::AccessCodeGenerate()
{
}

QString AccessCodeGenerate::generate()
{
    for (int i = 0; i < 40; i++)
        m_code.append(alphanum.at(rg.global()->bounded(lenOfAlphanum)));
    return m_code;
}


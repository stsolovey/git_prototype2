#include "loginvalidate.h"

LoginValidate::LoginValidate()
{

}

bool LoginValidate::validate(QString login)
{
    if (login.length() > 3)
        return true;
    else
        return false;
}

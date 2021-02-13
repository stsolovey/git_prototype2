#include "userregisterdata.h"

UserRegisterData::UserRegisterData()
{

}
UserRegisterData::UserRegisterData(int age, QString login, QString email, QString pass)
    : m_age(age), m_login(login), m_email(email), m_pass(pass)
{

}

int UserRegisterData::age() const
{
    return m_age;
}

QString UserRegisterData::login() const
{
    return m_login;
}

QString UserRegisterData::email() const
{
    return m_email;
}

QString UserRegisterData::pass() const
{
    return m_pass;
}

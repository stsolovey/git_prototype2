#include "task2.h"

int Task2::rating() const
{
    return m_rating;
}

int Task2::type() const
{
    return m_type;
}

int Task2::sentence() const
{
    return m_sentence;
}

int Task2::category() const
{
    return m_category;
}

int Task2::course() const
{
    return m_course;
}

int Task2::direction() const
{
    return m_direction;
}

int Task2::id() const
{
    return m_id;
}

Task2::Task2(int id, int direction, int course, int category, int sentence, int type, int rating) :
    m_id (id),
    m_direction (direction),
    m_course(course),
    m_category(category),
    m_sentence(sentence),
    m_type(type),
    m_rating(rating)
{

}

Task2::Task2( int direction, int course, int category, int sentence, int type, int rating) :

    m_direction (direction),
    m_course(course),
    m_category(category),
    m_sentence(sentence),
    m_type(type),
    m_rating(rating)
{

}


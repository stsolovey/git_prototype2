#include "task2.h"

Task2::Task2(){}

Task2::Task2(int id, int direction, int course, int category, int sentence, int type, bool answer_status) :
    m_id (id),
    m_direction (direction),
    m_course(course),
    m_category(category),
    m_sentence(sentence),
    m_type(type),
    m_answer_status(answer_status)
{

}

Task2::Task2( int direction, int course, int category, int sentence, int type, bool answer_status) :
    m_direction (direction),
    m_course(course),
    m_category(category),
    m_sentence(sentence),
    m_type(type),
    m_answer_status(answer_status)
{

}

bool Task2::answer_status() const
{
    return m_answer_status;
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



void Task2::setId(int id)
{
    m_id = id;
}

void Task2::setDirection(int direction)
{
    m_direction = direction;
}

void Task2::setCourse(int course)
{
    m_course = course;
}

void Task2::setCategory(int category)
{
    m_category = category;
}

void Task2::setSentence(int sentence)
{
    m_sentence = sentence;
}

void Task2::setType(int type)
{
    m_type = type;
}

void Task2::setAnswer_status(int answer_status)
{
    m_answer_status = answer_status;
}

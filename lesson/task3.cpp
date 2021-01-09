#include "task3.h"

Task3::Task3()
{

}
Task3::Task3(int direction, int course, int sentence, int type_of_exercise) :
    m_direction(direction),
    m_course(course),
    m_sentence(sentence),
    m_type_of_exercise(type_of_exercise)
{

}

bool Task3::operator == (const Task3 t3)
{
    if (direction() == t3.direction() and
        course() == t3.course() and
        sentence() == t3.sentence() and
        type_of_exercise() == t3.type_of_exercise())
        return true;
    else
        return false;
}

int Task3::type_of_exercise() const
{
    return m_type_of_exercise;
}
int Task3::sentence() const
{
    return m_sentence;
}
int Task3::course() const
{
    return m_course;
}
int Task3::direction() const
{
    return m_direction;
}



void Task3::setType_of_exercise(int type_of_exercise)
{
    m_type_of_exercise = type_of_exercise;
}
void Task3::setSentence(int sentence)
{
    m_sentence = sentence;
}
void Task3::setCourse(int course)
{
    m_course = course;
}
void Task3::setDirection(int direction)
{
    m_direction = direction;
}





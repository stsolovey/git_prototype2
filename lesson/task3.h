#ifndef TASK3_H
#define TASK3_H


class Task3
{
    int m_direction;
    int m_course;
    int m_sentence;
    int m_type_of_exercise;

public:
    Task3();
    Task3(int direction, int course, int sentence, int type_of_exercise);


     bool operator == (const Task3 t3);

    int direction() const;
    int course() const;
    int sentence() const;
    int type_of_exercise() const;


    void setDirection(int direction);
    void setCourse(int course);
    void setSentence(int sentence);
    void setType_of_exercise(int type_of_exercise);
};

#endif // TASK3_H

#ifndef TASK2_H
#define TASK2_H

class Task2
{
    int m_id;
    int m_direction;
    int m_course;
    int m_category;
    int m_sentence;
    int m_type;
    int m_rating;
public:
    explicit Task2(int, int, int, int, int, int, int);
    explicit Task2(int, int, int, int, int, int);
    int id() const;
    int direction() const;
    int course() const;
    int category() const;
    int sentence() const;
    int type() const;
    int rating() const;
};

#endif // TASK2_H

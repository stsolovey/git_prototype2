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
    int m_answer_status;
public:
    explicit Task2();
    explicit Task2(int, int, int, int, int, int, bool answer_status);
    explicit Task2(int, int, int, int, int, bool);
    int id() const;
    int direction() const;
    int course() const;
    int category() const;
    int sentence() const;
    int type() const;
    bool answer_status() const;
    void setId(int id);
    void setDirection(int direction);
    void setCourse(int course);
    void setCategory(int category);
    void setSentence(int sentence);
    void setType(int type);
    void setAnswer_status(int answer_status);
};

#endif // TASK2_H

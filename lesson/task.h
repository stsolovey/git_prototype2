#ifndef TASK_H
#define TASK_H
#include <QString>

class Task
{

public:
    explicit Task(int, QString, int, int);

    int exercise_id;
    QString exercise_text;
    int exercise_category;
    int exercise_type;

};

#endif // TASK_H

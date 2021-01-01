#ifndef TASK_H
#define TASK_H
#include <QString>

class Task
{

public:
    explicit Task(int, QString, QString, int);

    int exercise_id;
    QString exercise_text;
    QString exercise_translation;
    int exercise_type;

};

#endif // TASK_H

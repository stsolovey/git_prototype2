#include "task.h"

Task::Task(int id, QString text, QString trn, int type)
{
    exercise_id = id;
    exercise_text = text;
    exercise_translation = trn;
    exercise_type = type;
}

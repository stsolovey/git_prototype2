#include "task.h"

Task::Task(int id, QString text, int cat, int type)
{
    exercise_id = id;
    exercise_text = text;
    exercise_category = cat;
    exercise_type = type;
}

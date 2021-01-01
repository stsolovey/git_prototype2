#ifndef GETLESSON_H
#define GETLESSON_H

#include <QObject>
#include <QSqlQuery>

class GetLesson : public QObject
{
    Q_OBJECT
public:
    explicit GetLesson(QObject *parent = nullptr);
    QStringList getLesson(QSqlQuery query);

signals:

};

#endif // GETLESSON_H

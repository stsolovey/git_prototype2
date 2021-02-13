#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = 0);
    ~Connection();
private:
    QSqlDatabase db;

private:
    bool openDataBase();
    void closeDataBase();

public slots:
};

#endif // DATABASE_H

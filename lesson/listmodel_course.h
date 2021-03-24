#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class ListModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    int userId;
    enum Roles {
        IdRole = Qt::UserRole + 1,      // id
        NameRole, // имя
        EnabledRole
    };
    explicit ListModel(QObject *parent = 0);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    void setUserIdByAccessCode();

protected:
    QHash<int, QByteArray> roleNames() const;
signals:

public slots:
    void updateModel();

};

#endif // LISTMODEL_H

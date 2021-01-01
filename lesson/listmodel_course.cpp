#include "listmodel_course.h"
//#include "database/database.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}
void ListModel::updateModel()
{
    this->setQuery("SELECT * FROM ru_en_categories");
}

// Метод для получения данных из модели
QVariant ListModel::data(const QModelIndex & index, int role) const {

    // Определяем номер колонки, адрес по номеру роли
    int columnId = role - Qt::UserRole - 1;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index(index.row(), columnId);


    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

// Метод для получения имен ролей через хешированную таблицу.
QHash<int, QByteArray> ListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id_cat";
    roles[NameRole] = "name";
    return roles;
}

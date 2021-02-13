#include "listmodel_course.h"
//#include "database/database.h"
#include <QSqlError>
#include <QDebug>

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}
void ListModel::updateModel()
{
    //this->setQuery("SELECT * FROM ru_en_categories");
    this->setQuery(
        "select t1.*, enabled_category from ru_en_categories t1 "
        "left join"
        "(select ru_en_sentences.id_cat, min(user_slusla_sentences_stat.right_answers) enabled_category "
        "from ru_en_sentences "
        "left join user_slusla_sentences_stat "
        "on ru_en_sentences.\"﻿id\" = user_slusla_sentences_stat.sentence "
        "group by ru_en_sentences.id_cat "
        "order by ru_en_sentences.id_cat) t2 "
        "on t1.\"﻿id_cat\" = t2.id_cat+1 "
        "order by t1.\"﻿id_cat\" "

        );
    qDebug() << "this->lastError(): " << this->lastError();
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
    roles[EnabledRole] = "enabled_category";
    return roles;
}

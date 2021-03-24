#include "listmodel_course.h"
//#include "database/database.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSettings>
#include <QCoreApplication>

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}
void ListModel::updateModel()
{
    QString queryString(
        "select t1.*, enabled_category from ru_en_categories t1 "
        "left join"
        "(select ru_en_sentences.id_cat, min(t3.right_answers) enabled_category "
        "from ru_en_sentences "
        "left join  (SELECT * FROM user_slusla_sentences_stat WHERE userid = %1) t3 "
        "on ru_en_sentences.\"﻿id\" = t3.sentence "
        "group by ru_en_sentences.id_cat "
        "order by ru_en_sentences.id_cat) t2 "
        "on t1.\"﻿id_cat\" = t2.id_cat+1 "
        "order by t1.\"﻿id_cat\" "
        );
    //userId = 13;
    //this->setQuery("SELECT * FROM ru_en_categories");
    setUserIdByAccessCode();
    this->setQuery(
        queryString.arg(userId)

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

void ListModel::setUserIdByAccessCode()
{
    QString deviceAccessCode;
    QSettings settings(qApp->applicationDirPath()+"/settings.ini",QSettings::IniFormat);
    settings.beginGroup("Settings");
    {
        deviceAccessCode = settings.value("accessCode").toString();
    }
    settings.endGroup();
    QString queryString("SELECT user_id "
                        "FROM user_login_table "
                        "WHERE device_accesskey = \'%1\';");
    QSqlQuery query;
    query.exec(queryString.arg(deviceAccessCode));
    query.next();
    userId = query.value(0).toInt();
    qInfo() << userId;

    //QString queryString2("SELECT user_id "
    //                     "FROM user_login_table ;");
    //while (query.next())
        //qInfo() << query.value(0).toInt();
}

// Метод для получения имен ролей через хешированную таблицу.
QHash<int, QByteArray> ListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id_cat";
    roles[NameRole] = "name";
    roles[EnabledRole] = "enabled_category";
    return roles;
}

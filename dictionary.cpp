#include "dictionary.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
Dictionary::Dictionary()
{
}

QStringList Dictionary::getAttributeValues(QString attribute){
    QSqlQuery query(globaldb);
    query.prepare("select attributeValue from dictionary where attributeName = ?");
    query.addBindValue(attribute);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QString value;
    if(query.first()){
        value = query.value(0).toString();
    }
    query.finish();
    query.clear();
    return value.split(";",QString::SkipEmptyParts);
}

QMap<QString,QString> Dictionary::getExpenseMapByType(int type){
    QSqlQuery query(globaldb);
    query.prepare("select item,cost from expense_info where type = ?");
    query.addBindValue(type);
    query.exec();
    QMap<QString,QString> map;
    while(query.next()){
        map.insert(query.value(0).toString(),query.value(1).toString());
    }
    query.finish();
    query.clear();
    return map;
}

QStringList Dictionary::getExpenseNameByType(int type){
    QSqlQuery query(globaldb);
    query.prepare("select item from expense_info where type = ?");
    query.addBindValue(type);
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }
    return list;
}

QStringList Dictionary::getBtnListByParentAndUser(QString parent,QString user){
    QSqlQuery query(globaldb);
    qDebug()<<parent;
    query.prepare("select a.textName from menu a,role_menu b,operator c  where a.id = b.menuId and b.roleId = c.roleId "
                  "and a.type = 3 and c.userName = ? and a.parentId in (select id from menu  where objName = ? )");
    query.addBindValue(user);
    query.addBindValue(parent);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }
    query.clear();
    return list;
}

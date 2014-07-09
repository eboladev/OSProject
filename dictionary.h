#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<QStringList>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
class Dictionary
{
public:
    Dictionary();
    static QStringList getAttributeValues(QString);
    static QMap<QString,QString> getExpenseMapByType(int);
    static QStringList getExpenseNameByType(int);
    static QStringList getBtnListByParentAndUser(QString,QString);
};

#endif // DICTIONARY_H

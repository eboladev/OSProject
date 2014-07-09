#include "dateeditdelegate.h"
#include<QLineEdit>
#include<QDebug>
#include<QDateEdit>
#include<QDate>
DateEditDelegate::DateEditDelegate(QObject *parent)
    :QItemDelegate(parent)
{
}

QWidget* DateEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/, const QModelIndex &/*index*/) const{
    QDateEdit *date = new QDateEdit(parent);
    date->setCalendarPopup(true);
    date->setDisplayFormat("yyyy-MM-dd");
    date->setDate(QDate::currentDate());
    date->setMinimumDate(QDate(2014,3,1));
    date->setMaximumDate(QDate(2050,12,31));
    return date;
}

void DateEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    QDate value = index.model()->data(index,Qt::DisplayRole).toDate();
    QDateEdit *date = static_cast<QDateEdit*>(editor);
    date->setDate(value);
}

void DateEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QDateEdit *date = static_cast<QDateEdit*>(editor);
   QDate value = date->date();
    model->setData(index,value);
}

void DateEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const{
    editor->setGeometry(option.rect);
}

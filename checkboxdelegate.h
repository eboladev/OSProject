#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H
#include<QItemDelegate>
class CheckBoxDelegate:public QItemDelegate
{
public:
    CheckBoxDelegate(QObject *parent = 0);
    QRect CheckBoxRect(const QStyleOptionViewItem &option) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CHECKBOXDELEGATE_H

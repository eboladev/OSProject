#ifndef RESIDEREGISTERSTATUSDELEGATE_H
#define RESIDEREGISTERSTATUSDELEGATE_H
#include<QItemDelegate>
class ResideRegisterStatusDelegate:public QItemDelegate
{
public:
    ResideRegisterStatusDelegate(QObject *parent);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // RESIDEREGISTERSTATUSDELEGATE_H

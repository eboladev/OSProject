#ifndef SETTLESTATUSDELEGATE_H
#define SETTLESTATUSDELEGATE_H
#include<QItemDelegate>
class SettleStatusDelegate:public QItemDelegate
{
public:
    SettleStatusDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // SETTLESTATUSDELEGATE_H

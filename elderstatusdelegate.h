#ifndef ELDERSTATUSDELEGATE_H
#define ELDERSTATUSDELEGATE_H
#include<QItemDelegate>
class ElderStatusDelegate:public QItemDelegate
{
public:
    ElderStatusDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ELDERSTATUSDELEGATE_H

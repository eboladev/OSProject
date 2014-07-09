#ifndef VACATIONSTATUSDELEGATE_H
#define VACATIONSTATUSDELEGATE_H
#include<QItemDelegate>
class VacationStatusDelegate:public QItemDelegate
{
public:
    VacationStatusDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
//    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // VACATIONSTATUSDELEGATE_H

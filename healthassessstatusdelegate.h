#ifndef HEALTHASSESSSTATUSDELEGATE_H
#define HEALTHASSESSSTATUSDELEGATE_H
#include<QItemDelegate>
class HealthAssessStatusDelegate:public QItemDelegate
{
public:
    HealthAssessStatusDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // HEALTHASSESSSTATUSDELEGATE_H

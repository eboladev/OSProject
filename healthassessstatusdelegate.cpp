#include "healthassessstatusdelegate.h"
#include<QApplication>
#include<QPainter>
HealthAssessStatusDelegate::HealthAssessStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void HealthAssessStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("ÒÑÆÀ¹À");
    else if(content == 0)
        value = tr("Î´ÆÀ¹À");
    else
        value = tr("ÎÞ");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}

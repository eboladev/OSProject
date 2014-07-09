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
        value = tr("������");
    else if(content == 0)
        value = tr("δ����");
    else
        value = tr("��");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}

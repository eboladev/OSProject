#include "vacationstatusdelegate.h"
#include<QApplication>
#include<QStyledItemDelegate>

VacationStatusDelegate::VacationStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void VacationStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("已请假");
    else if(content == 2)
        value = tr("已销假");
    else
        value = tr("无");
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
}

//QSize VacationStatusDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const{
//    return QStyledItemDelegate::sizeHint(option,index);
//}

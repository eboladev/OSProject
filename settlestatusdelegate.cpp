#include "settlestatusdelegate.h"
#include<QApplication>
//#include<QTextOption>
#include<QPainter>
SettleStatusDelegate::SettleStatusDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void SettleStatusDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    int content = index.model()->data(index,Qt::DisplayRole).toInt();
    QString value;
    if(content == 1)
        value = tr("�ѽ���");
    else if(content == 0)
        value = tr("δ����");
    else
        value = tr("��");
//    QTextOption o(Qt::AlignRight | Qt::AlignVCenter);
//     painter->drawText(option.rect, value, o);
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    drawDisplay(painter, myOption, myOption.rect, value);
    drawFocus(painter, myOption, myOption.rect);
//    QApplication::style()->drawItemText(painter,option.rect,option.displayAlignment,QApplication::palette(),true,value);
}

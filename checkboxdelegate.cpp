#include "checkboxdelegate.h"
#include<QCheckBox>
#include<QApplication>
CheckBoxDelegate::CheckBoxDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
            //��ȡֵ
            int checked = index.model()->data(index, Qt::DisplayRole).toInt();
            //��ť�ķ��ѡ��
            QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
            checkBoxOption->state |= QStyle::State_Enabled;
            //����ֵ�ж��Ƿ�ѡ��
            if(checked)
            {
                checkBoxOption->state |= QStyle::State_On;
            }
            else
            {
                checkBoxOption->state |= QStyle::State_Off;
            }
            //����QCheckBox������״
            checkBoxOption->rect = CheckBoxRect(option);
            //����QCheckBox
            QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);
}

QRect CheckBoxDelegate::CheckBoxRect(const QStyleOptionViewItem &option) const{
        //���ư�ť����Ҫ�Ĳ���
        QStyleOptionButton checkBoxStyleOption;
        //���ո����ķ����� ����Ԫ��������
        QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
        //����QCheckBox����
        QPoint checkBoxPoint(option.rect.x() + option.rect.width() / 2 - checkBoxRect.width() / 2,
                             option.rect.y() + option.rect.height() / 2 - checkBoxRect.height() / 2);
        //����QCheckBox������״
        return QRect(checkBoxPoint, checkBoxRect.size());
}



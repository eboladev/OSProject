#include "checkboxdelegate.h"
#include<QCheckBox>
#include<QApplication>
CheckBoxDelegate::CheckBoxDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
            //获取值
            int checked = index.model()->data(index, Qt::DisplayRole).toInt();
            //按钮的风格选项
            QStyleOptionButton *checkBoxOption = new QStyleOptionButton();
            checkBoxOption->state |= QStyle::State_Enabled;
            //根据值判断是否选中
            if(checked)
            {
                checkBoxOption->state |= QStyle::State_On;
            }
            else
            {
                checkBoxOption->state |= QStyle::State_Off;
            }
            //返回QCheckBox几何形状
            checkBoxOption->rect = CheckBoxRect(option);
            //绘制QCheckBox
            QApplication::style()->drawControl(QStyle::CE_CheckBox,checkBoxOption,painter);
}

QRect CheckBoxDelegate::CheckBoxRect(const QStyleOptionViewItem &option) const{
        //绘制按钮所需要的参数
        QStyleOptionButton checkBoxStyleOption;
        //按照给定的风格参数 返回元素子区域
        QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
        //返回QCheckBox坐标
        QPoint checkBoxPoint(option.rect.x() + option.rect.width() / 2 - checkBoxRect.width() / 2,
                             option.rect.y() + option.rect.height() / 2 - checkBoxRect.height() / 2);
        //返回QCheckBox几何形状
        return QRect(checkBoxPoint, checkBoxRect.size());
}



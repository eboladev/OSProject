#include "dragdropwidget.h"
#include<QVBoxLayout>
DragDropWidget::DragDropWidget(const QString &title,QWidget *parent):
    QDockWidget(title,parent)
{   
    this->setMinimumHeight(240);
    this->setFixedWidth(260);
    drags = new QListWidget(this);
    garbage = new QLabel(tr("É¾³ý"),this);
    drags->setGeometry(0,30,260,210);
    garbage->setGeometry(0,250,260,40);
    garbage->setAlignment(Qt::AlignCenter);
    for(unsigned char i = 0;i<3;++i){
        QListWidgetItem *item = new QListWidgetItem(tr("%1").arg(i+1),drags);
        item->setSizeHint(QSize(180,50));
        drags->addItem(item);
    }
//    this->setFixedHeight(180);
}

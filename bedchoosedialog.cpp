#include "bedchoosedialog.h"
#include "ui_bedchoosedialog.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include<QRegExp>
#include "struct.h"
BedChooseDialog::BedChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BedChooseDialog)
{
    ui->setupUi(this);
     initModel();
    initView();
}

BedChooseDialog::~BedChooseDialog()
{
    delete model;
    delete ui;
}

void BedChooseDialog::initModel(){
    model = new QStandardItemModel(this);
    model->setColumnCount(1);
    model->setHeaderData(0,Qt::Horizontal,tr("楼宇"));
    createModel();
}

void BedChooseDialog::initView(){
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->verticalHeader()->hide();

    ui->treeView->setModel(model);    
    ui->treeView->setFixedWidth(150);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeView->expandAll();
}

void BedChooseDialog::createModel(){   
    QString buildingName;
    QStringList floors;    
    unsigned char i = 0;
    if(globaldb.open())
    {        
        QSqlQuery query(globaldb);
        //构建楼宇
        query.prepare("SELECT building_no,floorlist FROM buildingmaptofloor");
        query.exec();
        while(query.next())
        {
            QList<int> floorList;
            buildingName = query.value(0).toString();
            floors = query.value(1).toString().split("*");
            qDebug()<<buildingName<<floors;
            QStandardItem *buildingItem = new QStandardItem(buildingName);
            buildingItem->setIcon(QIcon("images/buildingitem.png"));
            for(i=0;i<floors.size();++i)
                floorList.append(floors.at(i).toInt());
            qSort(floorList.begin(),floorList.end());
            for(i=0;i<floorList.size();++i){
                QStandardItem *item = new QStandardItem(floornames.at(i));
                item->setIcon(QIcon("images/flooritem.png"));
                buildingItem->appendRow(item);
            }
            model->appendRow(buildingItem);
        }        
    }
    else
    {    
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");   
    }
}

void BedChooseDialog::on_treeView_clicked(const QModelIndex &index)
{
    if(index.isValid()){
        qDebug()<<index.row()<<" and "<<index.column();
        qDebug()<<index.parent().data().toString();
        qDebug()<<index.parent();
        QString sql;
        if(!index.parent().isValid())
            sql = tr("SELECT room_name,room_direction,bitmap,bedStatus,bed_no FROM device_info WHERE building_no =' %1' ORDER BY floor_no ASC , room_name ASC").arg(index.data().toString());
        else{
            int floor_no = floornames.indexOf(QRegExp(tr("%1").arg(index.data().toString())));
            qDebug()<<"floor_no:"<<floor_no;
            sql = tr("SELECT room_name,room_direction,bitmap,bedStatus,bed_no FROM device_info WHERE building_no = '%1' and floor_no = %2 ORDER BY  room_name ASC").arg(index.data().toString());

        }
        QSqlQuery query(globaldb);
        //query.prepare();
    }
}

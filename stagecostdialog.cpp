#include "stagecostdialog.h"
#include "ui_stagecostdialog.h"
#include<QStandardItem>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QDate>
#include "dateeditdelegate.h"
#include "dictionary.h"
extern QString operatorId;
StageCostDialog::StageCostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StageCostDialog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

StageCostDialog::~StageCostDialog()
{
    delete model;
    delete ui;
}

void StageCostDialog::initModel(){
    model = new QStandardItemModel(this);
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal,tr("项目"));
    model->setHeaderData(1,Qt::Horizontal,tr("费用"));
    model->setHeaderData(2,Qt::Horizontal,tr("开始日期"));
    model->setHeaderData(3,Qt::Horizontal,tr("截止日期"));
    QSqlQuery query(globaldb);
    query.prepare("select item,cost,startDate,endDate from expense_info where type = 5");
    query.exec();
    unsigned char i = 0;
    while(query.next()){
        model->setItem(i,0,new QStandardItem(query.value(0).toString()));
        model->setItem(i,1,new QStandardItem(query.value(1).toString()));
        model->setItem(i,2,new QStandardItem(query.value(2).toString()));
        model->setItem(i,3,new QStandardItem(query.value(3).toString()));
        ++i;
    }
}

void StageCostDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("stage_cost_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(25);
    ui->tableView->setItemDelegateForColumn(2,new DateEditDelegate(this));
    ui->tableView->setItemDelegateForColumn(3,new DateEditDelegate(this));
}

void StageCostDialog::on_btn_add_clicked()
{
    QStandardItem *item = new QStandardItem(tr("新建项目"));
    QStandardItem *cost = new QStandardItem(tr("0.00"));
    QStandardItem *startDate = new QStandardItem(tr("yyyy-MM-dd"));
    QStandardItem *endDate = new QStandardItem(tr("yyyy-MM-dd"));
    int row = model->rowCount();
    model->setItem(row,0,item);
    model->setItem(row,1,cost);
    model->setItem(row,2,startDate);
    model->setItem(row,3,endDate);
    QModelIndex index = model->indexFromItem(item);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}

void StageCostDialog::on_btn_delete_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void StageCostDialog::on_btn_ok_clicked()
{
    QSqlQuery query(globaldb);
    query.prepare("delete from expense_info where type = 5");
    query.exec();
    query.finish();
    for(unsigned char i = 0;i<model->rowCount();++i){
        query.prepare("insert into  expense_info (id,type,item,cost,startDate,endDate) values (NULL,5,?,?,?,?)");
        query.addBindValue(model->item(i,0)->text());
        query.addBindValue(model->item(i,1)->text().toFloat());
        query.addBindValue(model->item(i,2)->data(Qt::DisplayRole).toDate());
        query.addBindValue(model->item(i,3)->data(Qt::DisplayRole).toDate());
//        query.addBindValue(QDate::fromString(model->item(i,2)->text(),"yyyy-MM-dd"));都可以
//        query.addBindValue(QDate::fromString(model->item(i,3)->text(),"yyyy-MM-dd"));
        qDebug()<<model->item(i,2)->data(Qt::DisplayRole).toDate();
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        query.finish();
    }
    this->accept();
}

void StageCostDialog::on_btn_cancel_clicked()
{
    this->reject();
}

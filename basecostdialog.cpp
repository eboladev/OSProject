#include "basecostdialog.h"
#include "ui_basecostdialog.h"
#include<QStandardItem>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
BaseCostDialog::BaseCostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseCostDialog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

BaseCostDialog::~BaseCostDialog()
{
    delete model_value;
    delete model_attribute;
    delete ui;
}

void BaseCostDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("base_cost_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
    ui->listView_attribute->setModel(model_attribute);
    ui->listView_attribute->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setModel(model_value);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnWidth(0,120);
    ui->tableView->verticalHeader()->setDefaultSectionSize(25);
    connect(ui->listView_attribute,SIGNAL(clicked(QModelIndex)),this,SLOT(attributeClicked(QModelIndex)));
}

void BaseCostDialog::initModel(){
    model_attribute = new QStandardItemModel(this);
    model_value = new QStandardItemModel(this);
    model_value->setColumnCount(2);
    model_value->setHeaderData(0,Qt::Horizontal,tr("项目"));
    model_value->setHeaderData(1,Qt::Horizontal,tr("费用"));
    model_attribute->appendRow(new QStandardItem(tr("床位费设定(每天)")));
    model_attribute->appendRow(new QStandardItem(tr("护理费设定(每天)")));
    model_attribute->appendRow(new QStandardItem(tr("初始费设定")));
    model_attribute->appendRow(new QStandardItem(tr("特殊服务费设定")));
}

void BaseCostDialog::on_btn_add_clicked()
{
    QStandardItem *item = new QStandardItem(tr("新建项目"));
    QStandardItem *cost = new QStandardItem(tr("0.00"));
    int row = model_value->rowCount();
    model_value->setItem(row,0,item);
    model_value->setItem(row,1,cost);
    QModelIndex index = model_value->indexFromItem(item);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}

void BaseCostDialog::on_btn_delete_clicked()
{
    model_value->removeRow(ui->tableView->currentIndex().row());
}

void BaseCostDialog::on_btn_ok_clicked()
{
    QString attribute = model_attribute->data(ui->listView_attribute->currentIndex()).toString();
    QSqlQuery query(globaldb);
    if(attribute.compare(tr("床位费设定(每天)")) == 0){
        query.prepare("delete from expense_info where type = 1");
    }
    else if(attribute.compare(tr("护理费设定(每天)")) == 0){
        query.prepare("delete from expense_info where type = 2");
    }
    else if(attribute.compare(tr("初始费设定")) == 0){
        query.prepare("delete from expense_info where type = 3");
    }
    else if(attribute.compare(tr("特殊服务费设定")) == 0){
        query.prepare("delete from expense_info where type = 4");
    }
    else{
        this->accept();
        return;
    }
    query.exec();
    query.finish();

    for(unsigned char i = 0;i<model_value->rowCount();++i){
        query.prepare("insert into expense_info (id,type,item,cost) values (NULL,?,?,?)");
        if(attribute.compare(tr("床位费设定(每天)")) == 0)
            query.addBindValue(1);
        else if(attribute.compare(tr("护理费设定(每天)")) == 0)
            query.addBindValue(2);
        else if(attribute.compare(tr("初始费设定")) == 0)
            query.addBindValue(3);
        else if(attribute.compare(tr("特殊服务费设定")) == 0)
            query.addBindValue(4);

        query.addBindValue(model_value->item(i,0)->text());
        query.addBindValue(model_value->item(i,1)->text().toFloat());
        query.exec();
        query.finish();
    }

    this->accept();
}

void BaseCostDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void BaseCostDialog::attributeClicked(QModelIndex index){
    model_value->removeRows(0,model_value->rowCount());
    QString attribute = index.data().toString();
    qDebug()<<attribute;
    QSqlQuery query(globaldb);
    if(attribute.compare(tr("床位费设定(每天)")) == 0){
        query.prepare("select item,cost from expense_info where type = 1");
    }
    else if(attribute.compare(tr("护理费设定(每天)")) == 0){
        query.prepare("select item,cost from expense_info where type = 2");
    }
    else if(attribute.compare(tr("初始费设定")) == 0){
        query.prepare("select item,cost from expense_info where type = 3");
    }
    else{
        query.prepare("select item,cost from expense_info where type = 4");
    }
    query.exec();
    unsigned char i = 0;
    while(query.next()){
        model_value->setItem(i,0,new QStandardItem(query.value(0).toString()));
        model_value->setItem(i,1,new QStandardItem(query.value(1).toString()));
        ++i;
    }
    query.clear();
    query.finish();
}

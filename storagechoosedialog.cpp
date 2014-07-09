#include "storagechoosedialog.h"
#include "ui_storagechoosedialog.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QSqlDatabase globaldb;

StorageChooseDialog::StorageChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StorageChooseDialog)
{
    ui->setupUi(this);
    initView();
}

StorageChooseDialog::~StorageChooseDialog()
{
    delete ui;
}

void StorageChooseDialog::initView(){
    ui->comboBox_type->addItems(Dictionary::getAttributeValues(tr("物资分类")));
    ui->comboBox_standard->addItems(Dictionary::getAttributeValues(tr("物资规格")));
    QStringList header;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->verticalHeader()->hide();
    QSqlQuery query(globaldb);
    query.prepare("select id,type,name,standard,unit,rate,amount,warehouse,provider from storage");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(9);
    header<<"id"<<"物资分类"<<"物资名称"<<"规格"<<"单位"<<"单价"<<"数量"<<"仓库"<<"供应商";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    int i = 0;
    while(query.next()){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
    query.clear();
    query.finish();
    connect(ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void StorageChooseDialog::on_btn_clear_clicked()
{
    ui->comboBox_standard->setCurrentIndex(ui->comboBox_standard->findText(tr("全部")));
    ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(tr("全部")));
    ui->lineEdit->setText(tr(""));
}

void StorageChooseDialog::on_btn_search_clicked()
{
    ui->tableWidget->clearContents();
    QSqlQuery query(globaldb);
    QString sql = tr("select id,type,name,standard,unit,rate,amount,warehouse,provider from storage where id is not NULL");
    if(ui->lineEdit->text().compare(tr("")) != 0)
        sql.append(tr(" and name like '%%1%'").arg(ui->lineEdit->text()));
    if(ui->comboBox_type->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and type = '%1'").arg(ui->comboBox_type->currentText()));
    if(ui->comboBox_standard->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and standard = '%1'").arg(ui->comboBox_standard->currentText()));
    query.prepare(sql);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    qDebug()<<query.size();
    int i = 0;
    while(query.next()){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
    query.clear();
    query.finish();
}

void StorageChooseDialog::doubleClickRecord(QModelIndex index){
    QTableWidgetItem *item = ui->tableWidget->item(index.row(),0);
     qDebug()<<tr("item data is %1").arg(item->text());
    emit sendStorageChoosed(item->text().toInt());
    this->accept();
}

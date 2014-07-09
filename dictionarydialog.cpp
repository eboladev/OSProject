#include "dictionarydialog.h"
#include "ui_dictionarydialog.h"
#include<QSqlQuery>
#include<QStandardItem>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
DictionaryDialog::DictionaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DictionaryDialog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

DictionaryDialog::~DictionaryDialog()
{
    delete model_value;
    delete model_attribute;
    delete ui;
}

void DictionaryDialog::on_btn_ok_clicked()
{      
    QString attribute = model_attribute->data(ui->listView_attribute->currentIndex()).toString();
    QSqlQuery query(globaldb);
    QString value = tr("");
    for(unsigned char i = 0;i<model_value->rowCount();++i){
        value.append(model_value->item(i)->text());
        value.append(tr(";"));
    }
    query.prepare("update dictionary set attributeValue = ? where attributeName = ?");
    query.addBindValue(value);
    query.addBindValue(attribute);
    query.exec();
    query.finish();
    query.clear();
    this->accept();
}

void DictionaryDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void DictionaryDialog::initModel(){
    model_attribute = new QStandardItemModel(this);
    model_value = new QStandardItemModel(this);
    QSqlQuery query(globaldb);
    query.prepare("select  attributeName from dictionary");
    query.exec();
    while(query.next()){
        model_attribute->appendRow(new QStandardItem(query.value(0).toString()));
    }
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.clear();
    query.finish();
}

void DictionaryDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("dictionary_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->listView_value->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
        ui->listView_attribute->setModel(model_attribute);
        ui->listView_attribute->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->listView_value->setModel(model_value);
        connect(ui->listView_attribute,SIGNAL(clicked(QModelIndex)),this,SLOT(attributeClicked(QModelIndex)));
}

void DictionaryDialog::attributeClicked(QModelIndex index){
    model_value->clear();
    QString attribute = index.data().toString();
    qDebug()<<attribute;
    QSqlQuery query(globaldb);
    query.prepare("select attributeValue from dictionary where attributeName = ?");
    query.addBindValue(attribute);
    query.exec();
    if(query.first()){
        QString value = query.value(0).toString();
        QStringList value_list = value.split(";",QString::SkipEmptyParts);
        for(unsigned char i = 0;i<value_list.size();++i){
            model_value->appendRow(new QStandardItem(value_list.at(i)));
        }
    }
    query.clear();
    query.finish();
}

void DictionaryDialog::on_btn_add_clicked()
{
    QStandardItem *item = new QStandardItem(tr("新建项目"));
    int row = model_value->rowCount();
    model_value->insertRow(row,item);
    QModelIndex index = model_value->indexFromItem(item);
    ui->listView_value->setCurrentIndex(index);
    ui->listView_value->edit(index);
}

void DictionaryDialog::on_btn_delete_clicked()
{
    model_value->removeRow(ui->listView_value->currentIndex().row());
}

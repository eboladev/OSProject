#include "storage.h"
#include "ui_storage.h"
#include<QMessageBox>
#include<QDebug>
#include<QDate>
#include "dictionary.h"

Storage::Storage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
    initModel();
    initView();
}

Storage::~Storage()
{
    delete model;
    delete ui;
}

void Storage::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("storage");
    model->setHeaderData(model->fieldIndex("type"),Qt::Horizontal,tr("物资分类"));
     model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("物资名称"));
     model->setHeaderData(model->fieldIndex("standard"),Qt::Horizontal,tr("规格"));
     model->setHeaderData(model->fieldIndex("unit"),Qt::Horizontal,tr("单位"));
     model->setHeaderData(model->fieldIndex("rate"),Qt::Horizontal,tr("单价"));
     model->setHeaderData(model->fieldIndex("amount"),Qt::Horizontal,tr("数量"));
     model->setHeaderData(model->fieldIndex("warehouse"),Qt::Horizontal,tr("仓库"));
     model->setHeaderData(model->fieldIndex("provider"),Qt::Horizontal,tr("供应商"));
     model->select();
}

void Storage::initView(){
    ui->comboBox_type->addItems(Dictionary::getAttributeValues(tr("物资分类")));
    ui->comboBox_standard->addItems(Dictionary::getAttributeValues(tr("物资规格")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
}

void Storage::on_btn_clear_clicked()
{
    ui->lineEdit_name->setText(tr(""));
    ui->lineEdit_provider->setText(tr(""));
    ui->comboBox_standard->setCurrentIndex(ui->comboBox_standard->findText(tr("全部")));
    ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(tr("全部")));
}

void Storage::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) !=0)
        sql.append(tr(" name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_provider->text().compare(tr("")) !=0)
        sql.append(tr(" provider = '%1' and ").arg(ui->lineEdit_provider->text()));
    if(ui->comboBox_standard->currentText().compare(tr("全部")) !=0)
        sql.append(tr(" standard = '%1' and ").arg(ui->comboBox_standard->currentText()));
    if(ui->comboBox_type->currentText().compare(tr("全部")) !=0)
        sql.append(tr(" type = '%1' and ").arg(ui->comboBox_type->currentText()));
    sql.append(tr(" id is not NULL"));
    qDebug()<<sql;
    model->setFilter(sql);
}

void Storage::on_btn_close_clicked()
{
    emit closeStoragePage();
}

#include "elderbaseinfochoosedialog.h"
#include "ui_elderbaseinfochoosedialog.h"
#include<QSqlQuery>
#include<QTableWidgetItem>
#include<QSqlError>
#include<QDebug>

ElderBaseInfoChooseDialog::ElderBaseInfoChooseDialog(QWidget *parent,int pHealth,int pReside) :
    QDialog(parent),
    ui(new Ui::ElderBaseInfoChooseDialog),
    healthAssess(pHealth),
    resideRegister(pReside)
{
    ui->setupUi(this);
    initView();
}

ElderBaseInfoChooseDialog::~ElderBaseInfoChooseDialog()
{
    delete ui;
}

void ElderBaseInfoChooseDialog::initView(){
    QStringList header;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->hide();
    ui->comboBox_assess->setEnabled(false);
    ui->comboBox_reside->setEnabled(false);
    QString sql = tr("select eid,name,gender,cardType,cardNo from elder_info where eid is not NULL");
    if(healthAssess){
        ui->comboBox_assess->setCurrentIndex(ui->comboBox_assess->findText(tr("已评估")));
        sql.append(tr(" and healthAssess = 1"));
    }
    else{
        ui->comboBox_assess->setCurrentIndex(ui->comboBox_assess->findText(tr("未评估")));
        sql.append(tr(" and (healthAssess != 1 or healthAssess is NULL)"));
    }

    if(resideRegister){
        ui->comboBox_reside->setCurrentIndex(ui->comboBox_reside->findText(tr("已登记")));
        sql.append(tr(" and resideRegister = 1"));
    }
    else{
        ui->comboBox_reside->setCurrentIndex(ui->comboBox_reside->findText(tr("未登记")));
        sql.append(tr(" and (resideRegister != 1 or resideRegister is NULL)"));
    }

    QSqlQuery query(globaldb);   
    query.prepare(sql);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    qDebug()<<tr("query.size = %1").arg(query.size());
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(5);
    header<<"老人ID"<<"姓名"<<"性别"<<"证件类型"<<"证件号";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->setColumnWidth(1,80);
    ui->tableWidget->setColumnWidth(2,40);
    int i = 0;
    while(query.next()){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
//    ui->tableWidget->show();
    query.clear();
    query.finish();
    connect(ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void ElderBaseInfoChooseDialog::on_btn_clear_clicked()
{
    ui->lineEdit->setText(tr(""));
    ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(tr("全部")));    
}

void ElderBaseInfoChooseDialog::doubleClickRecord(QModelIndex index){
    QTableWidgetItem *item = ui->tableWidget->item(index.row(),0);
     qDebug()<<tr("item data is %1").arg(item->text());
    emit sendElderChoosed(item->text().toInt());
    this->accept();
}

void ElderBaseInfoChooseDialog::on_btn_search_clicked()
{
    ui->tableWidget->clearContents();
    QSqlQuery query(globaldb);
    QString sql = tr("select eid,name,gender,cardType,cardNo from elder_info where eid is not NULL");
    if(ui->lineEdit->text().compare(tr("")) != 0)
        sql.append(tr(" and name = '%1'").arg(ui->lineEdit->text()));
    if(ui->comboBox_gender->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and gender = '%1'").arg(ui->comboBox_gender->currentText()));
    if(ui->comboBox_assess->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox_assess->currentText().compare(tr("已评估")) == 0)
            sql.append(tr(" and healthAssess = 1"));
        else
            sql.append(tr(" and (healthAssess != 1 or healthAssess is NULL)"));
    }
    if(ui->comboBox_reside->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox_reside->currentText().compare(tr("已登记")) == 0)
            sql.append(tr(" and resideRegister = 1"));
        else
            sql.append(tr(" and (resideRegister != 1 or resideRegister is NULL)"));
    }
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
        ++i;
    }
    query.clear();
    query.finish();
}

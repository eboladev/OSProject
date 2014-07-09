#include "employeebaseinfochoosedialog.h"
#include "ui_employeebaseinfochoosedialog.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
extern QSqlDatabase globaldb;
EmployeeBaseInfoChooseDialog::EmployeeBaseInfoChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeBaseInfoChooseDialog)
{
    ui->setupUi(this);
    initView();
}

EmployeeBaseInfoChooseDialog::~EmployeeBaseInfoChooseDialog()
{
    delete ui;
}

void EmployeeBaseInfoChooseDialog::initView(){
    QStringList header;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->verticalHeader()->hide();
    QSqlQuery query(globaldb);
    query.prepare("select cardNo,name,gender,department,post from employee_info");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    qDebug()<<tr("query.size = %1").arg(query.size());
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(5);
    header<<"工号"<<"姓名"<<"性别"<<"部门"<<"职务";
    ui->tableWidget->setHorizontalHeaderLabels(header);
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
    query.clear();
    query.finish();
    connect(ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void EmployeeBaseInfoChooseDialog::doubleClickRecord(QModelIndex index){
    QTableWidgetItem *item = ui->tableWidget->item(index.row(),0);
     qDebug()<<tr("item data is %1").arg(item->text());
    emit sendEmployeeChoosed(item->text());
    this->accept();
}

void EmployeeBaseInfoChooseDialog::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
}

void EmployeeBaseInfoChooseDialog::on_btn_search_clicked()
{
    ui->tableWidget->clearContents();
    QSqlQuery query(globaldb);
    QString sql = tr("select cardNo,name,gender,department,post from employee_info where cardNo is not NULL");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and name = '%1'").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
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
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
    query.clear();
    query.finish();
}

#include "operationlog.h"
#include "ui_operationlog.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
OperationLog::OperationLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationLog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

OperationLog::~OperationLog()
{
    delete model;
    delete ui;
}

void OperationLog::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("operation_log");
    model->setHeaderData(model->fieldIndex("content"),Qt::Horizontal,tr("操作内容"));
    model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->select();
}

void OperationLog::initView(){
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
    ui->dateTimeEdit_start->setDate(QDate::currentDate().addDays(-1));
    ui->dateTimeEdit_end->setDate(QDate::currentDate().addDays(+1));
    ui->tableView->setColumnWidth(1,400);
}

void OperationLog::on_btn_clear_clicked()
{
    ui->lineEdit->setText(tr(""));
    ui->dateTimeEdit_start->setDate(QDate::currentDate().addDays(-1));
    ui->dateTimeEdit_end->setDate(QDate::currentDate().addDays(+1));
}

void OperationLog::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit->text().compare(tr("")) != 0)
        sql.append(tr(" operator = '%1' and ").arg(ui->lineEdit->text()));
    sql.append(tr("  operationTime >= '%1' and operationTime <= '%2'")
               .arg(ui->dateTimeEdit_start->dateTime().toString("yyyy-MM-dd H:mm:ss"))
               .arg(ui->dateTimeEdit_end->dateTime().toString("yyyy-MM-dd H:mm:ss")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void OperationLog::on_btn_close_clicked()
{
    emit closeOperationLogPage();
}

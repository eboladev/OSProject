#include "advicechoosedialog.h"
#include "ui_advicechoosedialog.h"
#include<QSqlQuery>
#include<QDate>
#include<QSqlError>
#include<QDebug>
#include<QTableWidgetItem>
AdviceChooseDialog::AdviceChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdviceChooseDialog)
{
    ui->setupUi(this);
    initView();
}

AdviceChooseDialog::~AdviceChooseDialog()
{
    delete ui;
}

void AdviceChooseDialog::initView(){
    ui->dateEdit_end->setDate(QDate::currentDate());
    ui->dateEdit_start->setDate(QDate::currentDate().addDays(-3));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->verticalHeader()->hide();
    QSqlQuery query(globaldb);
    query.prepare("select b.id,a.name,b.personInCharge,b.remark,b.occurenceDate from manage_info a,living_record b where a.cardNo = b.cardNo and b.item = 3");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    qDebug()<<tr("query.size = %1").arg(query.size());
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(5);
    QStringList header;
    header<<"医嘱Id"<<"老人"<<"医师"<<"医嘱内容"<<"医嘱日期";
    ui->tableWidget->setHorizontalHeaderLabels(header);
//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->setColumnWidth(1,60);
    ui->tableWidget->setColumnWidth(2,60);
    ui->tableWidget->setColumnWidth(3,500);
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

void AdviceChooseDialog::on_btn_clear_clicked()
{
    ui->lineEdit_doctor->setText(tr(""));
    ui->lineEdit_elder->setText(tr(""));
    ui->dateEdit_end->setDate(QDate::currentDate());
    ui->dateEdit_start->setDate(QDate::currentDate().addDays(-3));
}

void AdviceChooseDialog::on_btn_search_clicked()
{
    ui->tableWidget->clearContents();
    QSqlQuery query(globaldb);
    QString sql = tr("select b.id,a.name,b.personInCharge,b.remark,b.occurenceDate from manage_info a,living_record b where a.cardNo = b.cardNo and b.item = 3");
    if(ui->lineEdit_elder->text().compare(tr("")) != 0)
        sql.append(tr(" and a.name = '%1'").arg(ui->lineEdit_elder->text()));
    if(ui->lineEdit_doctor->text().compare(tr("")) != 0)
        sql.append(tr(" and b.personInCharge = '%1'").arg(ui->lineEdit_doctor->text()));
    sql.append(tr(" and b.occurenceDate >= '%1' and b.occurenceDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
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

void AdviceChooseDialog::doubleClickRecord(QModelIndex index){
    QTableWidgetItem *item = ui->tableWidget->item(index.row(),0);
     qDebug()<<tr("item data is %1").arg(item->text());
    emit sendAdviceChoosed(item->text().toInt());
    this->accept();
}

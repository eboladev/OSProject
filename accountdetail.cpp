#include "accountdetail.h"
#include "ui_accountdetail.h"
#include<QMessageBox>
#include<QDate>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
AccountDetail::AccountDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountDetail)
{
    ui->setupUi(this);
    initModel();
    initView();
}

AccountDetail::~AccountDetail()
{
    delete model;
    delete ui;
}

void AccountDetail::initModel(){
    model = new QStandardItemModel(this);
    model->setColumnCount(10);
    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("账户原"));
    model->setHeaderData(3,Qt::Horizontal,tr("账户新"));
    model->setHeaderData(4,Qt::Horizontal,tr("支付方式"));
    model->setHeaderData(5,Qt::Horizontal,tr("银行"));
    model->setHeaderData(6,Qt::Horizontal,tr("支票号"));
    model->setHeaderData(7,Qt::Horizontal,tr("备注"));
    model->setHeaderData(8,Qt::Horizontal,tr("操作员"));
    model->setHeaderData(9,Qt::Horizontal,tr("操作时间"));

}

void AccountDetail::initView(){
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth(0,90);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->setColumnWidth(5,150);
    ui->tableView->setColumnWidth(6,150);
    ui->tableView->setColumnWidth(7,170);
    ui->tableView->setColumnWidth(8,80);
    ui->tableView->setColumnWidth(9,150);
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
}

void AccountDetail::on_btn_close_clicked()
{
    emit closeAccountDetailPage();
}

void AccountDetail::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void AccountDetail::on_btn_search_clicked()
{
    QSqlQuery query(globaldb);
    QString sql=tr("select a.cardNo,b.name,a.accountOld,a.accountNew,a.payType,a.bank,a.checkNo,"
                   "a.remark,a.operator,a.operationTime from account_record a,manage_info b where a.cardNo = b.cardNo");
    sql.append(tr(" and a.operationTime>='%1' and a.operationTime<='%2' ").arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
                                                                                                                                                     .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and b.name = '%1'").arg(ui->lineEdit_name->text()));
    sql.append(tr(" order by a.operationTime desc"));
    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    model->removeRows(0,model->rowCount());
    int i=0;
    while(query.next()){
        model->setItem(i,0,new QStandardItem(query.value(0).toString()));
        model->setItem(i,1,new QStandardItem(query.value(1).toString()));
        model->setItem(i,2,new QStandardItem(query.value(2).toString()));
        model->setItem(i,3,new QStandardItem(query.value(3).toString()));
        model->setItem(i,4,new QStandardItem(query.value(4).toString()));
        model->setItem(i,5,new QStandardItem(query.value(5).toString()));
        model->setItem(i,6,new QStandardItem(query.value(6).toString()));
        model->setItem(i,7,new QStandardItem(query.value(7).toString()));
        model->setItem(i,8,new QStandardItem(query.value(8).toString()));
        model->setItem(i,9,new QStandardItem(query.value(9).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
        ++i;
    }
}

void AccountDetail::on_toolButton_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void AccountDetail::doubleClickRecord(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name from manage_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_cardNo->setText(cardNo);
        ui->lineEdit_name->setText(query.value(0).toString());
    }
    query.clear();
    query.finish();
}

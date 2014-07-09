#include "recedesettle.h"
#include "ui_recedesettle.h"
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
#include<QDate>
#include "settlestatusdelegate.h"
#include "dictionary.h"
extern QString operatorId;
RecedeSettle::RecedeSettle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecedeSettle)
{
    ui->setupUi(this);
    initModel();
    initView();
}

RecedeSettle::~RecedeSettle()
{
    delete model;
    delete ui;
}

void RecedeSettle::initModel(){
    model = new QStandardItemModel(this);
    model->setColumnCount(13);
    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("状态"));
    model->setHeaderData(3,Qt::Horizontal,tr("床位费"));
    model->setHeaderData(4,Qt::Horizontal,tr("护理费"));
    model->setHeaderData(5,Qt::Horizontal,tr("特殊服务费"));
    model->setHeaderData(6,Qt::Horizontal,tr("阶段性费用"));
    model->setHeaderData(7,Qt::Horizontal,tr("总费用"));
    model->setHeaderData(8,Qt::Horizontal,tr("退住日期"));
    model->setHeaderData(9,Qt::Horizontal,tr("对应月份"));
    model->setHeaderData(10,Qt::Horizontal,tr("结算日期"));
    model->setHeaderData(11,Qt::Horizontal,tr("操作员"));
    model->setHeaderData(12,Qt::Horizontal,tr("操作时间"));
    QSqlQuery query(globaldb);
    QString sql = "select a.cardNo,a.name,b.isSettled,b.bedCost,b.nurseCost,b.specialCost,b.stageCost,b.monthlyCost,"
            "a.outDate,b.mapMonth,b.settleDate,b.operator,b.operationTime from manage_info a,settle_account b "
            "where a.cardNo = b.cardNo and a.status = 3 and a.outDate = b.mapMonth";
    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
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
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("yyyy-MM-dd")));
        model->setItem(i,9,new QStandardItem(query.value(9).toDate().toString("yyyy-MM")));
        model->setItem(i,10,new QStandardItem(query.value(10).toDate().toString("yyyy-MM-dd")));
        model->setItem(i,11,new QStandardItem(query.value(11).toString()));
        model->setItem(i,12,new QStandardItem(query.value(12).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
        ++i;
    }
}

void RecedeSettle::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("recede_settle_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_settle->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();    
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setItemDelegateForColumn(2,new SettleStatusDelegate(this));
}

void RecedeSettle::on_btn_settle_clicked()
{
    dialog = new RecedeSettleDialog(this,model,ui->tableView->currentIndex().row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(on_btn_search_clicked()));
    dialog->exec();
}

void RecedeSettle::on_btn_close_clicked()
{
    emit closeRecedeSettlePage();
}

void RecedeSettle::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("全部")));
}

void RecedeSettle::on_btn_search_clicked()
{
    QSqlQuery query(globaldb);
    QString sql = "select a.cardNo,a.name,b.isSettled,b.bedCost,b.nurseCost,b.specialCost,b.stageCost,b.monthlyCost,"
            "a.outDate,b.mapMonth,b.settleDate,b.operator,b.operationTime from manage_info a,settle_account b "
            "where a.cardNo = b.cardNo and a.status = 3 and a.outDate = b.mapMonth";
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and a.name = '%1'").arg(ui->lineEdit_name->text()));
    if(ui->comboBox->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox->currentText().compare("已结算") == 0)
            sql.append(tr(" and b.isSettled = 1"));
        else
            sql.append(tr(" and b.isSettled = 0"));
    }
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
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("yyyy-MM-dd")));
        model->setItem(i,9,new QStandardItem(query.value(9).toDate().toString("yyyy-MM")));
        model->setItem(i,10,new QStandardItem(query.value(10).toDate().toString("yyyy-MM-dd")));
        model->setItem(i,11,new QStandardItem(query.value(11).toString()));
        model->setItem(i,12,new QStandardItem(query.value(12).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
        ++i;
    }
}

void RecedeSettle::doubleClickRecord(QModelIndex index){
    dialog = new RecedeSettleDialog(this,model,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(on_btn_search_clicked()));
    dialog->exec();
}

void RecedeSettle::on_toolButton_clicked()
{
    chooseDialog = new ManageInfoChooseDialog(this);
    connect(chooseDialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    chooseDialog->exec();
}

void RecedeSettle::doubleClickRecord(QString cardNo){
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

#include "monthlysettledialog.h"
#include "ui_monthlysettledialog.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>
#include<QDateTime>
#include "dictionary.h"
extern QString operatorId;
MonthlySettleDialog::MonthlySettleDialog(QWidget *parent,QStandardItemModel *pModel,int pIndex) :
    QDialog(parent),
    ui(new Ui::MonthlySettleDialog),
    model(pModel),
    index(pIndex)
{
    ui->setupUi(this);
    initModel();
    initView();
}

MonthlySettleDialog::~MonthlySettleDialog()
{
    delete modelBed;
    delete modelNurse;
    delete modelSpecial;
    delete modelStage;
    delete ui;
}

void MonthlySettleDialog::initModel(){
    QString cardNo = model->item(index,0)->data(Qt::DisplayRole).toString();
    ui->lineEdit_account->setText(tr("%1").arg(getElderAccountByCardNo(cardNo)));
    QString date = model->item(index,8)->data(Qt::DisplayRole).toString();
    qDebug()<<tr("%1  %2 %3").arg(cardNo).arg(date).arg(index);
    modelBed = new QStandardItemModel(this);
    modelBed->setColumnCount(2);
    modelBed->setHeaderData(0,Qt::Horizontal,tr("说明"));
    modelBed->setHeaderData(1,Qt::Horizontal,tr("费用"));
    QSqlQuery query(globaldb);
    query.prepare("select item,cost from cost_detail where cardNo = ? and SUBSTRING(costDate,1,7) = ? and  costType = 1");
    query.addBindValue(cardNo);
    query.addBindValue(date);
    query.exec();
    int i=0;
    while(query.next()){
        modelBed->setItem(i,0,new QStandardItem(query.value(0).toString()));
        modelBed->setItem(i,1,new QStandardItem(query.value(1).toString()));
        ++i;
    }
    query.finish();

    modelNurse = new QStandardItemModel(this);
    modelNurse->setColumnCount(2);
    modelNurse->setHeaderData(0,Qt::Horizontal,tr("说明"));
    modelNurse->setHeaderData(1,Qt::Horizontal,tr("费用"));
    query.prepare("select item,cost from cost_detail where cardNo = ? and SUBSTRING(costDate,1,7) = ? and  costType = 2");
    query.addBindValue(cardNo);
    query.addBindValue(date);
    query.exec();
    i=0;
    while(query.next()){
        modelNurse->setItem(i,0,new QStandardItem(query.value(0).toString()));
        modelNurse->setItem(i,1,new QStandardItem(query.value(1).toString()));
        ++i;
    }

    modelSpecial = new QStandardItemModel(this);
    modelSpecial->setColumnCount(2);
    modelSpecial->setHeaderData(0,Qt::Horizontal,tr("说明"));
    modelSpecial->setHeaderData(1,Qt::Horizontal,tr("费用"));
    query.prepare("select item,cost from cost_detail where cardNo = ? and SUBSTRING(costDate,1,7) = ? and  costType = 3");
    query.addBindValue(cardNo);
    query.addBindValue(date);
    query.exec();
    i=0;
    while(query.next()){
        modelSpecial->setItem(i,0,new QStandardItem(query.value(0).toString()));
        modelSpecial->setItem(i,1,new QStandardItem(query.value(1).toString()));
        ++i;
    }

    modelStage = new QStandardItemModel(this);
    modelStage->setColumnCount(2);
    modelStage->setHeaderData(0,Qt::Horizontal,tr("说明"));
    modelStage->setHeaderData(1,Qt::Horizontal,tr("费用"));
    query.prepare("select item,cost from cost_detail where cardNo = ? and SUBSTRING(costDate,1,7) = ? and  costType = 4");
    query.addBindValue(cardNo);
    query.addBindValue(date);
    query.exec();
    i=0;
    while(query.next()){
        modelStage->setItem(i,0,new QStandardItem(query.value(0).toString()));
        modelStage->setItem(i,1,new QStandardItem(query.value(1).toString()));
        ++i;
    }
}

void MonthlySettleDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("monthly_settle_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_settle->setEnabled(false);
    ui->lineEdit_name->setText(model->item(index,1)->data(Qt::DisplayRole).toString());
    ui->comboBox->setEnabled(false);    
    if(model->item(index,2)->data(Qt::DisplayRole).toInt())
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("已结算")));
    else
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("未结算")));
    if(ui->comboBox->currentText().compare(tr("已结算")) == 0)
        ui->btn_settle->setEnabled(false);
    ui->lineEdit_bedCost->setText(model->item(index,3)->data(Qt::DisplayRole).toString());
    ui->lineEdit_nurseCost->setText(model->item(index,4)->data(Qt::DisplayRole).toString());
    ui->lineEdit_SpecialCost->setText(model->item(index,5)->data(Qt::DisplayRole).toString());
    ui->lineEdit_stageCost->setText(model->item(index,6)->data(Qt::DisplayRole).toString());
    ui->lineEdit_totalCost->setText(model->item(index,7)->data(Qt::DisplayRole).toString());
    ui->tableView_bed->setModel(modelBed);
    ui->tableView_bed->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_bed->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_bed->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_bed->resizeColumnsToContents();
    ui->tableView_bed->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView_bed->verticalHeader()->hide();
    ui->tableView_bed->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_bed->setColumnWidth(0,310);
    ui->tableView_bed->setAlternatingRowColors(true);
    ui->tableView_bed->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");

    ui->tableView_nurse->setModel(modelNurse);
    ui->tableView_nurse->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_nurse->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_nurse->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_nurse->resizeColumnsToContents();
    ui->tableView_nurse->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView_nurse->verticalHeader()->hide();
    ui->tableView_nurse->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_nurse->setColumnWidth(0,310);
    ui->tableView_nurse->setAlternatingRowColors(true);
    ui->tableView_nurse->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");

    ui->tableView_special->setModel(modelSpecial);
    ui->tableView_special->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_special->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_special->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_special->resizeColumnsToContents();
    ui->tableView_special->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView_special->verticalHeader()->hide();
    ui->tableView_special->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_special->setColumnWidth(0,310);
    ui->tableView_special->setAlternatingRowColors(true);
    ui->tableView_special->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");

    ui->tableView_stage->setModel(modelStage);
    ui->tableView_stage->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_stage->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_stage->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_stage->resizeColumnsToContents();
    ui->tableView_stage->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView_stage->verticalHeader()->hide();
    ui->tableView_stage->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_stage->setColumnWidth(0,310);
    ui->tableView_stage->setAlternatingRowColors(true);
    ui->tableView_stage->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
}

void MonthlySettleDialog::on_btn_settle_clicked()
{
    float account = ui->lineEdit_account->text().toFloat();
    float cost = ui->lineEdit_totalCost->text().toFloat();
    QString cardNo = model->item(index,0)->data(Qt::DisplayRole).toString();
    if(account<cost){
        QMessageBox::warning(0,"警告","账户余额不足，无法结算","确定");
        return;
    }
    else{
        if(QSqlDatabase::database().transaction()){
            QSqlQuery query(globaldb);
            query.prepare("insert into account_record (id,cardNo,accountOld,accountNew,remark,operator,operationTime) values(NULL,?,?,?,?,?,?)");
            query.addBindValue(cardNo);
            query.addBindValue(account);
            query.addBindValue(account - cost);
            query.addBindValue(tr("月费用结算，扣除费用%1").arg(cost));
            query.addBindValue(tr("system"));
            query.addBindValue(QDateTime::currentDateTime());
            query.exec();
            query.finish();
            query.prepare("update manage_info set account =account - ? where cardNo = ?");
            query.addBindValue(cost);
            query.addBindValue(cardNo);
            query.exec();
            if(query.lastError().isValid())
                qDebug()<<query.lastError();
            query.finish();
            query.prepare("update settle_account set isSettled = 1,settleDate = ? where SUBSTRING(mapMonth,1,7) = ?");
            query.addBindValue(QDate::currentDate());
            query.addBindValue(model->item(index,8)->data(Qt::DisplayRole).toString());
            query.exec();
            if(query.lastError().isValid())
                qDebug()<<query.lastError();
            query.finish();
            query.clear();
            if(!QSqlDatabase::database().commit()){
                qDebug()<<QSqlDatabase::database().lastError();
                if(!QSqlDatabase::database().rollback())
                    qDebug()<<QSqlDatabase::database().lastError();
            }
        }
    }
    this->accept();
}

float MonthlySettleDialog::getElderAccountByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select account from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    float account = 0;
    if(query.first())
        account = query.value(0).toFloat();
    query.finish();
    query.clear();
    return account;
}

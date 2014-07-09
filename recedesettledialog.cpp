#include "recedesettledialog.h"
#include "ui_recedesettledialog.h"
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QDateTime>
#include "dictionary.h"
extern QString operatorId;
RecedeSettleDialog::RecedeSettleDialog(QWidget *parent,QStandardItemModel *pModel,int pIndex) :
    QDialog(parent),
    ui(new Ui::RecedeSettleDialog),
    model(pModel),
    index(pIndex)
{
    ui->setupUi(this);
    initModel();
    initView();
}

RecedeSettleDialog::~RecedeSettleDialog()
{
    delete modelBed;
    delete modelNurse;
    delete modelSpecial;
    delete modelStage;
    delete ui;
}

void RecedeSettleDialog::initModel(){
    QString cardNo = model->item(index,0)->data(Qt::DisplayRole).toString();
    ui->lineEdit_account->setText(tr("%1").arg(getElderAccountByCardNo(cardNo)));
    QString date = model->item(index,9)->data(Qt::DisplayRole).toString();
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

void RecedeSettleDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("recede_settle_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_save->setEnabled(false);
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->radioButton_cash,0);
    buttonGroup->addButton(ui->radioButton_card,1);
    buttonGroup->addButton(ui->radioButton_bank,2);
    buttonGroup->addButton(ui->radioButton_check,3);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(btnJudge(int)));
    ui->radioButton_cash->setChecked(true);
    ui->label_bank->setVisible(false);
    ui->lineEdit_bank->setVisible(false);
    ui->label_check->setVisible(false);
    ui->lineEdit_check->setVisible(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_name->setText(model->item(index,1)->data(Qt::DisplayRole).toString());
    ui->dateEdit->setDate(model->item(index,8)->data(Qt::DisplayRole).toDate());
    ui->comboBox->setEnabled(false);
    if(model->item(index,2)->data(Qt::DisplayRole).toInt())
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("已结算")));
    else
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("未结算")));
    if(ui->comboBox->currentText().compare(tr("已结算")) == 0)
        ui->btn_save->setEnabled(false);
    ui->lineEdit_bed->setText(model->item(index,3)->data(Qt::DisplayRole).toString());
    ui->lineEdit_nurse->setText(model->item(index,4)->data(Qt::DisplayRole).toString());
    ui->lineEdit_special->setText(model->item(index,5)->data(Qt::DisplayRole).toString());
    ui->lineEdit_stage->setText(model->item(index,6)->data(Qt::DisplayRole).toString());
    ui->lineEdit_total->setText(model->item(index,7)->data(Qt::DisplayRole).toString());
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
    if(ui->comboBox->currentText().compare(tr("未结算")) == 0){
        if(ui->lineEdit_total->text().toFloat() > ui->lineEdit_account->text().toFloat()){
            ui->groupBox_back->setVisible(false);
            ui->lineEdit_pay->setText(tr("%1").arg(ui->lineEdit_total->text().toFloat()-ui->lineEdit_account->text().toFloat()));
        }
        else{
            ui->groupBox_pay->setVisible(false);
            ui->lineEdit_back->setText(tr("%1").arg(ui->lineEdit_account->text().toFloat()-ui->lineEdit_total->text().toFloat()));
        }
    }
    else{
        ui->groupBox_back->setVisible(false);
        ui->groupBox_pay->setVisible(false);
    }
}

void RecedeSettleDialog::on_btn_save_clicked()
{
    if(QSqlDatabase::database().transaction()){
        QSqlQuery query(globaldb);
        query.prepare("update manage_info set account = 0 where cardNo = ?");
        query.addBindValue(model->item(index,0)->data(Qt::DisplayRole).toString());
        query.exec();
        query.prepare("update settle_account set isSettled = 1,settleDate = ? where cardNo = ? and mapMonth = ?");
        query.addBindValue(QDate::currentDate());
        query.addBindValue(model->item(index,0)->data(Qt::DisplayRole).toString());
        query.addBindValue(model->item(index,8)->data(Qt::DisplayRole).toDate().toString("yyyy-MM-dd"));
        query.exec();
        if(!QSqlDatabase::database().commit()){
            qDebug()<<QSqlDatabase::database().lastError();
            if(!QSqlDatabase::database().rollback())
                qDebug()<<QSqlDatabase::database().lastError();
        }
    }
    this->accept();
}

void RecedeSettleDialog::on_btn_cancel_clicked()
{
    this->reject();
}

float RecedeSettleDialog::getElderAccountByCardNo(QString cardNo){
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

void RecedeSettleDialog::btnJudge(int id){
    switch(id){
    case 0:ui->label_bank->setVisible(false);ui->lineEdit_bank->setVisible(false); ui->label_check->setVisible(false);ui->lineEdit_check->setVisible(false);break;
    case 1:ui->label_bank->setVisible(true);ui->lineEdit_bank->setVisible(true); ui->label_check->setVisible(false);ui->lineEdit_check->setVisible(false);break;
    case 2:ui->label_bank->setVisible(true);ui->lineEdit_bank->setVisible(true); ui->label_check->setVisible(false);ui->lineEdit_check->setVisible(false);break;
    case 3:ui->label_bank->setVisible(true);ui->lineEdit_bank->setVisible(true); ui->label_check->setVisible(true);ui->lineEdit_check->setVisible(true);break;
    default:break;
    }
}

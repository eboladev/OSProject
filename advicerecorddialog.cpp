#include "advicerecorddialog.h"
#include "ui_advicerecorddialog.h"
#include<QDate>
#include<QDateTime>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QSqlRecord>
#include "dictionary.h"
extern QString operatorId;
AdviceRecordDialog::AdviceRecordDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::AdviceRecordDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

AdviceRecordDialog::~AdviceRecordDialog()
{
    delete ui;
}

void AdviceRecordDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("advice_record_toolbutton",operatorId);
    if(!list.contains(tr("ÐÞ¸Ä")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    if(this->index != -1){
        QSqlRecord record = model->record(index);
        QSqlQuery query(globaldb);
        query.prepare("select a.name,b.cardNo,b.personInCharge,b.healthStatus,b.occurenceDate,b.remark,b.operator,"
                      "b.operationTime from manage_info a,living_record b where a.cardNo = b.cardNo and b.item = 3 and b.id = ?");
        query.addBindValue(record.value("id").toInt());
        query.exec();
        if(query.first()){
            ui->lineEdit_name->setText(query.value(0).toString());
            ui->lineEdit_cardNo->setText(query.value(1).toString());
            ui->lineEdit_doctor->setText(query.value(2).toString());
            ui->lineEdit_healthStatus->setText(query.value(3).toString());
            ui->dateEdit->setDate(query.value(4).toDate());
            ui->textEdit->setText(query.value(5).toString());
            ui->lineEdit_operator->setText(query.value(6).toString());
            ui->dateTimeEdit->setDateTime(query.value(7).toDateTime());
        }
        query.finish();
        query.clear();
    }
}

void AdviceRecordDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into living_record (id,cardNo,occurenceDate,healthStatus,personInCharge,remark,operator,operationTime,item)  values (NULL,?,?,?,?,?,?,?,?)");
    }
    else{
        query.prepare("update living_record set cardNo = ?,occurenceDate = ?,healthStatus = ?, personInCharge =?,remark=?,operator=?,operationTime=? where id = ?");
    }
    query.addBindValue(ui->lineEdit_cardNo->text());
    query.addBindValue(ui->dateEdit->date());
    query.addBindValue(ui->lineEdit_healthStatus->text());
    query.addBindValue(ui->lineEdit_doctor->text());
    query.addBindValue(ui->textEdit->toPlainText());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit->dateTime());
    if(this->isAdd)
        query.addBindValue(3);
    if(!this->isAdd){
        QSqlRecord record = model->record(index);
         query.addBindValue(record.value("id").toInt());
    }
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
    this->accept();
}

void AdviceRecordDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void AdviceRecordDialog::on_toolButton_cardNo_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void AdviceRecordDialog::on_toolButton_doctor_clicked()
{
    dialogEmployee = new EmployeeBaseInfoChooseDialog(this);
    connect(dialogEmployee,SIGNAL(sendEmployeeChoosed(QString)),this,SLOT(doubleClickEmployee(QString)));
    dialogEmployee->exec();
}

void AdviceRecordDialog::doubleClickRecord(QString cardNo){
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

void AdviceRecordDialog::doubleClickEmployee(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name from employee_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_doctor->setText(query.value(0).toString());
    }
    query.clear();
    query.finish();
}

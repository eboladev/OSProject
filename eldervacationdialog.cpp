#include "eldervacationdialog.h"
#include "ui_eldervacationdialog.h"
#include<QDate>
#include<QDateTime>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlError>
#include<QDebug>
#include "dictionary.h"
extern QString operatorId;
ElderVacationDialog::ElderVacationDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::ElderVacationDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

ElderVacationDialog::~ElderVacationDialog()
{
    delete ui;
}

void ElderVacationDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("elder_vacation_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateEdit_back->setDate(QDate::currentDate());
    ui->dateEdit_leave->setDate(QDate::currentDate());
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    if(this->isAdd)
        ui->dateEdit_back->setEnabled(false);
    if(this->index != -1){
        QSqlRecord record = model->record(index);
        QSqlQuery query(globaldb);
        query.prepare("select a.name,b.cardNo,b.status,b.leaveDate,b.backDate,b.auditor,b.remark,b.operator,"
                      "b.operationTime from manage_info a,elder_vacation b where a.cardNo = b.cardNo and b.id = ?");
        query.addBindValue(record.value("id").toInt());
        query.exec();
        if(query.first()){
            ui->lineEdit_name->setText(query.value(0).toString());
            ui->lineEdit_cardNo->setText(query.value(1).toString());
            if(query.value(2).toInt() == 1)
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("已请假")));
            else{
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("已销假")));
                ui->comboBox->setEnabled(false);
            }
            ui->dateEdit_leave->setDate(query.value(3).toDate());
            ui->dateEdit_back->setDate(query.value(4).toDate());
            ui->lineEdit_auditor->setText(query.value(5).toString());
            ui->textEdit->setText(query.value(6).toString());
            ui->lineEdit_operator->setText(query.value(7).toString());
            ui->dateTimeEdit->setDateTime(query.value(8).toDateTime());
        }
        query.finish();
        query.clear();
    }
}

void ElderVacationDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into elder_vacation (id,cardNo,status,leaveDate,backDate,auditor,remark,operator,operationTime)  values (NULL,?,?,?,?,?,?,?,?)");
    }
    else{
        query.prepare("update elder_vacation set cardNo = ?,status = ?,leaveDate = ?, backDate =?,auditor = ?,remark=?,operator=?,operationTime=? where id = ?");
    }
    query.addBindValue(ui->lineEdit_cardNo->text());
    if(ui->comboBox->currentText().compare(tr("已请假")) == 0)
        query.addBindValue(1);
    else
        query.addBindValue(2);
    query.addBindValue(ui->dateEdit_leave->date());
    if(this->isAdd || ui->comboBox->currentText().compare(tr("已请假"))==0)
        query.addBindValue(NULL);
    else
        query.addBindValue(ui->dateEdit_back->date());
    query.addBindValue(ui->lineEdit_auditor->text());
    query.addBindValue(ui->textEdit->toPlainText());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit->dateTime());
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

void ElderVacationDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void ElderVacationDialog::on_toolButton_cardNo_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void ElderVacationDialog::on_toolButton_auditor_clicked()
{
    dialogEmployee = new EmployeeBaseInfoChooseDialog(this);
    connect(dialogEmployee,SIGNAL(sendEmployeeChoosed(QString)),this,SLOT(doubleClickEmployee(QString)));
    dialogEmployee->exec();
}

void ElderVacationDialog::doubleClickRecord(QString cardNo){
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

void ElderVacationDialog::doubleClickEmployee(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name from employee_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_auditor->setText(query.value(0).toString());
    }
    query.clear();
    query.finish();
}

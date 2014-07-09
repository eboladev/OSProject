#include "employeebaseinfodialog.h"
#include "ui_employeebaseinfodialog.h"
#include<QSqlRecord>
#include<QMessageBox>
#include<QDateTime>
#include<QDebug>
#include "dictionary.h"
extern QString operatorId;
EmployeeBaseInfoDialog::EmployeeBaseInfoDialog(QWidget *parent,QSqlTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),    
    ui(new Ui::EmployeeBaseInfoDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

EmployeeBaseInfoDialog::~EmployeeBaseInfoDialog()
{
    delete ui;
}

void EmployeeBaseInfoDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("employee_info_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    qDebug()<<operatorId;
    ui->comboBox_computer->addItems(Dictionary::getAttributeValues(tr("计算机水平")));
    ui->comboBox_degree->addItems(Dictionary::getAttributeValues(tr("学历")));
    ui->comboBox_department->addItems(Dictionary::getAttributeValues(tr("部门")));
    ui->comboBox_english->addItems(Dictionary::getAttributeValues(tr("英语水平")));
    ui->comboBox_post->addItems(Dictionary::getAttributeValues(tr("职务")));
    ui->dateTimeEdit_operationTime->setDateTime(QDateTime::currentDateTime());
    if(this->index != -1){
        QSqlRecord record = model ->record(this->index);
        ui->lineEdit_address->setText(record.value("address").toString());
        ui->lineEdit_cardNo->setText(record.value("cardNo").toString());
        ui->lineEdit_identityNo->setText(record.value("identityNo").toString());
        ui->lineEdit_major->setText(record.value("major").toString());
        ui->lineEdit_name->setText(record.value("name").toString());
        ui->lineEdit_operator->setText(record.value("operator").toString());
        ui->lineEdit_remark->setText(record.value("remark").toString());
        ui->lineEdit_residence->setText(record.value("residence").toString());
        ui->lineEdit_school->setText(record.value("school").toString());
        ui->lineEdit_telephone->setText(record.value("telephone").toString());
        ui->lineEdit_zipCode->setText(record.value("zipCode").toString());
        ui->comboBox_computer->setCurrentIndex(ui->comboBox_computer->findText(record.value("computer").toString()));
        ui->comboBox_degree->setCurrentIndex(ui->comboBox_degree->findText(record.value("degree").toString()));
        ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(record.value("department").toString()));
        ui->comboBox_english->setCurrentIndex(ui->comboBox_english->findText(record.value("english").toString()));
        ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(record.value("gender").toString()));
        ui->comboBox_identityType->setCurrentIndex(ui->comboBox_identityType->findText(record.value("identityType").toString()));
        ui->comboBox_maritalStatus->setCurrentIndex(ui->comboBox_maritalStatus->findText(record.value("maritalStatus").toString()));
        ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(record.value("post").toString()));
        ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(record.value("status").toString()));
        ui->dateEdit_birthday->setDate(record.value("birthday").toDate());
        ui->dateEdit_entryDate->setDate(record.value("entryDate").toDate());
        ui->dateTimeEdit_operationTime->setDateTime(record.value("operationTime").toDateTime());
    }
}

void EmployeeBaseInfoDialog::on_btn_save_clicked()
{
    QSqlRecord record;
    if(this->isAdd)
         record = model->record();
    else
        record = model->record(this->index);

    record.setValue("cardNo",ui->lineEdit_cardNo->text());
    record.setValue("name",ui->lineEdit_name->text());
    record.setValue("gender",ui->comboBox_gender->currentText());
    record.setValue("identityType",ui->comboBox_identityType->currentText());
    record.setValue("identityNo",ui->lineEdit_identityNo->text());
    record.setValue("status",ui->comboBox_status->currentText());
    record.setValue("birthday",ui->dateEdit_birthday->date());
    record.setValue("maritalStatus",ui->comboBox_maritalStatus->currentText());
    record.setValue("department",ui->comboBox_department->currentText());
    record.setValue("post",ui->comboBox_post->currentText());
    record.setValue("degree",ui->comboBox_degree->currentText());
    record.setValue("school",ui->lineEdit_school->text());
    record.setValue("major",ui->lineEdit_major->text());
    record.setValue("english",ui->comboBox_english->currentText());
    record.setValue("computer",ui->comboBox_computer->currentText());
    record.setValue("residence",ui->lineEdit_residence->text());
    record.setValue("entryDate",ui->dateEdit_entryDate->date());
    record.setValue("telephone",ui->lineEdit_telephone->text());
    record.setValue("address",ui->lineEdit_address->text());
    record.setValue("zipCode",ui->lineEdit_zipCode->text());
    record.setValue("remark",ui->lineEdit_remark->text());
    record.setValue("operator",ui->lineEdit_operator->text());
    record.setValue("operationTime",ui->dateTimeEdit_operationTime->dateTime());

    if(this->isAdd){
        if(!model->insertRecord(-1,record)){
            QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
            this->accept();
        }
    }
    else{
        if(!model->setRecord(this->index,record)){
                QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
               model->submitAll();
                this->accept();
        }
    }
}

void EmployeeBaseInfoDialog::on_btn_cancel_clicked()
{
    this->reject();
}

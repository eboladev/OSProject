#include "checkindialog.h"
#include "ui_checkindialog.h"
#include<QDateTime>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>
#include<QSqlRecord>
#include<QDate>
#include "dictionary.h"
extern QSqlDatabase globaldb;
extern QString operatorId;
CheckInDialog::CheckInDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::CheckInDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

CheckInDialog::~CheckInDialog()
{
    delete ui;
}

void CheckInDialog::initView(){
    ui->dateEdit_inDate->setDate(QDate::currentDate());
    ui->lineEdit_operator->setText(operatorId);
    ui->comboBox_standard->addItems(Dictionary::getAttributeValues(tr("物资规格")));
    ui->comboBox_type->addItems(Dictionary::getAttributeValues(tr("物资分类")));
    ui->comboBox_unit->addItems(Dictionary::getAttributeValues(tr("物资单位")));
    ui->comboBox_warehouse->addItems(Dictionary::getAttributeValues(tr("仓库名")));
    ui->dateTimeEdit_operationTime->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_buyer->setEnabled(false);
    ui->lineEdit_cardNo->setEnabled(false);
    ui->comboBox_gender->setEnabled(false);
    ui->comboBox_department->setEnabled(false);
    ui->comboBox_post->setEnabled(false);
    if(!isAdd){
        ui->toolButton->setEnabled(false);
        ui->comboBox_standard->setEnabled(false);
        ui->comboBox_type->setEnabled(false);
        ui->comboBox_unit->setEnabled(false);
        ui->comboBox_warehouse->setEnabled(false);
        ui->lineEdit_amount->setEnabled(false);
        ui->lineEdit_auditor->setEnabled(false);
        ui->lineEdit_name->setEnabled(false);
        ui->lineEdit_operator->setEnabled(false);
        ui->lineEdit_provider->setEnabled(false);
        ui->lineEdit_rate->setEnabled(false);
        ui->dateEdit_inDate->setEnabled(false);
        ui->dateTimeEdit_operationTime->setEnabled(false);
    }

    if(this->index != -1){
        QSqlRecord record = model->record(index);
        int id = record.value("id").toInt();
        qDebug()<<record.value("id").toString();
        QSqlQuery query(globaldb);
        query.prepare("select a.cardNo,a.name,a.department,a.gender,a.post,b.amount,"
                      "b.auditor,b.inDate,b.name,b.operationTime,b.operator,b.provider,b.rate,"
                      "b.standard,b.type,b.unit,b.warehouse from employee_info a,check_in b where a.cardNo = b.buyer and b.id = ?");
        query.addBindValue(id);
        query.exec();
        if(query.size()>1){
            QMessageBox::warning(0,tr(" 警告"),tr("数据查询出错"));
        }
        if(query.lastError().isValid())
            qDebug()<<query.lastError();

        if(query.first()){
            ui->lineEdit_cardNo->setText(query.value(0).toString());
            ui->lineEdit_buyer->setText(query.value(1).toString());
            ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(query.value(2).toString()));
            ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(3).toString()));
            ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(query.value(4).toString()));
            ui->lineEdit_amount->setText(query.value(5).toString());
            ui->lineEdit_auditor->setText(query.value(6).toString());
            ui->dateEdit_inDate->setDate(query.value(7).toDate());
            ui->lineEdit_name->setText(query.value(8).toString());
            ui->dateTimeEdit_operationTime->setDateTime(query.value(9).toDateTime());
            ui->lineEdit_operator->setText(query.value(10).toString());
            ui->lineEdit_provider->setText(query.value(11).toString());
            ui->lineEdit_rate->setText(query.value(12).toString());
            ui->comboBox_standard->setCurrentIndex(ui->comboBox_standard->findText(query.value(13).toString()));
            ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(query.value(14).toString()));
            ui->comboBox_unit->setCurrentIndex(ui->comboBox_unit->findText(query.value(15).toString()));
            ui->comboBox_warehouse->setCurrentIndex(ui->comboBox_warehouse->findText(query.value(16).toString()));
        }
        query.clear();
        query.finish();
    }
}

void CheckInDialog::on_pushButton_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into check_in values (NULL,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit_cardNo->text());
    }
    else{
        query.prepare("update check_in set type = ?,name = ?,standard = ?, unit =?,rate=?,amount=?,provider=?,"
                      "warehouse=?,inDate=?,auditor=?,operator=?,operationTime=?");
    }
    query.addBindValue(ui->comboBox_type->currentText());
    query.addBindValue(ui->lineEdit_name->text());
    query.addBindValue(ui->comboBox_standard->currentText());
    query.addBindValue(ui->comboBox_unit->currentText());
    query.addBindValue(ui->lineEdit_rate->text().toFloat());
    query.addBindValue(ui->lineEdit_amount->text().toInt());
    query.addBindValue(ui->lineEdit_provider->text());
    query.addBindValue(ui->comboBox_warehouse->currentText());
    query.addBindValue(ui->dateEdit_inDate->date());
    query.addBindValue(ui->lineEdit_auditor->text());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());

    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();

    query.finish();
    query.prepare("select count(*) from storage where type = ? and name = ? and standard = ? and unit = ? and rate = ? and warehouse = ? and provider = ?");
    query.addBindValue(ui->comboBox_type->currentText());
    query.addBindValue(ui->lineEdit_name->text());
    query.addBindValue(ui->comboBox_standard->currentText());
    query.addBindValue(ui->comboBox_unit->currentText());
    query.addBindValue(ui->lineEdit_rate->text().toFloat());
    query.addBindValue(ui->comboBox_warehouse->currentText());
    query.addBindValue(ui->lineEdit_provider->text());
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();

    int i=0;
    if(query.first())
        i=query.value(0).toInt();
    query.finish();
    if(this->isAdd){
        if(i == 0){
            query.prepare("insert into storage values(NULL,?,?,?,?,?,?,?,?)");
            query.addBindValue(ui->comboBox_type->currentText());
            query.addBindValue(ui->lineEdit_name->text());
            query.addBindValue(ui->comboBox_standard->currentText());
            query.addBindValue(ui->comboBox_unit->currentText());
            query.addBindValue(ui->lineEdit_rate->text().toFloat());
            query.addBindValue(ui->lineEdit_amount->text().toInt());
            query.addBindValue(ui->comboBox_warehouse->currentText());
            query.addBindValue(ui->lineEdit_provider->text());
        }
        else if(i == 1){
            query.prepare("update storage set amount = amount + ? where type = ? and name = ? and standard = ? and unit = ? and rate = ? and warehouse = ? and provider = ?");
            query.addBindValue(ui->lineEdit_amount->text().toInt());
            query.addBindValue(ui->comboBox_type->currentText());
            query.addBindValue(ui->lineEdit_name->text());
            query.addBindValue(ui->comboBox_standard->currentText());
            query.addBindValue(ui->comboBox_unit->currentText());
            query.addBindValue(ui->lineEdit_rate->text().toFloat());
            query.addBindValue(ui->comboBox_warehouse->currentText());
            query.addBindValue(ui->lineEdit_provider->text());
        }
        else{
            QMessageBox::warning(0,tr(" 警告"),tr("数据查询出错"));
        }
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
    }

    this->accept();
}

void CheckInDialog::on_pushButton_cancel_clicked()
{
    this->reject();
}

void CheckInDialog::on_toolButton_clicked()
{
    dialog = new EmployeeBaseInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendEmployeeChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void CheckInDialog::doubleClickRecord(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name,gender,department,post from employee_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_cardNo->setText(cardNo);
        ui->lineEdit_buyer->setText(query.value(0).toString());
        ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(1).toString()));
        ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(query.value(2).toString()));
         ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(query.value(3).toString()));
    }
    query.clear();
    query.finish();
}

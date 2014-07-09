#include "specialservicedialog.h"
#include "ui_specialservicedialog.h"
#include<QSqlQuery>
#include<QDate>
#include<QDateTime>
#include<QSqlRecord>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
SpecialServiceDialog::SpecialServiceDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::SpecialServiceDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

SpecialServiceDialog::~SpecialServiceDialog()
{
    delete ui;
}

void SpecialServiceDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("special_service_toolbutton",operatorId);
    if(!list.contains(tr("ÐÞ¸Ä")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->comboBox->addItems(Dictionary::getExpenseNameByType(4));
    if(this->index != -1){
        QSqlRecord record = model->record(index);
        QSqlQuery query(globaldb);
        query.prepare("select a.name,b.cardNo,b.serviceItem,b.cost,b.occurenceDate,b.personInCharge,b.remark,b.operator,"
                      "b.operationTime from manage_info a,living_record b where a.cardNo = b.cardNo and b.item = 4 and b.id = ?");
        query.addBindValue(record.value("id").toInt());
        query.exec();
        if(query.first()){
            ui->lineEdit_name->setText(query.value(0).toString());
            ui->lineEdit_cardNo->setText(query.value(1).toString());
            ui->comboBox->setCurrentIndex(ui->comboBox->findText(query.value(2).toString()));
            ui->lineEdit_cost->setText(query.value(3).toString());
            ui->dateEdit->setDate(query.value(4).toDate());
            ui->lineEdit_personInCharge->setText(query.value(5).toString());
            ui->lineEdit_remark->setText(query.value(6).toString());
            ui->lineEdit_operator->setText(query.value(7).toString());
            ui->dateTimeEdit->setDateTime(query.value(8).toDateTime());
        }
        query.finish();
        query.clear();
    }
}

void SpecialServiceDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into living_record (id,cardNo,occurenceDate,serviceItem,cost,personInCharge,remark,operator,operationTime,item)  values (NULL,?,?,?,?,?,?,?,?,?)");
    }
    else{
        query.prepare("update living_record set cardNo = ?,occurenceDate = ?,serviceItem = ?, cost =?,personInCharge = ?,remark=?,operator=?,operationTime=? where id = ?");
    }
    query.addBindValue(ui->lineEdit_cardNo->text());
    query.addBindValue(ui->dateEdit->date());
    query.addBindValue(ui->comboBox->currentText());
    query.addBindValue(ui->lineEdit_cost->text().toFloat());
    query.addBindValue(ui->lineEdit_personInCharge->text());
    query.addBindValue(ui->lineEdit_remark->text());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit->dateTime());
    if(this->isAdd)
        query.addBindValue(4);
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

void SpecialServiceDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void SpecialServiceDialog::on_toolButton_elder_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void SpecialServiceDialog::on_toolButton_nurser_clicked()
{
    dialogEmployee = new EmployeeBaseInfoChooseDialog(this);
    connect(dialogEmployee,SIGNAL(sendEmployeeChoosed(QString)),this,SLOT(doubleClickEmployee(QString)));
    dialogEmployee->exec();
}

void SpecialServiceDialog::doubleClickRecord(QString cardNo){
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

void SpecialServiceDialog::doubleClickEmployee(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name from employee_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_personInCharge->setText(query.value(0).toString());
    }
    query.clear();
    query.finish();
}

void SpecialServiceDialog::on_comboBox_currentIndexChanged(const QString &name)
{
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(4);
    if(name.compare(tr("")) != 0)
        ui->lineEdit_cost->setText(map.find(name).value());
    else
        ui->lineEdit_cost->setText(tr(""));
}

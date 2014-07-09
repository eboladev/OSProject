#include "nursechangedialog.h"
#include "ui_nursechangedialog.h"
#include<QSqlQuery>
#include<QDate>
#include<QDateTime>
#include<QSqlRecord>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
NurseChangeDialog::NurseChangeDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::NurseChangeDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

NurseChangeDialog::~NurseChangeDialog()
{
    delete ui;
}

void NurseChangeDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("nurse_change_toolbutton",operatorId);
    if(!list.contains(tr("ÐÞ¸Ä")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->comboBox_formerBedLevel->addItems(Dictionary::getExpenseNameByType(1));
    ui->comboBox_formerNurseLevel->addItems(Dictionary::getExpenseNameByType(2));
    ui->comboBox_latterBedLevel->addItems(Dictionary::getExpenseNameByType(1));
    ui->comboBox_latterNurseLevel->addItems(Dictionary::getExpenseNameByType(2));
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    if(this->index != -1){
        QSqlRecord record = model->record(index);
        ui->lineEdit_name->setText(record.value("name").toString());
        QSqlQuery query(globaldb);
        query.prepare("select cardNo,additionalClauseNo,formerBuildingName,formerRegionNo,formerRoomNo,formerBedNo,formerBedLevel,"
                      "formerBedCost,formerNurseLevel,formerNurseCost,formerNurser,latterBuildingName,latterRegionNo,latterRoomNo,latterBedNo,"
                      "latterBedLevel,latterBedCost,latterNurseLevel,latterNurseCost,latterNurser,bedChangeDate,operator,operationTime from bed_change_record where id = ?");
        query.addBindValue(record.value("id").toInt());
        query.exec();
        if(query.first()){
            ui->lineEdit_cardNo->setText(query.value(0).toString());
            ui->lineEdit_additionalClauseNo->setText(query.value(1).toString());
            ui->lineEdit_formerBuildingName->setText(query.value(2).toString());
            ui->lineEdit_formerRegionNo->setText(query.value(3).toString());
            ui->lineEdit_formerRoomNo->setText(query.value(4).toString());
            ui->lineEdit_formerBedNo->setText(query.value(5).toString());
            ui->comboBox_formerBedLevel->setCurrentIndex(ui->comboBox_formerBedLevel->findText(query.value(6).toString()));
            ui->lineEdit_formerBedCost->setText(query.value(7).toString());
            ui->comboBox_formerNurseLevel->setCurrentIndex(ui->comboBox_formerNurseLevel->findText(query.value(8).toString()));
            ui->lineEdit_formerNurseCost->setText(query.value(9).toString());
            ui->lineEdit_formerNurser->setText(query.value(10).toString());
            ui->lineEdit_latterBuildingName->setText(query.value(11).toString());
            ui->lineEdit_latterRegionNo->setText(query.value(12).toString());
            ui->lineEdit_latterRoomNo->setText(query.value(13).toString());
            ui->lineEdit_latterBedNo->setText(query.value(14).toString());
            ui->comboBox_latterBedLevel->setCurrentIndex(ui->comboBox_latterBedLevel->findText(query.value(15).toString()));
            ui->lineEdit_latterBedCost->setText(query.value(16).toString());
            ui->comboBox_latterNurseLevel->setCurrentIndex(ui->comboBox_latterNurseLevel->findText(query.value(17).toString()));
            ui->lineEdit_latterNurseCost->setText(query.value(18).toString());
            ui->lineEdit_latterNurser->setText(query.value(19).toString());
            ui->dateEdit->setDate(query.value(20).toDate());
            ui->lineEdit_operator->setText(query.value(21).toString());
            ui->dateTimeEdit->setDateTime(query.value(22).toDateTime());
        }
        query.finish();
        query.clear();
    }
}

void NurseChangeDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into bed_change_record  values (NULL,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    }
    else{
        query.prepare("update bed_change_record set cardNo=?,additionalClauseNo=?,formerBuildingName=?,formerRegionNo=?,"
                      "formerRoomNo=?,formerBedNo=?,formerBedLevel=?,formerBedCost=?,formerNurseLevel=?,formerNurseCost=?,"
                      "formerNurser=?,latterBuildingName=?,latterRegionNo=?,latterRoomNo=?,latterBedNo=?,latterBedLevel=?,latterBedCost=?,"
                      "latterNurseLevel=?,latterNurseCost=?,latterNurser=?,bedChangeDate=?,operator=?,operationTime=?  where id = ?");
    }
    query.addBindValue(ui->lineEdit_cardNo->text());
    query.addBindValue(ui->lineEdit_additionalClauseNo->text());
    query.addBindValue(ui->lineEdit_formerBuildingName->text());
    query.addBindValue(ui->lineEdit_formerRegionNo->text());
    query.addBindValue(ui->lineEdit_formerRoomNo->text());
    query.addBindValue(ui->lineEdit_formerBedNo->text());
    query.addBindValue(ui->comboBox_formerBedLevel->currentText());
    query.addBindValue(ui->lineEdit_formerBedCost->text().toFloat());
    query.addBindValue(ui->comboBox_formerNurseLevel->currentText());
    query.addBindValue(ui->lineEdit_formerNurseCost->text().toFloat());
    query.addBindValue(ui->lineEdit_formerNurser->text());
    query.addBindValue(ui->lineEdit_latterBuildingName->text());
    query.addBindValue(ui->lineEdit_latterRegionNo->text());
    query.addBindValue(ui->lineEdit_latterRoomNo->text());
    query.addBindValue(ui->lineEdit_latterBedNo->text());
    query.addBindValue(ui->comboBox_latterBedLevel->currentText());
    query.addBindValue(ui->lineEdit_latterBedCost->text().toFloat());
    query.addBindValue(ui->comboBox_latterNurseLevel->currentText());
    query.addBindValue(ui->lineEdit_latterNurseCost->text().toFloat());
    query.addBindValue(ui->lineEdit_latterNurser->text());
    query.addBindValue(ui->dateEdit->date());
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
    updateManageInfo(ui->lineEdit_cardNo->text(),ui->lineEdit_latterBedCost->text().toFloat(),ui->lineEdit_latterNurseCost->text().toFloat());
    this->accept();
}

void NurseChangeDialog::updateManageInfo(QString cardNo,float bedCost,float nurseCost){
    QSqlQuery query(globaldb);
    query.prepare("update manage_info set levelChanged = 1,bedCost = ?,nurseCost = ? where cardNo = ?");
    query.addBindValue(bedCost);
    query.addBindValue(nurseCost);
    query.addBindValue(cardNo);
    query.exec();
    query.clear();
}

void NurseChangeDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void NurseChangeDialog::on_toolButton_cardNo_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void NurseChangeDialog::on_toolButton_building_clicked()
{

}

void NurseChangeDialog::doubleClickRecord(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name,buildingName,regionNo,roomNo,bedNo,bedLevel,bedCost,nurseLevel,nurseCost,nurserName from manage_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_cardNo->setText(cardNo);
        ui->lineEdit_name->setText(query.value(0).toString());
        ui->lineEdit_formerBuildingName->setText(query.value(1).toString());
        ui->lineEdit_formerRegionNo->setText(query.value(2).toString());
        ui->lineEdit_formerRoomNo->setText(query.value(3).toString());
        ui->lineEdit_formerBedNo->setText(query.value(4).toString());
        ui->comboBox_formerBedLevel->setCurrentIndex(ui->comboBox_formerBedLevel->findText(query.value(5).toString()));
        ui->lineEdit_formerBedCost->setText(query.value(6).toString());
        ui->comboBox_formerNurseLevel->setCurrentIndex(ui->comboBox_formerNurseLevel->findText(query.value(7).toString()));
        ui->lineEdit_formerNurseCost->setText(query.value(8).toString());
        ui->lineEdit_formerNurser->setText(query.value(9).toString());
    }
    query.clear();
    query.finish();
}

void NurseChangeDialog::on_comboBox_latterBedLevel_currentIndexChanged(const QString &name)
{
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(1);
    if(name.compare(tr("")) != 0)
        ui->lineEdit_latterBedCost->setText(map.find(name).value());
    else
        ui->lineEdit_latterBedCost->setText(tr(""));
}

void NurseChangeDialog::on_comboBox_latterNurseLevel_currentIndexChanged(const QString &name)
{
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(2);
    if(name.compare(tr("")) != 0)
        ui->lineEdit_latterNurseCost->setText(map.find(name).value());
    else
        ui->lineEdit_latterNurseCost->setText(tr(""));
}

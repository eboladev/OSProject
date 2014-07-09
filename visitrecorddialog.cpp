#include "visitrecorddialog.h"
#include "ui_visitrecorddialog.h"
#include<QSqlTableModel>
#include<QSqlRecord>
#include<QMessageBox>
#include<QDate>
#include<QDateTime>
#include<QDebug>
#include<QSqlQuery>
#include "dictionary.h"
extern QSqlDatabase globaldb;
extern QString operatorId;
VisitRecordDialog::VisitRecordDialog(QWidget *parent,QSqlTableModel *pModel) :
    QDialog(parent),
    ui(new Ui::VisitRecordDialog)
{
    ui->setupUi(this);
    isAdd = false;
    this->model = pModel;
    initView();
}

VisitRecordDialog::~VisitRecordDialog()
{
    delete ui;
}

void VisitRecordDialog::setIsAdd(bool a){
    this->isAdd=a;
}

bool VisitRecordDialog::getIsAdd(){
    return this->isAdd;
}

int VisitRecordDialog::getIndex(){
    return this->index;
}

void VisitRecordDialog::setIndex(int a){
    this->index = a;
}

void VisitRecordDialog::initView(){    
    QStringList list = Dictionary::getBtnListByParentAndUser("visit_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->combox_purpose->addItem(tr(""));
    ui->combox_purpose->addItem(tr("咨询"));
    ui->combox_purpose->addItem(tr("探访"));
    ui->combox_purpose->addItem(tr("预定"));
    ui->combox_mode->addItem(tr(""));
    ui->combox_mode->addItem(tr("来人"));
    ui->combox_mode->addItem(tr("电话"));
    ui->combox_gender->addItem(tr(""));
    ui->combox_gender->addItem(tr("男"));
    ui->combox_gender->addItem(tr("女"));
    ui->combox_card_type->addItem(tr(""));
    ui->combox_card_type->addItem(tr("身份证"));
    ui->combox_card_type->addItem(tr("军官证"));
    ui->combox_card_type->addItem(tr("护照"));
    ui->combox_card_type->addItem(tr("驾驶证"));
    QDate date = QDate::currentDate();
    ui->dateEdit_visit_date->setDate(date);
    ui->date_reside->setDate(date);
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->dateTime_operation->setDateTime(dateTime);
    ui->line_operator->setText(operatorId);
//    qDebug()<<this->getIsAdd();
}

void VisitRecordDialog::on_btn_save_clicked()
{
    QSqlRecord record;
    if(this->getIsAdd()){
         record = model->record();
         record.setValue("id",NULL);
    }
    else
        record = model->record(this->getIndex());

    record.setValue("visitorName",ui->line_visitor_name->text());
    record.setValue("visitorGender",ui->combox_gender->currentText());
    record.setValue("telephone",ui->line_telephone->text());
    record.setValue("cardType",ui->combox_card_type->currentText());
    record.setValue("cardNo",ui->line_card_no->text());
    record.setValue("visitPurpose",ui->combox_purpose->currentText());
    record.setValue("visitDate",ui->dateEdit_visit_date->date());
    record.setValue("visitMode",ui->combox_mode->currentText());
    record.setValue("elderName",ui->line_elder_name->text());
    record.setValue("relationship",ui->line_relationship->text());
    record.setValue("buildingName",ui->line_building_name->text());
    record.setValue("regionNo",ui->line_region_no->text());
    record.setValue("roomNo",ui->line_room_no->text());
    record.setValue("bedNo",ui->line_bed_no->text());
    record.setValue("resideDate",ui->date_reside->date());
    record.setValue("operator",ui->line_operator->text());
    record.setValue("operationTime",ui->dateTime_operation->dateTime());
    qDebug()<<this->getIsAdd();
    if(this->getIsAdd()){
        if(!model->insertRecord(-1,record)){
            QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
            this->accept();
        }
    }
    else{
        qDebug()<<tr("on_btn_save_clicked():index is %1 and %2").arg(this->getIndex()).arg(record.value("visitorGender").toString());
        if(!model->setRecord(this->getIndex(),record)){
                QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
               model->submitAll();
                this->accept();
        }
    }    
}

void VisitRecordDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void VisitRecordDialog::viewRecord(int index){
    qDebug()<<"viewRecord:";
    qDebug()<<index;
    QSqlRecord  record = model->record(index);
    ui->line_visitor_name->setText(record.value("visitorName").toString());
    ui->combox_gender->setCurrentIndex(ui->combox_gender->findText(record.value("visitorGender").toString()));
    ui->combox_card_type->setCurrentIndex(ui->combox_card_type->findText(record.value("cardType").toString()));
    ui->line_card_no->setText(record.value("cardNo").toString());
    ui->line_telephone->setText(record.value("telephone").toString());
    ui->dateEdit_visit_date->setDate(record.value("visitDate").toDate());
    ui->combox_purpose->setCurrentIndex(ui->combox_purpose->findText(record.value("visitPurpose").toString()));
    ui->combox_mode->setCurrentIndex(ui->combox_mode->findText(record.value("visitMode").toString()));
    ui->line_elder_name->setText(record.value("elderName").toString());
    ui->line_relationship->setText(record.value("relationship").toString());
    ui->line_building_name->setText(record.value("buildingName").toString());
    ui->line_region_no->setText(record.value("regionNo").toString());
    ui->line_room_no->setText(record.value("roomNo").toString());
    ui->line_bed_no->setText(record.value("bedNo").toString());
    ui->date_reside->setDate(record.value("resideDate").toDate());
    ui->line_operator->setText(record.value("operator").toString());
    ui->dateTime_operation->setDateTime(record.value("operationTime").toDateTime());
}

void VisitRecordDialog::on_combox_purpose_currentIndexChanged(const QString &purpose)
{
    if(purpose.compare(tr("咨询")) == 0){
        ui->combox_mode->setEnabled(true);
        ui->line_elder_name->setEnabled(false);
        ui->line_relationship->setEnabled(false);
        ui->line_building_name->setEnabled(false);
        ui->line_region_no->setEnabled(false);
        ui->line_room_no->setEnabled(false);
        ui->line_bed_no->setEnabled(false);
        ui->date_reside->setEnabled(false);
        ui->toolButton->setEnabled(false);
    }
    else if(purpose.compare(tr("探访")) == 0){
        ui->combox_mode->setEnabled(false);
        ui->line_elder_name->setEnabled(false);
        ui->line_relationship->setEnabled(true);
        ui->line_building_name->setEnabled(false);
        ui->line_region_no->setEnabled(false);
        ui->line_room_no->setEnabled(false);
        ui->line_bed_no->setEnabled(false);
        ui->date_reside->setEnabled(false);
        ui->toolButton->setEnabled(true);
    }
    else if(purpose.compare(tr("预定")) == 0){
        ui->combox_mode->setEnabled(false);
        ui->line_elder_name->setEnabled(true);
        ui->line_relationship->setEnabled(false);
        ui->line_building_name->setEnabled(true);
        ui->line_region_no->setEnabled(true);
        ui->line_room_no->setEnabled(true);
        ui->line_bed_no->setEnabled(true);
        ui->date_reside->setEnabled(true);
        ui->toolButton->setEnabled(false);
    }
    else{
        ui->combox_mode->setEnabled(false);
        ui->line_elder_name->setEnabled(false);
        ui->line_relationship->setEnabled(false);
        ui->line_building_name->setEnabled(false);
        ui->line_region_no->setEnabled(false);
        ui->line_room_no->setEnabled(false);
        ui->line_bed_no->setEnabled(false);
        ui->date_reside->setEnabled(false);
        ui->toolButton->setEnabled(false);
    }
}

void VisitRecordDialog::on_toolButton_clicked()
{
    dialog = new ManageInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void VisitRecordDialog::doubleClickRecord(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name,buildingName,regionNo,roomNo,bedNo from manage_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
//    if(query.lastError().isValid())
//        qDebug()<<query.lastError();
    if( query.first()){
        ui->line_elder_name->setText(query.value(0).toString());
        ui->line_building_name->setText(query.value(1).toString());
        ui->line_region_no->setText(query.value(2).toString());
        ui->line_room_no->setText(query.value(3).toString());
        ui->line_bed_no->setText(query.value(4).toString());
    }
    query.clear();
    query.finish();
}

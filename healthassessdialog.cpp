#include "healthassessdialog.h"
#include "ui_healthassessdialog.h"
#include<QDateTime>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QStringList>
#include "dictionary.h"

extern QSqlDatabase globaldb;
extern QString operatorId;
HealthAssessDialog::HealthAssessDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::HealthAssessDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

HealthAssessDialog::~HealthAssessDialog()
{    
    delete ui;    
}

void HealthAssessDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("health_assess__toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->comboBox_bloodType->addItems(Dictionary::getAttributeValues(tr("血型")));
    ui->comboBox_excretion->addItems(Dictionary::getAttributeValues(tr("大小便")));
    ui->comboBox_hearing->addItems(Dictionary::getAttributeValues(tr("听力")));
    ui->comboBox_memory->addItems(Dictionary::getAttributeValues(tr("记忆力")));
    ui->comboBox_mind->addItems(Dictionary::getAttributeValues(tr("神智")));
    ui->comboBox_nurseSuggestion->addItems(Dictionary::getExpenseNameByType(2));
    ui->comboBox_selfNurse->addItems(Dictionary::getAttributeValues(tr("自理级别")));
    ui->dateTimeEdit_operationTime->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_elderId->setEnabled(false);
    ui->lineEdit_name->setEnabled(false);
    ui->comboBox_gender->setEnabled(false);
    ui->comboBox_cardType->setEnabled(false);
    ui->lineEdit_cardNo->setEnabled(false);
    if(!isAdd){
        ui->toolButton->setEnabled(false);
    }

    if(this->index != -1){
        QSqlRecord record = model->record(index);
        int id = record.value("id").toInt();
        qDebug()<<record.value("id").toString();
        QSqlQuery query(globaldb);
        query.prepare("select elderId from health_assess where id = ?");
        query.addBindValue(id);
        query.exec();
        int elderId;
        if(query.first()){
              elderId  = query.value(0).toInt();
        }
        query.finish();
        query.prepare("select a.name,a.gender,a.cardType,a.cardNo,b.height,b.weight,"
                      "b.bloodType,b.bloodPressureLow,b.allergy,"
                      " b.bloodPressureHigh,b.diet,b.excretion,b.familyMedical,"
                      "b.hearing,b.leftEyesight,b.medicine,b.memory,b.mind,"
                      "b.nurseSuggestion,b.operationTime,b.operator,b.personalMedical,"
                      "b.pulse,b.remark,b.rightEyesight,b.selfNurse from elder_info a,health_assess b where a.eid = b.elderId AND a.eid = ? ");
        query.addBindValue(elderId);
        query.exec();
        if(query.size()>1){
            QMessageBox::warning(0,tr(" 警告"),tr("数据查询出错"));
        }
        if(query.lastError().isValid())
            qDebug()<<query.lastError();        

        if(query.first()){
            ui->lineEdit_elderId->setText(tr("%1").arg(elderId));
            ui->lineEdit_name->setText(query.value(0).toString());
            ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(1).toString()));
            ui->comboBox_cardType->setCurrentIndex(ui->comboBox_cardType->findText(query.value(2).toString()));
            ui->lineEdit_cardNo->setText(query.value(3).toString());
            ui->lineEdit_height->setText(query.value(4).toString());
            ui->lineEdit_weight->setText(query.value(5).toString());
            ui->comboBox_bloodType->setCurrentIndex(ui->comboBox_bloodType->findText(query.value(6).toString()));
            ui->lineEdit_bloodPressureLow->setText(query.value(7).toString());
            ui->lineEdit_allergy->setText(query.value(8).toString());
            ui->lineEdit_bloodPressureHigh->setText(query.value(9).toString());
            ui->lineEdit_diet->setText(query.value(10).toString());
            ui->comboBox_excretion->setCurrentIndex(ui->comboBox_excretion->findText(query.value(11).toString()));
            ui->lineEdit_familyMedical->setText(query.value(12).toString());
            ui->comboBox_hearing->setCurrentIndex(ui->comboBox_hearing->findText(query.value(13).toString()));
            ui->lineEdit_leftEyesight->setText(query.value(14).toString());
            ui->lineEdit_medicine->setText(query.value(15).toString());
            ui->comboBox_memory->setCurrentIndex(ui->comboBox_memory->findText(query.value(16).toString()));
            ui->comboBox_mind->setCurrentIndex(ui->comboBox_mind->findText(query.value(17).toString()));
            ui->comboBox_nurseSuggestion->setCurrentIndex(ui->comboBox_nurseSuggestion->findText(query.value(18).toString()));
            ui->dateTimeEdit_operationTime->setDateTime(query.value(19).toDateTime());
            ui->lineEdit_operator->setText(query.value(20).toString());
            ui->lineEdit_personalMedical->setText(query.value(21).toString());
            ui->lineEdit_pulse->setText(query.value(22).toString());
            ui->lineEdit_remark->setText(query.value(23).toString());
            ui->lineEdit_rightEyesight->setText(query.value(24).toString());
            ui->comboBox_selfNurse->setCurrentIndex(ui->comboBox_selfNurse->findText(query.value(25).toString()));
        }
        query.clear();
        query.finish();
    }
}

void HealthAssessDialog::on_btn_save_clicked(){
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into health_assess values (NULL,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
    }
    else{
        query.prepare("update health_assess set height = ?,weight = ?,bloodType = ?, bloodPressureLow =?,bloodPressureHigh=?,pulse=?,leftEyesight=?,"
                      "rightEyesight=?,memory=?,hearing=?,mind=?,selfNurse=?,diet=?,excretion=?,allergy=?,medicine=?,familyMedical=?,personalMedical=?,"
                      "nurseSuggestion=?,remark=?,operator=?,operationTime=? where elderId = ?");
    }
    query.addBindValue(ui->lineEdit_height->text().toFloat());
    query.addBindValue(ui->lineEdit_weight->text().toFloat());
    query.addBindValue(ui->comboBox_bloodType->currentText());
    query.addBindValue(ui->lineEdit_bloodPressureLow->text().toInt());
    query.addBindValue(ui->lineEdit_bloodPressureHigh->text().toInt());
    query.addBindValue(ui->lineEdit_pulse->text().toInt());
    query.addBindValue(ui->lineEdit_leftEyesight->text().toFloat());
    query.addBindValue(ui->lineEdit_rightEyesight->text().toFloat());
    query.addBindValue(ui->comboBox_memory->currentText());
    query.addBindValue(ui->comboBox_hearing->currentText());
    query.addBindValue(ui->comboBox_mind->currentText());
    query.addBindValue(ui->comboBox_selfNurse->currentText());
    query.addBindValue(ui->lineEdit_diet->text());
    query.addBindValue(ui->comboBox_excretion->currentText());
    query.addBindValue(ui->lineEdit_allergy->text());
    query.addBindValue(ui->lineEdit_medicine->text());
    query.addBindValue(ui->lineEdit_familyMedical->text());
    query.addBindValue(ui->lineEdit_personalMedical->text());
    query.addBindValue(ui->comboBox_nurseSuggestion->currentText());
    query.addBindValue(ui->lineEdit_remark->text());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());
    if(!this->isAdd)
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
    query.exec();
    if(query.lastError().isValid()){
         QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        qDebug()<<query.lastError();
    }
    query.finish();

    if(this->isAdd){
        query.prepare("update elder_info set healthAssess = 1 where eid = ?");
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
        query.exec();
        if(query.lastError().isValid()){
              QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
              qDebug()<<query.lastError();
        }
    }
    this->accept();
}

void HealthAssessDialog::on_btn_calcel_clicked()
{
    this->reject();
}

void HealthAssessDialog::on_toolButton_clicked()
{
    dialog = new ElderBaseInfoChooseDialog(this,0,0);
    connect(dialog,SIGNAL(sendElderChoosed(int)),this,SLOT(doubleClickRecord(int)));
    dialog->exec();
}

void HealthAssessDialog::doubleClickRecord(int id){
    QSqlQuery query(globaldb);
    query.prepare("select eid,name,gender,cardType,cardNo from elder_info where eid = ? ");
    query.addBindValue(id);
    query.exec();    
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_elderId->setText(query.value(0).toString());
        ui->lineEdit_name->setText(query.value(1).toString());
        ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(2).toString()));
        ui->comboBox_cardType->setCurrentIndex(ui->comboBox_cardType->findText(query.value(3).toString()));
        ui->lineEdit_cardNo->setText(query.value(4).toString());
    }
    query.clear();
    query.finish();
}

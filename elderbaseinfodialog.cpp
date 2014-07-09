#include "elderbaseinfodialog.h"
#include "ui_elderbaseinfodialog.h"
#include<QMessageBox>
#include<QDateTime>
#include<QSqlRecord>
#include<QFileDialog>
#include<QDebug>
#include<QPixmap>
#include<QBuffer>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QDir>
#include "dictionary.h"
extern QSqlDatabase globaldb;
extern QString operatorId;
ElderBaseInfoDialog::ElderBaseInfoDialog(QWidget *parent,QSqlTableModel *pModel) :
    QDialog(parent),
    ui(new Ui::ElderBaseInfoDialog)
{
    ui->setupUi(this);
    this->isAdd = false;
    this->isImage = false;
    this->model = pModel;
    initView();
}

ElderBaseInfoDialog::~ElderBaseInfoDialog()
{
    delete ui;
}

void ElderBaseInfoDialog::initView(){    
    QStringList list = Dictionary::getBtnListByParentAndUser("elder_info_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    calendar.InitConnection(QDir::currentPath());
    QStringList values = Dictionary::getAttributeValues(tr("学历"));
    ui->comboBox_education->addItems(values);
    ui->dateTimeEdit_operation->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_operator->setText(operatorId);
    ui->comboBox_nation->addItems(Dictionary::getAttributeValues(tr("民族")));
    ui->comboBox_belief->addItems(Dictionary::getAttributeValues(tr("宗教")));
}

void ElderBaseInfoDialog::setIsAdd(bool a){
    this->isAdd = a;
}

bool ElderBaseInfoDialog::getIsAdd(){
    return this->isAdd;
}

void ElderBaseInfoDialog::setIndex(int a){
    this->index = a;
}

int ElderBaseInfoDialog::getIndex(){
    return this->index;
}

void ElderBaseInfoDialog::viewRecord(int index){
    QSqlRecord record = model->record(index);
    ui->lineEdit_name->setText(record.value("name").toString());
    ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(record.value("gender").toString()));
    ui->comboBox_belief->setCurrentIndex(ui->comboBox_belief->findText(record.value("belief").toString()));
    ui->lineEdit_cardNo->setText(record.value("cardNo").toString());
    ui->lineEdit_hobby->setText(record.value("hobby").toString());
    ui->comboBox_nation->setCurrentIndex(ui->comboBox_nation->findText(record.value("nation").toString()));
    ui->lineEdit_operator->setText(record.value("operator").toString());
    ui->lineEdit_residence->setText(record.value("residence").toString());
    ui->comboBox_cardType->setCurrentIndex(ui->comboBox_cardType->findText(record.value("cardType").toString()));
    ui->comboBox_education->setCurrentIndex(ui->comboBox_education->findText(record.value("education").toString()));
    ui->textEdit_remark->setText(record.value("remark").toString());
    ui->dateEdit_birthday->setDate(record.value("birthday").toDate());
    ui->dateEdit_lunarBirthday->setDate(record.value("lunarBirthday").toDate());
    ui->dateTimeEdit_operation->setDateTime(record.value("operationTime").toDateTime());
//    int check = record.value("isLunar").toInt();
    ui->checkBox_isLunar->setChecked(record.value("isLunar").toInt() == 1);
    QPixmap pix;
    pix.loadFromData(record.value("image").toByteArray());
    ui->label_image->setPixmap(pix);
}

void ElderBaseInfoDialog::on_btn_save_clicked()
{
    QSqlRecord record;
    if(this->getIsAdd()){
         record = model->record();
         record.setValue("eid",NULL);
    }
    else
        record = model->record(this->getIndex());

    record.setValue("name",ui->lineEdit_name->text());
    record.setValue("gender",ui->comboBox_gender->currentText());
    record.setValue("nation",ui->comboBox_nation->currentText());
    record.setValue("belief",ui->comboBox_belief->currentText());
    record.setValue("hobby",ui->lineEdit_hobby->text());
    record.setValue("cardNo",ui->lineEdit_cardNo->text());
    record.setValue("operator",ui->lineEdit_operator->text());
    record.setValue("residence",ui->lineEdit_residence->text());
    record.setValue("cardType",ui->comboBox_cardType->currentText());
    record.setValue("education",ui->comboBox_education->currentText());
    record.setValue("birthday",ui->dateEdit_birthday->date());
    record.setValue("lunarBirthday",ui->dateEdit_lunarBirthday->date());
    record.setValue("operationTime",ui->dateTimeEdit_operation->dateTime());
    record.setValue("remark",ui->textEdit_remark->toPlainText());
    record.setValue("isLunar",ui->checkBox_isLunar->isChecked()?1:0);
    if(this->isImage){
        QByteArray bytes;
        QBuffer buffer(&bytes);
        buffer.open(QIODevice::WriteOnly);
        ui->label_image->pixmap()->save(&buffer,"JPG");
        record.setValue("image",bytes);
    }
    if(this->getIsAdd()){
        if(!model->insertRecord(-1,record)){
            QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
            this->accept();
        }
    }
    else{
        if(!model->setRecord(this->getIndex(),record)){
                QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        }
        else{
               updateNameByElderId(record.value("eid").toInt(),record.value("name").toString());
               model->submitAll();               
                this->accept();
        }
    }
}

void ElderBaseInfoDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void ElderBaseInfoDialog::on_btn_open_clicked()
{
    QString strImage = QFileDialog::getOpenFileName(this,tr("Open Image"),"/",tr("Image Files(*.jpg *.png *.bmp)"));
    qDebug()<<strImage;
    if(strImage.isEmpty())
        return;
    QPixmap pix(strImage);
    ui->label_image->setPixmap(pix.scaled(121,151,Qt::KeepAspectRatio));
    this->isImage = true;
}

void ElderBaseInfoDialog::updateNameByElderId(int id, QString name){
    QSqlQuery query(globaldb);
    query.prepare("select count(*) from manage_info where elderId = ?");
    query.addBindValue(id);
    query.exec();
    if(query.first()){
        if(query.value(0).toInt() == 0)
            return;
        else{
            query.finish();
            query.prepare("update manage_info set name = ? where elderId = ?");
            query.addBindValue(name);
            query.addBindValue(id);
            query.exec();
            query.finish();
            query.clear();
        }
    }
}

void ElderBaseInfoDialog::on_lineEdit_cardNo_lostFocus()
{
    if(ui->comboBox_cardType->currentText().compare(tr("身份证")) == 0){
        QString no = ui->lineEdit_cardNo->text();
        QDate birthday;
        int year,month,day;
        if(no.size() == 15){
            year = no.mid(6,2).toInt()+1900;
            month = no.mid(8,2).toInt();
            day = no.mid(10,2).toInt();
            birthday = QDate(year,month,day);
        }
        else if(no.size() == 18){
            year = no.mid(6,4).toInt();
            month = no.mid(10,2).toInt();
            day = no.mid(12,2).toInt();
            birthday = QDate(year,month,day);
        }
        else
            QMessageBox::warning(0,"警告","身份证输入错误","确定");

        ui->dateEdit_birthday->setDate(birthday);
        ui->dateEdit_lunarBirthday->setDate(birthday);
    }
}

void ElderBaseInfoDialog::on_checkBox_isLunar_clicked()
{
    QDate birthday = ui->dateEdit_birthday->date();
    if(ui->checkBox_isLunar->isChecked()){
        calendar.ctcl_solar_to_lunar(birthday.year(),birthday.month(),birthday.day(),&cal);
        ui->dateEdit_lunarBirthday->setDate(QDate(birthday.year(),cal.month,cal.day));
    }
    else
        ui->dateEdit_lunarBirthday->setDate(birthday);
}

void ElderBaseInfoDialog::on_dateEdit_birthday_dateChanged(const QDate &date)
{
    ui->dateEdit_lunarBirthday->setDate(date);
}

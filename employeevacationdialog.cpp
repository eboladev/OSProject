#include "employeevacationdialog.h"
#include "ui_employeevacationdialog.h"
#include<QDateTime>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QSqlDatabase globaldb;
extern QString operatorId;
EmployeeVacationDialog::EmployeeVacationDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::EmployeeVacationDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

EmployeeVacationDialog::~EmployeeVacationDialog()
{
    delete ui;
}

void EmployeeVacationDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("employee_vacation_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->comboBox_department->addItems(Dictionary::getAttributeValues(tr("部门")));
    ui->comboBox_post->addItems(Dictionary::getAttributeValues(tr("职务")));
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->radioButton_leave,0);
    buttonGroup->addButton(ui->radioButton_back,1);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
    ui->radioButton_leave->setChecked(true);
    ui->dateEdit_back->setVisible(false);
    ui->label_back->setVisible(false);
    ui->dateTimeEdit_operationTime->setDateTime(QDateTime::currentDateTime());
    ui->comboBox_status->setEnabled(false);
//    ui->lineEdit_cardNo->setEnabled(false);
//    ui->lineEdit_name->setEnabled(false);
//    ui->comboBox_gender->setEnabled(false);
//    ui->comboBox_department->setEnabled(false);
//    ui->comboBox_post->setEnabled(false);
    if(!this->isAdd){
        ui->toolButton->setEnabled(false);
    }

    if(this->index != -1){
        QSqlRecord record = model->record(index);
        int id = record.value("id").toInt();
        qDebug()<<record.value("id").toString();
        QSqlQuery query(globaldb);
        query.prepare("select a.cardNo,a.name,a.gender,a.department,a.post,b.auditor,b.backDate,"
                      "b.leaveDate,b.operationTime,b.operator,b.remark,b.status from employee_info a,employee_vacation b where a.cardNo = b.cardNo and b.id = ?");
        query.addBindValue(id);
        query.exec();
        if(query.size()>1){
            QMessageBox::warning(0,tr(" 警告"),tr("数据查询出错"));
        }
        if(query.lastError().isValid())
            qDebug()<<query.lastError();

        if(query.first()){
            ui->lineEdit_cardNo->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(2).toString()));
            ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(query.value(3).toString()));
             ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(query.value(4).toString()));
            ui->lineEdit_auditor->setText(query.value(5).toString());
            if(ui->dateEdit_back->isVisible())
                ui->dateEdit_back->setDate(query.value(6).toDate());
            if(ui->dateEdit_leave->isVisible())
                ui->dateEdit_leave->setDate(query.value(7).toDate());
            ui->dateTimeEdit_operationTime->setDateTime(query.value(8).toDateTime());
            ui->lineEdit_operator->setText(query.value(9).toString());
            ui->lineEdit_remark->setText(query.value(10).toString());
            switch(query.value(11).toInt()){
            case 1:ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("已请假")));break;
            case 2:ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("已销假")));break;
            default:ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("无")));break;
            }
        }
        query.clear();
        query.finish();
    }
}

void EmployeeVacationDialog::buttonJudge(int id){
    switch(id){
    case 0:ui->dateEdit_back->setVisible(false);ui->label_back->setVisible(false); ui->dateEdit_leave->setVisible(true);ui->label_leave->setVisible(true);break;
    case 1:ui->dateEdit_leave->setVisible(false);ui->label_leave->setVisible(false);ui->dateEdit_back->setVisible(true);ui->label_back->setVisible(true); break;
    default:break;
    }
}

void EmployeeVacationDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(ui->radioButton_leave->isChecked()){
        if(this->isAdd){
            query.prepare("insert into employee_vacation values (NULL,?,?,?,?,?,?,?,?)");
            query.addBindValue(ui->lineEdit_cardNo->text());
            query.addBindValue(1);
            query.addBindValue(ui->dateEdit_leave->date());
        }
        else{
            query.prepare("update employee_vacation set  leaveDate = ?, auditor =?,remark=?,operator=?,operationTime=? where id = ?");
        }
        query.addBindValue(ui->dateEdit_leave->date());
        query.addBindValue(ui->lineEdit_auditor->text());
        query.addBindValue(ui->lineEdit_remark->text());
        query.addBindValue(ui->lineEdit_operator->text());
        query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());
        if(!this->isAdd){
            QSqlRecord record = model->record(index);
            int id = record.value("id").toInt();
            query.addBindValue(id);
        }
    }
    else{
        query.prepare("update employee_vacation set status = 2, backDate = ?, auditor =?,remark=?,operator=?,operationTime=? where id = ?");
        query.addBindValue(ui->dateEdit_back->date());
        query.addBindValue(ui->lineEdit_auditor->text());
        query.addBindValue(ui->lineEdit_remark->text());
        query.addBindValue(ui->lineEdit_operator->text());
        query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());
        QSqlRecord record = model->record(index);
        int id = record.value("id").toInt();
        query.addBindValue(id);
    }
    query.exec();
    if(query.lastError().isValid()){
         QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        qDebug()<<query.lastError();
    }
    query.finish();

    query.prepare("select  status from employee_vacation  where cardNo = ?  ORDER BY operationTime DESC LIMIT 1");
    query.addBindValue(ui->lineEdit_cardNo->text());
    query.exec();
    if(query.first()){
        int status = query.value(0).toInt();
        query.finish();
        if(status == 1){
            query.prepare("update employee_info set status = '请假' where cardNo = ?");
            query.addBindValue(ui->lineEdit_cardNo->text());
            query.exec();
            query.finish();
            query.clear();
        }
        else if(status == 2){
            query.prepare("update employee_info set status = '在职' where cardNo = ?");
            query.addBindValue(ui->lineEdit_cardNo->text());
            query.exec();
            query.finish();
            query.clear();
        }

    }
    this->accept();
}

void EmployeeVacationDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void EmployeeVacationDialog::on_toolButton_clicked()
{
    dialog = new EmployeeBaseInfoChooseDialog(this);
    connect(dialog,SIGNAL(sendEmployeeChoosed(QString)),this,SLOT(doubleClickRecord(QString)));
    dialog->exec();
}

void EmployeeVacationDialog::doubleClickRecord(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name,gender,department,post from employee_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_cardNo->setText(cardNo);
        ui->lineEdit_name->setText(query.value(0).toString());
        ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(1).toString()));
        ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(query.value(2).toString()));
         ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(query.value(3).toString()));
    }
    query.clear();
    query.finish();
}



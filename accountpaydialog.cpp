#include "accountpaydialog.h"
#include "ui_accountpaydialog.h"
#include<QSqlRecord>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QDateTime>
#include "dictionary.h"
extern QString operatorId;
AccountPayDialog::AccountPayDialog(QWidget *parent,QSqlTableModel *pModel,int pIndex) :
    QDialog(parent),
    ui(new Ui::AccountPayDialog),
    model(pModel),
    index(pIndex)
{
    ui->setupUi(this);
    initView();
}

AccountPayDialog::~AccountPayDialog()
{
    delete ui;
}

void AccountPayDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("account_pay_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_accountRemain->setEnabled(false);
    if(this->index != -1){
        QSqlRecord record = model->record(index);
        ui->lineEdit_cardNo->setText(record.value("cardNo").toString());
        ui->lineEdit_name->setText(record.value("name").toString());
        ui->lineEdit_accountRemain->setText(record.value("account").toString());
    }
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->radioButton_cash,0);
    buttonGroup->addButton(ui->radioButton_card,1);
    buttonGroup->addButton(ui->radioButton_bank,2);
    buttonGroup->addButton(ui->radioButton_check,3);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
    ui->radioButton_cash->setChecked(true);
    ui->label_bank->setVisible(false);
    ui->lineEdit_bank->setVisible(false);
    ui->label_check->setVisible(false);
    ui->lineEdit_check->setVisible(false);
}

void AccountPayDialog::buttonJudge(int id){
    switch(id){
    case 0:
        ui->label_bank->setVisible(false);
        ui->lineEdit_bank->setVisible(false);
        ui->label_check->setVisible(false);
        ui->lineEdit_check->setVisible(false);
        break;
    case 1:
        ui->label_bank->setVisible(true);
        ui->lineEdit_bank->setVisible(true);
        ui->label_check->setVisible(false);
        ui->lineEdit_check->setVisible(false);
        break;
    case 2:
        ui->label_bank->setVisible(true);
        ui->lineEdit_bank->setVisible(true);
        ui->label_check->setVisible(false);
        ui->lineEdit_check->setVisible(false);
        break;
    case 3:
        ui->label_bank->setVisible(false);
        ui->lineEdit_bank->setVisible(false);
        ui->label_check->setVisible(true);
        ui->lineEdit_check->setVisible(true);
        break;
    default:
        break;
    }
}

void AccountPayDialog::on_btn_save_clicked()
{
    if(QSqlDatabase::database().transaction()){
        QSqlQuery query(globaldb);
        query.prepare("update manage_info set account = account + ? where cardNo = ?");
        query.addBindValue(ui->lineEdit_accountPay->text().toFloat());
        query.addBindValue(ui->lineEdit_cardNo->text());
        query.exec(); 
        query.prepare("insert into account_record values (NULL,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit_cardNo->text());     
        query.addBindValue(ui->lineEdit_accountRemain->text().toFloat());
        query.addBindValue(ui->lineEdit_accountRemain->text().toFloat() + ui->lineEdit_accountPay->text().toFloat());
        if(ui->radioButton_cash->isChecked())
            query.addBindValue(1);
        else if(ui->radioButton_card->isChecked())
            query.addBindValue(2);
        else if(ui->radioButton_bank->isChecked())
            query.addBindValue(3);
        else
            query.addBindValue(4);
        query.addBindValue(ui->lineEdit_bank->text());
        query.addBindValue(ui->lineEdit_check->text());
        query.addBindValue(tr("备用金续费%1").arg(ui->lineEdit_accountPay->text()));
        query.addBindValue(ui->lineEdit_operator->text());
        query.addBindValue(ui->dateTimeEdit->dateTime());
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        if(!QSqlDatabase::database().commit()){
            qDebug()<<QSqlDatabase::database().lastError();
            if(!QSqlDatabase::database().rollback())
                qDebug()<<QSqlDatabase::database().lastError();
        }
    }
    this->accept();
}

void AccountPayDialog::on_btn_cancel_clicked()
{
    this->reject();
}

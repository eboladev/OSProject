#include "passworddialog.h"
#include "ui_passworddialog.h"
#include<QSqlQuery>
#include<QMessageBox>
#include "dictionary.h"
extern QString operatorId;
PasswordDialog::PasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    ui->lineEdit_userName->setText(operatorId);
    QStringList list = Dictionary::getBtnListByParentAndUser("password_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_save->setEnabled(false);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::on_btn_save_clicked()
{
    if(ui->lineEdit_password->text().compare(ui->lineEdit_passwordAgain->text()) != 0){
        QMessageBox::warning(0,"警告","两次输入密码不一致","确定");
        return;
    }
    QSqlQuery query(globaldb);
    query.prepare("update operator set password = ? where userName = ?");
    query.addBindValue(ui->lineEdit_password->text());
    query.addBindValue(ui->lineEdit_userName->text());
    query.exec();
    this->accept();
}

void PasswordDialog::on_btn_cancel_clicked()
{
    this->reject();
}

#include "logindialog.h"
#include "ui_logindialog.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QDesktopWidget>

QString operatorId = "Anonymity";
QList<QString> menuList;
QList<QString> barList;
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loadUserInfo();
    this->setObjectName("logindialog");
    this->setStyleSheet("QDialog#logindialog{border-image:url(images/totalsystem.jpg);}");
    this->resize(QApplication::desktop()->width(),QApplication::desktop()->height());
    this->setWindowIcon(QIcon("images/totalsystem.png"));
    this->setWindowTitle(tr("登录"));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btn_login_clicked()
{
    QString user = ui->lineEdit_userName->text();
    if(user.isEmpty())
    {
        QMessageBox::warning(0,"警告","用户名为空，请输入用户名！","确定");
        return;
    }
    if(ui->lineEdit_password->text().isEmpty())
    {
        QMessageBox::warning(0,"警告","密码为空，请输入密码！","确定");
        return;
    }
    if(!map.contains(user)||map[user]!= ui->lineEdit_password->text())
    {
        QMessageBox::warning(0,"警告","用户名或密码错误！","确定");
        return;
    }
    else
    {
        operatorId = user;
        int roleId = getRoleIdByUserInfo(user,map[user]);
        menuList = getMenuNameListByRoleId(roleId);
        barList = getBarListByMenuList(menuList);
        accept();
   }
}

void LoginDialog::loadUserInfo(){
    QSqlQuery query(globaldb);
    query.prepare("select roleId,userName,password from operator");
    query.exec();
    while(query.next()){
        map.insert(query.value(1).toString(),query.value(2).toString());
    }
    query.finish();
    query.clear();
}

int LoginDialog::getRoleIdByUserInfo(QString userName,QString password){
    QSqlQuery query(globaldb);
    query.prepare("select roleId from operator where userName = ? and password = ?");
    query.addBindValue(userName);
    query.addBindValue(password);
    query.exec();
    int roleId = 0;
    if(query.first())
        roleId = query.value(0).toInt();
    query.finish();
    query.clear();
    return roleId;
}

QList<QString> LoginDialog::getMenuNameListByRoleId(int roleId){
    QSqlQuery query(globaldb);
    query.prepare("select objName from menu where id in "
                  "(select a.parentId from menu a,role_menu b where a.id = b.menuId and b.roleId = ? and a.textName = '查看')");
    query.addBindValue(roleId);
    query.exec();
    QList<QString> list;
    while(query.next())
        list.append(query.value(0).toString());
    query.finish();
    query.clear();
    return list;
}

QList<QString> LoginDialog::getBarListByMenuList(QList<QString> list){
    QSqlQuery query(globaldb);
    QList<QString> bar;
    QString name;
    for(int i = 0;i<list.size();++i){
        query.prepare("select a.objName from menu a,menu b where a.id = b.parentId and b.objName = ? ");
        query.addBindValue(list.at(i));
        query.exec();
        if(query.first()){
            name = query.value(0).toString();
            if(!bar.contains(name))
                bar.append(name);
        }
        query.finish();
    }

    query.clear();
    return bar;
}

QString LoginDialog::getObjNameById(int id){
    QSqlQuery query(globaldb);
    query.prepare("select objName from menu where id = ?");
    query.addBindValue(id);
    query.exec();
    QString name;
    if(query.first())
        name = query.value(0).toString();
    query.finish();
    query.clear();
    return name;
}

void LoginDialog::resizeEvent(QResizeEvent *event){
    QDialog::resizeEvent(event);
    ui->widget->move((QApplication::desktop()->width() - 415)/2 + 30,QApplication::desktop()->height()  - 200);
}

//登录界面
#include <QDebug>
#include <QSqlDatabase>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDesktopWidget>
#include "alarmdealwithconfirmdialog.h"
#include "ui_alarmdealwithconfirmdialog.h"
#include "struct.h"

//int appstate = -1;
//QString operatorId = "Anonymity";
AlarmDealWithConfirmDialog::AlarmDealWithConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDealWithConfirmDialog)
{
    ui->setupUi(this);
    qDebug()<<"AlarmDealWithConfirmDialog";
    connect(ui->confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    loadUserInfo();
    this->setObjectName("alarmdealwithconfirmdialog");
    this->setStyleSheet("QDialog#alarmdealwithconfirmdialog{border-image:url(images/totalsystem.jpg);}");
    this->resize(QApplication::desktop()->width(),QApplication::desktop()->height());
    this->setWindowIcon(QIcon("images/totalsystem.png"));
}

AlarmDealWithConfirmDialog::~AlarmDealWithConfirmDialog()
{
    delete ui;
}

void AlarmDealWithConfirmDialog::onConfirmPushButton()
{
    QString str = ui->identifier_lineedit->text();
    if(str.isEmpty())
    {
        QMessageBox::warning(0,"警告","用户名为空，请输入用户名！","确定");
        return;
    }
    if(ui->passwd_lineedit->text().isEmpty())
    {
        QMessageBox::warning(0,"警告","密码为空，请输入密码！","确定");
        return;
    }
    if(!usemaptopasswd.contains(str)||usemaptopasswd[str]!= ui->passwd_lineedit->text())
    {
        QMessageBox::warning(0,"警告","用户名或密码错误！","确定");
        return;
    }
    else
    {
        useridentifier = str;
        //uid = uids.at(id);
//        appstate = MONITORING;
        operatorId = useridentifier;
        /* switch(usetype)
       {
       case LOGGIN:
           insertLog("登陆系统");
           break;
       case LOCK:
           insertLog("锁定系统");
           break;
       case LOGOUT:
           insertLog("注销程序");
           break;

       }*/
        accept();
   }
}

void AlarmDealWithConfirmDialog::loadUserInfo()
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            //raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT identifer,passwd,uid FROM user_info");
        query.exec();
        while(query.next())
        {
            usemaptopasswd.insert(query.value(0).toString(),query.value(1).toString());
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            //raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
    qDebug()<<usemaptopasswd;
}

void AlarmDealWithConfirmDialog::setState(int usestate)
{
    usetype = usestate;
    if(usestate == LOGGIN)
    {
        this->setWindowTitle("登陆...");
       // this->setWindowFlags(Qt::WindowTitleHint);
    }
    else if(usestate == LOCK)
    {
        qDebug()<<"operatorId"<<operatorId;
        this->setWindowTitle("登陆...");
        ui->identifier_lineedit->setText(operatorId);
        ui->identifier_lineedit->setEnabled(false);
       // this->setWindowFlags(Qt::FramelessWindowHint);
    }
    else if(usestate == LOGOUT)
    {
        this->setWindowTitle("登陆...");
       // this->setWindowFlags(Qt::WindowTitleHint);
        operatorId = "Anonymity";
    }
    this->setWindowFlags(Qt::FramelessWindowHint);
    qDebug()<<"setstate";
}


void AlarmDealWithConfirmDialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    ui->widget->move((QApplication::desktop()->width() - 230)/2 + 15,QApplication::desktop()->height() - 110 - 75);
}


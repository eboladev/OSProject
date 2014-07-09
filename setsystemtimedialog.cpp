//配合日历控件
#include <QDebug>
#include "setsystemtimedialog.h"
#include "ui_setsystemtimedialog.h"
#include "time.h"
#include "windows.h"

SetSystemTimeDialog::SetSystemTimeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSystemTimeDialog)
{
    ui->setupUi(this);
    setWindowTitle("系统时间设置");
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    setFixedSize(140,95);
    connect(ui->confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onSetSystemTime()));
}

SetSystemTimeDialog::~SetSystemTimeDialog()
{
    delete ui;
}

void SetSystemTimeDialog::onSetSystemTime()
{
    qDebug()<<"设置系统时间";
   SYSTEMTIME st;
   GetSystemTime(&st);
  // qDebug()<<st.wYear<<st.wMonth<<st.wDay<<st.wHour<<st.wMinute<<st.wSecond;
   QDateTime tempdatetime;
   tempdatetime.setDate(ui->dateEdit->date());
   tempdatetime.setTime(ui->timeEdit->time());
   QDateTime datetime = tempdatetime.addSecs(-8*60*60);
   qDebug()<<"datetime"<<datetime;
   st.wYear = datetime.date().year();
   st.wMonth= datetime.date().month();
   st.wDay = datetime.date().day();
   st.wHour = datetime.time().hour();
   st.wMinute = datetime.time().minute();
   st.wSecond = datetime.time().second();
  // qDebug()<<st.wYear<<st.wMonth<<st.wDay<<st.wHour<<st.wMinute<<st.wSecond;
   qDebug()<<"SetSystemTime(&st)"<<SetSystemTime(&st);
   qDebug()<<datetime.date().year()<<datetime.date().month()<<datetime.date().day()<<datetime.time().hour()<<datetime.time().minute()<<datetime.time().second();
   this->accept();
}
void SetSystemTimeDialog::setCurrentTime()
{
    QDateTime curdatetime = QDateTime::currentDateTime();
    ui->dateEdit->setDate(curdatetime.date());
    ui->timeEdit->setTime(curdatetime.time());
}

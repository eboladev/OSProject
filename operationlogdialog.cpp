//������־
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

#include "operationlogdialog.h"
#include "ui_operationlogdialog.h"
#include "struct.h"

OperationLogDialog::OperationLogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperationLogDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    initDialog();
    this->setWindowIcon(QIcon("images/operationlogdialog_icon.png"));
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    QDateTime curdatetime = QDateTime::currentDateTime();
    ui->startdate_dateedit->setMinimumDate(curdatetime.date().addYears(-2).addDays(1));
    ui->enddate_dateedit->setMinimumDate(curdatetime.date().addYears(-2).addDays(1));
}

OperationLogDialog::~OperationLogDialog()
{
    delete ui;
}

/*void OperationLogDialog::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL","operationlogdialog");
    db.setHostName(serverIP);
    db.setPort(3306);
    db.setUserName(globalUserName);
    db.setPassword(globalUserName);
    db.setDatabaseName(globalDBName);
    QSqlError err;
    if(!globaldb.open())
    {
        err = db.lastError();
        qDebug()<<err;
        qDebug()<<"databaseerror";
        return;
    }
    else
    {
        qDebug()<<"connect succeed!";
    }
}*/

void OperationLogDialog::initDialog()
{
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    qDebug()<<"initDialog"<<globaldb.isOpen();
    model = new SqlTableModel(this,globaldb);
    model->setTable("operation");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(model->fieldIndex("identifer"),Qt::Horizontal,"Ա�����");
    model->setHeaderData(model->fieldIndex("time"),Qt::Horizontal,"ʱ��");
    model->setHeaderData(model->fieldIndex("item"),Qt::Horizontal,"��������");
    model->select();

    ui->view->setModel(model);
    ui->view->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->view->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->view->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->view->verticalHeader()->setDefaultSectionSize(25);
    ui->view->verticalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->view->horizontalHeader()->setHighlightSections(false);
    ui->view->horizontalHeader()->setStretchLastSection(true);
    ui->view->hideColumn(model->fieldIndex("oid"));
    ui->view->setColumnWidth(model->fieldIndex("time"),135);
    ui->view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->view->setAlternatingRowColors(true);
    ui->view->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: gray;}");
    ui->view->setFocusPolicy(Qt::NoFocus);

    QDate date = QDate::currentDate();
    ui->startdate_dateedit->setDate(date);
    ui->enddate_dateedit->setDate(date);
    connect(ui->search_pushbutton,SIGNAL(clicked()),this,SLOT(onSearchPushButton()));


    initReadStaffInfo();
    onSearchPushButton();
    this->setMinimumWidth(600);
   // this->setFixedSize(600,450);
    this->setWindowTitle("������־");
}

void OperationLogDialog::initReadStaffInfo()
{

    QSqlQuery query(globaldb);
    query.exec("SELECT DISTINCT identifer FROM user_info");
    if(query.size() > 0)
    {
        ui->staffid_comboBox->addItem("ȫ��");
        ui->staffid_comboBox->addItem("Anonymity");
    }
    while(query.next())
    {
        qDebug()<<query.value(0).toString();
        ui->staffid_comboBox->addItem(query.value(0).toString());
    }
    ui->staffid_comboBox->setCurrentIndex(0);
    query.clear();
    query.finish();
}

void OperationLogDialog::onSearchPushButton()
{
    //globaldb.close();
    //globaldb.open();
    if(ui->enddate_dateedit->dateTime() < ui->startdate_dateedit->dateTime())
    {
        QMessageBox::warning(0,"����","��ʼʱ����ڽ���ʱ��","ȷ��");
        return;
    }

    QString  startdatetime = ui->startdate_dateedit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString enddatetime = ui->enddate_dateedit->dateTime().addDays(1).toString("yyyy-MM-dd hh:mm:ss");
    QString staffname = ui->staffid_comboBox->currentText();

    if(staffname == "ȫ��")
    {
        model->setFilter(QObject::tr("time >= '%1' AND time <= '%2'").arg(startdatetime).arg(enddatetime));
        qDebug()<<staffname;
    }
    else
    {
        model->setFilter(QObject::tr("identifer = '%1' AND time >= '%2' AND time <= '%3'").arg(staffname).arg(startdatetime).arg(enddatetime));
        qDebug()<<staffname;
    }
}

void OperationLogDialog::closeEvent(QCloseEvent *event)
{
    //globaldb.close();
    QDialog::closeEvent(event);
}

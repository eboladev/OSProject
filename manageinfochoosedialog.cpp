#include "manageinfochoosedialog.h"
#include "ui_manageinfochoosedialog.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QSqlDatabase globaldb;
ManageInfoChooseDialog::ManageInfoChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageInfoChooseDialog)
{
    ui->setupUi(this);
    initView();
}

ManageInfoChooseDialog::~ManageInfoChooseDialog()
{
    delete ui;
}

void ManageInfoChooseDialog::initView(){
    ui->comboBox_selfNurse->addItems(Dictionary::getAttributeValues(tr("自理级别")));
    ui->comboBox_nurseLevel->addItems(Dictionary::getExpenseNameByType(2));
    ui->comboBox_bedLevel->addItems(Dictionary::getExpenseNameByType(1));
    QStringList header;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->verticalHeader()->hide();
    QSqlQuery query(globaldb);
    query.prepare("select  a.cardNo,b.name,b.gender,a.contractNo,c.selfNurse,a.nurseLevel,a.bedLevel,a.buildingName,"
                  "a.regionNo,a.roomNo,a.bedNo from manage_info a,elder_info b,health_assess c where a.elderId = b.eid and c.elderId = b.eid");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(11);
    header<<"卡号"<<"姓名"<<"性别"<<"合同号"<<"自理级别"<<"护理级别"<<"床位级别"<<"楼宇名"<<"区号"<<"房间号"<<"床位";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    int i = 0;
    while(query.next()){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(query.value(9).toString()));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(query.value(10).toString()));
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
    query.clear();
    query.finish();
    connect(ui->tableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void ManageInfoChooseDialog::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_contractNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox_bedLevel->setCurrentIndex(ui->comboBox_bedLevel->findText(tr("全部")));
    ui->comboBox_nurseLevel->setCurrentIndex(ui->comboBox_nurseLevel->findText(tr("全部")));
    ui->comboBox_selfNurse->setCurrentIndex(ui->comboBox_selfNurse->findText(tr("全部")));
}

void ManageInfoChooseDialog::on_btn_search_clicked()
{
    ui->tableWidget->clearContents();
    QSqlQuery query(globaldb);
    QString sql = tr("select  a.cardNo,b.name,b.gender,a.contractNo,c.selfNurse,a.nurseLevel,a.bedLevel,a.buildingName,"
                     "a.regionNo,a.roomNo,a.bedNo from manage_info a,elder_info b,health_assess c where a.elderId = b.eid and c.elderId = b.eid");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and b.name = '%1'").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_contractNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.contractNo = '%1'").arg(ui->lineEdit_contractNo->text()));
    if(ui->comboBox_bedLevel->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and a.bedLevel = '%1'").arg(ui->comboBox_bedLevel->currentText()));
    if(ui->comboBox_nurseLevel->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and a.nurseLevel = '%1'").arg(ui->comboBox_nurseLevel->currentText()));
    if(ui->comboBox_selfNurse->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" and c.selfNurse = '%1'").arg(ui->comboBox_selfNurse->currentText()));
    query.prepare(sql);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    qDebug()<<query.size();
    int i = 0;
    while(query.next()){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setRowHeight(i,20);
        ++i;
    }
    query.clear();
    query.finish();
}

void ManageInfoChooseDialog::doubleClickRecord(QModelIndex index){
    QTableWidgetItem *item = ui->tableWidget->item(index.row(),0);     
    emit sendManageInfoChoosed(item->text());
    this->accept();
}

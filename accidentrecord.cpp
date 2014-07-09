#include "accidentrecord.h"
#include "ui_accidentrecord.h"
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QDate>
#include "dictionary.h"
extern QString  operatorId;
AccidentRecord::AccidentRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccidentRecord)
{
    ui->setupUi(this);
    initModel();
    initView();
}

AccidentRecord::~AccidentRecord()
{
    delete ui;
}

void AccidentRecord::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("living_record");    
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("姓名"));
    model->setHeaderData(model->fieldIndex("occurenceDate"),Qt::Horizontal,tr("事发日期"));
     model->setHeaderData(model->fieldIndex("serviceItem"),Qt::Horizontal,tr("事故类型"));
     model->setHeaderData(model->fieldIndex("personInCharge"),Qt::Horizontal,tr("责任人"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("事故原因及解决方案"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->setRelation(model->fieldIndex("cardNo"),QSqlRelation("manage_info","cardNo","name"));
     model->setFilter("item = 2");
     model->select();
}

void AccidentRecord::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("accident_record_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
    ui->comboBox->addItems(Dictionary::getAttributeValues(tr("事故类型")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->hideColumn(model->fieldIndex("item"));
    ui->tableView->hideColumn(model->fieldIndex("healthStatus"));
    ui->tableView->hideColumn(model->fieldIndex("cost"));
    ui->tableView->hideColumn(model->fieldIndex("adviceId"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void AccidentRecord::on_btn_add_clicked()
{
    dialog = new AccidentRecordDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void AccidentRecord::on_btn_change_clicked()
{
    dialog = new AccidentRecordDialog(this,model,false,ui->tableView->currentIndex().row());
   qDebug()<< model->data(ui->tableView->currentIndex()).toString();
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void AccidentRecord::on_btn_delete_clicked()
{
    qDebug()<<ui->tableView->currentIndex().row();
    int result = QMessageBox::question(this,tr("警告"),tr("您确认删除此记录吗？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        model->removeRow(ui->tableView->currentIndex().row());
        if(model->lastError().isValid())
            qDebug()<<model->lastError();
        refreshModel();
    }
}

void AccidentRecord::on_btn_close_clicked()
{
    emit closeAccidentRecordPage();
}

void AccidentRecord::on_btn_clear_clicked()
{
    ui->lineEdit_name->setText(tr(""));
    ui->lineEdit_personInCharge->setText(tr(""));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("全部")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void AccidentRecord::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_personInCharge->text().compare(tr("")) != 0)
        sql.append(tr(" living_record.personInCharge = '%1' and ").arg(ui->lineEdit_personInCharge->text()));
    if(ui->comboBox->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" living_record.serviceItem = '%1' and ").arg(ui->comboBox->currentText()));
    sql.append(tr("  item = 2 and living_record.occurenceDate >= '%1' and living_record.occurenceDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void AccidentRecord::refreshModel(){
    model->select();
}

void AccidentRecord::doubleClickRecord(QModelIndex index){
    dialog = new AccidentRecordDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

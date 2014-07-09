#include "healthassess.h"
#include "ui_healthassess.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QSqlRelationalDelegate>
#include "dictionary.h"
extern QString operatorId;
HealthAssess::HealthAssess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HealthAssess)
{
    ui->setupUi(this);
    initModel();
    initView();
}

HealthAssess::~HealthAssess()
{    
    delete model;
    delete ui;    
}

void HealthAssess::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("health_assess");     
    model->setHeaderData(model->fieldIndex("elderId"),Qt::Horizontal,tr("姓名"));
     model->setHeaderData(model->fieldIndex("height"),Qt::Horizontal,tr("身高"));
     model->setHeaderData(model->fieldIndex("weight"),Qt::Horizontal,tr("体重"));
     model->setHeaderData(model->fieldIndex("bloodType"),Qt::Horizontal,tr("血型"));
     model->setHeaderData(model->fieldIndex("bloodPressureLow"),Qt::Horizontal,tr("舒张压"));
     model->setHeaderData(model->fieldIndex("bloodPressureHigh"),Qt::Horizontal,tr("收缩压"));
     model->setHeaderData(model->fieldIndex("pulse"),Qt::Horizontal,tr("脉搏"));
     model->setHeaderData(model->fieldIndex("leftEyesight"),Qt::Horizontal,tr("左眼视力"));
     model->setHeaderData(model->fieldIndex("rightEyesight"),Qt::Horizontal,tr("右眼视力"));
     model->setHeaderData(model->fieldIndex("mind"),Qt::Horizontal,tr("神智"));
     model->setHeaderData(model->fieldIndex("selfNurse"),Qt::Horizontal,tr("自理级别"));
     model->setHeaderData(model->fieldIndex("nurseSuggestion"),Qt::Horizontal,tr("建议护理级别"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("备注"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->setRelation(model->fieldIndex("elderId"),QSqlRelation("elder_info","eid","name"));
     model->select();
}

void HealthAssess::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("health_assess__toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
    ui->comboBox_selfNurse->addItems(Dictionary::getAttributeValues(tr("自理级别")));
    ui->comboBox_nurseSuggestion->addItems(Dictionary::getAttributeValues(tr("护理级别")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->hideColumn(model->fieldIndex("memory"));
    ui->tableView->hideColumn(model->fieldIndex("hearing"));
    ui->tableView->hideColumn(model->fieldIndex("diet"));
    ui->tableView->hideColumn(model->fieldIndex("excretion"));
    ui->tableView->hideColumn(model->fieldIndex("allergy"));
    ui->tableView->hideColumn(model->fieldIndex("medicine"));
    ui->tableView->hideColumn(model->fieldIndex("familyMedical"));
    ui->tableView->hideColumn(model->fieldIndex("personalMedical"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

void HealthAssess::on_btn_close_clicked()
{
    emit closeHealthAssessPage();
}

void HealthAssess::on_btn_add_clicked()
{
    dialog = new HealthAssessDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void HealthAssess::on_btn_change_clicked()
{
    dialog = new HealthAssessDialog(this,model,false,ui->tableView->currentIndex().row());
   qDebug()<< model->data(ui->tableView->currentIndex()).toString();
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void HealthAssess::doubleClickRecord(QModelIndex index){
    dialog = new HealthAssessDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void HealthAssess::on_btn_clear_clicked()
{
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox_nurseSuggestion->setCurrentIndex(ui->comboBox_nurseSuggestion->findText(tr("全部")));
    ui->comboBox_selfNurse->setCurrentIndex(ui->comboBox_selfNurse->findText(tr("全部")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void HealthAssess::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->comboBox_selfNurse->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" health_assess.selfNurse = '%1' and ").arg(ui->comboBox_selfNurse->currentText()));
    if(ui->comboBox_nurseSuggestion->currentText().compare(tr("全部")) != 0)
        sql.append(tr(" health_assess.nurseSuggestion = '%1' and ").arg(ui->comboBox_nurseSuggestion->currentText()));
    sql.append(tr("  health_assess.operationTime >= '%1' and health_assess.operationTime <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
    qDebug()<<model->data(model->index(1,1)).toString();
}

void HealthAssess::on_btn_delete_clicked()
{
    qDebug()<<ui->tableView->currentIndex().row();
    int result = QMessageBox::question(this,tr("警告"),tr("您确认删除此记录吗？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        QSqlRecord record = model->record(ui->tableView->currentIndex().row());
        QSqlQuery query(globaldb);
        query.prepare("select elderId from health_assess where id = ?");
        query.addBindValue(record.value("id").toInt());
        query.exec();
        int elderId;
        if(query.first())
            elderId = query.value(0).toInt();
        query.finish();

        query.prepare("update elder_info set healthAssess = 0 where eid = ?");
        query.addBindValue(elderId);
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        query.clear();
        query.finish();
        model->removeRow(ui->tableView->currentIndex().row());        
        if(model->lastError().isValid())
            qDebug()<<model->lastError();
        refreshModel();
    }
}

void HealthAssess::refreshModel(){
    model->select();
}

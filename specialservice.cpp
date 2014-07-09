#include "specialservice.h"
#include "ui_specialservice.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
SpecialService::SpecialService(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpecialService)
{
    ui->setupUi(this);
    initModel();
    initView();
}

SpecialService::~SpecialService()
{
    delete model;
    delete ui;
}

void SpecialService::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("living_record");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("����"));
    model->setHeaderData(model->fieldIndex("occurenceDate"),Qt::Horizontal,tr("��������"));
    model->setHeaderData(model->fieldIndex("personInCharge"),Qt::Horizontal,tr("����Ա"));
     model->setHeaderData(model->fieldIndex("serviceItem"),Qt::Horizontal,tr("������Ŀ"));
     model->setHeaderData(model->fieldIndex("cost"),Qt::Horizontal,tr("�������"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("˵��"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("����Ա"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("����ʱ��"));
     model->setRelation(model->fieldIndex("cardNo"),QSqlRelation("manage_info","cardNo","name"));
     model->setFilter("item = 4");
     model->select();
}

void SpecialService::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("special_service_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete->setEnabled(false);
    ui->comboBox->addItems(Dictionary::getExpenseNameByType(4));
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
    ui->tableView->hideColumn(model->fieldIndex("adviceId"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void SpecialService::on_btn_add_clicked()
{
    dialog = new SpecialServiceDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void SpecialService::on_btn_change_clicked()
{
    dialog = new SpecialServiceDialog(this,model,false,ui->tableView->currentIndex().row());
   qDebug()<< model->data(ui->tableView->currentIndex()).toString();
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void SpecialService::on_btn_delete_clicked()
{
    qDebug()<<ui->tableView->currentIndex().row();
    int result = QMessageBox::question(this,tr("����"),tr("��ȷ��ɾ���˼�¼��"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        model->removeRow(ui->tableView->currentIndex().row());
        if(model->lastError().isValid())
            qDebug()<<model->lastError();
        refreshModel();
    }
}

void SpecialService::on_btn_close_clicked()
{
    emit closeSpecialServicePage();
}

void SpecialService::on_btn_clear_clicked()
{
    ui->lineEdit->setText(tr(""));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("ȫ��")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void SpecialService::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit->text()));
    if(ui->comboBox->currentText().compare(tr("ȫ��")) != 0)
        sql.append(tr(" living_record.serviceItem = '%1' and ").arg(ui->comboBox->currentText()));
    sql.append(tr("  item = 4 and living_record.occurenceDate >= '%1' and living_record.occurenceDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void SpecialService::refreshModel(){
    model->select();
}

void SpecialService::doubleClickRecord(QModelIndex index){
    dialog = new SpecialServiceDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

#include "visitrecord.h"
#include "ui_visitrecord.h"
#include "visitrecorddialog.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
#include<QSqlError>
#include<QMouseEvent>
#include "dictionary.h"
extern QString operatorId;
VisitRecord::VisitRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitRecord)
{
        ui->setupUi(this);
        initModel();
        initView();

}

void VisitRecord::initView(){
    list = Dictionary::getBtnListByParentAndUser("visit_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add_record->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->btn_change_record->setEnabled(false);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete_record->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->resizeColumnsToContents();
    ui->combox_purpose->addItem(tr("ȫ��"));
    ui->combox_purpose->addItem(tr("��ѯ"));
    ui->combox_purpose->addItem(tr("̽��"));
    ui->combox_purpose->addItem(tr("Ԥ��"));
    ui->combox_mode->addItem(tr("ȫ��"));
    ui->combox_mode->addItem(tr("����"));
    ui->combox_mode->addItem(tr("�绰"));    
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void VisitRecord::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("visit_record");
    model->setHeaderData(model->fieldIndex("id"),Qt::Horizontal,tr("���"));
    model->setHeaderData(model->fieldIndex("visitorName"),Qt::Horizontal,tr("������"));
    model->setHeaderData(model->fieldIndex("visitorGender"),Qt::Horizontal,tr("�Ա�"));
    model->setHeaderData(model->fieldIndex("cardType"),Qt::Horizontal,tr("֤������"));
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("֤����"));
    model->setHeaderData(model->fieldIndex("telephone"),Qt::Horizontal,tr("��ϵ��ʽ"));
    model->setHeaderData(model->fieldIndex("visitPurpose"),Qt::Horizontal,tr("����Ŀ��"));
    model->setHeaderData(model->fieldIndex("visitDate"),Qt::Horizontal,tr("��������"));
    model->setHeaderData(model->fieldIndex("visitMode"),Qt::Horizontal,tr("��ѯ��ʽ"));
    model->setHeaderData(model->fieldIndex("elderName"),Qt::Horizontal,tr("����"));
    model->setHeaderData(model->fieldIndex("relationship"),Qt::Horizontal,tr("��ϵ"));
    model->setHeaderData(model->fieldIndex("resideDate"),Qt::Horizontal,tr("�ƻ���ס����"));
    model->setHeaderData(model->fieldIndex("buildingName"),Qt::Horizontal,tr("¥����"));
    model->setHeaderData(model->fieldIndex("regionNo"),Qt::Horizontal,tr("����"));
    model->setHeaderData(model->fieldIndex("roomNo"),Qt::Horizontal,tr("�����"));
    model->setHeaderData(model->fieldIndex("bedNo"),Qt::Horizontal,tr("��λ��"));
    model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("����Ա"));
    model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("����ʱ��"));   
    model->select();
//    if(model->lastError().isValid()){
//        qDebug()<<model->lastError();
//    }
}

VisitRecord::~VisitRecord()
{    
    delete model;
    delete ui;
}

void VisitRecord::on_btn_add_record_clicked()
{
    dialog = new VisitRecordDialog(this,model);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->setIsAdd(true);
    dialog->exec();
}

void VisitRecord::on_btn_close_clicked()
{
    emit closeVisitRecord();
}

void VisitRecord::on_btn_change_record_clicked()
{
    dialog = new VisitRecordDialog(this,model);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    connect(this,SIGNAL(changeRecord(int)),dialog,SLOT(viewRecord(int)));
    dialog->setIsAdd(false);
    dialog->setIndex(ui->tableView->currentIndex().row());
    qDebug()<<ui->tableView->currentIndex().row();
    emit changeRecord(ui->tableView->currentIndex().row());
    dialog->exec();
}

void VisitRecord::doubleClickRecord(QModelIndex index){ 
        dialog = new VisitRecordDialog(this,model);
        connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
        connect(this,SIGNAL(changeRecord(int)),dialog,SLOT(viewRecord(int)));
        dialog->setIsAdd(false);
        dialog->setIndex(index.row());
        qDebug()<<index.row();
        emit changeRecord(index.row());
        dialog->exec();
}

void VisitRecord::refreshModel(){
    model->select();
}

void VisitRecord::on_btn_delete_record_clicked()
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

void VisitRecord::on_btn_clear_clicked()
{
    ui->lineEdit_vistor->setText(tr(""));
    ui->lineEdit_elder->setText(tr(""));
    ui->combox_purpose->setCurrentIndex(ui->combox_purpose->findText(tr("ȫ��")));
    ui->combox_mode->setCurrentIndex(ui->combox_mode->findText(tr("ȫ��")));
    ui->dateEdit_visitStart->setDate(QDate(2014,3,1));
    ui->dateEdit_visitEnd->setDate(QDate(2050,12,31));
    ui->dateEdit_resideStart->setDate(QDate(2014,3,1));
    ui->dateEdit_resideEnd->setDate(QDate(2050,12,31));
}

void VisitRecord::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_vistor->text().compare(tr("")) != 0)
        sql.append(tr(" visitorName = '%1' and ").arg(ui->lineEdit_vistor->text()));
    if(ui->lineEdit_elder->text().compare(tr("")) != 0)
        sql.append(tr(" elderName = '%1' and ").arg(ui->lineEdit_elder->text()));
    if(ui->combox_purpose->currentText().compare(tr("ȫ��")) != 0)
        sql.append(tr("  visitPurpose = '%1' and ").arg(ui->combox_purpose->currentText()));
    if(ui->combox_mode->currentText().compare(tr("ȫ��")) != 0)
        sql.append(tr(" visitMode = '%1' and ").arg(ui->combox_mode->currentText()));
    sql.append(tr("  visitDate >= '%1' and visitDate <= '%2' and resideDate >= '%3' and resideDate <= '%4'")
               .arg(ui->dateEdit_visitStart->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_visitEnd->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_resideStart->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_resideEnd->date().toString("yyyy-MM-dd")));

    qDebug()<<sql;
    model->setFilter(sql);
}

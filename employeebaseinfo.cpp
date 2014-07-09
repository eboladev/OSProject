#include "employeebaseinfo.h"
#include "ui_employeebaseinfo.h"
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
EmployeeBaseinfo::EmployeeBaseinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeBaseinfo)
{
    ui->setupUi(this);
    initModel();
    initView();
}

EmployeeBaseinfo::~EmployeeBaseinfo()
{
    delete model;
    delete ui;
}

void EmployeeBaseinfo::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("employee_info");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("gender"),Qt::Horizontal,tr("�Ա�"));
     model->setHeaderData(model->fieldIndex("identityType"),Qt::Horizontal,tr("֤������"));
     model->setHeaderData(model->fieldIndex("identityNo"),Qt::Horizontal,tr("֤����"));
     model->setHeaderData(model->fieldIndex("status"),Qt::Horizontal,tr("״̬"));
     model->setHeaderData(model->fieldIndex("department"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("post"),Qt::Horizontal,tr("ְλ"));
     model->setHeaderData(model->fieldIndex("entryDate"),Qt::Horizontal,tr("��ְ����"));
     model->setHeaderData(model->fieldIndex("telephone"),Qt::Horizontal,tr("��ϵ��ʽ"));
     model->setHeaderData(model->fieldIndex("address"),Qt::Horizontal,tr("��ϵ��ַ"));
     model->setHeaderData(model->fieldIndex("zipCode"),Qt::Horizontal,tr("�ʱ�"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("��ע"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("����Ա"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("����ʱ��"));
     model->select();
}

void EmployeeBaseinfo::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("employee_info_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete->setEnabled(false);
    ui->comboBox_department->addItems(Dictionary::getAttributeValues(tr("����")));
    ui->comboBox_post->addItems(Dictionary::getAttributeValues(tr("ְ��")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("birthday"));
    ui->tableView->hideColumn(model->fieldIndex("maritalStatus"));
    ui->tableView->hideColumn(model->fieldIndex("degree"));
    ui->tableView->hideColumn(model->fieldIndex("diet"));
    ui->tableView->hideColumn(model->fieldIndex("school"));
    ui->tableView->hideColumn(model->fieldIndex("major"));
    ui->tableView->hideColumn(model->fieldIndex("english"));
    ui->tableView->hideColumn(model->fieldIndex("computer"));
    ui->tableView->hideColumn(model->fieldIndex("residence"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void EmployeeBaseinfo::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox_department->setCurrentIndex(ui->comboBox_department->findText(tr("ȫ��")));
    ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(tr("ȫ��")));
    ui->comboBox_post->setCurrentIndex(ui->comboBox_post->findText(tr("ȫ��")));
    ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("ȫ��")));
}

void EmployeeBaseinfo::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" cardNo = '%1' and ").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->comboBox_gender->currentText().compare(tr("ȫ��")) !=0)
        sql.append(tr(" gender = '%1' and ").arg(ui->comboBox_gender->currentText()));
    if(ui->comboBox_department->currentText().compare(tr("ȫ��")) !=0)
        sql.append(tr(" department = '%1' and ").arg(ui->comboBox_department->currentText()));
    if(ui->comboBox_post->currentText().compare(tr("ȫ��")) !=0)
        sql.append(tr(" post = '%1' and ").arg(ui->comboBox_post->currentText()));
    if(ui->comboBox_status->currentText().compare(tr("ȫ��")) !=0)
        sql.append(tr(" status = '%1' and ").arg(ui->comboBox_status->currentText()));
    sql.append(tr("  operationTime >= '%1' and operationTime <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void EmployeeBaseinfo::on_btn_add_clicked()
{
    dialog = new EmployeeBaseInfoDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void EmployeeBaseinfo::on_btn_change_clicked()
{
    dialog = new EmployeeBaseInfoDialog(this,model,false,ui->tableView->currentIndex().row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void EmployeeBaseinfo::on_btn_delete_clicked()
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

void EmployeeBaseinfo::on_btn_close_clicked()
{
    emit closeEmployeeBaseInfoPage();
}

void EmployeeBaseinfo::doubleClickRecord(QModelIndex index){
    dialog = new EmployeeBaseInfoDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void EmployeeBaseinfo::refreshModel(){
    model->select();
}

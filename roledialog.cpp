#include "roledialog.h"
#include "ui_roledialog.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
RoleDialog::RoleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoleDialog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

RoleDialog::~RoleDialog()
{
    delete model;
    delete ui;
}

void RoleDialog::on_btn_add_clicked()
{
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row,1),tr("��ɫ��"));
    model->setData(model->index(row,2),tr(""));
    ui->tableView->setCurrentIndex(model->index(row,1));
    ui->tableView->edit(model->index(row,1));
}

void RoleDialog::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("role");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("��ɫ��"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("��ע"));
     model->select();
}

void RoleDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("role_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setColumnWidth(1,80);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
}

void RoleDialog::on_btn_delete_clicked()
{
    model->removeRow(ui->tableView->currentIndex().row());
}

void RoleDialog::on_btn_save_clicked()
{
    model->database().transaction();
    if(model->submitAll())
        model->database().commit();
    else{
        model->database().rollback();
        QMessageBox::warning(this, tr("tableModel"),tr("���ݿ����:%1").arg(model->lastError().text()));
        model->revertAll();
    }
    this->accept();
}

void RoleDialog::on_btn_cancel_clicked()
{
    this->reject();
}

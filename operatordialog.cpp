#include "operatordialog.h"
#include "ui_operatordialog.h"
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
#include "dictionary.h"
extern QString operatorId;
OperatorDialog::OperatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperatorDialog)
{
    ui->setupUi(this);
    initModel();
    initView();
}

OperatorDialog::~OperatorDialog()
{
    delete modelRole;
    delete modelOperator;
    delete ui;
}

void OperatorDialog::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    modelRole = new QSqlTableModel(this,globaldb);
    modelRole->setTable("role");
    modelRole->setHeaderData(modelRole->fieldIndex("name"),Qt::Horizontal,tr("��ɫ��"));
     modelRole->setHeaderData(modelRole->fieldIndex("remark"),Qt::Horizontal,tr("��ע"));
     modelRole->select();

     modelOperator = new QSqlRelationalTableModel(this,globaldb);
     modelOperator->setTable("operator");
     modelOperator->setEditStrategy(QSqlTableModel::OnManualSubmit);
     modelOperator->setHeaderData(modelOperator->fieldIndex("roleId"),Qt::Horizontal,tr("��ɫ��"));
     modelOperator->setHeaderData(modelOperator->fieldIndex("userName"),Qt::Horizontal,tr("�û���"));
      modelOperator->setHeaderData(modelOperator->fieldIndex("password"),Qt::Horizontal,tr("����"));
      modelOperator->setRelation(modelOperator->fieldIndex("roleId"),QSqlRelation("role","id","name"));
//      modelOperator->select();
}

void OperatorDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("operator_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->tableView_operator->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete->setEnabled(false);
    ui->tableView_role->setModel(modelRole);
    ui->tableView_role->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_role->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_role->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_role->resizeColumnsToContents();
    ui->tableView_role->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_role->setColumnWidth(1,80);
    ui->tableView_role->verticalHeader()->hide();
    ui->tableView_role->hideColumn(modelRole->fieldIndex("id"));
//    ui->tableView_role->setCurrentIndex(modelRole->index(0,1));

    ui->tableView_operator->setModel(modelOperator);
    ui->tableView_operator->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_operator->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_operator->resizeColumnsToContents();
    ui->tableView_operator->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_operator->setColumnWidth(2,80);
    ui->tableView_operator->verticalHeader()->hide();
    ui->tableView_operator->hideColumn(modelOperator->fieldIndex("id"));
}

void OperatorDialog::on_btn_add_clicked()
{
    qDebug()<<ui->tableView_role->currentIndex().row();
    int row = modelOperator->rowCount();
    modelOperator->insertRow(row);
    modelOperator->setData(modelOperator->index(row,1),tr("%1").arg(modelRole->data(modelRole->index(ui->tableView_role->currentIndex().row(),0)).toInt()));
    modelOperator->setData(modelOperator->index(row,2),tr("�û���"));
    modelOperator->setData(modelOperator->index(row,3),tr("����"));
    ui->tableView_operator->setCurrentIndex(modelOperator->index(row,2));
    ui->tableView_operator->edit(modelOperator->index(row,2));
}

void OperatorDialog::on_btn_delete_clicked()
{
    modelOperator->removeRow(ui->tableView_operator->currentIndex().row());
}

void OperatorDialog::on_btn_save_clicked()
{
    modelOperator->database().transaction();
    if(modelOperator->submitAll())
        modelOperator->database().commit();
    else{
        modelOperator->database().rollback();
        QMessageBox::warning(this, tr("tableModel"),tr("���ݿ����:%1").arg(modelOperator->lastError().text()));
        modelOperator->revertAll();
    }
    this->accept();
}

void OperatorDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void OperatorDialog::on_tableView_role_clicked(const QModelIndex &index)
{
    int roleId = modelRole->data(modelRole->index(index.row(),0)).toInt();
    modelOperator->setFilter(tr("roleId = %1").arg(roleId));
    modelOperator->select();
}

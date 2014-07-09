#include "checkout.h"
#include "ui_checkout.h"
#include<QDate>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
CheckOut::CheckOut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckOut)
{
    ui->setupUi(this);
    initModel();
    initView();
}

CheckOut::~CheckOut()
{
    delete model;
    delete ui;
}

void CheckOut::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("check_out");
    model->setHeaderData(model->fieldIndex("claimer"),Qt::Horizontal,tr("领取人"));
     model->setHeaderData(model->fieldIndex("type"),Qt::Horizontal,tr("物资分类"));
     model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("物资名称"));
     model->setHeaderData(model->fieldIndex("standard"),Qt::Horizontal,tr("规格"));
     model->setHeaderData(model->fieldIndex("unit"),Qt::Horizontal,tr("单位"));
     model->setHeaderData(model->fieldIndex("rate"),Qt::Horizontal,tr("单价"));
     model->setHeaderData(model->fieldIndex("amount"),Qt::Horizontal,tr("数量"));
     model->setHeaderData(model->fieldIndex("provider"),Qt::Horizontal,tr("供应商"));
     model->setHeaderData(model->fieldIndex("warehouse"),Qt::Horizontal,tr("仓库名"));
     model->setHeaderData(model->fieldIndex("outDate"),Qt::Horizontal,tr("出库日期"));
     model->setHeaderData(model->fieldIndex("auditor"),Qt::Horizontal,tr("审核人"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->setRelation(model->fieldIndex("claimer"),QSqlRelation("employee_info","cardNo","name"));
     model->select();
}

void CheckOut::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("check_out_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    ui->comboBox_type->addItems(Dictionary::getAttributeValues(tr("物资分类")));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void CheckOut::on_btn_clear_clicked()
{
    ui->lineEdit_claimer->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->lineEdit_provider->setText(tr(""));
//    ui->comboBox_provider->setCurrentIndex(ui->comboBox_provider->findText(tr("全部")));
    ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(tr("全部")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void CheckOut::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_claimer->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_claimer->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" check_out.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_provider->text().compare(tr("")) != 0)
        sql.append(tr(" check_out.provider = '%1' and ").arg(ui->lineEdit_provider->text()));
    if(ui->comboBox_type->currentText().compare(tr("全部")) != 0)
             sql.append(tr(" check_out.type = '%1' and ").arg(ui->comboBox_type->currentText()));
    sql.append(tr("  check_out.outDate >= '%1' and check_out.outDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void CheckOut::on_btn_add_clicked()
{
    dialog = new CheckOutDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

//void CheckOut::on_btn_change_clicked()
//{
//    dialog = new CheckOutDialog(this,model,false,ui->tableView->currentIndex().row());
//    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
//    dialog->exec();
//}

//void CheckOut::on_btn_delete_clicked()
//{
//    int result = QMessageBox::question(this,tr("警告"),tr("您确认删除此记录吗？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
//    if(result == QMessageBox::Ok){
//        model->removeRow(ui->tableView->currentIndex().row());
//        if(model->lastError().isValid())
//            qDebug()<<model->lastError();
//        refreshModel();
//    }
//}

void CheckOut::on_btn_close_clicked()
{
      emit closeCheckOutPage();
}

void CheckOut::refreshModel(){
    model->select();
}

void CheckOut::doubleClickRecord(QModelIndex index){
    dialog = new CheckOutDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

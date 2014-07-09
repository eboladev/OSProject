#include "employeevacation.h"
#include "ui_employeevacation.h"
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QDate>
#include "vacationstatusdelegate.h"
#include "dictionary.h"
extern QString operatorId;
EmployeeVacation::EmployeeVacation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeVacation)
{
    ui->setupUi(this);
    initModel();
    initView();
}

EmployeeVacation::~EmployeeVacation()
{
    delete model;
    delete ui;
}

void EmployeeVacation::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("employee_vacation");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("姓名"));
     model->setHeaderData(model->fieldIndex("status"),Qt::Horizontal,tr("状态"));    
     model->setHeaderData(model->fieldIndex("leaveDate"),Qt::Horizontal,tr("请假日期"));
     model->setHeaderData(model->fieldIndex("backDate"),Qt::Horizontal,tr("销假日期"));
     model->setHeaderData(model->fieldIndex("auditor"),Qt::Horizontal,tr("批准人"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("备注"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->setRelation(model->fieldIndex("cardNo"),QSqlRelation("employee_info","cardNo","name"));
     model->select();
}

void EmployeeVacation::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("employee_vacation_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("修改")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("删除")))
        ui->btn_delete->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->hideColumn(model->fieldIndex("id"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("status"),new VacationStatusDelegate(this));
//    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

void EmployeeVacation::on_btn_add_clicked()
{
    dialog = new EmployeeVacationDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void EmployeeVacation::on_btn_change_clicked()
{
    dialog = new EmployeeVacationDialog(this,model,false,ui->tableView->currentIndex().row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void EmployeeVacation::on_btn_delete_clicked()
{   
    int result = QMessageBox::question(this,tr("警告"),tr("您确认删除此记录吗？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        model->removeRow(ui->tableView->currentIndex().row());
        if(model->lastError().isValid())
            qDebug()<<model->lastError();
        refreshModel();
    }
}

void EmployeeVacation::on_btn_close_clicked()
{
     emit closeEmployeeVacationPage();
}

void EmployeeVacation::on_btn_clear_clicked()
{
    ui->lineEdit_auditor->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->dateEdit_backEnd->setDate(QDate(2050,12,31));
    ui->dateEdit_backStart->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
    ui->dateEdit_leaveEnd->setDate(QDate(2050,12,31));
    ui->dateEdit_leaveStart->setDate(QDate(2014,3,1));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("全部")));
}

void EmployeeVacation::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->comboBox_status->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox_status->currentText().compare(tr("已请假")) == 0)
            sql.append(tr(" employee_vacation.status = '%1' and ").arg(1));
        else
             sql.append(tr(" employee_vacation.status = '%1' and ").arg(2));
    }
    if(ui->lineEdit_auditor->text().compare(tr("")) != 0)
        sql.append(tr(" employee_vacation.auditor = '%1' and ").arg(ui->lineEdit_auditor->text()));
    sql.append(tr("  employee_vacation.operationTime >= '%1' and employee_vacation.operationTime <= '%2' and "
                  "employee_vacation.leaveDate >= '%3' and employee_vacation.leaveDate <= '%4' and "
                  "employee_vacation.backDate >= '%5' and employee_vacation.backDate <='%6'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_leaveStart->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_leaveEnd->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_backStart->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_backEnd->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void EmployeeVacation::refreshModel(){
    model->select();
}

void EmployeeVacation::doubleClickRecord(QModelIndex index){
    dialog = new EmployeeVacationDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

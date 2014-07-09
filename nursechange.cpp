#include "nursechange.h"
#include "ui_nursechange.h"
#include<QMessageBox>
#include<QDate>
#include<QDebug>
#include<QSqlError>
#include "dictionary.h"
extern QString operatorId;
NurseChange::NurseChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NurseChange)
{
    ui->setupUi(this);
    initModel();
    initView();
}

NurseChange::~NurseChange()
{
    delete model;
    delete ui;
}

void NurseChange::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("bed_change_record");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("姓名"));
    model->setHeaderData(model->fieldIndex("additionalClauseNo"),Qt::Horizontal,tr("合同附加号"));
     model->setHeaderData(model->fieldIndex("formerBuildingName"),Qt::Horizontal,tr("原楼宇名"));
     model->setHeaderData(model->fieldIndex("formerRegionNo"),Qt::Horizontal,tr("原区号"));
     model->setHeaderData(model->fieldIndex("formerRoomNo"),Qt::Horizontal,tr("原房间号"));
     model->setHeaderData(model->fieldIndex("formerBedNo"),Qt::Horizontal,tr("原床位"));
     model->setHeaderData(model->fieldIndex("formerBedLevel"),Qt::Horizontal,tr("原床位级别"));
     model->setHeaderData(model->fieldIndex("formerBedCost"),Qt::Horizontal,tr("原床位费"));
     model->setHeaderData(model->fieldIndex("formerNurseLevel"),Qt::Horizontal,tr("原护理级别"));
     model->setHeaderData(model->fieldIndex("formerNurseCost"),Qt::Horizontal,tr("原护理费"));
     model->setHeaderData(model->fieldIndex("formerNurser"),Qt::Horizontal,tr("原护理员"));
     model->setHeaderData(model->fieldIndex("latterBuildingName"),Qt::Horizontal,tr("新楼宇名"));
     model->setHeaderData(model->fieldIndex("latterRegionNo"),Qt::Horizontal,tr("新区号"));
     model->setHeaderData(model->fieldIndex("latterRoomNo"),Qt::Horizontal,tr("新房间号"));
     model->setHeaderData(model->fieldIndex("latterBedNo"),Qt::Horizontal,tr("新床位"));
     model->setHeaderData(model->fieldIndex("latterBedLevel"),Qt::Horizontal,tr("新床位级别"));
     model->setHeaderData(model->fieldIndex("latterBedCost"),Qt::Horizontal,tr("新床位费"));
     model->setHeaderData(model->fieldIndex("latterNurseLevel"),Qt::Horizontal,tr("新护理级别"));
     model->setHeaderData(model->fieldIndex("latterNurseCost"),Qt::Horizontal,tr("新护理费"));
     model->setHeaderData(model->fieldIndex("latterNurser"),Qt::Horizontal,tr("新护理员"));
     model->setHeaderData(model->fieldIndex("bedChangeDate"),Qt::Horizontal,tr("变更日期"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->setRelation(model->fieldIndex("cardNo"),QSqlRelation("manage_info","cardNo","name"));
     model->select();
}

void NurseChange::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("nurse_change_toolbutton",operatorId);
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
    ui->tableView->hideColumn(model->fieldIndex("id"));
//    ui->tableView->hideColumn(model->fieldIndex("clause"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
}

void NurseChange::on_btn_add_clicked()
{
    dialog = new NurseChangeDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void NurseChange::on_btn_change_clicked()
{
    dialog = new NurseChangeDialog(this,model,false,ui->tableView->currentIndex().row());
   qDebug()<< model->data(ui->tableView->currentIndex()).toString();
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void NurseChange::on_btn_delete_clicked()
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

void NurseChange::on_btn_close_clicked()
{
    emit closeNurseChangePage();
}

void NurseChange::on_btn_clear_clicked()
{
    ui->lineEdit_additionalClauseNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void NurseChange::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_additionalClauseNo->text().compare(tr("")) != 0)
        sql.append(tr(" bed_change_record.name = '%1' and ").arg(ui->lineEdit_additionalClauseNo->text()));
    sql.append(tr("  bed_change_record.bedChangeDate >= '%1' and bed_change_record.bedChangeDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void NurseChange::refreshModel(){
    model->select();
}

void NurseChange::doubleClickRecord(QModelIndex index){
    dialog = new NurseChangeDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

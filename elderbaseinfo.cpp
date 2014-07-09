#include "elderbaseinfo.h"
#include "ui_elderbaseinfo.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QDate>
#include "dictionary.h"
#include "healthassessstatusdelegate.h"
#include "resideregisterstatusdelegate.h"
extern QString operatorId;
ElderBaseInfo::ElderBaseInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElderBaseInfo)
{
    ui->setupUi(this);
    initModel();
    initView();
}

ElderBaseInfo::~ElderBaseInfo()
{   
    delete model;
    delete ui;    
}

void ElderBaseInfo::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("elder_info");
    model->setHeaderData(model->fieldIndex("eid"),Qt::Horizontal,tr("老人ID"));
    model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("姓名"));
    model->setHeaderData(model->fieldIndex("gender"),Qt::Horizontal,tr("性别"));
    model->setHeaderData(model->fieldIndex("cardType"),Qt::Horizontal,tr("证件类型"));
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("证件号"));
    model->setHeaderData(model->fieldIndex("telephone"),Qt::Horizontal,tr("联系方式"));
    model->setHeaderData(model->fieldIndex("nation"),Qt::Horizontal,tr("名族"));
    model->setHeaderData(model->fieldIndex("birthday"),Qt::Horizontal,tr("出生日期"));
    model->setHeaderData(model->fieldIndex("belief"),Qt::Horizontal,tr("宗教信仰"));
    model->setHeaderData(model->fieldIndex("education"),Qt::Horizontal,tr("文化程度"));
   model->setHeaderData(model->fieldIndex("healthAssess"),Qt::Horizontal,tr("健康评估"));
   model->setHeaderData(model->fieldIndex("resideRegister"),Qt::Horizontal,tr("入住登记"));
   model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("备注"));
    model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
    model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
    model->select();
}

void ElderBaseInfo::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("elder_info_toolbutton",operatorId);
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
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
//    ui->tableView->hideColumn(model->fieldIndex("healthAssess"));
    ui->tableView->hideColumn(model->fieldIndex("isLunar"));
    ui->tableView->hideColumn(model->fieldIndex("lunarBirthday"));
    ui->tableView->hideColumn(model->fieldIndex("residence"));
    ui->tableView->hideColumn(model->fieldIndex("character"));
    ui->tableView->hideColumn(model->fieldIndex("hobby"));    
    ui->tableView->hideColumn(model->fieldIndex("birth_date"));
    ui->tableView->hideColumn(model->fieldIndex("device_id"));
    ui->tableView->hideColumn(model->fieldIndex("building_no"));
    ui->tableView->hideColumn(model->fieldIndex("floor_no"));
    ui->tableView->hideColumn(model->fieldIndex("room_no"));
    ui->tableView->hideColumn(model->fieldIndex("bed_no"));
    ui->tableView->hideColumn(model->fieldIndex("body_state"));
    ui->tableView->hideColumn(model->fieldIndex("service_type"));
    ui->tableView->hideColumn(model->fieldIndex("mat"));
    ui->tableView->hideColumn(model->fieldIndex("ic"));
    ui->tableView->hideColumn(model->fieldIndex("rfID"));
    ui->tableView->hideColumn(model->fieldIndex("tel"));
    ui->tableView->hideColumn(model->fieldIndex("contactor"));
    ui->tableView->hideColumn(model->fieldIndex("contactor_tel"));
    ui->tableView->hideColumn(model->fieldIndex("in_date"));
    ui->tableView->hideColumn(model->fieldIndex("out_date"));
    ui->tableView->hideColumn(model->fieldIndex("image"));
    ui->tableView->hideColumn(model->fieldIndex("hint1"));
    ui->tableView->hideColumn(model->fieldIndex("hint1_time"));
    ui->tableView->hideColumn(model->fieldIndex("hint2"));
    ui->tableView->hideColumn(model->fieldIndex("hint2_time"));
    ui->tableView->hideColumn(model->fieldIndex("hint3"));
    ui->tableView->hideColumn(model->fieldIndex("hint3_time"));
    ui->tableView->hideColumn(model->fieldIndex("valid"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("healthAssess"),new HealthAssessStatusDelegate(this));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("resideRegister"),new ResideRegisterStatusDelegate(this));
}

void ElderBaseInfo::on_btn_close_clicked()
{
    emit closeElderBaseInfoPage();
}

void ElderBaseInfo::refreshModel(){
    model->select();
}

void ElderBaseInfo::on_btn_add_clicked()
{
    dialog = new ElderBaseInfoDialog(this,model);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->setIsAdd(true);
    dialog->exec();
}

void ElderBaseInfo::on_btn_change_clicked()
{
    dialog = new ElderBaseInfoDialog(this,model);
    dialog->setIndex(ui->tableView->currentIndex().row());
    dialog->setIsAdd(false);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    connect(this,SIGNAL(changeRecord(int)),dialog,SLOT(viewRecord(int)));
    emit changeRecord(ui->tableView->currentIndex().row());
    dialog->exec();
}

void ElderBaseInfo::doubleClickRecord(QModelIndex index){
    dialog = new ElderBaseInfoDialog(this,model);
    dialog->setIndex(index.row());
    dialog->setIsAdd(false);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    connect(this,SIGNAL(changeRecord(int)),dialog,SLOT(viewRecord(int)));
    emit changeRecord(index.row());
    dialog->exec();
}

void ElderBaseInfo::on_btn_delete_clicked()
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

void ElderBaseInfo::on_btn_clear_clicked()
{
    ui->lineEdit_elder->setText(tr(""));
    ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(tr("全部")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void ElderBaseInfo::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_elder->text().compare(tr("")) != 0)
        sql.append(tr(" name = '%1' and ").arg(ui->lineEdit_elder->text()));
    if(ui->comboBox_gender->currentText().compare(tr("全部")) !=0)
        sql.append(tr(" gender = '%1' and ").arg(ui->comboBox_gender->currentText()));
    sql.append(tr("  operationTime >= '%1' and operationTime <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

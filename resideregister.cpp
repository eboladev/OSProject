#include "resideregister.h"
#include "ui_resideregister.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlError>
#include<QDate>
#include "dictionary.h"
#include<QSqlRecord>
#include<QSqlQuery>
#include "elderstatusdelegate.h"
#include "struct.h"
extern QString operatorId;
ResideRegister::ResideRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResideRegister)
{
    ui->setupUi(this);
    initModel();
    initView();
}

ResideRegister::~ResideRegister()
{
    delete model;
    delete ui;
}

void ResideRegister::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
    }
    model = new QSqlRelationalTableModel(this,globaldb);
    model->setTable("manage_info");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("elderId"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("contractNo"),Qt::Horizontal,tr("��ͬ��"));
     model->setHeaderData(model->fieldIndex("status"),Qt::Horizontal,tr("״̬"));
     model->setHeaderData(model->fieldIndex("buildingName"),Qt::Horizontal,tr("¥����"));
     model->setHeaderData(model->fieldIndex("regionNo"),Qt::Horizontal,tr("����"));
     model->setHeaderData(model->fieldIndex("roomNo"),Qt::Horizontal,tr("�����"));
     model->setHeaderData(model->fieldIndex("bedNo"),Qt::Horizontal,tr("��λ"));
     model->setHeaderData(model->fieldIndex("bedLevel"),Qt::Horizontal,tr("��λ�ȼ�"));
     model->setHeaderData(model->fieldIndex("bedCost"),Qt::Horizontal,tr("��λ��"));
     model->setHeaderData(model->fieldIndex("nurseLevel"),Qt::Horizontal,tr("������"));
     model->setHeaderData(model->fieldIndex("nurseCost"),Qt::Horizontal,tr("�����"));
     model->setHeaderData(model->fieldIndex("nurserName"),Qt::Horizontal,tr("������"));
     model->setHeaderData(model->fieldIndex("resideDate"),Qt::Horizontal,tr("��ס����"));
     model->setHeaderData(model->fieldIndex("outDate"),Qt::Horizontal,tr("��ס����"));
     model->setHeaderData(model->fieldIndex("account"),Qt::Horizontal,tr("�˻����"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("��ע"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("����Ա"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("����ʱ��"));
     model->setRelation(model->fieldIndex("elderId"),QSqlRelation("elder_info","eid","name"));     
     model->select();
}

void ResideRegister::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("living_toolbutton",operatorId);
    if(!list.contains(tr("���")))
        ui->btn_add->setEnabled(false);
    if(!list.contains(tr("�޸�")))
        ui->btn_change->setEnabled(false);
    if(!list.contains(tr("ɾ��")))
        ui->btn_delete->setEnabled(false);
    ui->comboBox_bedLevel->addItems(Dictionary::getExpenseNameByType(1));
    ui->comboBox_nurseLevel->addItems(Dictionary::getExpenseNameByType(2));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("name"));
    ui->tableView->hideColumn(model->fieldIndex("isCuff"));
    ui->tableView->hideColumn(model->fieldIndex("cuffNo"));
    ui->tableView->hideColumn(model->fieldIndex("cuffStartTime"));
    ui->tableView->hideColumn(model->fieldIndex("cuffEndTime"));
    ui->tableView->hideColumn(model->fieldIndex("isMattress"));
    ui->tableView->hideColumn(model->fieldIndex("levelChanged"));
    ui->tableView->hideColumn(model->fieldIndex("settleDate"));
    ui->tableView->hideColumn(model->fieldIndex("agreement"));
    ui->tableView->hideColumn(model->fieldIndex("personalMedical"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));  
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("status"),new ElderStatusDelegate(this));
}

void ResideRegister::on_btn_add_clicked()
{
    dialog = new ResideRegisterDialog(this,model,true);
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void ResideRegister::on_btn_change_clicked()
{
    dialog = new ResideRegisterDialog(this,model,false,ui->tableView->currentIndex().row());
   qDebug()<< model->data(ui->tableView->currentIndex()).toString();
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void ResideRegister::on_btn_delete_clicked()
{
    qDebug()<<ui->tableView->currentIndex().row();
    int result = QMessageBox::question(this,tr("����"),tr("��ȷ��ɾ���˼�¼��"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        QSqlRecord record = model->record(ui->tableView->currentIndex().row());
        QSqlQuery query(globaldb);
        query.prepare("select elderId from manage_info where cardNo = ?");
        query.addBindValue(record.value("cardNo").toString());
        query.exec();
        int elderId;
        if(query.first())
            elderId = query.value(0).toInt();
        query.finish();
        qDebug()<<elderId;
        query.prepare("update elder_info set resideRegister = 0 where eid = ?");
        query.addBindValue(elderId);
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();       
        query.finish();
        model->removeRow(ui->tableView->currentIndex().row());
        if(model->lastError().isValid())
            qDebug()<<model->lastError();

        query.prepare("update elder_info set birth_date = NULL,device_id = NULL,building_no = NULL,floor_no= NULL,room_no = NULL,bed_no = NULL,mat = NULL,ic = NULL,"
                      "rfID = NULL where eid = ?");
        query.addBindValue(elderId);
        query.exec();
        query.finish();
        smt->sendDelMat(record.value("buildingName").toString(),record.value("regionNo").toString(),record.value("roomNo").toString(),record.value("bedNo").toString());

        this->updateMattressState(false,record.value("buildingName").toString(),record.value("regionNo").toString().toInt(),record.value("roomNo").toString(),record.value("bedNo").toString().toInt());
        refreshModel();
    }
}

void ResideRegister::on_btn_close_clicked()
{
    emit closeResideRegisterPage();
}

void ResideRegister::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_contractNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox_bedLevel->setCurrentIndex(ui->comboBox_bedLevel->findText(tr("ȫ��")));
    ui->comboBox_nurseLevel->setCurrentIndex(ui->comboBox_nurseLevel->findText(tr("ȫ��")));
    ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("ȫ��")));
    ui->dateEdit_start->setDate(QDate(2014,3,1));
    ui->dateEdit_end->setDate(QDate(2050,12,31));
}

void ResideRegister::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" relTblAl_1.name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" manage_info.cardNo = '%1' and ").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_contractNo->text().compare(tr("")) != 0)
        sql.append(tr(" manage_info.contractNo = '%1' and ").arg(ui->lineEdit_contractNo->text()));
    if(ui->comboBox_bedLevel->currentText().compare(tr("ȫ��")) != 0)
        sql.append(tr(" manage_info.bedLevel = '%1' and ").arg(ui->comboBox_bedLevel->currentText()));
    if(ui->comboBox_nurseLevel->currentText().compare(tr("ȫ��")) != 0)
        sql.append(tr(" manage_info.nurseLevel = '%1' and ").arg(ui->comboBox_nurseLevel->currentText()));
    if(ui->comboBox_status->currentText().compare(tr("ȫ��")) != 0){
        if(ui->comboBox_status->currentText().compare(tr("��ס")) == 0)
            sql.append(tr(" manage_info.status = '%1' and ").arg(1));
        else if(ui->comboBox_status->currentText().compare(tr("���")) == 0)
            sql.append(tr(" manage_info.status = '%1' and ").arg(2));
        else
            sql.append(tr(" manage_info.status = '%1' and ").arg(3));
    }

    sql.append(tr("  manage_info.resideDate >= '%1' and manage_info.resideDate <= '%2'")
               .arg(ui->dateEdit_start->date().toString("yyyy-MM-dd"))
               .arg(ui->dateEdit_end->date().toString("yyyy-MM-dd")));
    qDebug()<<sql;
    model->setFilter(sql);
}

void ResideRegister::refreshModel(){
    model->select();
}

void ResideRegister::doubleClickRecord(QModelIndex index){
    dialog = new ResideRegisterDialog(this,model,false,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void ResideRegister::updateMattressState(bool isAdd,QString buildingName, int floorNo, QString roomName, int bedNo){
    QSqlQuery query(globaldb);
    int bedStatus = 0;
    query.prepare("select bedStatus from device_info where building_no = ? and floor_no = ? and room_name = ?");
    query.addBindValue(buildingName);
    query.addBindValue(floorNo);
    query.addBindValue(roomName);
    query.exec();
    if(query.first())
        bedStatus = query.value(0).toInt();
    if(isAdd)
        bedStatus |= (1<<(bedNo*2-2));
    else
        bedStatus &= ~(1<<(bedNo*2-2));
    bedStatus &= ~(1<<(bedNo*2-1));
    query.finish();
    query.prepare("update device_info set bedStatus = ? where building_no = ? and floor_no = ? and room_name = ?");
    query.addBindValue(bedStatus);
    query.addBindValue(buildingName);
    query.addBindValue(floorNo);
    query.addBindValue(roomName);
    query.exec();
    query.clear();
}

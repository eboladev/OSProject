#include "resideregisterdialog.h"
#include "ui_resideregisterdialog.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QPixmap>
#include<QFileDialog>
#include<QBuffer>
#include<QMessageBox>
#include "dictionary.h"
#include<QSqlRecord>
#include<QDate>
#include<QDateTime>
#include"struct.h"
extern QString operatorId;
ResideRegisterDialog::ResideRegisterDialog(QWidget *parent,QSqlRelationalTableModel *pModel,bool pIsAdd,int pIndex) :
    QDialog(parent),
    ui(new Ui::ResideRegisterDialog),
    model(pModel),
    isAdd(pIsAdd),
    index(pIndex)
{
    isImage = false;
    ui->setupUi(this);    
    initModel();
    initView();
}

ResideRegisterDialog::~ResideRegisterDialog()
{
    delete ms;
    delete ui;
}

void ResideRegisterDialog::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("living_toolbutton",operatorId);
    if(!list.contains(tr("修改")))
        ui->btn_save->setEnabled(false);
    ui->lineEdit_operator->setText(operatorId);
    ui->dateEdit_outDate->setDate(QDate::currentDate());
    ui->dateEdit_resideDate->setDate(QDate::currentDate());
    ui->dateTimeEdit_operationTime->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_account->setEnabled(false);
    ui->checkBox_levelChanged->setEnabled(false);
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(3);
    QMapIterator<QString,QString> iterator(map);
    ui->tableWidget->setRowCount(map.count());
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<"项目"<<"费用";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    unsigned char i = 0;
    while(iterator.hasNext()){
        iterator.next();
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(iterator.key()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(iterator.value()));
        qDebug()<<iterator.key();
        ++i;
    }
    ui->comboBox_bedLevel->addItems(Dictionary::getExpenseNameByType(1));
    ui->comboBox_nurseLevel->addItems(Dictionary::getExpenseNameByType(2));
    ui->comboBox_nurseSuggestion->addItems(Dictionary::getExpenseNameByType(2));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setModel(relativeModel);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(25);
    ui->comboBox_education->addItems(Dictionary::getAttributeValues(tr("学历")));
    ui->comboBox_bloodType->addItems(Dictionary::getAttributeValues(tr("血型")));
    ui->comboBox_hearing->addItems(Dictionary::getAttributeValues(tr("听力")));
    ui->comboBox_memory->addItems(Dictionary::getAttributeValues(tr("记忆力")));
    ui->comboBox_mind->addItems(Dictionary::getAttributeValues(tr("神智")));
    ui->comboBox_excretion->addItems(Dictionary::getAttributeValues(tr("大小便")));
    ui->comboBox_selfNurse->addItems(Dictionary::getAttributeValues(tr("自理级别")));
    ui->tabWidget->setCurrentWidget(ui->tab_base);
    ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("入住")));
    if(!this->isAdd)
        ui->toolButton->setEnabled(false);
    if(this->index != -1){   
        ui->lineEdit_cardNo->setEnabled(false);
        ui->btn_print->setEnabled(false);
        ui->comboBox_bedLevel->setEnabled(false);
        ui->comboBox_nurseLevel->setEnabled(false);
        QSqlRecord record = model->record(index);
        QString cardNo = record.value("cardNo").toString();
        QSqlQuery query(globaldb);
        query.prepare("select elderId from manage_info where cardNo = ?");
        query.addBindValue(cardNo);
        query.exec();
        int elderId = 0;
        if(query.first())
            elderId = query.value(0).toInt();
        query.finish();
        getElderBaseInfo(elderId);
        getElderHealthInfo(elderId);
        getElderRelativeInfo(elderId);
        query.prepare("select cardNo,contractNo,status,buildingName,regionNo,roomNo,bedNo,bedLevel,bedCost,nurseLevel,nurseCost,nurserName,"
                      "isCuff,cuffNo,cuffStartTime,cuffEndTime,isMattress,resideDate,outDate,levelChanged,account,settleDate,agreement,remark,operator,"
                      "operationTime from manage_info where elderId = ?");
        query.addBindValue(elderId);
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        if(query.first()){
            ui->lineEdit_cardNo->setText(query.value(0).toString());
            ui->lineEdit_contractNo->setText(query.value(1).toString());
            qDebug()<<query.value(2).toInt();
            if(query.value(2).toInt() == 1)
                ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("入住")));
            else if(query.value(2).toInt() == 2)
                ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("请假")));
            else
                ui->comboBox_status->setCurrentIndex(ui->comboBox_status->findText(tr("退住")));
            ui->lineEdit_buildingName->setText(query.value(3).toString());
            ui->lineEdit_regionNo->setText(query.value(4).toString());
            ui->lineEdit_roomNo->setText(query.value(5).toString());
            ui->lineEdit_bedNo->setText(query.value(6).toString());
            ui->comboBox_bedLevel->setCurrentIndex(ui->comboBox_bedLevel->findText(query.value(7).toString()));
            ui->lineEdit_bedCost->setText(query.value(8).toString());
            ui->comboBox_nurseLevel->setCurrentIndex(ui->comboBox_nurseLevel->findText(query.value(9).toString()));
            ui->lineEdit_nurseCost->setText(query.value(10).toString());
            ui->lineEdit_nurseName->setText(query.value(11).toString());
            ui->checkBox_isCuff->setChecked(query.value(12).toInt() == 1);
            ui->lineEdit_cuffNo->setText(query.value(13).toString());
            ui->dateTimeEdit_cuffStartTime->setDateTime(query.value(14).toDateTime());
            ui->dateTimeEdit_cuffEndTime->setDateTime(query.value(15).toDateTime());
            ui->checkBox_isMattress->setChecked(query.value(16).toInt() == 1);
            ui->dateEdit_resideDate->setDate(query.value(17).toDate());
            ui->dateEdit_outDate->setDate(query.value(18).toDate());
            ui->checkBox_levelChanged->setChecked(query.value(19).toInt() == 1);
            ui->lineEdit_account->setText(query.value(20).toString());
            ui->dateEdit_settleDate->setDate(query.value(21).toDate());
            QPixmap pix;
            pix.loadFromData(query.value(22).toByteArray());
            ui->label_agreement->setPixmap(pix);
            ui->lineEdit_manageRemark->setText(query.value(23).toString());
            ui->lineEdit_operator->setText(query.value(24).toString());
            ui->dateTimeEdit_operationTime->setDateTime(query.value(25).toDateTime());
        }
    }
    if(ui->comboBox_status->currentText().compare(tr("退住")) != 0)
        ui->dateEdit_outDate->setEnabled(false);
}

void ResideRegisterDialog::initModel(){
    ms = new ManualSettle;
    relativeModel = new QStandardItemModel(this);
    relativeModel->setColumnCount(5);
    relativeModel->setHeaderData(0,Qt::Horizontal,tr("姓名"));
    relativeModel->setHeaderData(1,Qt::Horizontal,tr("性别"));
    relativeModel->setHeaderData(2,Qt::Horizontal,tr("关系"));
    relativeModel->setHeaderData(3,Qt::Horizontal,tr("联系电话"));
    relativeModel->setHeaderData(4,Qt::Horizontal,tr("工作单位"));
}

void ResideRegisterDialog::on_btn_save_clicked()
{
    QSqlQuery query(globaldb);
    if(this->isAdd){
        query.prepare("insert into manage_info values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit_cardNo->text());
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
        query.addBindValue(ui->lineEdit_name->text());
    }
    else{
        query.prepare("update manage_info set contractNo = ?,status = ?,buildingName = ?, regionNo =?,roomNo=?,bedNo=?,bedLevel=?,"
                      "bedCost=?,nurseLevel=?,nurseCost=?,nurserName=?,isCuff=?,cuffNo=?,cuffStartTime=?,cuffEndTime=?,isMattress=?,resideDate=?,outDate=?,"
                      "levelChanged=?,account=?,settleDate=?,agreement=?,remark=?,operator=?,operationTime=?  where elderId = ?");
    }
    query.addBindValue(ui->lineEdit_contractNo->text());
    if(ui->comboBox_status->currentText().compare(tr("入住")) == 0)
        query.addBindValue(1);
    else if(ui->comboBox_status->currentText().compare(tr("请假")) == 0)
        query.addBindValue(2);
    else{
        query.addBindValue(3);
        ms->expenseSettle(ui->lineEdit_cardNo->text(),ui->dateEdit_outDate->date());
        this->recedeProcess(ui->lineEdit_elderId->text().toInt());
    }
    query.addBindValue(ui->lineEdit_buildingName->text());
    query.addBindValue(ui->lineEdit_regionNo->text());
    query.addBindValue(ui->lineEdit_roomNo->text());
    query.addBindValue(ui->lineEdit_bedNo->text());
    query.addBindValue(ui->comboBox_bedLevel->currentText());
    query.addBindValue(ui->lineEdit_bedCost->text().toFloat());
    query.addBindValue(ui->comboBox_nurseLevel->currentText());
    query.addBindValue(ui->lineEdit_nurseCost->text().toFloat());
    query.addBindValue(ui->lineEdit_nurseName->text());
    query.addBindValue(ui->checkBox_isCuff->isChecked()?1:0);
    query.addBindValue(ui->lineEdit_cuffNo->text());
    query.addBindValue(ui->dateTimeEdit_cuffStartTime->dateTime());
    query.addBindValue(ui->dateTimeEdit_cuffEndTime->dateTime());
    query.addBindValue(ui->checkBox_isMattress->isChecked()?1:0);
    query.addBindValue(ui->dateEdit_resideDate->date());
    if(ui->comboBox_status->currentText().compare(tr("退住")) == 0)
        query.addBindValue(ui->dateEdit_outDate->date());
    else
        query.addBindValue(NULL);
    query.addBindValue(ui->checkBox_levelChanged->isChecked()?1:0);
    query.addBindValue(ui->lineEdit_account->text().toFloat());
    query.addBindValue(NULL);
    if(this->isImage){
        QByteArray bytes;
        QBuffer buffer(&bytes);
        buffer.open(QIODevice::WriteOnly);
        ui->label_agreement->pixmap()->save(&buffer,"JPG");
        query.addBindValue(bytes);
    }
    else
        query.addBindValue(NULL);
    query.addBindValue(ui->lineEdit_manageRemark->text());
    query.addBindValue(ui->lineEdit_operator->text());
    query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());

    if(!this->isAdd)
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
    query.exec();
    if(query.lastError().isValid()){
         QMessageBox::about(0,tr("警告"),tr("数据保存失败"));
        qDebug()<<query.lastError();
    }
    query.finish();
    query.prepare("update elder_info set birth_date = ?,device_id = ?,building_no = ?,floor_no= ?,room_no = ?,bed_no = ?,mat = ?,ic = ?,rfID = ? where eid = ?" );
    query.addBindValue(ui->dateEdit_birthday->date());
    query.addBindValue(this->getDeviceId(ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text().toInt(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text().toInt()));
    query.addBindValue(ui->lineEdit_buildingName->text());
    query.addBindValue(ui->lineEdit_regionNo->text().toInt());
    query.addBindValue(ui->lineEdit_roomNo->text());
    query.addBindValue(ui->lineEdit_bedNo->text().toInt());
    query.addBindValue(ui->checkBox_isMattress->isChecked()?1:0);
    query.addBindValue(ui->lineEdit_cardNo->text());
    query.addBindValue(ui->lineEdit_cuffNo->text());
    query.addBindValue(ui->lineEdit_elderId->text().toInt());
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.clear();

    saveRelativeInfo();
    changeElderResideStatus();
    if(ui->checkBox_isMattress->isChecked() && ui->comboBox_status->currentText().compare(tr("退住")) != 0)
    {
        smt->sendAddMat(ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text());
        this->updateMattressState(true,ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text().toInt(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text().toInt());
    }
    else
    {
        smt->sendDelMat(ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text());
        this->updateMattressState(false,ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text().toInt(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text().toInt());
    }
    smt->sendUpdateRF();
    this->accept();
}

void ResideRegisterDialog::saveRelativeInfo(){
    QSqlQuery query(globaldb);
    query.prepare("delete from relative_info where elderId = ?");
    query.addBindValue(ui->lineEdit_elderId->text().toInt());
    query.exec();
    query.finish();
    for(unsigned char i = 0;i<relativeModel->rowCount();++i){
        query.prepare("insert into relative_info values (NULL,?,?,?,?,?,?,?,?)");
        query.addBindValue(ui->lineEdit_elderId->text().toInt());
        query.addBindValue(relativeModel->item(i,0)->text());
        query.addBindValue(relativeModel->item(i,1)->text());
        query.addBindValue(relativeModel->item(i,2)->text());
        query.addBindValue(relativeModel->item(i,3)->text());
        query.addBindValue(relativeModel->item(i,4)->text());
        query.addBindValue(ui->lineEdit_operator->text());
        query.addBindValue(ui->dateTimeEdit_operationTime->dateTime());
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        query.finish();
    }
}

void ResideRegisterDialog::changeElderResideStatus(){
    QSqlQuery query(globaldb);
    query.prepare("update elder_info set resideRegister = 1 where eid = ?");
    query.addBindValue(ui->lineEdit_elderId->text().toInt());
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
}

void ResideRegisterDialog::on_btn_cancel_clicked()
{
    this->reject();
}

void ResideRegisterDialog::on_toolButton_clicked()
{
    dialog = new ElderBaseInfoChooseDialog(this,1,0);
    connect(dialog,SIGNAL(sendElderChoosed(int)),this,SLOT(doubleClickRecord(int)));
    dialog->exec();
}

void ResideRegisterDialog::on_btn_uploading_clicked()
{
    QString strImage = QFileDialog::getOpenFileName(this,tr("Open Image"),"/",tr("Image Files(*.jpg *.png *.bmp)"));
    qDebug()<<strImage;
    if(strImage.isEmpty())
        return;
    QPixmap pix(strImage);
    ui->label_agreement->setPixmap(pix.scaled(171,211,Qt::KeepAspectRatio));
    this->isImage = true;
}

void ResideRegisterDialog::on_btn_add_clicked()
{
    int row = relativeModel->rowCount();
    QStandardItem *item = new QStandardItem(tr("新建项目"));
    relativeModel->setItem(row,0, item);
    relativeModel->setItem(row,1, new QStandardItem(tr("新建项目")));
    relativeModel->setItem(row,2, new QStandardItem(tr("新建项目")));
    relativeModel->setItem(row,3, new QStandardItem(tr("新建项目")));
    relativeModel->setItem(row,4, new QStandardItem(tr("新建项目")));
    QModelIndex index = relativeModel->indexFromItem(item);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}

void ResideRegisterDialog::on_btn_delete_clicked()
{
    relativeModel->removeRow(ui->tableView->currentIndex().row());
}

void ResideRegisterDialog::doubleClickRecord(int elderId){
    getElderBaseInfo(elderId);
    getElderHealthInfo(elderId);
}

void ResideRegisterDialog::getElderBaseInfo(int id){
    QSqlQuery query(globaldb);
    query.prepare("select name,gender,nation,cardType,cardNo,birthday,isLunar,lunarBirthday,residence,belief,education,hobby,remark,image from elder_info where eid = ?");
    query.addBindValue(id);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if(query.first()){
        ui->lineEdit_elderId->setText(tr("%1").arg(id));
        ui->lineEdit_name->setText(query.value(0).toString());
        ui->comboBox_gender->setCurrentIndex(ui->comboBox_gender->findText(query.value(1).toString()));
        ui->lineEdit_nation->setText(query.value(2).toString());
        ui->comboBox_identityType->setCurrentIndex(ui->comboBox_identityType->findText(query.value(3).toString()));
        ui->lineEdit_identityNo->setText(query.value(4).toString());
        ui->dateEdit_birthday->setDate(query.value(5).toDate());
        ui->checkBox_isLunar->setChecked(query.value(6).toInt() == 1);
        ui->dateEdit_lunarBirthday->setDate(query.value(7).toDate());
        ui->lineEdit_residence->setText(query.value(8).toString());
        ui->lineEdit_belief->setText(query.value(9).toString());
        ui->comboBox_education->setCurrentIndex(ui->comboBox_education->findText(query.value(10).toString()));
        ui->lineEdit_hobby->setText(query.value(11).toString());
        ui->lineEdit_elderRemark->setText(query.value(12).toString());
        QPixmap pix;
        pix.loadFromData(query.value(13).toByteArray());
        ui->label_photo->setPixmap(pix);
    }
    query.finish();
    query.clear();
}

void ResideRegisterDialog::getElderHealthInfo(int id){
    QSqlQuery query(globaldb);
    query.prepare("select height,weight,bloodType,bloodPressureLow,bloodPressureHigh,pulse,leftEyesight,"
                  "rightEyesight,memory,hearing,mind,selfNurse,diet,excretion,allergy,medicine,familyMedical,"
                  "personalMedical,nurseSuggestion,remark from health_assess where elderId = ?");
    query.addBindValue(id);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if(query.first()){
        ui->lineEdit_height->setText(query.value(0).toString());
        ui->lineEdit_weight->setText(query.value(1).toString());
        ui->comboBox_bloodType->setCurrentIndex(ui->comboBox_bloodType->findText(query.value(2).toString()));
        ui->lineEdit_bloodPressureLow->setText(query.value(3).toString());
        ui->lineEdit_bloodPressureHigh->setText(query.value(4).toString());
        ui->lineEdit_pulse->setText(query.value(5).toString());
        ui->lineEdit_leftEyesight->setText(query.value(6).toString());
        ui->lineEdit_rightEyesight->setText(query.value(7).toString());
        ui->comboBox_memory->setCurrentIndex(ui->comboBox_memory->findText(query.value(8).toString()));
        ui->comboBox_hearing->setCurrentIndex(ui->comboBox_hearing->findText(query.value(9).toString()));
        ui->comboBox_mind->setCurrentIndex(ui->comboBox_mind->findText(query.value(10).toString()));
        ui->comboBox_selfNurse->setCurrentIndex(ui->comboBox_selfNurse->findText(query.value(11).toString()));
        ui->lineEdit_diet->setText(query.value(12).toString());
        ui->comboBox_excretion->setCurrentIndex(ui->comboBox_excretion->findText(query.value(13).toString()));
        ui->lineEdit_allergy->setText(query.value(14).toString());
        ui->lineEdit_medicine->setText(query.value(15).toString());
        ui->lineEdit_familyMedical->setText(query.value(16).toString());
        ui->lineEdit_personalMedical->setText(query.value(17).toString());
        ui->comboBox_nurseSuggestion->setCurrentIndex(ui->comboBox_nurseSuggestion->findText(query.value(18).toString()));
        ui->lineEdit_manageRemark->setText(query.value(19).toString());
    }
    query.finish();
    query.clear();
}

void ResideRegisterDialog::getElderRelativeInfo(int id){
    QSqlQuery query(globaldb);
    query.prepare("select name,gender,relationship,telephone,job from relative_info where elderId = ?");
    query.addBindValue(id);
    query.exec();
    unsigned char i = 0;
    while(query.next()){
        relativeModel->setItem(i,0,new QStandardItem(query.value(0).toString()));
        relativeModel->setItem(i,1,new QStandardItem(query.value(1).toString()));
        relativeModel->setItem(i,2,new QStandardItem(query.value(2).toString()));
        relativeModel->setItem(i,3,new QStandardItem(query.value(3).toString()));
        relativeModel->setItem(i,4,new QStandardItem(query.value(4).toString()));
        ++i;
    }
    query.clear();
    query.finish();
}

void ResideRegisterDialog::on_comboBox_bedLevel_currentIndexChanged(const QString &name)
{
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(1);
    if(name.compare(tr("")) != 0)
        ui->lineEdit_bedCost->setText(map.find(name).value());
    else
        ui->lineEdit_bedCost->setText(tr(""));
}

void ResideRegisterDialog::on_comboBox_nurseLevel_currentIndexChanged(const QString &name)
{
    QMap<QString,QString> map = Dictionary::getExpenseMapByType(2);
    if(name.compare(tr("")) != 0)
        ui->lineEdit_nurseCost->setText(map.find(name).value());
    else
        ui->lineEdit_nurseCost->setText(tr(""));
}

void ResideRegisterDialog::on_btn_print_clicked()
{

}

void ResideRegisterDialog::on_comboBox_status_currentIndexChanged(const QString &status)
{
    if(status.compare(tr("退住")) == 0)
        ui->dateEdit_outDate->setEnabled(true);
    else
        ui->dateEdit_outDate->setEnabled(false);
}

int ResideRegisterDialog::getDeviceId(QString buildingName, int floorNo, QString roomName, int bedNo){
    QSqlQuery query(globaldb);
    query.prepare("select device_id from device_info where building_no = ? and floor_no = ? and room_name = ? and bed_no = ?");
    query.addBindValue(buildingName);
    query.addBindValue(floorNo);
    query.addBindValue(roomName);
    query.addBindValue(bedNo);
    query.exec();
    int id = 0;
    if(query.first())
        id = query.value(0).toInt();
    query.clear();
    return id;
}

void ResideRegisterDialog::recedeProcess(int elderId){
    QSqlQuery query(globaldb);
    query.prepare("update elder_info set birth_date = NULL,device_id = NULL,building_no = NULL,floor_no= NULL,room_no = NULL,bed_no = NULL,mat = NULL,ic = NULL,"
                  "rfID = NULL where eid = ?");
    query.addBindValue(elderId);
    query.exec();
    smt->sendDelMat(ui->lineEdit_buildingName->text(),ui->lineEdit_regionNo->text(),ui->lineEdit_roomNo->text(),ui->lineEdit_bedNo->text());
}

void ResideRegisterDialog::updateMattressState(bool isAdd,QString buildingName, int floorNo, QString roomName, int bedNo){
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

void ResideRegisterDialog::on_toolButton_bed_clicked()
{
    bedDialog = new BedChooseDialog(this);
    bedDialog->exec();
}

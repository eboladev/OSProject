#include "elderinfo.h"
#include "struct.h"
#include "ui_elderinfo.h"
#include <QMessageBox>
#include <QFileDialog>


extern QStringList floornames;
ElderInfo::ElderInfo(COMANDTYPE command, QStringList &plist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElderInfo)
{
    ui->setupUi(this);
    qDebug()<<"plist"<<plist;
    roomid = -1;
    bedno = -1;
    globaldb.open();
    connect(ui->building_comboBox_8,SIGNAL(currentIndexChanged(int)),this,SLOT(buildingChanged()));
    connect(ui->floorno_comboBox_9,SIGNAL(currentIndexChanged(int)),this,SLOT(floorChanged()));
    connect(ui->roomno_comboBox_7,SIGNAL(currentIndexChanged(int)),this,SLOT(roomChanged()));
    connect(ui->modifyButton,SIGNAL(clicked()),this,SLOT(modifyImage()));
    connect(ui->save_pushButton,SIGNAL(clicked()),this,SLOT(saveElder()));
    connect(ui->close_pushButton_2,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->roomview_pushButton,SIGNAL(clicked()),this,SLOT(onRoomView()));
    connect(ui->ic_lineedit_2,SIGNAL(editingFinished()),this,SLOT(dynamicSetBirthDate()));
    connect(this,SIGNAL(refresh()),this,SLOT(dialogInit()));
    ui->roomview_pushButton->hide();

    commandType = command;
    if(commandType == VIEWELDER)
        ui->roomview_pushButton->show();
    switch (command) {
    case NEWELDER:
        this->setWindowTitle("添加老人");
        elderID = -1;
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":"+ plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    case SCANELDER:
        this->setWindowTitle("编辑老人信息");
        elderID = plist.at(0).toInt();
        break;
    case EDITELDER:
        this->setWindowTitle("编辑老人信息");
        elderID = getDeviceID(plist);
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":" + plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    case VIEWELDER:
        this->setWindowTitle("查看老人信息");
        elderID = getDeviceID(plist);
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":" + plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    default:
        break;
    }

    ui->sex_comboBox_13->addItem("女");
    ui->sex_comboBox_13->addItem("男");
    QStringList list;
    list<<"身体健康"<<"瘫痪在床"<<"行动不便"<<"正常起居"<<"出院";
    for(int i = 0;i < list.size();i ++)
        ui->bodystate_comboBox_12->addItem(list.at(i));
    if(commandType == NEWELDER)
        ui->bodystate_comboBox_12->removeItem(list.size()-1);
    list.clear();
    list<<"一级监护"<<"二级监护"<<"三级监护";
    for(int j = 0;j < list.size();j ++)
        ui->servicetype_comboBox_10->addItem(list.at(j));
    ui->mat_comboBox_11->addItem("无");
    ui->mat_comboBox_11->addItem("有");


    dialogInit();
    flag = 1;
//    ui->floorno_comboBox_9->setEnabled(false);
//    ui->building_comboBox_8->setEnabled(false);
    setReadOnly(commandType);
    if(commandType == NEWELDER)
    {
        ui->building_comboBox_8->setCurrentIndex(
                    ui->building_comboBox_8->findText(plist.at(0)));
        ui->floorno_comboBox_9->setCurrentIndex(
                    ui->floorno_comboBox_9->findText(plist.at(1) + "楼"));
        ui->roomno_comboBox_7->setCurrentIndex(
                    ui->roomno_comboBox_7->findText(plist.at(2)));
        ui->bed_comboBox_8->setCurrentIndex(
                    ui->bed_comboBox_8->findText(plist.at(3) + "号床"));

    }
    ui->custominfo_groupbox->hide();
    dynamicSetBirthDate();
    qDebug()<<"record"<<plist<<elderID<<commandType;
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

ElderInfo::~ElderInfo()
{
    qDebug()<<"析构函数";
    delete ui;
}



/*bool ElderInfo::createDbConnetion()
{
    db = QSqlDatabase::addDatabase("QMYSQL","ElderManager");
    db.setHostName(HOSTADDRESS);
    db.setDatabaseName(globalDBName);
    db.setUserName("shy");
    db.setPassword("shy");
    bool ok = db.open();
    return ok;
}*/



void ElderInfo::setValid(bool valid)
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql = QString("update elder_info set valid = ? where eid = %1").arg(elderID);
        query.prepare(sql);
        query.addBindValue(valid);
        query.exec();
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::setValid 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}

void ElderInfo::dialogInit()
{
    //building combobox init
    globaldb.open();
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery(QString("select distinct building_no from device_info"),globaldb);
    ui->building_comboBox_8->setModel(queryModel);
    ui->building_comboBox_8->setModelColumn(0);

    QSqlQueryModel *recordModel = new QSqlQueryModel(this);
    recordModel->setQuery(QString("select * from elder_info where eid = '%1'").arg(elderID),globaldb);
    record = recordModel->record(0);
    if(!record.isEmpty() && commandType == VIEWELDER)
    {
        if(record.value(25).toInt() == 0)       //record中valid字段为0，为历史记录，设为不可编辑
        {
            QList<QLineEdit*> leList = this->findChildren<QLineEdit*>();
            for(int i = 0;i < leList.size();i ++)
                leList.at(i)->setDisabled(true);
            QList<QComboBox*> comList = this->findChildren<QComboBox*>();
            for(int j = 0;j < comList.size();j ++)
                comList.at(j)->setDisabled(true);
            ui->modifyButton->setEnabled(false);
            ui->save_pushButton->setEnabled(false);
        }
    }
//    if(commandType != NEWELDER)
///        ui->name_lineedit_2->setEnabled(false);
    ui->name_lineedit_2->setText(record.value(1).toString());
    ui->sex_comboBox_13->setCurrentIndex(
                ui->sex_comboBox_13->findText(record.value(2).toString()));
    /*
    ui->birth_dateEdit->setDate(QDate::fromString(ui->ic_lineedit_2->text().mid(7,8),"yyyymmdd"));
    qDebug()<<QDate::fromString(ui->ic_lineedit_2->text().mid(7,8),"yyyymmdd")
           <<"*************************************************************************"
             <<ui->ic_lineedit_2->text().mid(7,8);*/
    //ui->birth_dateEdit->setReadOnly(true);
    ui->building_comboBox_8->setCurrentIndex(
                ui->building_comboBox_8->findText(record.value(5).toString()));
    ui->floorno_comboBox_9->setCurrentIndex(
                ui->floorno_comboBox_9->findText(record.value(6).toString() + "楼"));
    ui->roomno_comboBox_7->setCurrentIndex(
                ui->roomno_comboBox_7->findText(record.value(7).toString()));
    ui->bed_comboBox_8->addItem(record.value(8).toString() + "号床");
    ui->bed_comboBox_8->setCurrentIndex(ui->bed_comboBox_8->count() - 1);
//    ui->bed_comboBox_8->setCurrentIndex(
  //              ui->bed_comboBox_8->findText(record.value(8).toString() + "号床"));
    ui->bodystate_comboBox_12->setCurrentIndex(
                ui->bodystate_comboBox_12->findText(record.value(9).toString()));
    ui->servicetype_comboBox_10->setCurrentIndex(record.value(10).toInt() - 1);
    ui->mat_comboBox_11->setCurrentIndex(record.value(11).toInt());

    QRegExp rx("[1-9]\\d{5}[1-2]\\d{3}(0[1-9]|1[0-2])([0-2]\\d|3[0-1])\\d{3}(\\d|x)");
    QRegExpValidator* validator = new QRegExpValidator(rx,this);
    ui->ic_lineedit_2->setValidator(validator);

    ui->ic_lineedit_2->setText(record.value(12).toString());
    ui->rf_lineedit->setText(record.value(13).toString());
    ui->tel_lineedit_2->setText(record.value(14).toString());
    ui->contactor_lineedit_2->setText(record.value(15).toString());
    ui->contactortellineedit_2->setText(record.value(16).toString());
    ui->in_dateEdit_2->setDate(record.value(17).toDate());
//    ui->in_dateEdit_2->setReadOnly(true);
    if(commandType == NEWELDER)
        ui->in_dateEdit_2->setDate(QDate::currentDate());
    ui->out_dateEdit_3->setDate(record.value(18).toDate());
    ui->out_dateEdit_3->setDisabled(true);
    QPixmap pix;
    pix.loadFromData(record.value(19).toByteArray());
    ui->photo_label_2->setPixmap(pix);
    ui->tab2LineEdit1->setText(record.value(20).toString());
    ui->timeEdit1->setTime(record.value(21).toTime());
    ui->tab2LineEdit2->setText(record.value(22).toString());
    ui->timeEdit2->setTime(record.value(23).toTime());
    ui->tab2LineEdit3->setText(record.value(24).toString());
    ui->timeEdit3->setTime(record.value(25).toTime());
    ui->deviceID_lineEdit->hide();
    //this->setWindowTitle("信息编辑");
}


void ElderInfo::buildingChanged()
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql = QString("select distinct floor_no from device_info where building_no = '%1' order by floor_no")
                .arg(ui->building_comboBox_8->currentText());
        if(!query.exec(sql))
        {
            qDebug()<<"buildingChanged failed!";
        }
        ui->floorno_comboBox_9->clear();
        while(query.next())
        {
            ui->floorno_comboBox_9->addItem(query.value(0).toString() + "楼");
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::buildingChanged 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}


void ElderInfo::floorChanged()
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql =  QString("select distinct room_name from device_info where building_no = '%1'"
                               "and floor_no = '%2'").arg(ui->building_comboBox_8->currentText())
                .arg(ui->floorno_comboBox_9->currentText().left(1));
        qDebug()<<sql;
        if(!query.exec(sql))
        {
            qDebug()<<"floorChanged failed!";
        }
        ui->roomno_comboBox_7->clear();
        while(query.next())
        {
            ui->roomno_comboBox_7->addItem(query.value(0).toString());
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::floorChanged 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }

}



void ElderInfo::roomChanged()
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql =  QString("select bitmap,bed_no,device_id from device_info where building_no = '%1'"
                               "and floor_no = '%2' and room_name = '%3'")
                .arg(ui->building_comboBox_8->currentText())
                .arg(ui->floorno_comboBox_9->currentText().left(1))
                .arg(ui->roomno_comboBox_7->currentText());
        if(!query.exec(sql))
        {
            qDebug()<<"roomChanged failed!";
        }
        ui->bed_comboBox_8->clear();
        query.next();
        quint32 bitmap = query.value(0).toUInt();
        quint32 bedCounted = query.value(1).toUInt();
        ui->deviceID_lineEdit->setText(query.value(2).toString());
        qDebug()<<sql<<bitmap<<bedCounted;
        for(quint32 i = 1;i <= 6;i ++ )
        {
            if(bedValue(bitmap,i) == 1)
                ui->bed_comboBox_8->addItem(QString("%1号床").arg(i));
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::roomChanged 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }

}

void ElderInfo::modifyImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                    tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    qDebug()<<fileName;
    if(fileName.isEmpty())
        return;
    QPixmap pix(fileName);
    ui->photo_label_2->setPixmap(pix.scaled(116,153,Qt::KeepAspectRatio));

}

void ElderInfo::saveElder()
{
    //判断是否添加人员已经存在


    if(ui->name_lineedit_2->text().simplified().isEmpty() ||
            ui->ic_lineedit_2->text().simplified().size() != 18)
    {
        QMessageBox mess;
        mess.setText("姓名或者身份证号码错误！");
        mess.exec();
        return;
    }
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
    QSqlQuery query(globaldb);
    if(commandType == NEWELDER)
    {
        query.prepare("select distinct ic from elder_info where valid = ?");
        query.addBindValue("1");
        if(query.exec())
        {

        }
        else
        {
            QMessageBox::warning(0,"警告","执行失败!","确定");
        }
        QString curic = ui->ic_lineedit_2->text();
        QString str;
        while(query.next())
        {
             str = query.value(0).toString();
             QMessageBox::warning(0,"警告",str,"确定");
             if(str == curic)
             {
                 QMessageBox::warning(0,"警告","该老人已经入住!","确定");
                 query.clear();
                 query.finish();
                 return;
             }
        }
    }
    QString sql;
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    ui->photo_label_2->pixmap()->save(&buffer, "JPG");
    if(commandType == NEWELDER)
    {
        sql = "insert into elder_info(name,gender,birth_date,device_id,building_no,"
                "floor_no,room_no,bed_no,body_state,service_type,mat,ic,rfID,tel,contactor,"
                "contactor_tel,in_date,out_date,image,hint1,hint1_time,hint2,hint2_time,"
                "hint3,hint3_time,valid) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

    }
    else
    {
        if(ui->building_comboBox_8->currentText() != record.value(5).toString()
                || ui->floorno_comboBox_9->currentText().left(1) != record.value(6).toString()
                || ui->roomno_comboBox_7->currentText() != record.value(7).toString()
                || ui->bed_comboBox_8->currentText().left(1) != record.value(8).toString())
            //换床处理，需要修改bitmap，bedno，type字段
        {
            int ret = QMessageBox::warning(this, "通知",
                                            "确定此位老人换床吗？",
                                            QMessageBox::Yes | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;
            modifyBitmap(record.value(4).toInt(),record.value(8).toInt(),false);
            //从原来房间的bitmap中去掉
            sql = "insert into elder_info(name,gender,birth_date,device_id,building_no,"
                    "floor_no,room_no,bed_no,body_state,service_type,mat,ic,rfID,tel,contactor,"
                    "contactor_tel,in_date,out_date,image,hint1,hint1_time,hint2,hint2_time,"
                    "hint3,hint3_time)values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
            flag = 2;
            qDebug()<<"换床";

        }else if(ui->bodystate_comboBox_12->currentText() == "出院")
            //出院处理，同样需要修改三个字段
        {
            int ret = QMessageBox::warning(this, "通知",
                                            "确定此位老人出院吗？",
                                           QMessageBox::Yes | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;

            modifyBitmap(ui->deviceID_lineEdit->text().toInt(),record.value(8).toInt(),false);
            sql = "insert into elder_info (name,gender,birth_date,device_id,building_no,"
                    "floor_no,room_no,bed_no,body_state,service_type,mat,ic,rfID,tel,contactor,"
                    "contactor_tel,in_date,out_date,image,hint1,hint1_time,hint2,hint2_time,"
                    "hint3,hint3_time)values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
            flag = 3;
            qDebug()<<"出院";
        }
        else
            {
            sql = QString("update elder_info SET name = ?,gender = ?,birth_date = ?,device_id =?,building_no=?,"
                    "floor_no=?,room_no=?,bed_no=?,body_state=?,service_type=?,mat=?,ic=?,rfID=?,tel=?,"
                    "contactor=?,contactor_tel=?,in_date=?,out_date=?,image=?,hint1=?,hint1_time=?,"
                    "hint2=?,hint2_time=?,hint3=?,hint3_time=? WHERE eid = %1").arg(elderID);
            qDebug()<<"更新";
            }
    }
    query.prepare(sql);
    query.bindValue(0,ui->name_lineedit_2->text());
    query.bindValue(1,ui->sex_comboBox_13->currentText());
    query.bindValue(2,ui->birth_dateEdit->date());
    query.bindValue(3,ui->deviceID_lineEdit->text());
    query.bindValue(4,ui->building_comboBox_8->currentText());
    query.bindValue(5,ui->floorno_comboBox_9->currentText().left(1));
    query.bindValue(6,ui->roomno_comboBox_7->currentText());
    query.bindValue(7,ui->bed_comboBox_8->currentText().left(1));
    query.bindValue(8,ui->bodystate_comboBox_12->currentText());
    query.bindValue(9,ui->servicetype_comboBox_10->currentIndex()+1);
    query.bindValue(10,ui->mat_comboBox_11->currentIndex());
    query.bindValue(11,ui->ic_lineedit_2->text());
    query.bindValue(12,ui->rf_lineedit->text());
    query.bindValue(13,ui->tel_lineedit_2->text());
    query.bindValue(14,ui->contactor_lineedit_2->text());
    query.bindValue(15,ui->contactortellineedit_2->text());
    query.bindValue(16,ui->in_dateEdit_2->date());
    if(flag == 3)       //出院
        query.bindValue(17,QDate::currentDate());
    query.bindValue(18,bytes);
    query.bindValue(19,ui->tab2LineEdit1->text());
    query.bindValue(20,ui->timeEdit1->time());
    query.bindValue(21,ui->tab2LineEdit2->text());
    query.bindValue(22,ui->timeEdit2->time());
    query.bindValue(23,ui->tab2LineEdit3->text());
    query.bindValue(24,ui->timeEdit3->time());
    if(commandType == NEWELDER)
        query.bindValue(25,true);
    if(!query.exec())
    {
        qDebug()<<"新建，插入失败"<<query.lastError();
        return;
    }
    if(commandType == NEWELDER)
    {
        modifyBitmap(ui->deviceID_lineEdit->text().toInt(),
                     ui->bed_comboBox_8->currentText().left(1).toInt(),
                     true);             //新的房间更新相应的bitmap
        updateType(ui->deviceID_lineEdit->text().toInt());
        *oldernameptr = ui->name_lineedit_2->text();
        qDebug()<<"添加人员edlderinfo"<<"roomid"<<roomid<<"bedno"<<bedno<<"mat[roomid].bitmap"<<mat[roomid].bitmap;
        if(roomid >= 0 && bedno >= 1)
            {
                if(ui->mat_comboBox_11->currentText() == "有")
                {
                    mat[roomid].bitmap = mat[roomid].bitmap | (quint8)(pow(2,bedno - 1));
                }
                else if(ui->mat_comboBox_11->currentText() == "无")
                {
                    mat[roomid].bitmap = mat[roomid].bitmap & (~(quint8)(pow(2,bedno - 1)));
                }
            }
        qDebug()<<"添加人员edlderinfo"<<"roomid"<<roomid<<"bedno"<<bedno<<"mat[roomid].bitmap"<<mat[roomid].bitmap;
        //this->close();
        this->accept();
    }
    if(flag > 1)
    {
        setValid(false);        //原来的记录无效
        //获取新插入的记录id
        sql = "select last_insert_id();";
        query.exec(sql);
        query.next();
        if(!query.value(0).isNull())
            elderID = query.value(0).toInt();
        if(flag == 3) //出院，新的记录也要invalid
            setValid(false);
        else              //换床，新纪录为valid
        {
            modifyBitmap(ui->deviceID_lineEdit->text().toInt(),
                         ui->bed_comboBox_8->currentText().left(1).toInt(),
                         true);             //新的房间更新相应的bitmap
            setValid(true);
            updateType(ui->deviceID_lineEdit->text().toInt());
        }
        qDebug()<<elderID<<"插入后";
    }
    updateType(ui->deviceID_lineEdit->text().toInt());
    emit refresh();
    query.clear();
    query.finish();

    //修改床位床垫信息
    if(commandType == NEWELDER) return;
    if(roomid >= 0 && bedno >= 1)
    {
        if(ui->mat_comboBox_11->currentText() == "有")
        {
            mat[roomid].bitmap = mat[roomid].bitmap | (quint8)(pow(2,bedno - 1));
        }
        else if(ui->mat_comboBox_11->currentText() == "无")
        {
            mat[roomid].bitmap = mat[roomid].bitmap & (~(quint8)(pow(2,bedno - 1)));
        }
    }
    //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::saveElder 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}



int ElderInfo::getDeviceID(QStringList list)
{
    if(list.size() < 4)
    {
        qDebug()<<"缺少参数";
        return -1;
    }
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql = QString("select eid from elder_info where building_no = '%1' and floor_no = '%2'"
                              " and room_no = '%3' and bed_no = '%4' and valid = 1").arg(list.at(0)).arg(list.at(1).toInt())
                .arg(list.at(2)).arg(list.at(3).toInt());
        query.exec(sql);
        if(query.next())
        {
            return query.value(0).toInt();
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::getDeviceID 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
    return -1;
}



/************************************************************
 *设置各个内容是否可编辑
 *
 ************************************************************/
void ElderInfo::setReadOnly(COMANDTYPE command)
{
    ui->building_comboBox_8->setDisabled(true);
    ui->floorno_comboBox_9->setDisabled(true);
    ui->roomno_comboBox_7->setDisabled(true);
    ui->bed_comboBox_8->setDisabled(true);
    ui->birth_dateEdit->setDisabled(true);
    ui->deviceID_lineEdit->setDisabled(true);
    switch (command) {
    case NEWELDER:
        /*ui->building_comboBox_8->setDisabled(true);
        ui->floorno_comboBox_9->setEnabled(false);
        ui->roomno_comboBox_7->setEnabled(false);
        ui->bed_comboBox_8->setEnabled(false);*/
        break;
    case EDITELDER:
    case SCANELDER:
//       ui->name_lineedit_2->setReadOnly(true);
        //by nan
        ui->name_lineedit_2->setDisabled(true);
        ui->deviceID_lineEdit->setEnabled(true);
        break;
    case VIEWELDER:
    {
        QList<QLineEdit*> lList = this->findChildren<QLineEdit*>();
        for(int i = 0;i < lList.size();i ++)
            lList.at(i)->setDisabled(true);
        QList<QComboBox*> cList = this->findChildren<QComboBox*>();
        for(int j = 0;j < cList.size();j ++)
            cList.at(j)->setEnabled(false);
        ui->modifyButton->setDisabled(true);
        ui->in_dateEdit_2->setDisabled(true);
        qDebug()<<"setreadonly";
        //by nan
        ui->close_pushButton_2->hide();
        break;
    }
    default:
        break;
    }
}


void ElderInfo::updateType(int deviceID)
{
    QSqlQuery query(QString("select distinct gender from elder_info where device_id = %1 and valid = 1")
                    .arg(deviceID),globaldb);
    quint8 type = 0;
    query.exec();
    if(query.next())
    {
        if(query.size() > 1)
            type = 3;
        else
        {
            if(query.value(0).toString() == "男")
                type = 1;
            else
                type = 2;
        }
    }
    qDebug()<<type<<"类型为:"<<deviceID<<query.size();
    QString sql = QString("update device_info set type = %1 where device_id = %2")
            .arg(type).arg(deviceID);
    query.exec(sql);
}






/*************************************************************
 *计算bedNo号床的值，0为没床，1为空床没人住，2为有人住，3保留未使用
 *
 ************************************************************/
quint8 ElderInfo::bedValue(quint32 bitmap, quint8 bedNo)
{
    bitmap = bitmap >> 2*(bedNo - 1);
    return bitmap & 3;
}

void ElderInfo::modifyBitmap(qint32 did,quint8 bedno, bool in)
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        QString sql = QString("select bitmap from device_info where device_id = '%1'")
                .arg(did);
        query.exec(sql);
        query.next();
        quint32 bitmap = query.value(0).toUInt();
        qDebug()<<did<<bitmap<<in<<"原始值";
        if(in)                  //入院
        {
            bitmap = setN0(bitmap,2 * (bedno - 1));
            bitmap = setN1(bitmap,2 * (bedno - 1) + 1);

        }else                   //出院
        {
            bitmap = setN1(bitmap,2 * (bedno - 1));
            bitmap = setN0(bitmap,2 * (bedno - 1) + 1);
        }
        qDebug()<<bitmap;
        sql = QString("update device_info set bitmap = ? where device_id = '%1'").arg(did);
        query.prepare(sql);
        query.addBindValue(bitmap);
        if(!query.exec())
            qDebug()<<query.lastError()<<"修改bitmap";
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::modifyBitmap 数据库连接失败！";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"警告","数据库连接失败！","确定");
        }
    }
}

quint32 ElderInfo::setN0(quint32 bitmap, quint8 n)
{
    bitmap &= ~(1<<n);
    return bitmap;
}

quint32 ElderInfo::setN1(quint32 bitmap, quint8 n)
{
    bitmap |= (1<<n);
    return bitmap;

}

void ElderInfo::setOlder(QString * oldernameptr)
{
    this->oldernameptr = oldernameptr;
}


void ElderInfo::onRoomView()
{
    QString tempfloorstr = ui->floorno_comboBox_9->currentText();
    int floornum = tempfloorstr.left(tempfloorstr.count() - 1).toInt();
    emit locateAndOpenRoom(ui->building_comboBox_8->currentText(),floornames.at(floornum - 1),ui->roomno_comboBox_7->currentText());
}

//set the birth date from ic no
void ElderInfo::dynamicSetBirthDate()
{
    if(ui->ic_lineedit_2->text().size() == 18)
        ui->birth_dateEdit->setDate(QDate::fromString(ui->ic_lineedit_2->text().mid(6,8),"yyyyMMdd"));
    else
        ui->birth_dateEdit->setDate(QDate(1970,13,1));

}


void ElderInfo::closeEvent(QCloseEvent * event)
{
    //globaldb.close();
    QDialog::closeEvent(event);
}
void ElderInfo::setLookupRoomEnable(bool flag)
{
    ui->roomview_pushButton->setVisible(flag);
}

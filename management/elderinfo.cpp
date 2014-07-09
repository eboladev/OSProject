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
        this->setWindowTitle("�������");
        elderID = -1;
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":"+ plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    case SCANELDER:
        this->setWindowTitle("�༭������Ϣ");
        elderID = plist.at(0).toInt();
        break;
    case EDITELDER:
        this->setWindowTitle("�༭������Ϣ");
        elderID = getDeviceID(plist);
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":" + plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    case VIEWELDER:
        this->setWindowTitle("�鿴������Ϣ");
        elderID = getDeviceID(plist);
        roomid = roomnameToIds[plist.at(0)+":"+floornames.at(plist.at(1).toInt()-1)+":" + plist.at(2)];
        bedno = plist.at(3).toInt();
        break;
    default:
        break;
    }

    ui->sex_comboBox_13->addItem("Ů");
    ui->sex_comboBox_13->addItem("��");
    QStringList list;
    list<<"���彡��"<<"̱���ڴ�"<<"�ж�����"<<"�������"<<"��Ժ";
    for(int i = 0;i < list.size();i ++)
        ui->bodystate_comboBox_12->addItem(list.at(i));
    if(commandType == NEWELDER)
        ui->bodystate_comboBox_12->removeItem(list.size()-1);
    list.clear();
    list<<"һ���໤"<<"�����໤"<<"�����໤";
    for(int j = 0;j < list.size();j ++)
        ui->servicetype_comboBox_10->addItem(list.at(j));
    ui->mat_comboBox_11->addItem("��");
    ui->mat_comboBox_11->addItem("��");


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
                    ui->floorno_comboBox_9->findText(plist.at(1) + "¥"));
        ui->roomno_comboBox_7->setCurrentIndex(
                    ui->roomno_comboBox_7->findText(plist.at(2)));
        ui->bed_comboBox_8->setCurrentIndex(
                    ui->bed_comboBox_8->findText(plist.at(3) + "�Ŵ�"));

    }
    ui->custominfo_groupbox->hide();
    dynamicSetBirthDate();
    qDebug()<<"record"<<plist<<elderID<<commandType;
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

ElderInfo::~ElderInfo()
{
    qDebug()<<"��������";
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
        qDebug()<<"ElderInfo::setValid ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
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
        if(record.value(25).toInt() == 0)       //record��valid�ֶ�Ϊ0��Ϊ��ʷ��¼����Ϊ���ɱ༭
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
                ui->floorno_comboBox_9->findText(record.value(6).toString() + "¥"));
    ui->roomno_comboBox_7->setCurrentIndex(
                ui->roomno_comboBox_7->findText(record.value(7).toString()));
    ui->bed_comboBox_8->addItem(record.value(8).toString() + "�Ŵ�");
    ui->bed_comboBox_8->setCurrentIndex(ui->bed_comboBox_8->count() - 1);
//    ui->bed_comboBox_8->setCurrentIndex(
  //              ui->bed_comboBox_8->findText(record.value(8).toString() + "�Ŵ�"));
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
    //this->setWindowTitle("��Ϣ�༭");
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
            ui->floorno_comboBox_9->addItem(query.value(0).toString() + "¥");
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::buildingChanged ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
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
        qDebug()<<"ElderInfo::floorChanged ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
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
                ui->bed_comboBox_8->addItem(QString("%1�Ŵ�").arg(i));
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::roomChanged ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
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
    //�ж��Ƿ������Ա�Ѿ�����


    if(ui->name_lineedit_2->text().simplified().isEmpty() ||
            ui->ic_lineedit_2->text().simplified().size() != 18)
    {
        QMessageBox mess;
        mess.setText("�����������֤�������");
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
            QMessageBox::warning(0,"����","ִ��ʧ��!","ȷ��");
        }
        QString curic = ui->ic_lineedit_2->text();
        QString str;
        while(query.next())
        {
             str = query.value(0).toString();
             QMessageBox::warning(0,"����",str,"ȷ��");
             if(str == curic)
             {
                 QMessageBox::warning(0,"����","�������Ѿ���ס!","ȷ��");
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
            //����������Ҫ�޸�bitmap��bedno��type�ֶ�
        {
            int ret = QMessageBox::warning(this, "֪ͨ",
                                            "ȷ����λ���˻�����",
                                            QMessageBox::Yes | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;
            modifyBitmap(record.value(4).toInt(),record.value(8).toInt(),false);
            //��ԭ�������bitmap��ȥ��
            sql = "insert into elder_info(name,gender,birth_date,device_id,building_no,"
                    "floor_no,room_no,bed_no,body_state,service_type,mat,ic,rfID,tel,contactor,"
                    "contactor_tel,in_date,out_date,image,hint1,hint1_time,hint2,hint2_time,"
                    "hint3,hint3_time)values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
            flag = 2;
            qDebug()<<"����";

        }else if(ui->bodystate_comboBox_12->currentText() == "��Ժ")
            //��Ժ����ͬ����Ҫ�޸������ֶ�
        {
            int ret = QMessageBox::warning(this, "֪ͨ",
                                            "ȷ����λ���˳�Ժ��",
                                           QMessageBox::Yes | QMessageBox::Cancel);
            if(ret == QMessageBox::Cancel)
                return;

            modifyBitmap(ui->deviceID_lineEdit->text().toInt(),record.value(8).toInt(),false);
            sql = "insert into elder_info (name,gender,birth_date,device_id,building_no,"
                    "floor_no,room_no,bed_no,body_state,service_type,mat,ic,rfID,tel,contactor,"
                    "contactor_tel,in_date,out_date,image,hint1,hint1_time,hint2,hint2_time,"
                    "hint3,hint3_time)values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
            flag = 3;
            qDebug()<<"��Ժ";
        }
        else
            {
            sql = QString("update elder_info SET name = ?,gender = ?,birth_date = ?,device_id =?,building_no=?,"
                    "floor_no=?,room_no=?,bed_no=?,body_state=?,service_type=?,mat=?,ic=?,rfID=?,tel=?,"
                    "contactor=?,contactor_tel=?,in_date=?,out_date=?,image=?,hint1=?,hint1_time=?,"
                    "hint2=?,hint2_time=?,hint3=?,hint3_time=? WHERE eid = %1").arg(elderID);
            qDebug()<<"����";
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
    if(flag == 3)       //��Ժ
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
        qDebug()<<"�½�������ʧ��"<<query.lastError();
        return;
    }
    if(commandType == NEWELDER)
    {
        modifyBitmap(ui->deviceID_lineEdit->text().toInt(),
                     ui->bed_comboBox_8->currentText().left(1).toInt(),
                     true);             //�µķ��������Ӧ��bitmap
        updateType(ui->deviceID_lineEdit->text().toInt());
        *oldernameptr = ui->name_lineedit_2->text();
        qDebug()<<"�����Աedlderinfo"<<"roomid"<<roomid<<"bedno"<<bedno<<"mat[roomid].bitmap"<<mat[roomid].bitmap;
        if(roomid >= 0 && bedno >= 1)
            {
                if(ui->mat_comboBox_11->currentText() == "��")
                {
                    mat[roomid].bitmap = mat[roomid].bitmap | (quint8)(pow(2,bedno - 1));
                }
                else if(ui->mat_comboBox_11->currentText() == "��")
                {
                    mat[roomid].bitmap = mat[roomid].bitmap & (~(quint8)(pow(2,bedno - 1)));
                }
            }
        qDebug()<<"�����Աedlderinfo"<<"roomid"<<roomid<<"bedno"<<bedno<<"mat[roomid].bitmap"<<mat[roomid].bitmap;
        //this->close();
        this->accept();
    }
    if(flag > 1)
    {
        setValid(false);        //ԭ���ļ�¼��Ч
        //��ȡ�²���ļ�¼id
        sql = "select last_insert_id();";
        query.exec(sql);
        query.next();
        if(!query.value(0).isNull())
            elderID = query.value(0).toInt();
        if(flag == 3) //��Ժ���µļ�¼ҲҪinvalid
            setValid(false);
        else              //�������¼�¼Ϊvalid
        {
            modifyBitmap(ui->deviceID_lineEdit->text().toInt(),
                         ui->bed_comboBox_8->currentText().left(1).toInt(),
                         true);             //�µķ��������Ӧ��bitmap
            setValid(true);
            updateType(ui->deviceID_lineEdit->text().toInt());
        }
        qDebug()<<elderID<<"�����";
    }
    updateType(ui->deviceID_lineEdit->text().toInt());
    emit refresh();
    query.clear();
    query.finish();

    //�޸Ĵ�λ������Ϣ
    if(commandType == NEWELDER) return;
    if(roomid >= 0 && bedno >= 1)
    {
        if(ui->mat_comboBox_11->currentText() == "��")
        {
            mat[roomid].bitmap = mat[roomid].bitmap | (quint8)(pow(2,bedno - 1));
        }
        else if(ui->mat_comboBox_11->currentText() == "��")
        {
            mat[roomid].bitmap = mat[roomid].bitmap & (~(quint8)(pow(2,bedno - 1)));
        }
    }
    //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::saveElder ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
        }
    }
}



int ElderInfo::getDeviceID(QStringList list)
{
    if(list.size() < 4)
    {
        qDebug()<<"ȱ�ٲ���";
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
        qDebug()<<"ElderInfo::getDeviceID ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
        }
    }
    return -1;
}



/************************************************************
 *���ø��������Ƿ�ɱ༭
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
            if(query.value(0).toString() == "��")
                type = 1;
            else
                type = 2;
        }
    }
    qDebug()<<type<<"����Ϊ:"<<deviceID<<query.size();
    QString sql = QString("update device_info set type = %1 where device_id = %2")
            .arg(type).arg(deviceID);
    query.exec(sql);
}






/*************************************************************
 *����bedNo�Ŵ���ֵ��0Ϊû����1Ϊ�մ�û��ס��2Ϊ����ס��3����δʹ��
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
        qDebug()<<did<<bitmap<<in<<"ԭʼֵ";
        if(in)                  //��Ժ
        {
            bitmap = setN0(bitmap,2 * (bedno - 1));
            bitmap = setN1(bitmap,2 * (bedno - 1) + 1);

        }else                   //��Ժ
        {
            bitmap = setN1(bitmap,2 * (bedno - 1));
            bitmap = setN0(bitmap,2 * (bedno - 1) + 1);
        }
        qDebug()<<bitmap;
        sql = QString("update device_info set bitmap = ? where device_id = '%1'").arg(did);
        query.prepare(sql);
        query.addBindValue(bitmap);
        if(!query.exec())
            qDebug()<<query.lastError()<<"�޸�bitmap";
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        qDebug()<<"ElderInfo::modifyBitmap ���ݿ�����ʧ�ܣ�";
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
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

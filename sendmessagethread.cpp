#include "struct.h"
#include "sendmessagethread.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

SendMessageThread::SendMessageThread(QObject *parent) :
    QThread(parent)
{
    tcpserver = 0;
    tcpsocket = 0;
    if(connectToDatabase())
    {
        tcpserver = new QTcpServer(this);
        tcpserver->listen(QHostAddress(sursysip),8004);
        connect(tcpserver,SIGNAL(newConnection()),this,SLOT(newConnection()));
        //insertMessage("QString opname","QString opargs");
    }
}
bool SendMessageThread::connectToDatabase()
{
    smtdb = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL","senmessagethread"));
    smtdb->setHostName(serverIP);
    smtdb->setPort(3306);
    smtdb->setDatabaseName(globalDBName);
    smtdb->setUserName("zsn");
    smtdb->setPassword("zsn");
    QSqlError err;
    if(!smtdb->open())
    {
        err = smtdb->lastError();
        qDebug()<<err;
        qDebug()<<"databaseerror";
        return false;
    }
    else
    {
        qDebug()<<"connect succeed!";
        return true;
    }
}

void SendMessageThread::run()
{
   this->exec();
}

void SendMessageThread::newConnection()
{
    tcpsocket = tcpserver->nextPendingConnection();
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    qDebug()<<tcpsocket->peerAddress();
}

void SendMessageThread::readData()
{
    if(tcpsocket && tcpsocket->state() == QAbstractSocket::ConnectedState)
    {
        QByteArray results = tcpsocket->readAll();
        QString resultstr;
        resultstr.append(results);
        QStringList resultlists = resultstr.split(":");
        if(resultlists.at(0) == "delroom")
        {
            if(resultlists.at(1) == "true")
            {
                emit delRoom(true);
            }
            else if(resultlists.at(0) == "false")
            {
                emit delRoom(false);
            }
        }

    }
}

void SendMessageThread::socketDisconnected()
{
   // tcpsocket = 0;
}

void SendMessageThread::insertMessage(QString opname,QString opargs)
{
    if(smtdb->open())
    {
        QSqlQuery query(*smtdb);
        //先删除已被读取的消息
        query.prepare("DELETE FROM op_man_to_age_data WHERE rw_flag = ?");
        query.addBindValue(0);
        query.exec();

        query.prepare("INSERT INTO op_man_to_age_data (op_name,op_arg,rw_flag) VALUES(?,?,?)");
        query.addBindValue(opname);
        query.addBindValue(opargs);
        query.addBindValue(1);
        query.exec();

        query.clear();
        query.finish();
    }
}
void SendMessageThread::sendUpdateMessage()
{
    if(tcpsocket)
    {
        QByteArray bytearray;
        bytearray.append("updatetreewidget");
        tcpsocket->write(bytearray);
    }
}
void SendMessageThread::sendAddBuilding(QString buildingname)
{
    insertMessage("addbuilding",buildingname);
    sendUpdateMessage();
}

void SendMessageThread::sendDelBuilding(QString buildingname)
{
     insertMessage("delbuilding",buildingname);
     sendUpdateMessage();
}

void SendMessageThread::sendDelFloor(QString buildingname,QString floorname)
{
    insertMessage("delfloor",buildingname+":"+floorname);
    sendUpdateMessage();
}

void SendMessageThread::sendAddFloor(QString buildingname,QString floorname)
{
    insertMessage("addfloor",buildingname+":"+floorname);
    sendUpdateMessage();
}

void SendMessageThread::sendAddRoom(QString buildingname,QString floorname,QString roomname,bool monitorflag)
{
    insertMessage("addroom",buildingname+":"+floorname+":" + roomname+":"+(monitorflag ? "true":"false"));
    sendUpdateMessage();
}
void SendMessageThread::sendDelRoom(QString buildingname,QString floorname,QString roomname)
{
    insertMessage("delroom",buildingname+":"+floorname+":" + roomname);
    sendUpdateMessage();
}

void SendMessageThread::sendDelRoomRequest(QString builingname,QString floorname,QString roomname)
{
    if(tcpsocket)
    {
        QByteArray bytearray;
        QString str = "delroomrequest";
        str.append(":");
        str.append(builingname);
        str.append(":");
        str.append(floorname);
        str.append(":");
        str.append(roomname);
        bytearray.append(str);
        tcpsocket->write(bytearray);
    }
}
void SendMessageThread::sendMonitorRoom(QString buildingname,QString floorname,QString roomname, bool monitorflag)
{
    insertMessage("monitorroom",buildingname+":"+floorname+":" + roomname+":"+(monitorflag ? "true":"false"));
    sendUpdateMessage();
}

void SendMessageThread::sendAddBed(QString buildingname,QString floorname,QString roomname,QString bedname)
{
    insertMessage("addbed",buildingname+":"+floorname+":" + roomname + ":" + bedname);
    sendUpdateMessage();
}

void SendMessageThread::sendDelBed(QString buildingname,QString floorname,QString roomname,QString bedname)
{
    insertMessage("delbed",buildingname+":"+floorname+":" + roomname + ":" + bedname);
    sendUpdateMessage();
}

void SendMessageThread::sendAddMat(QString buildingname,QString floorname,QString roomname,QString bedname)
{
    insertMessage("addmat",buildingname+":"+floorname+":" + roomname + ":" + bedname);
    sendUpdateMessage();
}

void SendMessageThread::sendDelMat(QString buildingname,QString floorname,QString roomname,QString bedname)
{
    insertMessage("delmat",buildingname+":"+floorname+":" + roomname + ":" + bedname);
    sendUpdateMessage();
}

void SendMessageThread::sendUpdateRF()
{
    if(tcpsocket)
    {
        QByteArray bytearray;
        bytearray.append("updaterf");
        tcpsocket->write(bytearray);
    }
}


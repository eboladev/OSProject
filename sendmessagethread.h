#ifndef SENDMESSAGETHREAD_H
#define SENDMESSAGETHREAD_H

#include <QObject>
#include <QtNetwork>
#include <iostream>
#include <QThread>

class QSqlDatabase;
class SendMessageThread : public QThread
{
    Q_OBJECT
public:
    explicit SendMessageThread(QObject *parent = 0);


    void sendAddBuilding(QString buildingname);
    void sendDelBuilding(QString buildingname);
    void sendAddFloor(QString buildingname,QString floorname);
    void sendDelFloor(QString buildingname,QString floorname);
    void sendAddRoom(QString buildingname,QString floorname,QString roomname, bool monitorflag);
    void sendDelRoomRequest(QString builingname,QString floorname,QString roomname);
    void sendDelRoom(QString buildingname,QString floorname,QString roomname);
    void sendMonitorRoom(QString buildingname,QString floorname,QString roomname, bool monitorflag);

    void sendAddBed(QString buildingname,QString floorname,QString roomname,QString bedname);
    void sendDelBed(QString buildingname,QString floorname,QString roomname,QString bedname);
    void sendAddMat(QString buildingname,QString floorname,QString roomname,QString bedname);
    void sendDelMat(QString buildingname,QString floorname,QString roomname,QString bedname);

    void sendUpdateRF();



    
signals:
    void delRoom(bool flag);
    
private slots:
    void newConnection();
    void readData();
    void socketDisconnected();
protected:
    void run();


private:
    QTcpServer * tcpserver;
    QTcpSocket * tcpsocket;
    QSqlDatabase * smtdb;

    bool connectToDatabase();
    void insertMessage(QString opname,QString opargs);
    void sendUpdateMessage();



};

#endif // RECEIVER_H

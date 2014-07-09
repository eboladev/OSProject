#ifndef ELDERINFO_H
#define ELDERINFO_H

#include <QDialog>
#include <QDataWidgetMapper>
#include <QtSql>
#include <QStringList>

#ifndef HOSTADDRESS
#define HOSTADDRESS "192.168.0.100"
#endif

namespace Ui {
class ElderInfo;
}

enum COMANDTYPE{NEWELDER,EDITELDER,SCANELDER,VIEWELDER};

class ElderInfo : public QDialog
{
    Q_OBJECT

public:
    //初始化 参数1，命令类型,参数2，参数
    explicit ElderInfo(COMANDTYPE command,QStringList &plist,QWidget *parent = 0);
    ~ElderInfo();
    quint8 bedValue(quint32 bitmap,quint8 bedNo);        //判断bedNo号床的值，bedNo为1~6
    //bool createDbConnetion();
    void setValid(bool valid);
    void modifyBitmap(qint32 did, quint8 bedno, bool in);
    int getDeviceID(QStringList list);
    void setReadOnly(COMANDTYPE command);
    void updateType(int deviceID);         //1,男 2，女 3，混合


    void setOlder(QString * oldernameptr);
    void setLookupRoomEnable(bool flag);
public slots:
    void dialogInit();
    void buildingChanged();
    void floorChanged();
    void roomChanged();
    void modifyImage();
    void saveElder();
    void onRoomView();
    void dynamicSetBirthDate();

protected:
    void closeEvent(QCloseEvent * event);
private:
    quint32 setN0(quint32 bitmap,quint8 n);
    quint32 setN1(quint32 bitmap,quint8 n);

signals:
    void refresh();
    void locateAndOpenRoom(QString buildname,QString floorname,QString roomname);

private:
    Ui::ElderInfo *ui;
    //QSqlDatabase db;
    QSqlRecord record;
    QSqlRecord changeRecord;
    COMANDTYPE commandType;
    qint32 elderID;
    quint8 flag;
    QString * oldernameptr;
    //by nan
    int roomid;
    int bedno;
};

#endif // ELDERINFO_H

#ifndef ADDVIEWTODIALOG_H
#define ADDVIEWTODIALOG_H

#include <QDialog>
#include <QMap>
#include <QList>
class QSqlDatabase;
namespace Ui {
class AddViewToDialog;
}

class AddViewToDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddViewToDialog(QString viewname,QWidget *parent = 0);
    QString tarbuildingname;
    QString tarfloorname;
    QString tarroomname;
    ~AddViewToDialog();
public slots:
    void onBuildingChanged(QString buildingname);
    void onFloorChanged(QString floorname);
    void onConfirmPushButton();
    
private:
    Ui::AddViewToDialog *ui;
    //QSqlDatabase * db;
    QMap<QString,QList<int> > buildingMapToFloor;

     void loadBuildingAndRoom();
     void initDialog();
     //void connectToDatabase();
};

#endif // ADDVIEWTODIALOG_H

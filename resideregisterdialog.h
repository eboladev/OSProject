#ifndef RESIDEREGISTERDIALOG_H
#define RESIDEREGISTERDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "elderbaseinfochoosedialog.h"
#include<QStandardItemModel>
#include "manualsettle.h"
#include "bedchoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ResideRegisterDialog;
}

class ResideRegisterDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ResideRegisterDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~ResideRegisterDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_clicked();
    void on_btn_uploading_clicked();
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void  doubleClickRecord(int);
    void getElderBaseInfo(int);
    void getElderHealthInfo(int);
    void getElderRelativeInfo(int);
    void saveRelativeInfo();
    //更改elder_info表中老人入住登记状态
    void changeElderResideStatus();
    void on_comboBox_bedLevel_currentIndexChanged(const QString &);
    void on_comboBox_nurseLevel_currentIndexChanged(const QString &);
    void on_btn_print_clicked();
    void on_comboBox_status_currentIndexChanged(const QString &);
    int getDeviceId(QString,int,QString,int);
    void recedeProcess(int);
    void updateMattressState(bool,QString,int,QString,int);
    void on_toolButton_bed_clicked();

private:
    bool isAdd;
    int index;
    bool isImage;
    void initView();
    void initModel();
    Ui::ResideRegisterDialog *ui;
    QSqlRelationalTableModel *model;
    ElderBaseInfoChooseDialog *dialog;
    BedChooseDialog *bedDialog;
    QStandardItemModel *relativeModel;
    ManualSettle *ms;
};

#endif // RESIDEREGISTERDIALOG_H

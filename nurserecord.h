#ifndef NURSERECORD_H
#define NURSERECORD_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "nurserecorddialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class NurseRecord;
}

class NurseRecord : public QWidget
{
    Q_OBJECT
    
public:
    explicit NurseRecord(QWidget *parent = 0);
    ~NurseRecord();
signals:
    void closeNurseRecordPage();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_change_clicked();
    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::NurseRecord *ui;
    QSqlRelationalTableModel *model;
    NurseRecordDialog *dialog;
};

#endif // NURSERECORD_H

#ifndef VISITRECORD_H
#define VISITRECORD_H

#include <QWidget>
#include<QSqlTableModel>
#include "visitrecorddialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class VisitRecord;
}

class VisitRecord : public QWidget
{
    Q_OBJECT
    
public:
    explicit VisitRecord(QWidget *parent = 0);    
    ~VisitRecord();
    void initModel();
    void initView();
signals:
    void closeVisitRecord();
    void changeRecord(int);

private slots:
    void on_btn_add_record_clicked();
    void on_btn_close_clicked();
    void on_btn_change_record_clicked();
    void refreshModel();
    void on_btn_delete_record_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    Ui::VisitRecord *ui; 
    QSqlTableModel *model;
    VisitRecordDialog *dialog;
    QStringList list;
};

#endif // VISITRECORD_H

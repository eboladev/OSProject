#ifndef ACCIDENTRECORD_H
#define ACCIDENTRECORD_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "accidentrecorddialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class AccidentRecord;
}

class AccidentRecord : public QWidget
{
    Q_OBJECT
    
public:
    explicit AccidentRecord(QWidget *parent = 0);
    ~AccidentRecord();
signals:
    void closeAccidentRecordPage();
    
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
    Ui::AccidentRecord *ui;
    QSqlRelationalTableModel *model;
    AccidentRecordDialog *dialog;
};

#endif // ACCIDENTRECORD_H

#ifndef ADVICERECORD_H
#define ADVICERECORD_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "advicerecorddialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class AdviceRecord;
}

class AdviceRecord : public QWidget
{
    Q_OBJECT
    
public:
    explicit AdviceRecord(QWidget *parent = 0);
    ~AdviceRecord();
signals:
    void closeAdviceRecordPage();
    
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
    Ui::AdviceRecord *ui;
    QSqlRelationalTableModel *model;
    AdviceRecordDialog *dialog;
};

#endif // ADVICERECORD_H

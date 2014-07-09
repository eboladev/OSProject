#ifndef ELDERBASEINFO_H
#define ELDERBASEINFO_H

#include <QWidget>
#include<QSqlTableModel>
#include "elderbaseinfodialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ElderBaseInfo;
}

class ElderBaseInfo : public QWidget
{
    Q_OBJECT
    
public:
    explicit ElderBaseInfo(QWidget *parent = 0);
    ~ElderBaseInfo();
signals:
    void closeElderBaseInfoPage();
    void changeRecord(int);
    
private slots:
    void on_btn_close_clicked();
    void on_btn_add_clicked();
    void refreshModel();
    void on_btn_change_clicked();
    void on_btn_delete_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::ElderBaseInfo *ui;
    QSqlTableModel *model;
    ElderBaseInfoDialog *dialog;    
};

#endif // ELDERBASEINFO_H

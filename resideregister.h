#ifndef RESIDEREGISTER_H
#define RESIDEREGISTER_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "resideregisterdialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ResideRegister;
}

class ResideRegister : public QWidget
{
    Q_OBJECT
    
public:
    explicit ResideRegister(QWidget *parent = 0);
    ~ResideRegister();
signals:
    void closeResideRegisterPage();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_change_clicked();
    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);
    void updateMattressState(bool,QString,int,QString,int);

private:
    void initModel();
    void initView();
    Ui::ResideRegister *ui;
    QSqlRelationalTableModel *model;
    ResideRegisterDialog *dialog;
};

#endif // RESIDEREGISTER_H

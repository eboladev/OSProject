#ifndef ELDERVACATION_H
#define ELDERVACATION_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "eldervacationdialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ElderVacation;
}

class ElderVacation : public QWidget
{
    Q_OBJECT
    
public:
    explicit ElderVacation(QWidget *parent = 0);
    ~ElderVacation();
signals:
    void closeElderVacationPage();
    
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
    void initView();
    void initModel();
    Ui::ElderVacation *ui;
    QSqlRelationalTableModel *model;
    ElderVacationDialog *dialog;
};

#endif // ELDERVACATION_H

#ifndef CHECKIN_H
#define CHECKIN_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "checkindialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class CheckIn;
}

class CheckIn : public QWidget
{
    Q_OBJECT
    
public:
    explicit CheckIn(QWidget *parent = 0);
    ~CheckIn();
signals:
    void closeCheckInPage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_add_clicked();
//    void on_btn_change_clicked();
//    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::CheckIn *ui;
    QSqlRelationalTableModel *model;
    CheckInDialog *dialog;
};

#endif // CHECKIN_H

#ifndef ELDERBASEINFODIALOG_H
#define ELDERBASEINFODIALOG_H

#include <QDialog>
class QSqlTableModel;
#include<QSqlDatabase>
#include<QDate>
#include "datewidget.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ElderBaseInfoDialog;
}

class ElderBaseInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ElderBaseInfoDialog(QWidget *parent = 0,QSqlTableModel *pModel = 0);
    ~ElderBaseInfoDialog();
    bool getIsAdd();
    void setIsAdd(bool);
    int getIndex();
    void setIndex(int);

public slots:
    void viewRecord(int);
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_btn_open_clicked();
    void updateNameByElderId(int,QString);
    void on_lineEdit_cardNo_lostFocus();
    void on_checkBox_isLunar_clicked();
    void on_dateEdit_birthday_dateChanged(const QDate &date);

private:
     void initView();
    Ui::ElderBaseInfoDialog *ui;
    QSqlTableModel *model;   
    bool isAdd;
    bool isImage;
    int index;
    MyCTCalendar calendar;
    CTCalendar cal;
};

#endif // ELDERBASEINFODIALOG_H

#ifndef ELDERBIRTHDAY_H
#define ELDERBIRTHDAY_H

#include <QWidget>
#include<QStandardItemModel>
#include<QSqlDatabase>
#include "datewidget.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ElderBirthday;
}

class ElderBirthday : public QWidget
{
    Q_OBJECT
    
public:
    explicit ElderBirthday(QWidget *parent = 0);
    ~ElderBirthday();
signals:
    void closeElderBirthdayPage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_close_clicked();
    void on_dateEdit_start_dateChanged(const QDate &);
    void on_dateEdit_end_dateChanged(const QDate &);

private:
    void initModel();
    void initView();
    Ui::ElderBirthday *ui;
    QStandardItemModel *model;
    MyCTCalendar calendar;
    CTCalendar cal;
};

#endif // ELDERBIRTHDAY_H

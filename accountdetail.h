#ifndef ACCOUNTDETAIL_H
#define ACCOUNTDETAIL_H

#include <QWidget>
#include<QStandardItemModel>
#include "manageinfochoosedialog.h"
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class AccountDetail;
}

class AccountDetail : public QWidget
{
    Q_OBJECT
    
public:
    explicit AccountDetail(QWidget *parent = 0);
    ~AccountDetail();
    
signals:
    void closeAccountDetailPage();

private slots:
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_toolButton_clicked();
    void doubleClickRecord(QString);
private:
    void initModel();
    void initView();
    Ui::AccountDetail *ui;
    QStandardItemModel *model;
    ManageInfoChooseDialog *dialog;
};

#endif // ACCOUNTDETAIL_H

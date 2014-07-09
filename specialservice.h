#ifndef SPECIALSERVICE_H
#define SPECIALSERVICE_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "specialservicedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class SpecialService;
}

class SpecialService : public QWidget
{
    Q_OBJECT
    
public:
    explicit SpecialService(QWidget *parent = 0);
    ~SpecialService();
signals:
    void closeSpecialServicePage();
    
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
    Ui::SpecialService *ui;
    QSqlRelationalTableModel *model;
    SpecialServiceDialog *dialog;
};

#endif // SPECIALSERVICE_H

#ifndef HEALTHASSESS_H
#define HEALTHASSESS_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include<healthassessdialog.h>
extern QSqlDatabase globaldb;
namespace Ui {
class HealthAssess;
}

class HealthAssess : public QWidget
{
    Q_OBJECT
    
public:
    explicit HealthAssess(QWidget *parent = 0);
    ~HealthAssess();
signals:
    void closeHealthAssessPage();
    
private slots:
    void on_btn_close_clicked();
    void on_btn_add_clicked();
    void on_btn_change_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_delete_clicked();
    void refreshModel();
     void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::HealthAssess *ui;
    QSqlRelationalTableModel *model;
    HealthAssessDialog *dialog;
};

#endif // HEALTHASSESS_H

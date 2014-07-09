#ifndef OPERATIONLOG_H
#define OPERATIONLOG_H

#include <QWidget>
#include<QSqlTableModel>
extern QSqlDatabase globaldb;
namespace Ui {
class OperationLog;
}

class OperationLog : public QWidget
{
    Q_OBJECT
    
public:
    explicit OperationLog(QWidget *parent = 0);
    ~OperationLog();

signals:
    void closeOperationLogPage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_close_clicked();

private:
    void initModel();
    void initView();
    QSqlTableModel *model;
    Ui::OperationLog *ui;
};

#endif // OPERATIONLOG_H

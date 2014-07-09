#ifndef EMPLOYEEBASEINFOCHOOSEDIALOG_H
#define EMPLOYEEBASEINFOCHOOSEDIALOG_H

#include <QDialog>
#include<QModelIndex>
namespace Ui {
class EmployeeBaseInfoChooseDialog;
}

class EmployeeBaseInfoChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EmployeeBaseInfoChooseDialog(QWidget *parent = 0);
    ~EmployeeBaseInfoChooseDialog();
signals:
    void sendEmployeeChoosed(QString);
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initView();
    Ui::EmployeeBaseInfoChooseDialog *ui;
};

#endif // EMPLOYEEBASEINFOCHOOSEDIALOG_H

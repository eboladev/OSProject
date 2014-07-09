#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PasswordDialog(QWidget *parent = 0);
    ~PasswordDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::PasswordDialog *ui;
};

#endif // PASSWORDDIALOG_H

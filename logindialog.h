#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include<QMap>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

protected:
    void resizeEvent(QResizeEvent *event);
    
private slots:
    void on_btn_login_clicked();
    void loadUserInfo();
    int getRoleIdByUserInfo(QString,QString);
    QList<QString> getMenuNameListByRoleId(int);
    QList<QString> getBarListByMenuList(QList<QString>);
    QString getObjNameById(int);
private:
    Ui::LoginDialog *ui;
    QMap<QString,QString> map;
};

#endif // LOGINDIALOG_H

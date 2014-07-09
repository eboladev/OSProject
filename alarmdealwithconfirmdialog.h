#ifndef ALARMDEALWITHCONFIRMDIALOG_H
#define ALARMDEALWITHCONFIRMDIALOG_H

#include <QDialog>
#include <QMap>
namespace Ui {
class AlarmDealWithConfirmDialog;
}

class AlarmDealWithConfirmDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AlarmDealWithConfirmDialog(QWidget *parent = 0);
    void setState(int usestate);

    ~AlarmDealWithConfirmDialog();
    QString useridentifier;
    //int uid;
   // QVector<int> uids;
protected:
    void resizeEvent(QResizeEvent *event);
public slots:
    void onConfirmPushButton();
    
private:
    Ui::AlarmDealWithConfirmDialog *ui;
    void loadUserInfo();
    int usetype;
    QMap<QString,QString> usemaptopasswd;

};

#endif // ALARMDEALWITHCONFIRMDIALOG_H

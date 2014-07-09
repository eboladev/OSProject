#ifndef HEALTHASSESSDIALOG_H
#define HEALTHASSESSDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "elderbaseinfochoosedialog.h"
namespace Ui {
class HealthAssessDialog;
}

class HealthAssessDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit HealthAssessDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~HealthAssessDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_calcel_clicked();
    void on_toolButton_clicked();
    void  doubleClickRecord(int);

private:
    void initView();
    Ui::HealthAssessDialog *ui;
    QSqlRelationalTableModel *model;
    ElderBaseInfoChooseDialog *dialog;
    bool isAdd;
    int index;
};

#endif // HEALTHASSESSDIALOG_H

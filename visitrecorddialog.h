#ifndef VISITRECORDDIALOG_H
#define VISITRECORDDIALOG_H

#include <QDialog>
#include "manageinfochoosedialog.h"
class QSqlTableModel;

namespace Ui {
class VisitRecordDialog;
}

class VisitRecordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VisitRecordDialog(QWidget *parent = 0,QSqlTableModel *pModel = 0);
    ~VisitRecordDialog();
    bool getIsAdd();
    void setIsAdd(bool);
    int getIndex();
    void setIndex(int);
    
public slots:
    void viewRecord(int);
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_combox_purpose_currentIndexChanged(const QString &);
    void on_toolButton_clicked();
    void doubleClickRecord(QString);

private:
    void initView();
    bool isAdd;
    int index;
    Ui::VisitRecordDialog *ui;
    QSqlTableModel *model;
    ManageInfoChooseDialog *dialog;
};

#endif // VISITRECORDDIALOG_H

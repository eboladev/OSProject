#ifndef OPERATIONLOGDIALOG_H
#define OPERATIONLOGDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>
class SqlTableModel;

namespace Ui {
class OperationLogDialog;
}

class OperationLogDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OperationLogDialog(QWidget *parent = 0);
    ~OperationLogDialog();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void onSearchPushButton();
    
private:
    Ui::OperationLogDialog *ui;
    //QSqlDatabase db;
    SqlTableModel * model;
   // void connectToDatabase();
    void initDialog();
    void initReadStaffInfo();
};



class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    SqlTableModel(QObject * parent = 0, QSqlDatabase db = QSqlDatabase() ) : QSqlTableModel(parent,db){}
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
    {
        if(index.column() < 3 && Qt::TextAlignmentRole == role )
            return Qt::AlignCenter;
        return QSqlTableModel::data(index, role);
    }

};

#endif // OPERATIONLOGDIALOG_H

#include "accountpay.h"
#include "ui_accountpay.h"
#include<QMessageBox>
#include<QDebug>
#include "elderstatusdelegate.h"
#include "dictionary.h"
extern QString operatorId;
AccountPay::AccountPay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountPay)
{
    ui->setupUi(this);
    initModel();
    initView();
}

AccountPay::~AccountPay()
{
    delete model;
    delete ui;
}

void AccountPay::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    model = new QSqlTableModel(this,globaldb);
    model->setTable("manage_info");
    model->setHeaderData(model->fieldIndex("cardNo"),Qt::Horizontal,tr("卡号"));
     model->setHeaderData(model->fieldIndex("name"),Qt::Horizontal,tr("姓名"));
     model->setHeaderData(model->fieldIndex("contractNo"),Qt::Horizontal,tr("合同号"));
     model->setHeaderData(model->fieldIndex("status"),Qt::Horizontal,tr("状态"));
     model->setHeaderData(model->fieldIndex("buildingName"),Qt::Horizontal,tr("楼宇名"));
     model->setHeaderData(model->fieldIndex("regionNo"),Qt::Horizontal,tr("区号"));
     model->setHeaderData(model->fieldIndex("roomNo"),Qt::Horizontal,tr("房间号"));
     model->setHeaderData(model->fieldIndex("bedNo"),Qt::Horizontal,tr("床位"));
     model->setHeaderData(model->fieldIndex("bedLevel"),Qt::Horizontal,tr("床位等级"));
     model->setHeaderData(model->fieldIndex("bedCost"),Qt::Horizontal,tr("床位费"));
     model->setHeaderData(model->fieldIndex("nurseLevel"),Qt::Horizontal,tr("护理级别"));
     model->setHeaderData(model->fieldIndex("nurseCost"),Qt::Horizontal,tr("护理费"));
     model->setHeaderData(model->fieldIndex("nurserName"),Qt::Horizontal,tr("负责人"));
     model->setHeaderData(model->fieldIndex("resideDate"),Qt::Horizontal,tr("入住日期"));
     model->setHeaderData(model->fieldIndex("outDate"),Qt::Horizontal,tr("退住日期"));
     model->setHeaderData(model->fieldIndex("account"),Qt::Horizontal,tr("账户余额"));
     model->setHeaderData(model->fieldIndex("remark"),Qt::Horizontal,tr("备注"));
     model->setHeaderData(model->fieldIndex("operator"),Qt::Horizontal,tr("操作员"));
     model->setHeaderData(model->fieldIndex("operationTime"),Qt::Horizontal,tr("操作时间"));
     model->select();
}

void AccountPay::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("account_pay_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_accountPay->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(model->fieldIndex("elderId"));
    ui->tableView->hideColumn(model->fieldIndex("isCuff"));
    ui->tableView->hideColumn(model->fieldIndex("cuffNo"));
    ui->tableView->hideColumn(model->fieldIndex("cuffStartTime"));
    ui->tableView->hideColumn(model->fieldIndex("cuffEndTime"));
    ui->tableView->hideColumn(model->fieldIndex("isMattress"));
    ui->tableView->hideColumn(model->fieldIndex("levelChanged"));
    ui->tableView->hideColumn(model->fieldIndex("settleDate"));
    ui->tableView->hideColumn(model->fieldIndex("agreement"));
    ui->tableView->hideColumn(model->fieldIndex("personalMedical"));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("status"),new ElderStatusDelegate(this));
}

void AccountPay::on_btn_accountPay_clicked()
{
    dialog = new AccountPayDialog(this,model,ui->tableView->currentIndex().row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

void AccountPay::on_btn_close_clicked()
{
    emit closeAccountPayPage();
}

void AccountPay::on_btn_clear_clicked()
{
    ui->lineEdit_accountEnd->setText(tr(""));
    ui->lineEdit_accountStart->setText(tr(""));
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
}

void AccountPay::on_btn_search_clicked()
{
    QString sql = tr("");
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" name = '%1' and ").arg(ui->lineEdit_name->text()));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" cardNo = '%1' and ").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_accountStart->text().compare(tr("")) != 0)
        sql.append(tr(" account >= %1 and ").arg(ui->lineEdit_accountStart->text()));
    if(ui->lineEdit_accountEnd->text().compare(tr("")) != 0)
        sql.append(tr(" account <= %1 and ").arg(ui->lineEdit_accountEnd->text()));
    sql.append(tr(" cardNo is not NULL"));
    qDebug()<<sql;
    model->setFilter(sql);
}

void AccountPay::refreshModel(){
    model->select();
}

void AccountPay::doubleClickRecord(QModelIndex index){
    dialog = new AccountPayDialog(this,model,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(refreshModel()));
    dialog->exec();
}

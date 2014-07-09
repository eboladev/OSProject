#include "monthlyresidestatistics.h"
#include "ui_monthlyresidestatistics.h"
#include<QDate>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include "print.h"
extern QSqlDatabase globaldb;
MonthlyResideStatistics::MonthlyResideStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonthlyResideStatistics)
{
    ui->setupUi(this);  
    initView();
    initHtml();
}

MonthlyResideStatistics::~MonthlyResideStatistics()
{
    delete ui;
}

void MonthlyResideStatistics::initView(){
    ui->dateEdit->setDate(QDate::currentDate());
}

void MonthlyResideStatistics::initHtml(){
    html = "<body>";
    QSqlQuery query(globaldb);
    query.prepare("select count(*) from manage_info where SUBSTR(resideDate,1,7) = ?");
    query.addBindValue(ui->dateEdit->date().toString("yyyy-MM"));
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if(query.first())
        html.append(tr("<h1 align=\"center\"> ����ס���ͳ��</h1><p>��������%1�� </p>").arg(query.value(0).toString()));
    query.finish();
    QString sql = "select a.cardNo,b.name,b.gender,a.contractNo, case when a.status =1 then '��ס' when a.status = 2 then  '���' else '��ס' end as status,"
            "a.buildingName,a.regionNo,a.roomNo,a.bedNo,a.bedCost,a.nurseLevel,a.nurseCost,a.nurserName,a.resideDate,a.account,a.remark,a.operator,"
            "a.operationTime from manage_info a,elder_info b where a.elderId = b.eid";
    sql.append(tr(" and SUBSTR(a.resideDate,1,7) = '%1'").arg(ui->dateEdit->date().toString("yyyy-MM")));
    query.prepare(sql);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    html .append( "<table width=\"100%\" border=1 cellspacing=0><tr><td>����</td><td>����</td><td>�Ա�</td><td>��ͬ��</td><td>״̬</td><td>¥����</td>"
              "<td>����</td><td>�����</td><td>��λ</td><td>��λ��</td><td>������</td><td>�����</td><td>������</td><td>��ס����</td>"
              "<td>�˻�</td><td>��ע</td><td>����Ա</td><td>����ʱ��</td></tr>");
    while(query.next()){
        html.append(tr("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td><td>%7</td><td>%8</td>"
                       "<td>%9</td><td>%10</td><td>%11</td><td>%12</td><td>%13</td><td>%14</td><td>%15</td><td>%16</td>"
                       "<td>%17</td><td>%18</td></tr>").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString())
                    .arg(query.value(4).toString()).arg(query.value(5).toString()).arg(query.value(6).toString()).arg(query.value(7).toString()).arg(query.value(8).toString())
                    .arg(query.value(9).toString()).arg(query.value(10).toString()).arg(query.value(11).toString()).arg(query.value(12).toString()).arg(query.value(13).toString())
                    .arg(query.value(14).toString()).arg(query.value(15).toString()).arg(query.value(16).toString()).arg(query.value(17).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
    }
    html.append(tr("</table></body>"));
}

void MonthlyResideStatistics::on_btn_search_clicked()
{
    initHtml();
    ui->textBrowser->setHtml(html);
}

void MonthlyResideStatistics::on_btn_print_clicked()
{
    Print::printHtml(html);
}

void MonthlyResideStatistics::on_btn_close_clicked()
{
    emit closeMonthlyAResideStatisticsPage();
}

#include "manualsettle.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QSqlDatabase>
#include<QDateTime>
extern QSqlDatabase globaldb;
ManualSettle::ManualSettle(QObject *parent) :
    QObject(parent)
{
}

void ManualSettle::expenseSettle(QString cardNo,QDate recedeDate){
    if(QSqlDatabase::database().transaction()){
        QSqlQuery query(globaldb);
        query.prepare("insert into settle_account values (NULL,?,?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(cardNo);        
        float bedCost = getElderBedCostByCardNo(cardNo,recedeDate);
        float nurseCost = getElderNurseCostByCardNo(cardNo,recedeDate);
        float specialCost = getElderSpecialServiceCostByCardNo(cardNo,recedeDate);
        float stageCost = getElderStageCost(cardNo,recedeDate);
        updateLevelChangedByCardNo(cardNo);
        float totalCost = bedCost+nurseCost+specialCost+stageCost;      
        query.addBindValue(0);
        query.addBindValue(bedCost);
        query.addBindValue(nurseCost);
        query.addBindValue(specialCost);
        query.addBindValue(stageCost);
        query.addBindValue(totalCost);
        query.addBindValue(recedeDate);
        query.addBindValue(NULL);
        query.addBindValue(tr("system"));
        query.addBindValue(QDateTime::currentDateTime());
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();

        if(!QSqlDatabase::database().commit()){
            qDebug()<<QSqlDatabase::database().lastError();
            if(!QSqlDatabase::database().rollback())
                qDebug()<<QSqlDatabase::database().lastError();
        }
    }
}

float ManualSettle::getElderAccountByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select account from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    float account = 0;
    if(query.first())
        account = query.value(0).toFloat();
    query.finish();
    query.clear();
    return account;
}

float ManualSettle::getElderBedCostByCardNo(QString cardNo,QDate recedeDate){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate,levelChanged,bedCost from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    int isChanged = 0;
    bool isNewResided = false;
    float bedCost = 0;
    float monthlyCost = 0;
    QDate resideDate;
    if(query.first()){
        resideDate = query.value(0).toDate();
        isChanged = query.value(1).toInt();
        bedCost = query.value(2).toFloat();
    }
    if(resideDate.year() == QDate::currentDate().year() && resideDate.month() == QDate::currentDate().month())
        isNewResided = true;
    if(isChanged){
        QMap<QDate,float> map = getElderBedChangeInfoByCardNo(cardNo,recedeDate);
        QMapIterator<QDate,float> iterator(map);
        bool first = true;
        QDate date;
        while(iterator.hasNext()){
            iterator.next();
            if(first){
                if(isNewResided){
                    monthlyCost+=(iterator.key().day()-resideDate.day())*iterator.value();
                    insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-resideDate.day()),(iterator.key().day()-resideDate.day())*iterator.value(),recedeDate);
                }
                else{
                    monthlyCost+=(iterator.key().day()-1)*iterator.value();
                    insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-1),(iterator.key().day()-1)*iterator.value(),recedeDate);
                }
                first = false;
                date=iterator.key();
            }
            else{
                monthlyCost+=(iterator.key().day()-date.day())*iterator.value();
                insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-date.day()),(iterator.key().day()-date.day())*iterator.value(),recedeDate);
                date=iterator.key();
            }
        }
        monthlyCost+=(recedeDate.day()-date.day())*bedCost;
        insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(recedeDate.day()-date.day()),(recedeDate.day()-date.day())*bedCost,recedeDate);
    }
    else{
        if(isNewResided){
            monthlyCost = bedCost *(recedeDate.day() - resideDate.day());
            insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(recedeDate.day() - resideDate.day()),bedCost *(recedeDate.day() - resideDate.day()),recedeDate);
        }
        else{
            monthlyCost = bedCost * (recedeDate.day()-1);
            insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(recedeDate.day()-1),bedCost * (recedeDate.day()-1),recedeDate);
        }
    }
        return monthlyCost;
}

float ManualSettle::getElderNurseCostByCardNo(QString cardNo,QDate recedeDate){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate,levelChanged,nurseCost from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    int isChanged = 0;
    bool isNewResided = false;
    float nurseCost = 0;
    float monthlyCost = 0;
    QDate resideDate;
    if(query.first()){
        resideDate = query.value(0).toDate();
        isChanged = query.value(1).toInt();
        nurseCost = query.value(2).toFloat();
    }
    if(resideDate.year() == recedeDate.year() && resideDate.month() == recedeDate.month())
        isNewResided = true;
    if(isChanged){
        QMap<QDate,float> map = getElderNurseChangeInfoByCardNo(cardNo,recedeDate);
        QMapIterator<QDate,float> iterator(map);
        bool first = true;
        QDate date;
        while(iterator.hasNext()){
            iterator.next();
            if(first){
                if(isNewResided){
                    monthlyCost+=(iterator.key().day()-resideDate.day())*iterator.value();
                    insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-resideDate.day()),(iterator.key().day()-resideDate.day())*iterator.value(),recedeDate);
                }
                else{
                    monthlyCost+=(iterator.key().day()-1)*iterator.value();
                    insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-1),(iterator.key().day()-1)*iterator.value(),recedeDate);
                }
                first = false;
                date=iterator.key();
            }
            else{
                monthlyCost+=(iterator.key().day()-date.day())*iterator.value();
                insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-date.day()),(iterator.key().day()-date.day())*iterator.value(),recedeDate);
                date=iterator.key();
            }
        }
        monthlyCost+=(recedeDate.day()-date.day())*nurseCost;
        insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(nurseCost).arg(recedeDate.day()-date.day()),(recedeDate.day()-date.day())*nurseCost,recedeDate);
    }
    else{
        if(isNewResided){
            monthlyCost = nurseCost *(recedeDate.day() - resideDate.day());
            insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(nurseCost).arg(recedeDate.day() - resideDate.day()),nurseCost *(recedeDate.day() - resideDate.day()),recedeDate);
        }
        else{
            monthlyCost = nurseCost * (recedeDate.day()-1);
            insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数 %2").arg(nurseCost).arg(recedeDate.day()-1),nurseCost * (recedeDate.day()-1),recedeDate);
        }
    }
        return monthlyCost;
}

float ManualSettle::getElderSpecialServiceCostByCardNo(QString cardNo,QDate recedeDate){
    int year = recedeDate.year();
    int month = recedeDate.month();
    QSqlQuery query(globaldb);
    query.prepare("select serviceItem,cost,occurenceDate from living_record where item = 4 and cardNo = ? and occurenceDate >= ? and occurenceDate <= ?");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1));
    query.addBindValue(recedeDate);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    float cost = 0;
    while(query.next()){
        insertSpecialCostInfo(cardNo,3,query.value(0).toString(),query.value(1).toFloat(),query.value(2).toDate());
        cost += query.value(1).toFloat();
    }
    return cost;
}

float ManualSettle::getElderStageCost(QString cardNo,QDate recedeDate){
    int year = recedeDate.year();
    int month = recedeDate.month();
    QDate resideDate = getElderResideDateByCardNo(cardNo);
    bool isNewResided = false;
    if(resideDate.year() == recedeDate.year() && resideDate.month() == recedeDate.month())
        isNewResided = true;
    QSqlQuery query(globaldb);
    query.prepare("select item,cost,startDate,endDate from expense_info where type = 5");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QString item;
    float cost = 0;
    QDate startDate;
    QDate endDate;
    float monthlyCost = 0;
    while(query.next()){
        item = query.value(0).toString();
        cost = query.value(1).toFloat();
        startDate = query.value(2).toDate();
        endDate = query.value(3).toDate();
        if(isNewResided){
            if(startDate>=recedeDate || endDate<resideDate)
                continue;
            else if(startDate<=resideDate && endDate>=recedeDate){
                monthlyCost += cost*(recedeDate.day()-resideDate.day());
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(recedeDate.day()-resideDate.day()),cost*(recedeDate.day()-resideDate.day()),recedeDate);
            }
            else if(startDate>=resideDate && endDate < recedeDate){
                monthlyCost += cost*(endDate.day()-startDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-startDate.day()+1),cost*(endDate.day()-startDate.day()+1),recedeDate);
            }
            else if(startDate<resideDate && endDate<=recedeDate){
                monthlyCost += cost*(endDate.day()-resideDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-resideDate.day()+1),cost*(endDate.day()-resideDate.day()+1),recedeDate);
            }
            else{
                monthlyCost += cost*(recedeDate.day()-startDate.day());
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(recedeDate.day()-startDate.day()),cost*(recedeDate.day()-startDate.day()),recedeDate);
            }
        }
        else{
            if(startDate>=recedeDate || endDate<QDate(year,month,1))
                continue;
            else if(startDate<=QDate(year,month,1) && endDate>=recedeDate){
                monthlyCost += cost*(recedeDate.day()-1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(recedeDate.day()-1),cost*(recedeDate.day()-1),recedeDate);
            }
            else if(startDate>=QDate(year,month,1) && endDate<recedeDate){
                monthlyCost += cost*(endDate.day()-startDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-startDate.day()+1),cost*(endDate.day()-startDate.day()+1),recedeDate);
            }
            else if(startDate<=QDate(year,month,1) && endDate<recedeDate){
                monthlyCost += cost*endDate.day();
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()),cost*endDate.day(),recedeDate);
            }
            else{
                monthlyCost += cost*(recedeDate.day()-startDate.day());
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(recedeDate.day()-startDate.day()),cost*(recedeDate.day()-startDate.day()),recedeDate);
            }
        }
    }
    return monthlyCost;
}

//获取护理变更次数
//int ManualSettle::getElderNurseChangeTimesByCardNo(QString cardNo){
//    int days = QDate::currentDate().addMonths(-1).daysInMonth();
//    int year = QDate::currentDate().addMonths(-1).year();
//    int month = QDate::currentDate().addMonths(-1).month();
//    QSqlQuery query(globaldb);
//    query.prepare("select count(*) from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ?");
//    query.addBindValue(cardNo);
//    query.addBindValue(QDate(year,month,1));
//    query.addBindValue(QDate(year,month,days));
//    query.exec();
//    if(query.lastError().isValid())
//        qDebug()<<query.lastError();
//    int times = 0;
//    if(query.first())
//        times = query.value(0).toInt();
//    query.finish();
//    query.clear();
//    return times;
//}

//获取具体的转床记录信息用于结算
QMap<QDate,float> ManualSettle::getElderBedChangeInfoByCardNo(QString cardNo,QDate recedeDate){
    int year = recedeDate.year();
    int month = recedeDate.month();
    QSqlQuery query(globaldb);
    query.prepare("select bedChangeDate,formerBedCost from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ? order by bedChangeDate asc");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1));
    query.addBindValue(recedeDate);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QMap<QDate,float> map;
    while(query.next())
        map.insert(query.value(0).toDate(),query.value(1).toFloat());
    return map;
}

QMap<QDate,float> ManualSettle::getElderNurseChangeInfoByCardNo(QString cardNo,QDate recedeDate){
    int year = recedeDate.year();
    int month = recedeDate.month();
    QSqlQuery query(globaldb);
    query.prepare("select bedChangeDate,formerNurseCost from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ? order by bedChangeDate asc");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1));
    query.addBindValue(recedeDate);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QMap<QDate,float> map;
    while(query.next())
        map.insert(query.value(0).toDate(),query.value(1).toFloat());
    return map;
}

void ManualSettle::updateAccountByCardNoAndCost(QString cardNo, float cost){
        QSqlQuery query(globaldb);
        query.prepare("insert into account_record (id,cardNo,accountOld,accountNew,remark,operator,operationTime) values(NULL,?,?,?,?,?,?)");
        query.addBindValue(cardNo);
        float account = getElderAccountByCardNo(cardNo);
        query.addBindValue(account);
        query.addBindValue(account - cost);
        query.addBindValue(tr("月费用结算，扣除费用%1").arg(cost));
        query.addBindValue(tr("system"));
        query.addBindValue(QDateTime::currentDateTime());
        query.exec();
        query.finish();
        query.prepare("update manage_info set account =account - ? where cardNo = ?");
        query.addBindValue(cost);
        query.addBindValue(cardNo);
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        query.finish();
        query.clear();
}

void ManualSettle::updateLevelChangedByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("update manage_info set levelChanged = 0 where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    query.clear();
}

void ManualSettle::insertBedOrNurseCostInfo(QString cardNo, int type, QString item, float cost){
    QSqlQuery query(globaldb);
    query.prepare("insert into cost_detail (id,cardNo,costType,item,cost) values (NULL,?,?,?,?)");
    query.addBindValue(cardNo);
    query.addBindValue(type);
    query.addBindValue(item);
    query.addBindValue(cost);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
}

void ManualSettle::insertSpecialCostInfo(QString cardNo, int type, QString item, float cost, QDate date){
    QSqlQuery query(globaldb);
    query.prepare("insert into cost_detail (id,cardNo,costType,item,cost,costDate) values (NULL,?,?,?,?,?)");
    query.addBindValue(cardNo);
    query.addBindValue(type);
    query.addBindValue(item);
    query.addBindValue(cost);
    query.addBindValue(date);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
}

QDate ManualSettle::getElderResideDateByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QDate date;
    if(query.first())
        date = query.value(0).toDate();
    return date;
}

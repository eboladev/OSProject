#ifndef MANUALSETTLE_H
#define MANUALSETTLE_H

#include <QObject>
#include<QDate>
#include<QMap>
#include<QStringList>
class ManualSettle : public QObject
{
    Q_OBJECT
public:
    explicit ManualSettle(QObject *parent = 0);
    
signals:
    
public slots:
    void expenseSettle(QString cardNo,QDate);
    float getElderAccountByCardNo(QString);
    float getElderBedCostByCardNo(QString,QDate);
    float getElderNurseCostByCardNo(QString,QDate);
    float getElderStageCost(QString,QDate);
    float getElderSpecialServiceCostByCardNo(QString,QDate);
    QMap<QDate,float> getElderBedChangeInfoByCardNo(QString,QDate);
    QMap<QDate,float> getElderNurseChangeInfoByCardNo(QString,QDate);
    void updateAccountByCardNoAndCost(QString,float);
    void updateLevelChangedByCardNo(QString);
    void insertBedOrNurseCostInfo(QString,int,QString,float);
    void insertSpecialCostInfo(QString,int,QString,float,QDate);
    QDate getElderResideDateByCardNo(QString);
    
};

#endif // MANUALSETTLE_H

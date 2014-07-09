#ifndef ROOMSTATESEARCHDIALOG_H
#define ROOMSTATESEARCHDIALOG_H

#include <QDialog>
#include <QVector>
#include <QMap>
#include <QBitArray>
//要检查与情况下的合法性
class QListWidget;
namespace Ui {
class RoomStateSearchDialog;
}

class RoomStateSearchDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RoomStateSearchDialog(QWidget *parent = 0);
    ~RoomStateSearchDialog();

    QBitArray orbits;
    QBitArray andbits;
    enum {simple_or,simple_and,advanced};//查询等级标志
    int rssdstate;


    QString advancedcondtion;
    QList<int> args;

    
private slots:
     void recordDemonstrationDialogOldPos();


   /* //所有房间
    void on_all_radiobutton_clicked();
    //正常房间
    void on_normal_radiobutton_clicked();
    //离线房间
    void on_offline_radiobutton_clicked();
    //报警房间
    void on_alarm_radiobutton_clicked();*/
    //简单查询
    void on_simplesearch_groupbox_clicked();
    //或关系
    void on_or_radiobutton_clicked();
    //且关系
    void on_and_radiobutton_clicked();
    //漏水
    void on_water_checkbox_clicked();
    //烟雾
    void on_smoke_checkbox_clicked();
    //温度上限
    void on_temperatureup_checkbox_clicked();
    //温度下限
    void on_temperaturedown_checkbox_clicked();
    //湿度上限
    void on_humidityup_checkbox_clicked();
    //湿度下限
    void on_humiditydown_checkbox_clicked();
    //氧气上限
    void on_oxygenup_checkbox_clicked();
    //氧气下限
    void on_oxygendown_checkbox_clicked();
    //二氧化碳上限
    void on_carbodioxideup_checkbox_clicked();
    //二氧化碳下限
    void on_carbodioxidedown_checkbox_clicked();
   /*  //空气品质上限
    void on_comindexup_checkbox_clicked();
    //空气品质下限
    void on_comindexdown_checkbox_clicked();*/
    //高级查询
    void on_advancedsearch_groupbox_clicked();
    //漏水
    void on_waterlevel_toolbutton_clicked();
    //烟雾
    void on_smoke_toolbutton_clicked();
    //温度上限
    void on_temperatureup_toolbutton_clicked();
    //温度下限
    void on_temperaturedown_toolbutton_clicked();
    //湿度上限
    void on_humidityup_toolbutton_clicked();
    //湿度上限
    void on_humiditydown_toolbutton_clicked();
    //氧气上限
    void on_oxygenup_toolbutton_clicked();
    //氧气下限
    void on_oxygendown_toolbutton_clicked();
    //二氧化碳上限
    void on_carbodioxideup_toolbutton_clicked();
    //二氧化碳下限
    void on_carbodioxidedown_toolbutton_clicked();
    //空气品质上限
   /* void on_comindexup_toolbutton_clicked();
    //空气品质下限
    void on_comindexdown_toolbutton_clicked();*/




    //左括号
    void on_leftbracket_toolbutton_clicked();
    //又括号
    void on_rightbracket_toolbutton_clicked();
    //或关系
    void on_or_toolbutton_clicked();
    //与关系
    void on_and_toolbutton_clicked();
    //清除
    void on_clear_toolbutton_clicked();
    //回删
    void on_backdel_toolbutton_clicked();
    //示例
    void on_demonstration_toolbutton_clicked();




    void on_simpleandadvanced_pushbutton_clicked();

    void on_search_pushbutton_clicked();

    void on_mainvoltageup_checkbox_clicked();

    void on_mainvoltagedown_checkbox_clicked();

    void on_zerovoltageup_checkbox_clicked();

    void on_zerovoltagedown_checkbox_clicked();

    void on_mainvoltageup_toolbutton_clicked();

    void on_mainvoltagedown_toolbutton_clicked();

    void on_zerovoltageup_toolbutton_clicked();

    void on_zerovoltagedown_toolbutton_clicked();

    void on_pm25_toolbutton_clicked();

    void on_mat_toolbutton_clicked();

    void on_comindex_toolbutton_clicked();

    void on_pm25_checkbox_clicked();

    void on_mat_checkbox_clicked();

    void on_comindex_checkbox_clicked();

protected:
    void closeEvent(QCloseEvent * event);

private:
    Ui::RoomStateSearchDialog *ui;

    QListWidget * demonstration_listwidget;
    QDialog * demonstration_dialog;
    QList<int> expeachstrlenth;
    QPoint oldpos;
    QString expstr;//高级查询条件表达式


    void createDemonstrationDialog();
    void initRoomStateSearchDialog();
    bool checkExpStrValidity();
    void E();
    void EP();
    void T();
    int j;
    bool flag;
    int bracket;
    bool isfailed;
    /*enum {temperatureup,temperaturedown,humidityup,humiditydown,oxygenup,oxygendown,carbodioxideup, carbodioxidedown,
          comindexup,comindexdown,mainvoltageup,mainvoltagedown,zerovoltageup,zerovoltagedown,waterlevel,smoke};*/

    void conditionToSqlCondtion();

};

#endif // ROOMSTATESEARCHDIALOG_H

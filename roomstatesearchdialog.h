#ifndef ROOMSTATESEARCHDIALOG_H
#define ROOMSTATESEARCHDIALOG_H

#include <QDialog>
#include <QVector>
#include <QMap>
#include <QBitArray>
//Ҫ���������µĺϷ���
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
    enum {simple_or,simple_and,advanced};//��ѯ�ȼ���־
    int rssdstate;


    QString advancedcondtion;
    QList<int> args;

    
private slots:
     void recordDemonstrationDialogOldPos();


   /* //���з���
    void on_all_radiobutton_clicked();
    //��������
    void on_normal_radiobutton_clicked();
    //���߷���
    void on_offline_radiobutton_clicked();
    //��������
    void on_alarm_radiobutton_clicked();*/
    //�򵥲�ѯ
    void on_simplesearch_groupbox_clicked();
    //���ϵ
    void on_or_radiobutton_clicked();
    //�ҹ�ϵ
    void on_and_radiobutton_clicked();
    //©ˮ
    void on_water_checkbox_clicked();
    //����
    void on_smoke_checkbox_clicked();
    //�¶�����
    void on_temperatureup_checkbox_clicked();
    //�¶�����
    void on_temperaturedown_checkbox_clicked();
    //ʪ������
    void on_humidityup_checkbox_clicked();
    //ʪ������
    void on_humiditydown_checkbox_clicked();
    //��������
    void on_oxygenup_checkbox_clicked();
    //��������
    void on_oxygendown_checkbox_clicked();
    //������̼����
    void on_carbodioxideup_checkbox_clicked();
    //������̼����
    void on_carbodioxidedown_checkbox_clicked();
   /*  //����Ʒ������
    void on_comindexup_checkbox_clicked();
    //����Ʒ������
    void on_comindexdown_checkbox_clicked();*/
    //�߼���ѯ
    void on_advancedsearch_groupbox_clicked();
    //©ˮ
    void on_waterlevel_toolbutton_clicked();
    //����
    void on_smoke_toolbutton_clicked();
    //�¶�����
    void on_temperatureup_toolbutton_clicked();
    //�¶�����
    void on_temperaturedown_toolbutton_clicked();
    //ʪ������
    void on_humidityup_toolbutton_clicked();
    //ʪ������
    void on_humiditydown_toolbutton_clicked();
    //��������
    void on_oxygenup_toolbutton_clicked();
    //��������
    void on_oxygendown_toolbutton_clicked();
    //������̼����
    void on_carbodioxideup_toolbutton_clicked();
    //������̼����
    void on_carbodioxidedown_toolbutton_clicked();
    //����Ʒ������
   /* void on_comindexup_toolbutton_clicked();
    //����Ʒ������
    void on_comindexdown_toolbutton_clicked();*/




    //������
    void on_leftbracket_toolbutton_clicked();
    //������
    void on_rightbracket_toolbutton_clicked();
    //���ϵ
    void on_or_toolbutton_clicked();
    //���ϵ
    void on_and_toolbutton_clicked();
    //���
    void on_clear_toolbutton_clicked();
    //��ɾ
    void on_backdel_toolbutton_clicked();
    //ʾ��
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
    QString expstr;//�߼���ѯ�������ʽ


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

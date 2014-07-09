#include <QListWidget>
#include <QDebug>
#include <QMessageBox>
#include "roomstatesearchdialog.h"
#include "ui_roomstatesearchdialog.h"
#include "struct.h"

RoomStateSearchDialog::RoomStateSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomStateSearchDialog)
{
    ui->setupUi(this);
    j=0;
    flag = false;
    bracket = 0;
    isfailed = false;
    createDemonstrationDialog();
    initRoomStateSearchDialog();
    this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint);

}
void RoomStateSearchDialog::initRoomStateSearchDialog()
{
    ui->advancedsearch_groupbox->hide();

    this->setFixedHeight(160);
    //this->setFixedWidth(710);
    this->setFixedWidth(520);
    /*ui->simpleandadvanced_pushbutton->setGeometry(525 + 35,130,55,25);
    ui->search_pushbutton->setGeometry(590 + 35,130,55,25);*/
    ui->simpleandadvanced_pushbutton->setGeometry(335 + 35,130,55,25);
    ui->search_pushbutton->setGeometry(400 + 35,130,55,25);
    ui->search_pushbutton->setEnabled(true);
    ui->advancedsearch_groupbox->setEnabled(false);
    ui->or_radiobutton->setChecked(true);
    orbits.resize(19);
    orbits.fill(0);
    andbits.resize(19);
    andbits.fill(0);
    rssdstate = simple_or;
    advancedcondtion = "";

    //���ز���Ҫ�Ĳ���
    ui->water_checkbox->hide();
    ui->waterlevel_toolbutton->hide();
    ui->mainvoltagedown_checkbox->hide();
    ui->mainvoltageup_checkbox->hide();
    ui->mainvoltagedown_toolbutton->hide();
    ui->mainvoltageup_toolbutton->hide();
    ui->zerovoltagedown_checkbox->hide();
    ui->zerovoltageup_checkbox->hide();
    ui->zerovoltagedown_toolbutton->hide();
    ui->zerovoltageup_toolbutton->hide();


}

void RoomStateSearchDialog::createDemonstrationDialog()
{
    demonstration_listwidget = new QListWidget(this);
    QStringList demonstrationlist;
    demonstrationlist<<"�¶�����"<<"�¶�����|�¶�����"<<"���¶�����|�¶����ޣ�|ʪ������"
                     <<"���¶�����|�¶����ޣ�&ʪ������"<<"ʪ������&���¶�����|�¶����ޣ�"
                     <<"���¶�����|�¶����ޣ�&��ʪ������|ʪ�����ޣ�"<<"���¶�����&ʪ������&�������ޣ�|������������&����Ʒ�ʣ�"
                     <<"�����÷����¶�����&�¶����ޣ�ͬһ�����������޲����ò��ҹ�ϵ��";
    demonstration_listwidget->addItems(demonstrationlist);
    demonstration_listwidget->setFocusPolicy(Qt::NoFocus);
    demonstration_dialog = new QDialog(this);
    demonstration_dialog->setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    QHBoxLayout * hbl = new QHBoxLayout(demonstration_dialog);
    hbl->addWidget(demonstration_listwidget);
    demonstration_dialog->setLayout(hbl);
    demonstration_dialog->setWindowTitle(tr("ʾ��"));
    demonstration_dialog->setFixedSize(460,200);
    demonstration_dialog->hide();
    connect(demonstration_dialog,SIGNAL(finished(int)),this,SLOT(recordDemonstrationDialogOldPos()));
}


RoomStateSearchDialog::~RoomStateSearchDialog()
{
    delete ui;
}

void RoomStateSearchDialog::recordDemonstrationDialogOldPos()
{
    oldpos = demonstration_dialog->pos();
    ui->demonstration_toolbutton->setEnabled(true);

}

/*void RoomStateSearchDialog::on_all_radiobutton_clicked()
{
     //���з���
    qDebug()<<tr("���з���");
    ui->search_pushbutton->setEnabled(false);
    ui->simplesearch_groupbox->setEnabled(false);
    ui->advancedsearch_groupbox->setEnabled(false);
}

void RoomStateSearchDialog::on_normal_radiobutton_clicked()
{
    //��������
    qDebug()<<tr("��������");
    ui->search_pushbutton->setEnabled(false);
    ui->simplesearch_groupbox->setEnabled(false);
    ui->advancedsearch_groupbox->setEnabled(false);
}

void RoomStateSearchDialog::on_offline_radiobutton_clicked()
{
    //���߷���
    qDebug()<<tr("���߷���");
    ui->search_pushbutton->setEnabled(false);
    ui->simplesearch_groupbox->setEnabled(false);
    ui->advancedsearch_groupbox->setEnabled(false);
}

void RoomStateSearchDialog::on_alarm_radiobutton_clicked()
{
    //����
    qDebug()<<tr("����");
    ui->search_pushbutton->setEnabled(true);
    ui->simplesearch_groupbox->setEnabled(true);
    ui->advancedsearch_groupbox->setEnabled(true);
}*/

void RoomStateSearchDialog::on_simplesearch_groupbox_clicked()
{
    //�򵥲�ѯ
    qDebug()<<tr("�򵥲�ѯ");
    if(ui->simplesearch_groupbox->isChecked())
    {
        ui->advancedsearch_groupbox->setChecked(false);
    }
}

void RoomStateSearchDialog::on_or_radiobutton_clicked()
{
    //���ϵ
    qDebug()<<tr("���ϵ");
    rssdstate = simple_or;
    ui->temperatureup_checkbox->setChecked(orbits.testBit(temperatureup));
    ui->temperaturedown_checkbox->setChecked(orbits.testBit(temperaturedown));
    ui->humidityup_checkbox->setChecked(orbits.testBit(humidityup));
    ui->humiditydown_checkbox->setChecked(orbits.testBit(humiditydown));
    ui->oxygenup_checkbox->setChecked(orbits.testBit(oxygenup));
    ui->oxygendown_checkbox->setChecked(orbits.testBit(oxygendown));
    ui->carbodioxideup_checkbox->setChecked(orbits.testBit(carbodioxideup));
    ui->carbodioxidedown_checkbox->setChecked(orbits.testBit(carbodioxidedown));
    //ui->comindexup_checkbox->setChecked(orbits.testBit(comindexup));
    //ui->comindexdown_checkbox->setChecked(orbits.testBit(comindexdown));
    ui->mainvoltageup_checkbox->setChecked(orbits.testBit(mainvoltageup));
    ui->mainvoltagedown_checkbox->setChecked(orbits.testBit(mainvoltagedown));
    ui->zerovoltageup_checkbox->setChecked(orbits.testBit(zerovoltageup));
    ui->zerovoltagedown_checkbox->setChecked(orbits.testBit(zerovoltagedown));

    ui->water_checkbox->setChecked(orbits.testBit(waterlevel));
    ui->smoke_checkbox->setChecked(orbits.testBit(smoke));

    ui->comindex_checkbox->setChecked(orbits.testBit(comindexup));
    ui->pm25_checkbox->setChecked(orbits.testBit(pm25up));
    ui->mat_checkbox->setChecked(orbits.testBit(mattress));
}

void RoomStateSearchDialog::on_and_radiobutton_clicked()
{
    //���ϵ
    qDebug()<<tr("���ϵ");
    rssdstate = simple_and;
    ui->temperatureup_checkbox->setChecked(andbits.testBit(temperatureup));
    ui->temperaturedown_checkbox->setChecked(andbits.testBit(temperaturedown));
    ui->humidityup_checkbox->setChecked(andbits.testBit(humidityup));
    ui->humiditydown_checkbox->setChecked(andbits.testBit(humiditydown));
    ui->oxygenup_checkbox->setChecked(andbits.testBit(oxygenup));
    ui->oxygendown_checkbox->setChecked(andbits.testBit(oxygendown));
    ui->carbodioxideup_checkbox->setChecked(andbits.testBit(carbodioxideup));
    ui->carbodioxidedown_checkbox->setChecked(andbits.testBit(carbodioxidedown));
    //ui->comindexup_checkbox->setChecked(andbits.testBit(comindexup));
   // ui->comindexdown_checkbox->setChecked(andbits.testBit(comindexdown));
    ui->mainvoltageup_checkbox->setChecked(andbits.testBit(mainvoltageup));
    ui->mainvoltagedown_checkbox->setChecked(andbits.testBit(mainvoltagedown));
    ui->zerovoltageup_checkbox->setChecked(andbits.testBit(zerovoltageup));
    ui->zerovoltagedown_checkbox->setChecked(andbits.testBit(zerovoltagedown));

    ui->water_checkbox->setChecked(andbits.testBit(waterlevel));
    ui->smoke_checkbox->setChecked(andbits.testBit(smoke));

    ui->comindex_checkbox->setChecked(andbits.testBit(comindexup));
    ui->pm25_checkbox->setChecked(andbits.testBit(pm25up));
    ui->mat_checkbox->setChecked(andbits.testBit(mattress));


}

void RoomStateSearchDialog::on_water_checkbox_clicked()
{
    //©ˮ
    qDebug()<<tr("©ˮ");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->water_checkbox->isChecked())
        {
            orbits.setBit(waterlevel,true);
        }
        else
        {
            orbits.setBit(waterlevel,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->water_checkbox->isChecked())
        {
            andbits.setBit(waterlevel,true);
        }
        else
        {
            andbits.setBit(waterlevel,false);
        }
    }
}

void RoomStateSearchDialog::on_smoke_checkbox_clicked()
{
    //����
    qDebug()<<tr("����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->smoke_checkbox->isChecked())
        {
            orbits.setBit(smoke,true);
        }
        else
        {
            orbits.setBit(smoke,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->smoke_checkbox->isChecked())
        {
            andbits.setBit(smoke,true);
        }
        else
        {
            andbits.setBit(smoke,false);
        }
    }
}

void RoomStateSearchDialog::on_pm25_checkbox_clicked()
{
    //PM2.5
    qDebug()<<tr("PM2.5");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->pm25_checkbox->isChecked())
        {
            orbits.setBit(pm25up,true);
        }
        else
        {
            orbits.setBit(pm25up,false);
        }
        orbits.setBit(pm25down,false);

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->pm25_checkbox->isChecked())
        {
            andbits.setBit(pm25up,true);
        }
        else
        {
            andbits.setBit(pm25up,false);
        }
        andbits.setBit(pm25down,false);
    }
}
void RoomStateSearchDialog::on_mat_checkbox_clicked()
{
    //����
    qDebug()<<tr("����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->mat_checkbox->isChecked())
        {
            orbits.setBit(mattress,true);
        }
        else
        {
            orbits.setBit(mattress,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->mat_checkbox->isChecked())
        {
            andbits.setBit(mattress,true);
        }
        else
        {
            andbits.setBit(mattress,false);
        }
    }

}

void RoomStateSearchDialog::on_comindex_checkbox_clicked()
{
    //����Ʒ��
    qDebug()<<tr("����Ʒ��");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->comindex_checkbox->isChecked())
        {
            orbits.setBit(comindexup,true);
        }
        else
        {
            orbits.setBit(comindexup,false);
        }
        orbits.setBit(comindexdown,false);

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->comindex_checkbox->isChecked())
        {
            andbits.setBit(comindexup,true);
        }
        else
        {
            andbits.setBit(comindexup,false);
        }
        andbits.setBit(comindexdown,false);
    }
}


void RoomStateSearchDialog::on_temperatureup_checkbox_clicked()
{
    //�¶�����
    qDebug()<<tr("�¶�����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->temperatureup_checkbox->isChecked())
        {
            orbits.setBit(temperatureup,true);
        }
        else
        {
            orbits.setBit(temperatureup,false);
        }
    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->temperatureup_checkbox->isChecked())
        {
            andbits.setBit(temperatureup,true);
        }
        else
        {
            andbits.setBit(temperatureup,false);
        }
    }
}

void RoomStateSearchDialog::on_temperaturedown_checkbox_clicked()
{
    //�¶�����
    qDebug()<<tr("�¶�����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->temperaturedown_checkbox->isChecked())
        {
            orbits.setBit(temperaturedown,true);
        }
        else
        {

            orbits.setBit(temperaturedown,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->temperaturedown_checkbox->isChecked())
        {
            andbits.setBit(temperaturedown,true);
        }
        else
        {
            andbits.setBit(temperaturedown,false);
        }
    }
}

void RoomStateSearchDialog::on_humidityup_checkbox_clicked()
{
    //ʪ������
    qDebug()<<tr("ʪ������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->humidityup_checkbox->isChecked())
        {
            orbits.setBit(humidityup,true);
        }
        else
        {
            orbits.setBit(humidityup,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->humidityup_checkbox->isChecked())
        {
            andbits.setBit(humidityup,true);
        }
        else
        {
            andbits.setBit(humidityup,false);
        }
    }
}

void RoomStateSearchDialog::on_humiditydown_checkbox_clicked()
{
    //ʪ������
    qDebug()<<tr("ʪ������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->humiditydown_checkbox->isChecked())
        {
            orbits.setBit(humiditydown,true);
        }
        else
        {
            orbits.setBit(humiditydown,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->humiditydown_checkbox->isChecked())
        {
            andbits.setBit(humiditydown,true);
        }
        else
        {
            andbits.setBit(humiditydown,false);
        }
    }
}

void RoomStateSearchDialog::on_oxygenup_checkbox_clicked()
{
    //��������
    qDebug()<<tr("��������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->oxygenup_checkbox->isChecked())
        {
            orbits.setBit(oxygenup,true);
        }
        else
        {
            orbits.setBit(oxygenup,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->oxygenup_checkbox->isChecked())
        {
            andbits.setBit(oxygenup,true);
        }
        else
        {
            andbits.setBit(oxygenup,false);
        }
    }
}

void RoomStateSearchDialog::on_oxygendown_checkbox_clicked()
{
    //��������
    qDebug()<<tr("��������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->oxygendown_checkbox->isChecked())
        {
            orbits.setBit(oxygendown,true);
        }
        else
        {
            orbits.setBit(oxygendown,false);
        }
    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->oxygendown_checkbox->isChecked())
        {
            andbits.setBit(oxygendown,true);
        }
        else
        {
            andbits.setBit(oxygendown,false);
        }
    }
}

void RoomStateSearchDialog::on_carbodioxideup_checkbox_clicked()
{
    //������̼����
    qDebug()<<tr("������̼����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->carbodioxideup_checkbox->isChecked())
        {
            orbits.setBit(carbodioxideup,true);
        }
        else
        {
            orbits.setBit(carbodioxideup,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->carbodioxideup_checkbox->isChecked())
        {
            andbits.setBit(carbodioxideup,true);
        }
        else
        {
            andbits.setBit(carbodioxideup,false);
        }
    }
}

void RoomStateSearchDialog::on_carbodioxidedown_checkbox_clicked()
{
    //������̼����
    qDebug()<<tr("������̼����");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->carbodioxidedown_checkbox->isChecked())
        {
            orbits.setBit(carbodioxidedown,true);
        }
        else
        {
            orbits.setBit(carbodioxidedown,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->carbodioxidedown_checkbox->isChecked())
        {
            andbits.setBit(carbodioxidedown,true);
        }
        else
        {
            andbits.setBit(carbodioxidedown,false);
        }
    }
}

/*void RoomStateSearchDialog::on_comindexup_checkbox_clicked()
{
    //����Ʒ������
    qDebug()<<tr("����Ʒ������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->comindexup_checkbox->isChecked())
        {
            orbits.setBit(comindexup,true);
        }
        else
        {
            orbits.setBit(comindexup,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->comindexup_checkbox->isChecked())
        {
            andbits.setBit(comindexup,true);
        }
        else
        {
            andbits.setBit(comindexup,false);
        }
    }
}

void RoomStateSearchDialog::on_comindexdown_checkbox_clicked()
{
    //����Ʒ������
    qDebug()<<tr("����Ʒ������");
    if(ui->or_radiobutton->isChecked())
    {
        if(ui->comindexdown_checkbox->isChecked())
        {
            orbits.setBit(comindexdown,true);
        }
        else
        {
            orbits.setBit(comindexdown,false);
        }

    }
    else if(ui->and_radiobutton->isChecked())
    {
        if(ui->comindexdown_checkbox->isChecked())
        {
            andbits.setBit(comindexdown,true);
        }
        else
        {
            andbits.setBit(comindexdown,false);
        }
    }
}*/
void RoomStateSearchDialog::on_mainvoltageup_checkbox_clicked()
{
     qDebug()<<tr("�е��ѹ����");
     if(ui->or_radiobutton->isChecked())
     {
         if(ui->mainvoltageup_checkbox->isChecked())
         {
             orbits.setBit(mainvoltageup,true);
         }
         else
         {
             orbits.setBit(mainvoltageup,false);
         }

     }
     else if(ui->and_radiobutton->isChecked())
     {
         if(ui->mainvoltageup_checkbox->isChecked())
         {
             andbits.setBit(mainvoltageup,true);
         }
         else
         {
             andbits.setBit(mainvoltageup,false);
         }
     }
}

void RoomStateSearchDialog::on_mainvoltagedown_checkbox_clicked()
{
     qDebug()<<tr("�е��ѹ����");
     if(ui->or_radiobutton->isChecked())
     {
         if(ui->mainvoltagedown_checkbox->isChecked())
         {
             orbits.setBit(mainvoltagedown,true);
         }
         else
         {
             orbits.setBit(mainvoltagedown,false);
         }

     }
     else if(ui->and_radiobutton->isChecked())
     {
         if(ui->mainvoltagedown_checkbox->isChecked())
         {
             andbits.setBit(mainvoltagedown,true);
         }
         else
         {
             andbits.setBit(mainvoltagedown,false);
         }
     }
}

void RoomStateSearchDialog::on_zerovoltageup_checkbox_clicked()
{
     qDebug()<<tr("���ѹ������");
     if(ui->or_radiobutton->isChecked())
     {
         if(ui->zerovoltageup_checkbox->isChecked())
         {
             orbits.setBit(zerovoltageup,true);
         }
         else
         {
             orbits.setBit(zerovoltageup,false);
         }

     }
     else if(ui->and_radiobutton->isChecked())
     {
         if(ui->zerovoltageup_checkbox->isChecked())
         {
             andbits.setBit(zerovoltageup,true);
         }
         else
         {
             andbits.setBit(zerovoltageup,false);
         }
     }
}

void RoomStateSearchDialog::on_zerovoltagedown_checkbox_clicked()
{
     qDebug()<<tr("���ѹ������");
     if(ui->or_radiobutton->isChecked())
     {
         if(ui->zerovoltagedown_checkbox->isChecked())
         {
             orbits.setBit(zerovoltagedown,true);
         }
         else
         {
             orbits.setBit(zerovoltagedown,false);
         }

     }
     else if(ui->and_radiobutton->isChecked())
     {
         if(ui->zerovoltagedown_checkbox->isChecked())
         {
             andbits.setBit(zerovoltagedown,true);
         }
         else
         {
             andbits.setBit(zerovoltagedown,false);
         }
     }
}



void RoomStateSearchDialog::on_advancedsearch_groupbox_clicked()
{
    //�߼���ѯ
    qDebug()<<tr("�߼���ѯ");
    if(ui->advancedsearch_groupbox->isChecked())
    {
        ui->simplesearch_groupbox->setChecked(false);
    }
}

void RoomStateSearchDialog::on_waterlevel_toolbutton_clicked()
{
    //©ˮ
    qDebug()<<tr("©ˮ");
    expstr.append('*');
    expeachstrlenth.insert(0,2);
    //advancedcondtion.append("smoke")
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"©ˮ");
}

void RoomStateSearchDialog::on_pm25_toolbutton_clicked()
{
    qDebug()<<tr("pm25");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"PM25");

}

void RoomStateSearchDialog::on_mat_toolbutton_clicked()
{
    expstr.append('*');
    expeachstrlenth.insert(0,2);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"����");
}

void RoomStateSearchDialog::on_comindex_toolbutton_clicked()
{
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"����Ʒ��");
}

void RoomStateSearchDialog::on_smoke_toolbutton_clicked()
{
    //����
    qDebug()<<tr("����");
    expstr.append('*');
    expeachstrlenth.insert(0,2);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"����");
}

void RoomStateSearchDialog::on_temperatureup_toolbutton_clicked()
{
    //�¶�����
    qDebug()<<tr("�¶�����");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"�¶�����");
}

void RoomStateSearchDialog::on_temperaturedown_toolbutton_clicked()
{
    //�¶�����
    qDebug()<<tr("�¶�����");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"�¶�����");
}

void RoomStateSearchDialog::on_humidityup_toolbutton_clicked()
{
    //ʪ������
    qDebug()<<tr("ʪ������");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"ʪ������");
}

void RoomStateSearchDialog::on_humiditydown_toolbutton_clicked()
{
    //ʪ������
    qDebug()<<tr("ʪ������");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"ʪ������");
}

void RoomStateSearchDialog::on_oxygenup_toolbutton_clicked()
{
    //��������
    qDebug()<<tr("��������");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"��������");
}

void RoomStateSearchDialog::on_oxygendown_toolbutton_clicked()
{
    //��������
    qDebug()<<tr("��������");
    expstr.append('*');
    expeachstrlenth.insert(0,4);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"��������");
}

void RoomStateSearchDialog::on_carbodioxideup_toolbutton_clicked()
{
    //������̼����
    qDebug()<<tr("������̼����");
    expstr.append('*');
    expeachstrlenth.insert(0,6);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"������̼����");
}

void RoomStateSearchDialog::on_carbodioxidedown_toolbutton_clicked()
{
    //������̼����
    qDebug()<<tr("������̼����");
    expstr.append('*');
    expeachstrlenth.insert(0,6);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"������̼����");
}

/*void RoomStateSearchDialog::on_comindexup_toolbutton_clicked()
{
    //����Ʒ������
    qDebug()<<tr("����Ʒ������");
    expstr.append('*');
    expeachstrlenth.insert(0,6);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"����Ʒ������");
}

void RoomStateSearchDialog::on_comindexdown_toolbutton_clicked()
{
    //����Ʒ������
    qDebug()<<tr("����Ʒ������");
    expstr.append('*');
    expeachstrlenth.insert(0,6);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"����Ʒ������");
}*/

void RoomStateSearchDialog::on_mainvoltageup_toolbutton_clicked()
{
     qDebug()<<tr("�е��ѹ����");
     expstr.append('*');
     expeachstrlenth.insert(0,6);
     ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"�е��ѹ����");
}

void RoomStateSearchDialog::on_mainvoltagedown_toolbutton_clicked()
{
     qDebug()<<tr("�е��ѹ����");
     expstr.append('*');
     expeachstrlenth.insert(0,6);
     ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"�е��ѹ����");
}

void RoomStateSearchDialog::on_zerovoltageup_toolbutton_clicked()
{
     qDebug()<<tr("���ѹ������");
     expstr.append('*');
     expeachstrlenth.insert(0,6);
     ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"���ѹ������");
}

void RoomStateSearchDialog::on_zerovoltagedown_toolbutton_clicked()
{
     qDebug()<<tr("���ѹ������");
     expstr.append('*');
     expeachstrlenth.insert(0,6);
     ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"���ѹ������");
}


void RoomStateSearchDialog::on_leftbracket_toolbutton_clicked()
{
    //������
    qDebug()<<tr("������");
    expstr.append('(');
    expeachstrlenth.insert(0,1);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"(");
}

void RoomStateSearchDialog::on_rightbracket_toolbutton_clicked()
{
    //������
    qDebug()<<tr("������");
    expstr.append(')');
    expeachstrlenth.insert(0,1);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+")");
}

void RoomStateSearchDialog::on_or_toolbutton_clicked()
{
    //���ϵ
    qDebug()<<tr("���ϵ");
    expstr.append('|');
    expeachstrlenth.insert(0,1);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"|");
}

void RoomStateSearchDialog::on_and_toolbutton_clicked()
{
    //���ϵ
    qDebug()<<tr("���ϵ");
    expstr.append('&');
    expeachstrlenth.insert(0,1);
    ui->exp_textedit->setText(ui->exp_textedit->toPlainText()+"&");
}

void RoomStateSearchDialog::on_clear_toolbutton_clicked()
{
    //���
    qDebug()<<tr("���");
    expstr.clear();
    ui->exp_textedit->clear();
}

void RoomStateSearchDialog::on_backdel_toolbutton_clicked()
{
    //��ɾ
    qDebug()<<tr("��ɾ");
    QString text = ui->exp_textedit->toPlainText();
    if(!text.isEmpty())
    {
        ui->exp_textedit->setText(text.left(text.length()-expeachstrlenth.takeFirst()));
        expstr.remove(expstr.length()-1,1);
    }
}

void RoomStateSearchDialog::on_demonstration_toolbutton_clicked()
{
    //ʾ��
    qDebug()<<tr("ʾ��");
    if(demonstration_dialog->isHidden())
    {
        demonstration_dialog->move(oldpos);
        demonstration_dialog->show();
        ui->demonstration_toolbutton->setEnabled(false);
    }
    else
        demonstration_dialog->hide();
    //oldpos =
}

void RoomStateSearchDialog::on_simpleandadvanced_pushbutton_clicked()
{
    if(ui->advancedsearch_groupbox->isHidden())
    {
        this->setFixedHeight(375);
        ui->advancedsearch_groupbox->show();
        /*ui->simpleandadvanced_pushbutton->setGeometry(525 + 35,340,55,25);
        ui->search_pushbutton->setGeometry(590 + 35,340,55,25);*/
        ui->simpleandadvanced_pushbutton->setGeometry(335 + 35,340,55,25);
        ui->search_pushbutton->setGeometry(400 + 35,340,55,25);
        ui->simpleandadvanced_pushbutton->setText(tr("��<<"));
        ui->simplesearch_groupbox->setChecked(false);
        ui->advancedsearch_groupbox->setChecked(true);
        ui->advancedsearch_groupbox->setEnabled(true);
    }
    else
    {
        this->setFixedHeight(160);
        ui->advancedsearch_groupbox->hide();
        /*ui->simpleandadvanced_pushbutton->setGeometry(525 + 35,130,55,25);
        ui->search_pushbutton->setGeometry(590 + 35,130,55,25);*/
        ui->simpleandadvanced_pushbutton->setGeometry(335 + 35,130,55,25);
        ui->search_pushbutton->setGeometry(400 + 35,130,55,25);
        ui->simpleandadvanced_pushbutton->setText(tr("�߼�>>"));
        ui->simplesearch_groupbox->setChecked(true);
        ui->advancedsearch_groupbox->setChecked(false);
    }
}

bool RoomStateSearchDialog::checkExpStrValidity()
{
    E();
    j=0;
    bool tempflag = flag;
    flag = false;
    isfailed = false;
    bracket = 0;
    return tempflag;
}
//�ݹ��½�����
void RoomStateSearchDialog::E()
{

   qDebug()<<expstr.length();
   T();
   EP();


}
void RoomStateSearchDialog::EP()
{
    if(isfailed) return;
    if(j < expstr.length()&&(expstr.at(j)=='&'||expstr.at(j)=='|'))
    {
            j++;
            T();
            EP();
    }
}
void RoomStateSearchDialog::T()
{
    if(j < expstr.length()&&expstr.at(j)=='*')
    {
        j++;
        if(j == expstr.length()&&!bracket)
            flag = true;
    }
    else if(j < expstr.length()&&expstr.at(j)=='(')
    {
        j++;
        bracket++;
        E();
        if(isfailed) return;
        if(j < expstr.length()&&expstr.at(j)==')')
        {
            j++;
            bracket--;
            if(j == expstr.length()&&!bracket)
            {
                flag = true;

               /* if(expstr.at(j-2) == '|' ||expstr.at(j-2) == '&')
                    flag = false;*/

                return;
            }
        }
        else
        {
            if(j == expstr.length()) return;
            flag = false;
            return;
        }
    }
    else
    {
        if(j == expstr.length()) return;
       // j++;
        flag = false;
        isfailed = true;
        return;
    }
}
void RoomStateSearchDialog::conditionToSqlCondtion()
{
    advancedcondtion.clear();
    args.clear();
    QString tempstr = ui->exp_textedit->toPlainText();
    qDebug()<<tempstr;
    int i = 0;
    int length = tempstr.size();
    while(i < length)
    {
        qDebug()<<"hha";
        qDebug()<<tempstr.at(i).digitValue();
        qDebug()<<QChar('(').digitValue();
        qDebug()<<QChar(')').digitValue();
        if(tempstr.at(i) == QChar('('))
        {
            advancedcondtion +="(";
            qDebug()<<"123";
            i++;
        }
        else if(tempstr.at(i) == QChar(')'))
        {
            advancedcondtion+=")";
             qDebug()<<"321";
            i++;
        }
        else if(tempstr.at(i) == '&')
        {
            advancedcondtion.append(" AND ");
            i++;
        }
        else if(tempstr.at(i) == '|')
        {
            advancedcondtion.append(" OR ");
            i++;
        }
        else
        {
            QString str;
            str.append(tempstr.at(i));
            i++;
            while(i < length && tempstr.at(i) != '(' && tempstr.at(i) != ')' && tempstr.at(i) != '&' && tempstr.at(i) != '|')
            {
                str.append(tempstr.at(i));
                i++;
                qDebug()<<"hahahahah";
            }
            qDebug()<<i;
            //��������ַ���
            if(str == "�¶�����")
            {
                advancedcondtion.append("temp_flag = ?");
                args.append(temperatureup);
            }
            else if(str == "�¶�����")
            {
                advancedcondtion.append("temp_flag = ?");
                args.append(temperaturedown);
            }
            else if(str == "ʪ������")
            {
                advancedcondtion.append("mois_flag = ?");
                args.append(humidityup);
            }
            else if(str == "ʪ������")
            {
                advancedcondtion.append("mois_flag = ?");
                args.append(humiditydown);
            }
            else if(str == "��������")
            {
                advancedcondtion.append("O2_flag = ?");
                args.append(oxygenup);
            }
            else if(str == "��������")
            {
                advancedcondtion.append("O2_flag = ?");
                args.append(oxygendown);
            }
            else if(str == "������̼����")
            {
                advancedcondtion.append("CO2_flag = ?");
                args.append(carbodioxideup);
            }
            else if(str == "������̼����")
            {
                advancedcondtion.append("CO2_flag = ?");
                args.append(carbodioxidedown);
            }
            /*else if(str == "����Ʒ������")
            {
                advancedcondtion.append("indexs_flag = ?");
                args.append(comindexup);
            }
            else if(str == "����Ʒ������")
            {
                advancedcondtion.append("indexs_flag = ?");
                args.append(comindexdown);
            }*/
            else if(str == "�е��ѹ����")
            {
                advancedcondtion.append("vol1_flag = ?");
                args.append(mainvoltageup);
            }
            else if(str == "�е��ѹ����")
            {
                advancedcondtion.append("vol1_flag = ?");
                args.append(mainvoltagedown);
            }
            else if(str == "���ѹ������")
            {
                advancedcondtion.append("vol2_flag = ?");
                args.append(zerovoltageup);
            }
            else if(str == "���ѹ������")
            {
                advancedcondtion.append("vol2_flag = ?");
                args.append(zerovoltagedown);
            }
            else if(str == "����")
            {
                advancedcondtion.append("smoke = ?");
                args.append(smoke);
            }
            else if(str == "©ˮ")
            {
                advancedcondtion.append("water = ?");
                args.append(waterlevel);
            }
            else if(str == "����")
            {
                advancedcondtion.append("mat_flag = ?");
                args.append(mattress);
            }
            else if(str == "PM25")
            {
                advancedcondtion.append("pm25_flag = ?");
                args.append(pm25up);
            }
            else if(str == "����Ʒ��")
            {
                advancedcondtion.append("indexs_flag = ?");
                args.append(comindexup);
            }


            //continue�¸�ѭ�����ж�
        }


    }

}


//�ݹ��½�����
void RoomStateSearchDialog::on_search_pushbutton_clicked()
{

        if(ui->advancedsearch_groupbox->isChecked())
        {
            qDebug()<<expstr;
            if(expstr.isEmpty())
            {
                QMessageBox::warning(0,tr("����"),tr("���ʽΪ�գ�"),tr("ȷ��"));
                return;
            }
            if(checkExpStrValidity())
            {
                qDebug()<<"chenggong";
                rssdstate = advanced;
                qDebug()<<ui->exp_textedit->toPlainText();
                conditionToSqlCondtion();
                accept();
            }
            else
            {
                QMessageBox::warning(0,tr("����"),tr("���ʽ����"),tr("ȷ��"));
                return;
            }
        }
        else if(ui->simplesearch_groupbox->isChecked())
        {
            if(ui->and_radiobutton->isChecked())
                rssdstate = simple_and;
            else
                rssdstate = simple_or;
            qDebug()<<"simple";
            accept();
        }


}


void RoomStateSearchDialog::closeEvent(QCloseEvent * event)
{
    //this->reject();
    QDialog::closeEvent(event);
}






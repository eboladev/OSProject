#include <QtGui/QHeaderView>
#include <QtCore/QDebug>
#include <QtGui/QListWidget>
#include <QtGui/QTableWidgetItem>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QDateTime>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include "controltablelistwidget.h"
#include "plotter.h"
#include "plotsettings.h"
#include "mainwindow.h"
#include "preferencedialog.h"
#include "historydataform.h"
//所需控件头文件
#include "preferencedialog.h"

#include "plotsettings.h"
#include "plotter.h"
#include "parametertable.h"
#include "prametertablewidget.h"
#include "historydataform.h"
#include "receiver.h"
#include "instrumentpanel.h"
#include "thermometer.h"
#include "histogramwidget.h"
#include "struct.h"

ControlTableListWidget::ControlTableListWidget(QWidget *parent) :
    QTableWidget(parent),columnsize(4),rowsize(6)
{
    //listmodewidget = new QListWidget(this);
    sbn = false;
    sbt = false;
    sbf = false;
    sbm = false;
    islist = false;
    isicon = false;
    istablelist = true;

    curindex = -1;//初始化为-1用于判断
    controltype = -1;//初始化为-1用于判断

    getControls();
    createTableList();
    createRightMenuActions();
    this->setFocusPolicy(Qt::NoFocus);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    //this->setSelectionBehavior();
    //this
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),SLOT(showRightMenu(QPoint)));
    connect(this,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(defaultAction(int,int)));
    this->setStyleSheet("QTableWidget{background-color:#FFFFE0;}");
}
void ControlTableListWidget::createTableList()
{

    QStringList filenameandsuffixs;
    QStringList usedfrequecys;
    QStringList accesstimes;

    QFile controlfile("controltables.dat");
    if (!controlfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }
    QTextStream in(&controlfile);
    while(!in.atEnd())
    {
        QString str = in.readLine();
        QStringList temp = str.split("*");
        filenameandsuffixs.append(temp.at(0));
        usedfrequecys.append(temp.at(1));
        accesstimes.append(temp.at(2));
    }
    controlfile.close();
    qDebug()<<filenameandsuffixs;
    qDebug()<<usedfrequecys;
    qDebug()<<accesstimes;




    this->setColumnCount(columnsize);
    this->setRowCount(filenameandsuffixs.count());
    horizentitle = new QStringList;
    horizentitle->append(tr("名称"));
    horizentitle->append(tr("类型"));
    horizentitle->append(tr("次数"));
    horizentitle->append(tr("时间"));
    this->verticalHeader()->setVisible(false);


    this->setHorizontalHeaderLabels(*horizentitle);//设置表头标题
    this->horizontalHeader()->setStretchLastSection(true);//设置满表宽度
    this->horizontalHeader()->setHighlightSections(false);

  //this->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    this->verticalHeader()->setDefaultSectionSize(20);//设置行距
  //this->horizontalHeader()->resizeSection(0,150);
    this->horizontalHeader()->setFixedHeight(20);
  //this->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    this->setFrameShape(QFrame::NoFrame);//设置无边框
    this->setShowGrid(false);//显示无表格
    //this->setSelectionMode(QAbstractItemView::ExtendedSelection);//可多选Ctrl、Shift、  Ctrl+A都可以
    this->setSelectionBehavior(QAbstractItemView::SelectRows);//设置按行选择
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    this->setColumnHidden(1,true);
    this->setIconSize(QSize(30,18));
    this->setStyleSheet("selection-background-color:lightblue;");


   /* QFileInfoList::iterator i = list.begin();
    QFileInfo tempinfo;
    int temprow = 0;
    while(i != list.end())
    {
        tempinfo = *i;
        QTableWidgetItem * item = new QTableWidgetItem(QIcon("images/historicalcurve.jpg"),tempinfo.fileName());
        int type = -1;
        QString filesuffix = tempinfo.suffix();

        if(filesuffix == "rtc")
            type = rtc_ctl;
        else if(filesuffix == "hsc")
            type = hsc_ctl;
        else if(filesuffix == "pmt")
            type = pmt_ctl;
        else if(filesuffix == "tmt")
            type = tmt_ctl;
        else if(filesuffix == "isp")
            type = isp_ctl;
        else if(filesuffix == "bct")
            type = bct_ctl;

        item->setData(Qt::UserRole,type);

        this->setItem(temprow,0,item);
        this->setItem(temprow,1,new QTableWidgetItem(tempinfo.suffix()));
        this->setItem(temprow,2,new QTableWidgetItem(tempinfo.suffix()+tr("  文件")));
        this->setItem(temprow,3,new QTableWidgetItem(tempinfo.lastModified().toString("yyyy-MM-dd hh:mm")));
        i++;
        temprow++;
    }*/
    for(int i = 0; i < filenameandsuffixs.count(); i++)
    {
        QTableWidgetItem * item = new QTableWidgetItem(QIcon("images/historicalcurve.jpg"),filenameandsuffixs.at(i));
        QString tempstr = filenameandsuffixs.at(i);
        QString filesuffix = tempstr.split(".").last();
        QString iconstr;
        iconstr.append("images/");
        int type = -1;
        if(filesuffix == "rtc")
        {
            type = rtc_ctl;
            iconstr.append("rtc_1");
        }
        else if(filesuffix == "hsc")
        {
            type = hsc_ctl;
            iconstr.append("hsc_1");
        }
        else if(filesuffix == "pmt")
        {
            type = pmt_ctl;
            iconstr.append("pmt_1");
        }
        else if(filesuffix == "tmt")
        {
            type = tmt_ctl;
            iconstr.append("tmt_1");
        }
        else if(filesuffix == "isp")
        {
            type = isp_ctl;
            iconstr.append("isp_1");
        }
        else if(filesuffix == "bct")
        {
            type = bct_ctl;
            iconstr.append("bct_1");
        }
        iconstr.append(".png");
        item->setIcon(QIcon(iconstr));
        item->setData(Qt::UserRole,type);
        item->setToolTip(item->text());
        this->setItem(i,0,item);
        this->setItem(i,1,new QTableWidgetItem(filesuffix));
        item = new QTableWidgetItem(usedfrequecys.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        this->setItem(i,2,item);
        item = new QTableWidgetItem(accesstimes.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        this->setItem(i,3,item);
    }
}

void ControlTableListWidget::createRightMenuActions()
{
    //创建右键菜单
     previewcontrol_action = new QAction(tr("预览"),this);
   //  newcontrol_action = new QAction(tr("新建"),this);//是否需要？
     editcontrol_action = new QAction(tr("编辑"),this);
     deletecontrol_action = new QAction(tr("删除"),this);

     detailinfolist_action = new QAction(tr("详细信息"),this);
     listmode_action = new QAction(tr("列表"),this);
     iconmode_action = new QAction(tr("图标"),this);
     sortbyname_aciton = new QAction(tr("名称"),this);
     sortbytype_action = new QAction(tr("类型"),this);
     sortbyfrequency_action = new QAction(tr("使用频次"),this);
     sortbymoditime_action = new QAction(tr("访问时间"),this);

     connect(previewcontrol_action,SIGNAL(triggered()),this,SLOT(previewControl()));
     connect(editcontrol_action,SIGNAL(triggered()),this,SLOT(editControl()));
     connect(deletecontrol_action,SIGNAL(triggered()),this,SLOT(deleteControlRequest()));
    // connect(newcontrol_action,SIGNAL(triggered()),this,SLOT(newControl()));
     connect(detailinfolist_action,SIGNAL(triggered()),this,SLOT(detailInfoPermutation()));
     connect(listmode_action,SIGNAL(triggered()),this,SLOT(listPermutation()));
     connect(iconmode_action,SIGNAL(triggered()),this,SLOT(iconPermutation()));
     connect(sortbyname_aciton,SIGNAL(triggered()),this,SLOT(sortByName()));
     connect(sortbytype_action,SIGNAL(triggered()),this,SLOT(sortByType()));
     connect(sortbyfrequency_action,SIGNAL(triggered()),this,SLOT(sortByFrequency()));
     connect(sortbymoditime_action,SIGNAL(triggered()),this,SLOT(sortByModiTime()));


     realtimecurve_action = new QAction(tr("实时曲线"),this);
     historycurve_action = new QAction(tr("历史曲线"),this);
     parametertable_action = new QAction(tr("参数表"),this);
     historydataform_action = new QAction(tr("历史数据"),this);
     thermometer_action = new QAction(tr("温度计"),this);
     instrumentpanel_action = new QAction(tr("仪表盘"),this);
     barchart_action = new QAction(tr("条形图"),this);

     connect(realtimecurve_action,SIGNAL(triggered()),this,SLOT(newRealTimeCurve()));
     connect(historycurve_action,SIGNAL(triggered()),this,SLOT(newHistoryCurve()));
     connect(parametertable_action,SIGNAL(triggered()),this,SLOT(newParameterTable()));
     connect(historydataform_action,SIGNAL(triggered()),this,SLOT(newHistoryDataForm()));
     connect(thermometer_action,SIGNAL(triggered()),this,SLOT(newThermometer()));
     connect(instrumentpanel_action,SIGNAL(triggered()),this,SLOT(newInstrumentPanel()));
     connect(barchart_action,SIGNAL(triggered()),this,SLOT(newBarchart()));



}

void ControlTableListWidget::defaultAction(int row,int col)
{
    if(row >= 0 && col >= 0)
    {
        QTableWidgetItem * curItem = item(row,0);
        qDebug()<<"curItem"<<curItem;
        if(curItem != NULL)
        {
            controltype = curItem->data(Qt::UserRole).toInt();
            qDebug()<<"controltype"<<controltype;
            curindex = row;
        }
        this->previewControl();
    }
}
void ControlTableListWidget::previewControl()
{
    //预览控件
    qDebug()<<tr("预览控件");
    qDebug()<<"currentindex"<<curindex;
    item(curindex,3)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));
    QDialog * previewdlg = new QDialog(this);
    previewdlg->setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);

   // previewdlg->setWindowModality(Qt::ApplicationModal);
    QString filename = item(curindex,0)->text();
    QHBoxLayout * hlt = new QHBoxLayout(previewdlg);
    hlt->setMargin(0);
    qDebug()<<"controltype"<<controltype;
    switch(controltype)
    {
    case rtc_ctl:
    {
        //预览实时曲线
        previewdlg->setWindowTitle("实时曲线");
        Plotter * plotter = new Plotter(previewdlg);
        plotter->loadArgs(filename);
      //  plotter->launch();
        hlt->addWidget(plotter);
        previewdlg->setFixedHeight(550);
        previewdlg->setFixedWidth(plotter->minimumWidth());
    }
        break;
    case hsc_ctl:
    {
        //预览历史曲线
    }
        break;
    case pmt_ctl:
    {
        //预览参数表
        previewdlg->setWindowTitle(tr("参数表"));
        PrameterTableWidget * parametertable= new PrameterTableWidget(previewdlg);
        parametertable->loadArgs(filename);
       // parametertable->launch();
        hlt->addWidget(parametertable);
        previewdlg->resize(parametertable->minimumWidth(),parametertable->minimumHeight());
    }
        break;
    case hsd_ctl:
    {
        //预览历史数据
        HistoryDataForm * historydatatable = new HistoryDataForm(previewdlg);
        hlt->addWidget(historydatatable);
    }
        break;
    case tmt_ctl:
    {
        //预览温度计
        previewdlg->setWindowTitle(tr("温度计"));
        Thermometer * thermometer = new Thermometer(previewdlg);
        qDebug()<<filename;
        thermometer->loadArgs(filename);
       // thermometer->launch();
        hlt->addWidget(thermometer);
        previewdlg->setFixedSize(166,330);
         /*Thermometer * thermometer = new Thermometer;
         thermometer->loadArgs(filename);
         thermometer->show();*/
    }
        break;
    case isp_ctl:
    {
        qDebug()<<"预览仪表盘";
        //预览仪表盘
        previewdlg->setWindowTitle(tr("仪表盘"));
        InstrumentPanel * instrumentpanel = new InstrumentPanel(previewdlg);
        instrumentpanel->loadArgs(filename);
       // instrumentpanel->launch();
        hlt->addWidget(instrumentpanel);
        previewdlg->setFixedSize(300,300);

        /*InstrumentPanel * instrumentpanel = new InstrumentPanel;
        instrumentpanel->loadArgs(filename);
        instrumentpanel->launch();
        instrumentpanel->show();*/
    }
        break;
    case bct_ctl:
    {
        //预览条形图
        previewdlg->setWindowTitle(tr("条形图"));
        HistoGramWidget * histogram = new HistoGramWidget(previewdlg);
        histogram->loadArgs(filename);
       // histogram->launch();
        hlt->addWidget(histogram);
        previewdlg->setFixedWidth(histogram->minimumWidth());
        previewdlg->setFixedHeight(histogram->minimumHeight());
    }
        break;
    default:qDebug()<<"control error!";
    }

    previewdlg->setLayout(hlt);
    this->modifyControlTable();
    previewdlg->setEnabled(false);
    previewdlg->exec();

}

void ControlTableListWidget::editControl()
{
    //编辑控件
    qDebug()<<tr("编辑控件");
   // emit edit(curindex);
    item(curindex,3)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));
    this->modifyControlTable();
    PreferenceDialog * argselet = new PreferenceDialog(controltype,item(curindex,0)->text(),true,this);
    //argselet->oldfilename = item(curindex,0)->text();
    qDebug()<<"kongjianleixing"<<controltype;
    qDebug()<<item(curindex,0)->text();
    //argselet->setEdit(true);

    argselet->exec();
    delete argselet;


}

void ControlTableListWidget::deleteControlRequest()
{
    //删除控件
    qDebug()<<tr("删除控件");
    emit del(curindex);
}

void ControlTableListWidget::deleteControl(bool flag)
{

    int result = QMessageBox::warning(0,"警告","是否删除该控件！","确定","取消");
    if(result == 1)
        return;
    if(!flag)
    {
        QMessageBox::warning(0,tr("警告"),tr("控件使用中，无法删除！"),tr("确定"));
        return;
    }
    QString controlfilename = item(curindex,0)->text();
    QString path = "controls/";
    QFile file(path+controlfilename);
    if(!file.exists())//是否要判断？
    {
        QMessageBox::critical(0,tr("错误"),tr("对应文件不存在，删除无效控件！"),tr("确定"));
        this->removeRow(curindex);//是否？
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }

    QTextStream in(&file);
    QStringList filecontents;
    int count = in.readLine().toInt();
    filecontents<<QString::number(count);
    while(count > 0)
    {
        filecontents<<in.readLine();
        --count;
    }
    QString str = in.readLine();
    if(str.isNull())
    {
        file.remove();
        this->removeRow(curindex);
        modifyControlTable();
        if(islist) emit showlistmode();
        else if(isicon) emit showiconmode();
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("该控件在其他视图中使用，无法删除！"),tr("确定"));
        file.close();
        return;
    }
}

/*void ControlTableListWidget::newControl()
{
     //新建视图
    qDebug()<<tr("新建控件");
   // emit edit(curindex);
}*/

void ControlTableListWidget::detailInfoPermutation()
{
     //详细信息列表
    if(istablelist == false)
    {
        istablelist = true;
        islist = false;
        isicon = false;
        this->show();
        emit hideList();
        //list隐藏如何实现
    }
    qDebug()<<tr("详细信息");
}

void ControlTableListWidget::listPermutation()
{
     //列表
    qDebug()<<tr("列表");
    if(islist == false)
    {
        islist = true;
        isicon = false;
        istablelist = false;
        emit this->showlistmode();
    }
}

void ControlTableListWidget::iconPermutation()
{
    //图标
    qDebug()<<tr("图标");
    if(isicon == false)
    {
        isicon = true;
        islist = false;
        istablelist = false;
        emit this->showiconmode();
    }

}

void ControlTableListWidget::sortByName()
{
    //按名排序
    if(!sbn)
    {
        sortByColumn(0,Qt::AscendingOrder);
        sbn = true;
    }
    else
    {
       sortByColumn(0,Qt::DescendingOrder);
        sbn = false;
    }
    if(islist == true)
        emit this->showlistmode();
    else if(isicon == true)
        emit this->showiconmode();
    qDebug()<<tr("名称");
    modifyControlTable();
}

void ControlTableListWidget::sortByType()
{
    //按类型排序
    if(!sbt)
    {
        sortByColumn(1,Qt::AscendingOrder);
        sbt = true;
    }
    else
    {
        sortByColumn(1,Qt::DescendingOrder);
        sbt = false;
    }
    if(islist == true)
        emit this->showlistmode();
    else if(isicon == true)
        emit this->showiconmode();
    qDebug()<<tr("类型");
    modifyControlTable();
}

void ControlTableListWidget::sortByFrequency()
{
    //按使用频次排序
    if(!sbf)
    {
        //sortByColumn(2,Qt::AscendingOrder);
        sortByFrequencyCustom(!sbf);
        sbf = true;
    }
    else
    {
        //sortByColumn(2,Qt::DescendingOrder);
        sortByFrequencyCustom(!sbf);
        sbf = false;
    }
    if(islist == true)
        emit this->showlistmode();
    else if(isicon == true)
        emit this->showiconmode();
    qDebug()<<tr("使用频次");
    modifyControlTable();
}

void ControlTableListWidget::sortByModiTime()
{

    //按修改时间排序
    if(!sbm)
    {
        sortByColumn(3,Qt::AscendingOrder);
        sbm = true;
    }
    else
    {
        sortByColumn(3,Qt::DescendingOrder);
        sbm = false;
    }
    if(islist == true)
        emit this->showlistmode();
    else if(isicon == true)
        emit this->showiconmode();
    qDebug()<<tr("修改时间");
    modifyControlTable();
}


void ControlTableListWidget::newRealTimeCurve()
{
    qDebug()<<tr("新建实时曲线");
    PreferenceDialog * argselet = new PreferenceDialog(rtc_ctl,"",false,this);
    argselet->exec();
    delete argselet;
}

void ControlTableListWidget::newHistoryCurve()
{
    qDebug()<<tr("新建历史曲线");
    PreferenceDialog * argselet = new PreferenceDialog(hsc_ctl,"",false,this);
    argselet->exec();
    delete argselet;
}

void ControlTableListWidget::newParameterTable()
{
    qDebug()<<tr("新建参数表");
    PreferenceDialog * argselet = new PreferenceDialog(pmt_ctl,"",false,this);
    argselet->exec();
    delete argselet;

}

void ControlTableListWidget::newHistoryDataForm()
{
    qDebug()<<tr("新建历史数据");
}

void ControlTableListWidget::newThermometer()
{
    qDebug()<<tr("新建温度计");
    PreferenceDialog * argselet = new PreferenceDialog(tmt_ctl,"",false,this);
    argselet->exec();
    delete argselet;
}

void ControlTableListWidget::newInstrumentPanel()
{
    qDebug()<<tr("新建仪表盘");
    PreferenceDialog * argselet = new PreferenceDialog(isp_ctl,"",false,this);
    argselet->exec();
    delete argselet;

}

void ControlTableListWidget::newBarchart()
{
    qDebug()<<tr("新建条形图");

    PreferenceDialog * argselet = new PreferenceDialog(bct_ctl,"",false,this);
    argselet->exec();
    delete argselet;
}

void ControlTableListWidget::createRightMenu(int * curItem)//实现右键菜单创建
{
    if(curItem != NULL)
        {
            QMenu * viewright_menu = new QMenu();

            viewright_menu->addAction(previewcontrol_action);
           // viewright_menu->addAction(newcontrol_action);
            viewright_menu->addAction(editcontrol_action);
            viewright_menu->addAction(deletecontrol_action);


            QMenu * newcontrol_menu = new QMenu(tr("新建"),viewright_menu);
            newcontrol_menu->addAction(realtimecurve_action);
            //newcontrol_menu->addAction(historycurve_action);
            newcontrol_menu->addAction(parametertable_action);
           // newcontrol_menu->addAction(historydataform_action);
            newcontrol_menu->addAction(thermometer_action);
            newcontrol_menu->addAction(instrumentpanel_action);
            newcontrol_menu->addAction(barchart_action);
            viewright_menu->addMenu(newcontrol_menu);



            QMenu * viewmode_menu = new QMenu(tr("查看"),viewright_menu);
            viewmode_menu->addAction(listmode_action);
            viewmode_menu->addAction(iconmode_action);
            viewmode_menu->addAction(detailinfolist_action);
            viewright_menu->addMenu(viewmode_menu);

            QMenu * iconpermutation_menu = new QMenu(tr("排列"),viewright_menu);
            iconpermutation_menu->addAction(sortbyname_aciton);
            iconpermutation_menu->addAction(sortbytype_action);
            iconpermutation_menu->addAction(sortbyfrequency_action);
            iconpermutation_menu->addAction(sortbymoditime_action);
            viewright_menu->addMenu(iconpermutation_menu);

            viewright_menu->exec(QCursor::pos());
            delete newcontrol_menu;
            delete iconpermutation_menu;
            delete viewmode_menu;
            delete viewright_menu;
        }
        else
        {
            QMenu * viewright_menu = new QMenu();

            QMenu * newcontrol_menu = new QMenu(tr("新建"),viewright_menu);
            newcontrol_menu->addAction(realtimecurve_action);
           // newcontrol_menu->addAction(historycurve_action);
            newcontrol_menu->addAction(parametertable_action);
           // newcontrol_menu->addAction(historydataform_action);
            newcontrol_menu->addAction(thermometer_action);
            newcontrol_menu->addAction(instrumentpanel_action);
            newcontrol_menu->addAction(barchart_action);
            viewright_menu->addMenu(newcontrol_menu);

            QMenu * viewmode_menu = new QMenu(tr("查看"),viewright_menu);
            viewmode_menu->addAction(listmode_action);
            viewmode_menu->addAction(iconmode_action);
            viewmode_menu->addAction(detailinfolist_action);
            viewright_menu->addMenu(viewmode_menu);

            QMenu * iconpermutation_menu = new QMenu(tr("排列"),viewright_menu);
            iconpermutation_menu->addAction(sortbyname_aciton);
            iconpermutation_menu->addAction(sortbytype_action);
            iconpermutation_menu->addAction(sortbyfrequency_action);
            iconpermutation_menu->addAction(sortbymoditime_action);
            viewright_menu->addMenu(iconpermutation_menu);
            viewright_menu->exec(QCursor::pos());
            delete newcontrol_menu;
            delete iconpermutation_menu;
            delete viewmode_menu;
            delete viewright_menu;

        }

}
void ControlTableListWidget::showRightMenu( const QPoint & pos)
{

    //显示右键菜单
    qDebug()<<tr("视图菜单")<<pos.x()<<" "<<pos.y();
    QTableWidgetItem *curItem = this->itemAt(pos);
    if(curItem != NULL)
    {
        curindex = currentRow();
        controltype =  item(curindex,0)->data(Qt::UserRole).toInt();
    }
    this->createRightMenu((int *)curItem);
}
void ControlTableListWidget::getControls()
{
    QDir rootdir("controls//");
    rootdir.setFilter(rootdir.filter()|QDir::NoDotAndDotDot);
    QStringList strings;
    strings<<"*";

    list = rootdir.entryInfoList(strings);
    qDebug()<<"listcount"<<list.count();

}

/*void ControlTableListWidget::hideTableList()
{
    this->hide();
    //isicon = true;
    //islist = false;
    istablelist = false;
}*/



void ControlTableListWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startpos = event->pos();
    QTableWidget::mousePressEvent(event);
}

void ControlTableListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startpos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            performDrag();
    }
    QTableWidget::mouseMoveEvent(event);
}

void ControlTableListWidget::performDrag()
{
    QTableWidgetItem *preitem = this->itemAt(startpos);
    if (preitem) {
        QTableWidgetItem *item = this->item(preitem->row(),0);
        QMimeData *mimeData = new QMimeData;
       // QString controltype = QString::number((item->data(Qt::UserRole)).toInt());
        mimeData->setText(item->text());

        QDrag drag(this);
        drag.setMimeData(mimeData);
        int type = item->data(Qt::UserRole).toInt();
        QString pixmapstr = "images/";
        switch(type)
        {
        case rtc_ctl:
        {
            pixmapstr.append("rtc_3");
        }
            break;
        case pmt_ctl:
        {
            pixmapstr.append("pmt_3");
        }
            break;
        case tmt_ctl:
        {
            pixmapstr.append("tmt_3");
        }
            break;
        case isp_ctl:
        {
            pixmapstr.append("isp_3");
        }
            break;
        case bct_ctl:
        {
            pixmapstr.append("bct_3");
        }
            break;
        }
        pixmapstr.append(".png");
        drag.setPixmap(QPixmap(pixmapstr));
        if (drag.exec(Qt::MoveAction) == Qt::MoveAction)
            ;
    }
}

void ControlTableListWidget::modifyControlTable()
{
    QFile controlfile("controltables.dat");
    if (!controlfile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("警告"),tr("文件打开失败！"),tr("确定"));
        return;
    }
    QTextStream in(&controlfile);
    controlfile.resize(0);
    controlfile.seek(0);
    for(int i = 0; i < this->rowCount(); i++)
    {
        in<<item(i,0)->text()<<"*"<<item(i,2)->text()<<"*"<<item(i,3)->text()<<"\n";
    }
    controlfile.close();
}


void ControlTableListWidget::sortByFrequencyCustom(bool ascend)
{
    QList<SortItem> list;
    for(int i = 0; i < rowCount(); i++)
    {
        SortItem newitem;
        newitem.row = i;
        newitem.frequecy = item(i,2)->text().toInt();
        int j = 0;
        if(ascend)
            for(j = list.count() - 1; j >=0 ; j--)
            {
                if(newitem.frequecy >= list.at(j).frequecy) break;
            }
        else
            for(j = list.count() - 1; j >=0 ; j--)
            {
                if(newitem.frequecy <= list.at(j).frequecy) break;
            }
        list.insert(j + 1,newitem);
    }
    QTableWidgetItem * tempitem;
    int temprowcount = rowCount();
    for(int i = 0; i < temprowcount; i++)
    {
        this->insertRow(temprowcount + i);
        tempitem = new QTableWidgetItem(item(list.at(i).row,0)->text());
        tempitem->setIcon(item(list.at(i).row,0)->icon());
        tempitem->setData(Qt::UserRole,item(list.at(i).row,0)->data(Qt::UserRole));
        tempitem->setToolTip(item(list.at(i).row,0)->toolTip());
        setItem(temprowcount + i,0,tempitem);
        tempitem = new QTableWidgetItem(item(list.at(i).row,1)->text());
        setItem(temprowcount + i,1,tempitem);
        tempitem = new QTableWidgetItem(item(list.at(i).row,2)->text());
        tempitem->setTextAlignment(Qt::AlignCenter);
        setItem(temprowcount + i,2,tempitem);
        tempitem = new QTableWidgetItem(item(list.at(i).row,3)->text());
        tempitem->setTextAlignment(Qt::AlignCenter);
        setItem(temprowcount + i,3,tempitem);
    }
    for(int i = 0; i < temprowcount; i++)
        removeRow(0);
    list.clear();
}

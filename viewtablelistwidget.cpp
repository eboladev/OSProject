#include <QtGui/QHeaderView>
#include <QtCore/QDebug>
#include <QtGui/QListWidget>
#include <QtGui/QTableWidgetItem>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QDateTime>
#include <QMessageBox>
#include <QMenu>
#include <iterator>
#include "viewtablelistwidget.h"
#include "plotter.h"
#include "plotsettings.h"
#include "mainwindow.h"
#include "preferencedialog.h"
#include "sendviewfiles.h"
#include "addviewtodialog.h"
#include "struct.h"

ViewTableListWidget::ViewTableListWidget(QWidget *parent) :
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
    curindex  = -1;
    viewname = "";
   // getViews();
    createTableList();
    createRightMenuActions();
   // createRightMenu();
    this->setFocusPolicy(Qt::NoFocus);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),SLOT(showRightMenu(QPoint)));
    connect(this,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(defaultAction(int,int)));
    this->setStyleSheet("QTableWidget{background-color:#FFFFE0;}");
}
void ViewTableListWidget::createTableList()
{

    QStringList filenameandsuffixs;
    QStringList usedfrequecys;
    QStringList accesstimes;

    QFile viewfile("viewtables.dat");
    if (!viewfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream in(&viewfile);
    while(!in.atEnd())
    {
        QString str = in.readLine();
        QStringList temp = str.split("*");
        filenameandsuffixs.append(temp.at(0));
        usedfrequecys.append(temp.at(1));
        accesstimes.append(temp.at(2));
    }
    viewfile.close();


   qDebug()<<filenameandsuffixs;
   qDebug()<<usedfrequecys;
   qDebug()<<accesstimes;

   /* this->setRowCount(list.length());
    this->setColumnCount(columnsize);
    int temprow = 0;
    for(int num = 0;num < 1 ; num++)
    {
        QFileInfoList::iterator i = list.begin();
        QFileInfo tempinfo;

        while(i != list.end())
        {
            tempinfo = *i;
            this->setItem(temprow,0,new QTableWidgetItem(QIcon("images/historicalcurve.jpg"),tempinfo.fileName()));
            this->setItem(temprow,1,new QTableWidgetItem(tempinfo.suffix()));
            this->setItem(temprow,2,new QTableWidgetItem("0"));
            this->setItem(temprow,3,new QTableWidgetItem(tempinfo.lastModified().toString("yyyy-MM-dd hh:mm")));
            i++;
            temprow++;
        }
    }*/

    this->setRowCount(filenameandsuffixs.count());
    this->setColumnCount(columnsize);
    for(int i = 0; i < filenameandsuffixs.count(); i++)
    {
        QTableWidgetItem * item = new QTableWidgetItem(QIcon("images/historicalcurve.jpg"),filenameandsuffixs.at(i));
        item->setToolTip(item->text());
        this->setItem(i,0,item);
        QString tempstr = filenameandsuffixs.at(i);
        item = new QTableWidgetItem(tempstr.split(".").last());
        this->setItem(i,1,item);
        item = new QTableWidgetItem(usedfrequecys.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        this->setItem(i,2,item);
        item = new QTableWidgetItem(accesstimes.at(i));
        item->setTextAlignment(Qt::AlignCenter);
        this->setItem(i,3,new QTableWidgetItem(accesstimes.at(i)));
    }



    horizentitle = new QStringList;
    horizentitle->append(tr("����"));
    horizentitle->append(tr("����"));
    horizentitle->append(tr("����"));
    horizentitle->append(tr("ʱ��"));
    this->verticalHeader()->setVisible(false);


    this->setHorizontalHeaderLabels(*horizentitle);//���ñ�ͷ����
    this->horizontalHeader()->setStretchLastSection(true);//����������
    this->horizontalHeader()->setHighlightSections(false);

  //this->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    this->verticalHeader()->setDefaultSectionSize(20);//�����о�
  //this->horizontalHeader()->resizeSection(0,150);
    this->horizontalHeader()->setFixedHeight(20);
  //this->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    this->setFrameShape(QFrame::NoFrame);//�����ޱ߿�
    this->setShowGrid(false);//��ʾ�ޱ��
    this->setSelectionMode(QAbstractItemView::SingleSelection);//�ɶ�ѡCtrl��Shift��  Ctrl+A������
    this->setSelectionBehavior(QAbstractItemView::SelectRows);//���ð���ѡ��
    //this->setSelectionMode(QAbstractItemView::SingleSelection);//����Ϊ���ɵ���ѡ��
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);//���ò��ɱ༭
    this->setIconSize(QSize(30,18));
    this->setColumnHidden(1,true);
    this->setStyleSheet("selection-background-color:lightblue;");

}

void ViewTableListWidget::createRightMenuActions()
{
    //�����Ҽ��˵�
     lookupView_action = new QAction(tr("�鿴"),this);
     newview_action = new QAction(tr("�½�"),this);
     editview_aciton = new QAction(tr("�༭"),this);
     sendview_action = new QAction(tr("����"),this);
     deleteview_action = new QAction(tr("ɾ��"),this);
     addto_action = new QAction(tr("��ӵ�..."),this);

     detailinfolist_action = new QAction(tr("��ϸ��Ϣ"),this);
     listmode_action = new QAction(tr("�б�"),this);
     iconmode_action = new QAction(tr("ͼ��"),this);
     sortbyname_aciton = new QAction(tr("����"),this);
     sortbytype_action = new QAction(tr("����"),this);
     sortbyfrequency_action = new QAction(tr("ʹ�ô���"),this);
     sortbymoditime_action = new QAction(tr("����ʱ��"),this);

     connect(lookupView_action,SIGNAL(triggered()),this,SLOT(lookupView()));
     connect(newview_action,SIGNAL(triggered()),this,SLOT(newView()));
     connect(editview_aciton,SIGNAL(triggered()),this,SLOT(editView()));
     connect(sendview_action,SIGNAL(triggered()),this,SLOT(sendView()));
     connect(deleteview_action,SIGNAL(triggered()),this,SLOT(deleteViewRequest()));
     connect(addto_action,SIGNAL(triggered()),this,SLOT(addViewTo()));

     connect(detailinfolist_action,SIGNAL(triggered()),this,SLOT(detailInfoPermutation()));
     connect(listmode_action,SIGNAL(triggered()),this,SLOT(listPermutation()));
     connect(iconmode_action,SIGNAL(triggered()),this,SLOT(iconPermutation()));
     connect(sortbyname_aciton,SIGNAL(triggered()),this,SLOT(sortByName()));
     connect(sortbytype_action,SIGNAL(triggered()),this,SLOT(sortByType()));
     connect(sortbyfrequency_action,SIGNAL(triggered()),this,SLOT(sortByFrequency()));
     connect(sortbymoditime_action,SIGNAL(triggered()),this,SLOT(sortByModiTime()));
}

void ViewTableListWidget::defaultAction(int row, int col)
{
    if(row >= 0 && col >= 0)
    {
        curindex = row;
    }
    lookupView();
    qDebug()<<"defaultactionchenggong"<<curindex;
}

void ViewTableListWidget::lookupView()
{
    //�鿴��ͼ
    qDebug()<<tr("�鿴��ͼ");
    emit open(curindex);

}

void ViewTableListWidget::newView()
{
     //�½���ͼ
    qDebug()<<tr("�½���ͼ");
    emit newViewSignal(curindex);//ע��˴������Ĵ��ڵ�ͨ��


}

void ViewTableListWidget::editView()
{
    //�½���ͼ
    qDebug()<<tr("�½���ͼ");
    emit editViewSignal(curindex);

}

void ViewTableListWidget::sendView()
{
    //������ͼ
    qDebug()<<tr("������ͼ");
    emit send(curindex);
    SendViewFiles svf(viewfilenames);

    svf.exec();
}

void ViewTableListWidget::deleteViewRequest()
{
    //ɾ����ͼ
    qDebug()<<tr("ɾ����ͼ");
     emit del(curindex);


}

void ViewTableListWidget::deleteView(bool flag)
{
    int result = QMessageBox::warning(0,tr("����"),tr("�Ƿ�ɾ������ͼ��"),tr("��"),tr("��"));
    if(result == 1)
         return;
    if(!flag)
    {
        QMessageBox::warning(0,tr("����"),tr("��ͼʹ���У��޷�ɾ����"),tr("ȷ��"));
        return;
    }
    QString viewfilename = item(curindex,0)->text();
    if(viewfilename.isEmpty())
    {
        QMessageBox::warning(0,tr("����"),tr("��ͼΪ�գ�"),tr("ȷ��"));
        return;
    }
    //�ж���û���ڷ���������汻ʹ��
    QFile viewfile("viewaddtotree.dat");
    if(viewfile.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream ts(&viewfile);
        QString viewsstr = ts.readLine();
        if(viewsstr.contains(viewfilename))
        {
            QMessageBox::warning(0,tr("����"),tr("��ͼ�Ѿ��ڷ��������ʹ�ã��޷�ɾ����"),tr("ȷ��"));
            viewfile.close();
            return;
        }
    }
    viewfile.close();
    QString path = "view/";
    QFile file(path+viewfilename);
    if(!file.exists())//�Ƿ�Ҫ�жϣ�
    {
        QMessageBox::critical(0,tr("����"),tr("��Ӧ�ļ������ڣ���ɾ����Ч�ؼ���"),tr("ȷ��"));
        this->removeRow(curindex);//�Ƿ�
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream in(&file);
    QString controlstr;
    int count = in.readLine().toInt();

    while(count > 0)
    {
       controlstr = in.readLine();
       QStringList controlinfo =  controlstr.split("*");
       unlinkControlToView(controlinfo.first());
        --count;
    }
    file.remove();
    this->removeRow(curindex);
    modifyViewTable();
    if(islist) emit showlistmode();
    else if(isicon) emit showiconmode();

}

void ViewTableListWidget::addViewTo()
{
     qDebug()<<tr("�����ͼ��������");
     QString viewfliename = this->item(curindex,0)->text();
     AddViewToDialog avtd(viewfliename,this);
     if(avtd.exec() == avtd.Accepted)
     {
         qDebug()<<"����";
         emit addViewToSignal(avtd.tarbuildingname,avtd.tarfloorname,avtd.tarroomname,viewfliename);
     }
}

void ViewTableListWidget::detailInfoPermutation()
{
     //��ϸ��Ϣ�б�
    if(istablelist == false)
    {
        istablelist = true;
        islist = false;
        isicon = false;
        this->show();
        emit hideList();
        //list�������ʵ��
    }
    qDebug()<<tr("��ϸ��Ϣ");
}

void ViewTableListWidget::listPermutation()
{
     //�б�
    qDebug()<<tr("�б�");
    if(islist == false)
    {
        islist = true;
        isicon = false;
        istablelist = false;
        emit this->showlistmode();
    }
}

void ViewTableListWidget::iconPermutation()
{
    //ͼ��
    qDebug()<<tr("ͼ��");
    if(isicon == false)
    {
        isicon = true;
        islist = false;
        istablelist = false;
        emit this->showiconmode();
    }

}

void ViewTableListWidget::sortByName()
{
    //��������
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
    qDebug()<<tr("����");
    modifyViewTable();
}

void ViewTableListWidget::sortByType()
{
    //����������
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
    qDebug()<<tr("����");
    modifyViewTable();
}

void ViewTableListWidget::sortByFrequency()
{
    //��ʹ�ô�������
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
    qDebug()<<tr("ʹ�ô���");
    modifyViewTable();
}

void ViewTableListWidget::sortByModiTime()
{

    //���޸�ʱ������
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
    qDebug()<<tr("�޸�ʱ��");
    modifyViewTable();
}


void ViewTableListWidget::createRightMenu(int * curItem)//ʵ���Ҽ��˵�����
{
    if(curItem != NULL)
        {
            QMenu * viewright_menu = new QMenu();

            viewright_menu->addAction(lookupView_action);
            viewright_menu->addAction(newview_action);
            viewright_menu->addAction(editview_aciton);
           // viewright_menu->addAction(sendview_action);
            viewright_menu->addAction(deleteview_action);
            viewright_menu->addAction(addto_action);


            QMenu * viewmode_menu = new QMenu(tr("�鿴"),viewright_menu);
            viewmode_menu->addAction(listmode_action);
            viewmode_menu->addAction(iconmode_action);
            viewmode_menu->addAction(detailinfolist_action);
            viewright_menu->addMenu(viewmode_menu);

            QMenu * iconpermutation_menu = new QMenu(tr("����"),viewright_menu);
            iconpermutation_menu->addAction(sortbyname_aciton);
            iconpermutation_menu->addAction(sortbytype_action);
            iconpermutation_menu->addAction(sortbyfrequency_action);
            iconpermutation_menu->addAction(sortbymoditime_action);
            viewright_menu->addMenu(iconpermutation_menu);

            viewright_menu->exec(QCursor::pos());
            delete iconpermutation_menu;
            delete viewmode_menu;
            delete viewright_menu;
        }
        else
        {
            QMenu * viewright_menu = new QMenu();

            viewright_menu->addAction(newview_action);

            QMenu * viewmode_menu = new QMenu(tr("�鿴"),viewright_menu);
            viewmode_menu->addAction(listmode_action);
            viewmode_menu->addAction(iconmode_action);
            viewmode_menu->addAction(detailinfolist_action);
            viewright_menu->addMenu(viewmode_menu);

            QMenu * iconpermutation_menu = new QMenu(tr("����"),viewright_menu);
            iconpermutation_menu->addAction(sortbyname_aciton);
            iconpermutation_menu->addAction(sortbytype_action);
            iconpermutation_menu->addAction(sortbyfrequency_action);
            iconpermutation_menu->addAction(sortbymoditime_action);
            viewright_menu->addMenu(iconpermutation_menu);
            viewright_menu->exec(QCursor::pos());
            //�ͷ��ڴ���Ч
            delete iconpermutation_menu;
            delete viewmode_menu;
            delete viewright_menu;

        }

}
void ViewTableListWidget::showRightMenu( const QPoint & pos)
{

    //��ʾ�Ҽ��˵�
    qDebug()<<tr("��ͼ�˵�")<<pos.x()<<" "<<pos.y();

    QTableWidgetItem *curItem = this->itemAt(pos);



    if(curItem != NULL)
    {
        curindex = currentRow();
        viewfilenames.clear();
        QList<QTableWidgetSelectionRange> rangelist = this->selectedRanges();
        QList<QTableWidgetSelectionRange>::iterator iter = rangelist.begin();
        while(iter != rangelist.end())
        {
            QTableWidgetSelectionRange range = *iter;
            for(int i =range.topRow(); i<=range.bottomRow(); i++ )
                viewfilenames<<item(i,0)->text();
            ++iter;
        }
    }
    qDebug()<<viewfilenames;
    this->createRightMenu((int *)curItem);
}
void ViewTableListWidget::getViews()
{
    QDir rootdir("view//");
    rootdir.setFilter(rootdir.filter()|QDir::NoDotAndDotDot);
    QStringList strings;
    strings<<"*";
    list = rootdir.entryInfoList(strings);
    qDebug()<<list.length();
    //QFileInfoList list = rootdir.entryInfoList(strings);
   // qDebug()<<*list.begin();

    QFileInfoList::iterator i = list.begin();
    QFileInfo tempinfo;
    while(i != list.end())
    {
        tempinfo = *i;
        if(tempinfo.completeBaseName()==QString(tr("��C������")))
        {
            //qDebug()<<tr("���");
         //   rename("view//asdsagashg","view//newfilename");
           // tempinfo.setFile("haha");
        }
      //  qDebug()<<tempinfo.completeBaseName();
        i++;
    }
   /* list.clear();
    qDebug()<<list.length();*/
}

/*void ViewTableListWidget::hideTableList()
{
    this->hide();
    //isicon = true;
    //islist = false;
    istablelist = false;
}*/

void ViewTableListWidget::addViewName(QString str)
{
    qDebug()<<tr("�źŷ���ɹ�")<<str;
    QDir rootdir("view//");
    rootdir.setFilter(rootdir.filter()|QDir::NoDotAndDotDot);
    QStringList strings;
    strings<<str;
     QFileInfo tempinfo = *(rootdir.entryInfoList(strings).begin());
     qDebug()<<tempinfo.absolutePath();
    this->insertRow(rowCount());
    int temprow = rowCount()-1;
    QTableWidgetItem * item = new QTableWidgetItem(QIcon("images/historicalcurve.jpg"),tempinfo.fileName());
    item->setToolTip(item->text());
    this->setItem(temprow,0,item);
    this->setItem(temprow,1,new QTableWidgetItem(tempinfo.suffix()));
    item = new QTableWidgetItem("0");
    item->setTextAlignment(Qt::AlignCenter);
    this->setItem(temprow,2,item);
    item = new QTableWidgetItem(tempinfo.lastModified().toString("yyyy-MM-dd hh:mm"));
    item->setTextAlignment(Qt::AlignCenter);
    this->setItem(temprow,3,item);
    modifyViewTable();
}

void ViewTableListWidget::unlinkControlToView(QString controlname)
{
    qDebug()<<controlname;
    QString path = "controls/";
    QFile file(path+controlname);
    if(!file.exists())//�Ƿ�Ҫ�жϣ�
    {
        QMessageBox::critical(0,tr("����"),tr("�����ؼ��ļ������ڣ��������"),tr("ȷ��"));
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�����ؼ���ʧ�ܴ�ʧ�ܣ�"),tr("ȷ��"));
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
    /*if(inout.atEnd())
    {
        filecontents<<ui->filename_lineedit->text()+".view";
    }
    else
    {
        QString str = inout.readLine();
        str+="*"+ui->filename_lineedit->text()+".view";
        filecontents<<str;
    }*/
    QString viewsname = in.readLine();
    file.close();
    QString newviewsnamestr;
    if(!viewsname.isNull())
    {
        QStringList viewnamelist = viewsname.split("*");
        QStringList::iterator i = viewnamelist.begin();
        while(i != viewnamelist.end())
        {
            qDebug()<<(*i);
            if((*i) !=  item(curindex,0)->text())
            {
                newviewsnamestr += (*i);
                newviewsnamestr += "*";
            }
            ++i;
        }
    }
    if(!newviewsnamestr.isEmpty())
    {

        newviewsnamestr = newviewsnamestr.left(newviewsnamestr.size()-1);
        filecontents<<newviewsnamestr;
    }
    //inout.seek(0);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    QStringList::iterator i = filecontents.begin();
    while(i != filecontents.end())
    {
        out<<(*i)<<"\n";
        ++i;
    }
    file.close();
}

void ViewTableListWidget::modifyViewTable()
{
    QFile viewfile("viewtables.dat");
    if (!viewfile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream in(&viewfile);
    viewfile.resize(0);
    viewfile.seek(0);
    for(int i = 0; i < this->rowCount(); i++)
    {
        in<<item(i,0)->text()<<"*"<<item(i,2)->text()<<"*"<<item(i,3)->text()<<"\n";
    }
    viewfile.close();
}

void ViewTableListWidget::increaseUseFrequecy(QString name)
{
    qDebug()<<"����ʹ�ô���";
    int i = 0;
    for(i = 0; i < this->rowCount(); i++)
    {
        if(name == this->item(i,0)->text()) break;
    }
    if( i < this->rowCount())
    {
        item(i,2)->setText(QString::number(item(i,2)->text().toLongLong()+1));
    }
    modifyViewTable();
}

void ViewTableListWidget::modifyAcessTime(QString name)
{
    qDebug()<<"����ʹ�ô���";
    int i = 0;
    for(i = 0; i < this->rowCount(); i++)
    {
        if(name == this->item(i,0)->text()) break;
    }
    if( i < this->rowCount())
    {
        item(i,3)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"));
    }
    modifyViewTable();
}


void ViewTableListWidget::sortByFrequencyCustom(bool ascend)
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








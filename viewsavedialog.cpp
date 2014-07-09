#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QtAlgorithms>
#include <QFileInfoList>
#include "viewsavedialog.h"
#include "ui_viewsavedialog.h"

ViewSaveDialog::ViewSaveDialog(bool flag,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewSaveDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    this->setFixedWidth(280);
    this->setFixedHeight(270);
    ui->filename_listwidget->setFocusPolicy(Qt::NoFocus);
    //isnew = flag;
    issave = true;
   /* if(!isnew)
    {
        objectnames.clear();
        controllist.clear();
        readViewFile();

    }*/
    getViewsName();
    connect(ui->confirm_pushbutton,SIGNAL(clicked()),this,SLOT(onConfirmPushButton()));
    connect(ui->cancel_pushbutton,SIGNAL(clicked()),this,SLOT(onCancelPushButton()));
    connect(ui->filename_lineedit,SIGNAL(textChanged(QString)),this,SLOT(fileNameChanged(QString)));
    fileNameChanged("");
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
    setWindowTitle("��ͼ����");
}

ViewSaveDialog::~ViewSaveDialog()
{
    delete ui;
}


void ViewSaveDialog::onConfirmPushButton()
{

    bool ischanged = fileIsChanged();
    QString path = "view/";
    QString filename = ui->filename_lineedit->text();
    if(filename.isEmpty())
    {
        QMessageBox::warning(0,tr("����"),tr("δ�����ļ�����"),tr("ȷ��"));
        return;
    }
    QString suffix = ".view";
    //�����ļ����Ϸ�����֤
    QFile file(path+filename+suffix);
    if(ui->filename_lineedit->isEnabled()&&file.exists())
    {
        //ע��˴�
        QMessageBox::warning(0,tr("����"),tr("���ļ����Ѵ���,������ѡ���ļ�����"),tr("ȷ��"));
        return;
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("����"),tr("�ļ�д��ʱ�ļ���ʧ�ܣ�"),tr("ȷ��"));
        return;
    }
    QTextStream out(&file);
    out<<controllist.size()<<"\n";
    QObjectList::iterator controliter = controllist.begin();

    while(controliter != controllist.end())
    {
        QWidget * widget = ((QWidget *)(*controliter));//�˴����ö�ÿ����ͼ�������Ŀؼ����ݽ��ж�д
        out<<widget->windowTitle()<<"*"<<widget->objectName()<<"*"<<widget->x()<<"*"<<widget->y()<<"*"<<widget->width()<<"*"<<widget->height()<<";"<<"\n";
        linkControlToView(widget->windowTitle());
        ++controliter;
    }
    if(ui->filename_lineedit->isEnabled())
        emit saveview(filename+suffix);
    emit tabName(filename+suffix);
    qDebug()<<"ȷ�ϱ�����ͼ";
    file.flush();
    file.close();
    this->accept();
}
void ViewSaveDialog::onCancelPushButton()
{
    this->accept();
}

void ViewSaveDialog::fileNameChanged(QString filename)
{
   if(filename.contains('\\')||filename.contains('\/')||filename.contains(':')||filename.contains('?')||filename.contains('\"')
           ||filename.contains('*')||filename.contains(';')||filename.contains('>')||filename.contains('<')||filename.contains('|')||filename.contains('.'))
   {
       filename.remove('\\');
       filename.remove('\/');
       filename.remove(':');
       filename.remove('?');
       filename.remove('\"');
       filename.remove('*');
       filename.remove(';');
       filename.remove('>');
       filename.remove('<');
       filename.remove('|');
       filename.remove('.');
       ui->filename_lineedit->setText(filename);
       QMessageBox::warning(0,tr("����"),tr("��ʹ�ó� \\ \/ : ? \" * ; . > < | ֮��������ַ���"),tr("ȷ��"));
       return ;
   }
   if(ui->filename_listwidget->count() != 0)
       ui->filename_listwidget->clear();
   QFileInfoList::iterator i = list.begin();
   QFileInfo tempinfo;
   while(i != list.end())
   {
       tempinfo = *i;
       QListWidgetItem * item = new QListWidgetItem(tempinfo.fileName(),ui->filename_listwidget);
       item->setHidden(true);
       ui->filename_listwidget->addItem(item);
       i++;
   }
   QList<QListWidgetItem *> findednameslist = ui->filename_listwidget->findItems(filename,Qt::MatchStartsWith|Qt::MatchCaseSensitive);
   QList<QListWidgetItem *>::iterator iter = findednameslist.begin();
   while(iter != findednameslist.end())
   {
       (*iter)->setHidden(false);
       iter++;
   }

}

void ViewSaveDialog::getViewsName()
{

    QDir rootdir("view/");
    rootdir.setFilter(rootdir.filter()|QDir::NoDotAndDotDot);
    QStringList strings;
    strings<<"*";
    list = rootdir.entryInfoList(strings);
    qDebug()<<"listsize"<<list.size();
    fileNameChanged(ui->filename_lineedit->text());
}

void ViewSaveDialog::setFileViewState(bool isnew)
{
    this->isnew = isnew;
    if(isnew)
    {
     //  ui->filename_lineedit->setText();//���Դ��ݴ��ڵ�title��Ϊtext����
    }

}

void ViewSaveDialog::setFileSaveAction(bool issave)
{
    this->issave = issave;
    if(issave)
    {
        ui->filename_groupbox->setTitle("����Ϊ(.view)");
    }
    else
    {
        ui->filename_groupbox->setTitle("���Ϊ(.view)");
    }
    if(issave)
    {
        if(ui->filename_lineedit->text().isEmpty())
        {
            ui->filename_lineedit->setEnabled(true);
        }
        else
        {
            ui->filename_lineedit->setEnabled(false);
            list.clear();
            getViewsName();
            fileNameChanged(ui->filename_lineedit->text());
        }
    }
    else
    {
        ui->filename_lineedit->setEnabled(true);
        list.clear();
        getViewsName();
        fileNameChanged(ui->filename_lineedit->text());
    }
}

bool ViewSaveDialog::fileIsChanged()
{
   /* QObjectList  childrenlist = ((TabInnerWidget *)parentWidget())->children();
    QObjectList newcontrollist;
    QList<QString> newobjectnames;
    QObjectList::iterator iter = childrenlist.begin();
    while(iter != childrenlist.end())
    {
        qDebug()<<"new children:"<<((*iter)->objectName());
        QString objectname = (*iter)->objectName();

        if(objectname.left(1) == "v")
        {
            newcontrollist<<(*iter);
            newobjectnames<<objectname;
        }
        ++iter;
    }
    qSort(objectnames.begin(),objectnames.end());
    qSort(newobjectnames.begin(),newobjectnames.end());
    objectnames.clear();
    controllist.clear();
    objectnames = newobjectnames;
    controllist = newcontrollist;
    if(objectnames == newobjectnames)
    {
        return false;
    }
    else
    {
        return true;
    }*/
}

void ViewSaveDialog::readViewFile()
{
    //��ȡ��ͼ�ļ�
}

void ViewSaveDialog::linkControlToView(QString controlfilename)
{
     QString path = "controls/";
     QFile file(path+controlfilename);
     if(!file.exists())//�Ƿ�Ҫ�жϣ�
     {
         QMessageBox::critical(0,tr("����"),tr("�����ؼ��ļ������ڣ��������"),tr("ȷ��"));
         return;
     }
     if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
     {
         QMessageBox::warning(0,tr("����"),tr("�����ؼ���ʧ�ܴ�ʧ�ܣ�"),tr("ȷ��"));
         return;
     }

     QTextStream inout(&file);
     QStringList filecontents;
     int count = inout.readLine().toInt();
     filecontents<<QString::number(count);
     while(count > 0)
     {
         filecontents<<inout.readLine();
         --count;
     }
     if(inout.atEnd())
     {
         filecontents<<ui->filename_lineedit->text()+".view";
     }
     else
     {
         QString str = inout.readLine();
         str+="*"+ui->filename_lineedit->text()+".view";
         filecontents<<str;
     }
     inout.seek(0);
     QStringList::iterator i = filecontents.begin();
     while(i != filecontents.end())
     {
         inout<<(*i)<<"\n";
         ++i;
     }
     inout.flush();
     file.close();

}

void ViewSaveDialog::setSaveName(QString oldfilename)
{
    if(issave)
    {
        if(!oldfilename.isEmpty())
        {
            ui->filename_lineedit->setText(oldfilename);
            ui->filename_lineedit->setEnabled(false);
        }
        else
        {
            ui->filename_lineedit->setText("");
            ui->filename_lineedit->setEnabled(true);
        }
    }
    else
    {
        ui->filename_lineedit->setText("");
        ui->filename_lineedit->setEnabled(true);
    }
}

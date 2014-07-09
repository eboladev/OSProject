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
    setWindowTitle("视图保存");
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
        QMessageBox::warning(0,tr("警告"),tr("未输入文件名！"),tr("确定"));
        return;
    }
    QString suffix = ".view";
    //进行文件名合法性验证
    QFile file(path+filename+suffix);
    if(ui->filename_lineedit->isEnabled()&&file.exists())
    {
        //注意此处
        QMessageBox::warning(0,tr("警告"),tr("该文件名已存在,请重新选择文件名！"),tr("确定"));
        return;
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0,tr("警告"),tr("文件写入时文件打开失败！"),tr("确定"));
        return;
    }
    QTextStream out(&file);
    out<<controllist.size()<<"\n";
    QObjectList::iterator controliter = controllist.begin();

    while(controliter != controllist.end())
    {
        QWidget * widget = ((QWidget *)(*controliter));//此处还得对每个视图所关联的控件内容进行读写
        out<<widget->windowTitle()<<"*"<<widget->objectName()<<"*"<<widget->x()<<"*"<<widget->y()<<"*"<<widget->width()<<"*"<<widget->height()<<";"<<"\n";
        linkControlToView(widget->windowTitle());
        ++controliter;
    }
    if(ui->filename_lineedit->isEnabled())
        emit saveview(filename+suffix);
    emit tabName(filename+suffix);
    qDebug()<<"确认保存视图";
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
       QMessageBox::warning(0,tr("警告"),tr("请使用除 \\ \/ : ? \" * ; . > < | 之外的其他字符！"),tr("确定"));
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
     //  ui->filename_lineedit->setText();//可以传递窗口的title作为text内容
    }

}

void ViewSaveDialog::setFileSaveAction(bool issave)
{
    this->issave = issave;
    if(issave)
    {
        ui->filename_groupbox->setTitle("保存为(.view)");
    }
    else
    {
        ui->filename_groupbox->setTitle("另存为(.view)");
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
    //读取视图文件
}

void ViewSaveDialog::linkControlToView(QString controlfilename)
{
     QString path = "controls/";
     QFile file(path+controlfilename);
     if(!file.exists())//是否要判断？
     {
         QMessageBox::critical(0,tr("错误"),tr("关联控件文件不存在，程序出错！"),tr("确定"));
         return;
     }
     if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
     {
         QMessageBox::warning(0,tr("警告"),tr("关联控件打开失败打开失败！"),tr("确定"));
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

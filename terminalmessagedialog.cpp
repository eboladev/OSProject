#include <QMessageBox>
#include <QSqlDatabase>
#include <QtNetwork>
#include <QUdpSocket>
#include <QSqlQuery>
#include <QTime>
#include <QTimer>
#include "terminalmessagedialog.h"
#include "struct.h"
#include "ui_terminalmessagedialog.h"


/*
  Ŀǰ������UDP���ͣ����͹���û�м�ʱȷ�ϣ�ֻ����Ϣ���ͳ�ȥ��������֤�����Ƿ����ߣ�TCP����ע�͵����Ա���
  */
TerminalMessageDialog::TerminalMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TerminalMessageDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    initDialog();
    udpclient =  new QUdpSocket(this);
    udpclient->bind(QNetworkInterface::allAddresses().first(),45454);
    connect(udpclient,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));

    this->setWindowTitle("�ּ����Ϣ����");
    this->setWindowIcon(QIcon("images/terminalmessagedialog_icon.png"));
    setWindowFlags(Qt::Dialog|Qt::WindowTitleHint);
}

TerminalMessageDialog::~TerminalMessageDialog()
{
    delete ui;
}

void TerminalMessageDialog::initDialog()
{
    if(globaldb.open())
    {
        if(!dbisconnected)
        {
            dbisconnected = true;
            raao->setAppEnable(true);
        }
        QSqlQuery query(globaldb);
        query.prepare("SELECT name,IP FROM terminal");
        query.exec();
        while(query.next())
        {
            ui->targetmonitor_combobox->addItem(query.value(0).toString(),query.value(1));
        }
        query.clear();
        query.finish();
        //globaldb.close();
    }
    else
    {
        if(dbisconnected)
        {
            dbisconnected = false;
            raao->setAppEnable(false);
            QMessageBox::warning(0,"����","���ݿ�����ʧ�ܣ�","ȷ��");
        }
    }
    //��ȡ���ӻ�IP���õ���Ϣ
    connect(ui->addmonitor_toolbutton,SIGNAL(clicked()),this,SLOT(onAddMonitor()));
    connect(ui->removemonitor_toolbutton,SIGNAL(clicked()),this,SLOT(onRemoveMonitor()));
    connect(ui->sent_pushbutton,SIGNAL(clicked()),this,SLOT(onSendMessage()));
    connect(ui->editmessage_plaintextedit,SIGNAL(textChanged()),this,SLOT(onTextChanged()));
}

void TerminalMessageDialog::onAddMonitor()
{

    QString monitorname = ui->targetmonitor_combobox->currentText();
    if(monitorname.isEmpty()) return;
    QList<QListWidgetItem *> itemslist = ui->selectedmonitor_listwidget->findItems("",Qt::MatchContains);
    qDebug()<<itemslist;
    QList<QListWidgetItem *>::iterator i = itemslist.begin();
    bool flag = false;
    while(i != itemslist.end())
    {
        if((*i)->text() == monitorname)
        {
            flag = true;
            break;
        }
        i++;
    }
    if(!flag)
    {
        QListWidgetItem * listitem = new QListWidgetItem(ui->selectedmonitor_listwidget);
        listitem->setText(monitorname);
        listitem->setData(Qt::UserRole,ui->targetmonitor_combobox->itemData(ui->targetmonitor_combobox->currentIndex()).toString());
        ui->selectedmonitor_listwidget->addItem(listitem);
    }
    else
        QMessageBox::warning(0,tr("����"),tr("�ü��ӻ��Ѵ��ڣ�"),tr("ȷ��"));
}

void TerminalMessageDialog::onRemoveMonitor()
{
    int row = ui->selectedmonitor_listwidget->currentRow();
    if(row >= 0)
         delete ui->selectedmonitor_listwidget->takeItem(row);
}


/*void TerminalMessageDialog::startNextConnect()
{
    ++sentcount;
    if(tcpclient != NULL) delete tcpclient;
    if(ui->selectedmonitor_listwidget->count() > sentcount)
    {
        tcpclient = new QTcpSocket(this);
        tcpclient->setSocketDescriptor(0);
        connect(tcpclient,SIGNAL(connected()),this,SLOT(startTransfer()));
        connect(tcpclient,SIGNAL(readyRead()),this,SLOT(startNextTransfer()));
        connect(tcpclient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
        connect(tcpclient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
        itemid++;
        tcpclient->connectToHost(ui->selectedmonitor_listwidget->item(itemid)->data(Qt::UserRole).toString(),5555);
        //tcpclient->connectToHost("192.168.0.11",5555);
        qDebug()<<"startnextconnect";
    }
    else
    {
        ui->exit_pushbutton->setEnabled(true);
    }
}*/

void TerminalMessageDialog::onSendMessage()
{
    if(ui->selectedmonitor_listwidget->count() <= 0)
    {
        QMessageBox::warning(0,"����","ѡ����ӻ���","ȷ��");
        return;
    }
    if(ui->editmessage_plaintextedit->toPlainText().size() <= 0)
    {
        QMessageBox::warning(0,"����","������ϢΪ�գ�","ȷ��");
        return;
    }

    ipToMonitorid.clear();
    isSucceds.clear();
    /*for(int i = 0; i < ui->selectedmonitor_listwidget->count(); i++)
    {
        QTcpSocket *tcpclient =  new QTcpSocket(this);
        sockets.append(tcpclient);

        connect(tcpclient,SIGNAL(connected()),this,SLOT(sendMessage()));
        connect(tcpclient,SIGNAL(readyRead()),this,SLOT(receiveReply()));
        connect(tcpclient,SIGNAL(disconnected()),tcpclient,SLOT(deleteLater()));
        //connect(tcpclient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
        // connect(tcpserverconnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
        isSucceds.append(false);
        ipToMonitorid.insert(ui->selectedmonitor_listwidget->item(i)->data(Qt::UserRole).toString(),i);
        tcpclient->connectToHost(ui->selectedmonitor_listwidget->item(i)->data(Qt::UserRole).toString(),5556);
    }*/
    ui->sentmessage_plaintextedit->appendPlainText(QTime::currentTime().toString("hh:mm:ss"));
    ui->sentmessage_plaintextedit->appendPlainText(ui->editmessage_plaintextedit->toPlainText());

    QByteArray datagram;
    datagram.append(ui->editmessage_plaintextedit->toPlainText());

    for(int i = 0; i < ui->selectedmonitor_listwidget->count(); i++)
    {
        //sockets.append(udpclient);
        isSucceds.append(false);
        ipToMonitorid.insert(ui->selectedmonitor_listwidget->item(i)->data(Qt::UserRole).toString(),i);
        udpclient->writeDatagram(datagram.data(),datagram.size(),QHostAddress(ui->selectedmonitor_listwidget->item(i)->data(Qt::UserRole).toString()),45454);
    }
    ui->editmessage_plaintextedit->clear();


    //timer->start(5000);
}
void TerminalMessageDialog::sendMessage()
{
    qDebug()<<"������Ϣ";
    QTcpSocket * tcpclient = (qobject_cast<QTcpSocket *>(sender()));
    QByteArray data;
    data.append(ui->editmessage_plaintextedit->toPlainText());
    tcpclient->write(data);
}

void TerminalMessageDialog::onTextChanged()
{
    QString text = ui->editmessage_plaintextedit->toPlainText();
    QByteArray testdata;
    testdata.append(text);
    if(testdata.size() > 80)
    {
        QString str(testdata.left(80));
        ui->editmessage_plaintextedit->clear();
        ui->editmessage_plaintextedit->appendPlainText(str);
        QMessageBox::warning(0,"����","��Ϣ������","ȷ��");
    }
}

void TerminalMessageDialog::receiveReply()
{
    qDebug()<<"receivereply";
   QTcpSocket * tcpclient = (qobject_cast<QTcpSocket *>(sender()));
   QByteArray data =  tcpclient->readAll();
   QString str(data);
   qDebug()<<str;
   qDebug()<<str;
   isSucceds[ipToMonitorid[str]] = true;
   //tcpclient->disconnectFromHost();
}

void TerminalMessageDialog::onTimer()
{
    timer->stop();
    QString failmonitor;
    int faildecount = 0;
    for(int i = 0; i < ui->selectedmonitor_listwidget->count(); i++)
    {
        if(!isSucceds.at(i))
        {
           failmonitor.append(ui->selectedmonitor_listwidget->item(i)->text());
           failmonitor.append("; ");
           faildecount++;
        }
    }
    if(faildecount)
    {
        failmonitor.remove(failmonitor.size() - 1,1);
        failmonitor.append("��Ϣ����ʧ��");
        QMessageBox::warning(0,"����",failmonitor,"ȷ��");
    }

    for(int i = 0; i < ui->selectedmonitor_listwidget->count(); i++)
    {
       // sockets.at(i)->disconnectFromHost();
          sockets.at(i)->close();
    }

}


void TerminalMessageDialog::closeEvent(QCloseEvent * event)
{
    //�ж��Ƿ�ֱ���˳�
    QDialog::closeEvent(event);
}

void TerminalMessageDialog::displayError(QAbstractSocket::SocketError)//��ʾ����
{
     QTcpSocket * tcpclient = (qobject_cast<QTcpSocket *>(sender()));
     qDebug() <<"tcpclient->errorString();"<< tcpclient->errorString();
}

void TerminalMessageDialog::processPendingDatagram()
{
   // QUdpSocket * tempsocket = (qobject_cast<QUdpSocket *>(sender()));
    while(udpclient->hasPendingDatagrams())  //ӵ�еȴ������ݱ�
    {
        QByteArray datagram; //ӵ�ڴ�Ž��յ����ݱ�
        datagram.resize(udpclient->pendingDatagramSize());
        //��datagram�Ĵ�СΪ�ȴ���������ݱ��Ĵ�С���������ܽ��յ�����������
        udpclient->readDatagram(datagram.data(),datagram.size());
        //�������ݱ��������ŵ�datagram��
        qDebug()<<"processPendingDatagram"<<datagram;
        //�����ݱ�������ʾ����
    }
    qDebug()<<"processPendingDatagram";
   // delete tempsocket;
}

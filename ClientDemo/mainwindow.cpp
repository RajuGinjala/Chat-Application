#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket= new QTcpSocket();

    socket->connectToHost(QHostAddress::LocalHost,8888);

   connect(socket,SIGNAL(readyRead()),this,SLOT(Read_data_from_socket()));

    socket->open(QIODevice::ReadWrite);

    if(socket->isOpen())
    {
        QMessageBox::information(this,"CLient Pop up","connected to server");


    }else
    {
         QMessageBox::information(this,"CLient Pop up","connected not to server try again ?");

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Read_data_from_socket()
{
    if(socket)
    {
        if(socket->isOpen())
        {
             QByteArray msg_rev=socket->readAll();


             ui->clientscreen->append("Server :"+QString::fromStdString(msg_rev.toStdString()));

             ui->clientscreen->setAlignment(Qt::AlignLeft);

             ui->clientscreen->setTextColor(Qt::blue);
        }
    }


}



void MainWindow::on_sendbutton_clicked()
{
    if(socket)
    {
         if(socket->isOpen())
         {
             QString send_msg=ui->msgbox->text();

             socket->write(send_msg.toStdString().c_str());

             ui->clientscreen->append("you :"+send_msg);

             ui->clientscreen->setAlignment(Qt::AlignRight);

             ui->clientscreen->setTextColor(Qt::black);

         }
         else
         {
             QMessageBox::information(this,"NOt connected","server"+socket->errorString());
         }
    }

    ui->msgbox->clear();

}


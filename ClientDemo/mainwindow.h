#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpSocket>

#include <QString>

#include <QMessageBox>

#include <QHostAddress>

#include <QByteArray>

#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendbutton_clicked();
    void Read_data_from_socket();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;




};
#endif // MAINWINDOW_H

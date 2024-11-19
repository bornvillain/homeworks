#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dw=new DialogWindow(this);
}

MainWindow::~MainWindow()
{
    delete dw;
    delete ui;
}

void MainWindow::on_pushButton_connect_clicked()
{
    dw->show();
}


#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_on->setText("On");
    ui->radioButton_of->setText("Off");
    ui->progressBar->setMaximum(10);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    ui->pushButton->setText("Change progress");
    ui->pushButton->setCheckable(true);

    for(int i=0;i<10;++i){
        ui->comboBox_digits->addItem(QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  int current_value=ui->progressBar->value();
  ui->progressBar->setValue(++current_value);
  if(current_value>ui->progressBar->maximum()){
    ui->progressBar->setValue(0);
  }
}


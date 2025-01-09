#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stopwatch = new Stopwatch(this);
    connect(stopwatch, &Stopwatch::time_updated,this,&MainWindow::update_display);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_display(int m,int s,int ms,const QList<QString>& laps)
{
    QString time_text=QString::number(m)+" : "+QString::number(s)+" : "+QString::number(ms);
    ui->time_label->setText(time_text);
    QString display_text;
    if(!laps.isEmpty()){
        for(int i=0;i<laps.size();++i){
            display_text += QString("\nLap %1, time %2").arg(i + 1).arg(laps[i]);
        }
    }
    ui->lap_textBrowser->setText(display_text);
    ui->lap_textBrowser->moveCursor(QTextCursor::End);
    ui->lap_textBrowser->ensureCursorVisible();
}

void MainWindow::on_start_pushButton_clicked()
{
    if(ui->start_pushButton->isChecked()){
        ui->start_pushButton->setText("Stop");
        ui->lap_pushButton->setEnabled(true);
        stopwatch->start();
    }
    else{
        ui->start_pushButton->setText("Start");
        ui->lap_pushButton->setEnabled(false);
        stopwatch->stop();
    }
}


void MainWindow::on_reset_pushButton_clicked()
{
    stopwatch->reset();
    update_display(0,0,0,{});
}


void MainWindow::on_lap_pushButton_clicked()
{
    stopwatch->record_lap();
}


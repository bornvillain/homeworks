#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "stopwatch.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
private slots:
    void update_display(int m,int s,int ms, const QList<QString>& laps);
    void on_start_pushButton_clicked();
    void on_reset_pushButton_clicked();
    void on_lap_pushButton_clicked();
};
#endif // MAINWINDOW_H

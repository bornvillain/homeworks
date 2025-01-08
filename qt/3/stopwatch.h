#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QList>

class Stopwatch: public QObject
{
    Q_OBJECT
public:
    Stopwatch(QObject *parent=nullptr);

    void start();
    void stop();
    void reset();
    void record_lap();

signals:
    void time_updated(int m,int s,int ms,const QList<QString>& laps);

private slots:
    void on_timeout();
private:
    QTimer *timer;
    int ms,s,m, last_lap_ms,last_lap_s,last_lap_m;
    QList<QString> laps;
};

#endif // STOPWATCH_H

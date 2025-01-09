#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    :QObject(parent), ms(0), s(0), m(0),last_lap_ms(0),last_lap_s(0),last_lap_m(0)
{
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Stopwatch::on_timeout);
}

void Stopwatch::start()
{
    timer->start(100);
}

void Stopwatch::stop()
{
    timer->stop();
}

void Stopwatch::reset()
{
    ms=s=m=0;
    laps.clear();
    emit time_updated(m,s,ms,laps);
    last_lap_ms=last_lap_s=last_lap_m=0;
}

void Stopwatch::record_lap()
{
    int lap_ms=ms-last_lap_ms;
    int lap_s=s-last_lap_s;
    int lap_m=m-last_lap_m;

    if(lap_ms<0){
        lap_s--;
        lap_ms+=1000;
    }

    if(lap_s<0){
        lap_m--;
        lap_s+=60;
    }


    QString lap_time=QString::number(lap_m)+" : "+QString::number(lap_s)+" : "+QString::number(lap_ms/100);
    laps.append(lap_time);

    last_lap_ms=ms;
    last_lap_s=s;
    last_lap_m=m;
    emit time_updated(m,s,ms,laps);
}

void Stopwatch::on_timeout()
{
    ms+=100;
    if(ms>=1000){
        ms=0;
        ++s;
    }
    if(s>=60){
        s=0;
        ++m;
    }
    emit time_updated(m,s,ms/100,laps);
}

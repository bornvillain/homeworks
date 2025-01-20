#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345
#define ANOTHER_BIND_PORT 12346

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );

    void ReadDatagramFromInput(QNetworkDatagram datagram);
    void SendDatagramFromInput(QString text);

private slots:
    void readPendingDatagrams(void);
    void readDatagramsFromInput(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* anotherUdpSocket;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_senTextInfoToGUI(QString senderAddress, int textSize);

};

#endif // UDPWORKER_H

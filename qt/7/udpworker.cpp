#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);

    anotherUdpSocket = new QUdpSocket(this);
    anotherUdpSocket->bind(QHostAddress::LocalHost, ANOTHER_BIND_PORT);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);
    connect(anotherUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readDatagramsFromInput);

}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;

    emit sig_sendTimeToGUI(dateTime);
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}

void UDPworker::ReadDatagramFromInput(QNetworkDatagram datagram)
{
    QString senderAddress= datagram.senderAddress().toString();
    QString text=datagram.data().data();
    int textSize = text.length();

    emit sig_senTextInfoToGUI(senderAddress, textSize);
}

void UDPworker::SendDatagramFromInput(QString text)
{
    anotherUdpSocket->writeDatagram(text.toUtf8(),QHostAddress::LocalHost,ANOTHER_BIND_PORT);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(serviceUdpSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
        ReadDatagram(datagram);
    }

}

void UDPworker::readDatagramsFromInput( void )
{
    while(anotherUdpSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = anotherUdpSocket->receiveDatagram();
        ReadDatagramFromInput(datagram);
    }
}

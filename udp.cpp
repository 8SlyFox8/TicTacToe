#include "udp.h"

UDP::UDP(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this); //Создание объекта сокета QUdpSocket
    //Соединение сигнала сокета со слотом
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readingData()));
}

///
/// \brief UDP::readingData
/// \brief Чтение данных
///
void UDP::readingData() //Чтение данных
{
    while (udpSocket->hasPendingDatagrams())
    {
        //Порверка размера ждущего обработки сообщения
        UdpMessage.resize(udpSocket->pendingDatagramSize());
        //Чтение данных из сообщения
        udpSocket->readDatagram(UdpMessage.data(), UdpMessage.size());
        qDebug() << UdpMessage.data(); //Вывод информации в консоль
        if (UdpMessage[0] == '9') {
            emit buttonClear();
            emit choiceOfWhoTurn(true);
            emit buttonLock(true);
        }
        else {
            emit playerTurn(UdpMessage[0]);
        }

    }
}

///
/// \brief UDP::transmitMessage
/// \brief Передача данных о ходе или смене режима игры
/// \param comand
///
void UDP::transmitMessage(QByteArray comand)
{
    udpSocket->writeDatagram(comand, senderIP, senderPORT);
}

///
/// \brief UDP::sendLanSetting
/// \brief Передача данных для подключения в сетевом режиме
/// \param senderIp
/// \param senderPort
/// \param recipientIp
/// \param recipientPort
///
void UDP::sendLanSetting(QString senderIp, QString senderPort,
                         QString recipientIp, QString recipientPort)
{
    senderIP = QHostAddress(senderIp);
    senderPORT = senderPort.toUInt();
    recipientIP = QHostAddress(recipientIp);
    recipientPORT = recipientPort.toUInt();
    //Выставление адреса и порта по которому будет получено сообщение
    udpSocket->bind(recipientIP, recipientPORT);
}

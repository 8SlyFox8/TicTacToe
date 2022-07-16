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
        //Если пришла '9' - перейти в сетевой режим игры
        if (UdpMessage[0] == '9') {
            emit buttonClear(); //Очистить полк текущей игры
            emit choiceOfWhoTurn(true); //Ходит соперник
            emit buttonLock(true); //Заблокировать все клетки
        }
        else {
            // Метод для ходов противника в онлайн режиме
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
    //Отправка сообщения на заданный IP и порт
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

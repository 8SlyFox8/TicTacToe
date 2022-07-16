#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>

class UDP : public QObject
{
    Q_OBJECT
public:
    explicit UDP(QObject *parent = nullptr);
    QByteArray UdpMessage; //Массив сообщения

signals:
    void buttonLock(bool unlockButtons);
    void choiceOfWhoTurn(bool changeCurrentMove);
    void buttonClear();
    void playerTurn(char selectedCell);

public slots:
    void readingData(); //Чтение данных
    // Передача данных о ходе или смене режима игры
    void transmitMessage(QByteArray comand);
    // Передача данных для подключения в сетевом режиме
    void sendLanSetting(QString senderIp, QString senderPort,
                        QString recipientIp, QString recipientPort);

private:
    QUdpSocket *udpSocket; //Указатель на объект класса QUdpScoket
    QHostAddress senderIP; //IP-адрес противника в сетивой игре
    quint16 senderPORT; //Порт противника в сетивой игре
    QHostAddress recipientIP; //IP-адрес игрока в сетивой игре
    quint16 recipientPORT; //Порт игрока в сетивой игре
};

#endif // UDP_H

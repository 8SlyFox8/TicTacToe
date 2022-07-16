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
    // Метод для блокировки кнопок не в свой ход
    void buttonLock(bool unlockButtons);
    // Метод для выбора кто ходит и какой фигурой
    void choiceOfWhoTurn(bool changeCurrentMove);
    // Очистка поля при запуске/перезапуске режима игры
    void buttonClear();
    // Метод для ходов противника в онлайн режиме
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

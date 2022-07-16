#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QMessageBox>
#include <udp.h>

namespace Ui {
class config;
}

class config : public QDialog
{
    Q_OBJECT

protected:
    //Настройка полей ввода для окна настроек и считыванте настроей из файла настроек
    void showEvent(QShowEvent *event) override;

public:
    explicit config(QWidget *parent = nullptr);
    ~config();

signals:
    void sendLanSetting(QString senderIp, QString senderPort,
                        QString recipientIp, QString recipientPort);

private slots:
    //Сохраннение настроек IP и порта для сетевой игры в файл
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::config *ui;
    QRegExp mask; //Макска для ввода IP
    QDir dir; //Папка для настроек
    QFile file_config; //Файл настроек
    QString senderIP; //IP-адрес противника в сетивой игре
    QString senderPort; //Порт противника в сетивой игре
    QString recipientIP; //IP-адрес игрока в сетивой игре
    QString recipientPort; //Порт игрока в сетивой игре

    UDP instanceUDP;
};

#endif // CONFIG_H

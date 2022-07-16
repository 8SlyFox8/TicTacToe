#include "config.h"
#include "ui_config.h"

config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);

    connect(this, &config::sendLanSetting, &instanceUDP, &UDP::sendLanSetting);
}

config::~config()
{
    delete ui;
}

///
/// \brief config::showEvent
/// \brief Настройка полей ввода для окна настроек
/// и считыванте настроей из файла настроек
/// \param event
///
void config::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    mask = QRegExp("[0-9.]{0,13}"); //Макска для ввода IP
    ui->lineEdit->setValidator(new QRegExpValidator(mask));
    //Макска для ввода порта
    ui->lineEdit_2->setValidator(new QIntValidator(0, 9999, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(mask));
    //Макска для ввода порта
    ui->lineEdit_4->setValidator(new QIntValidator(0, 9999, this));

    file_config.setFileName("Settings/LANsettings.cfg");
    if (file_config.open(QIODevice::ReadOnly))
    {
        senderIP = file_config.readLine();
        senderIP = senderIP.left(senderIP.indexOf("\r\n"));
        ui->lineEdit->setText(senderIP);
        senderPort = file_config.readLine();
        senderPort = senderPort.left(senderPort.indexOf("\r\n"));
        ui->lineEdit_2->setText(senderPort);
        recipientIP = file_config.readLine();
        recipientIP = recipientIP.left(recipientIP.indexOf("\r\n"));
        ui->lineEdit_3->setText(recipientIP);
        recipientPort = file_config.readLine();
        ui->lineEdit_4->setText(recipientPort);
        file_config.close();
    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Файл настроек не загрузился");
    }
   void showEvent();
}


///
/// \brief config::on_pushButton_clicked
/// \brief Сохраннение настроек IP и порта для сетевой игры в файл
///
void config::on_pushButton_clicked()
{
    //Проверка и/или создание папки настроек
    if (!dir.exists("Settings"))
    {
        dir.mkdir("Settings");
    }
    file_config.setFileName("Settings/LANsettings.cfg");
    if (file_config.open(QIODevice::WriteOnly))
    {
        QTextStream writeStream(&file_config);
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        writeStream << ui->lineEdit->text() << codec->toUnicode("\r\n")
                    << ui->lineEdit_2->text() << codec->toUnicode("\r\n")
                    << ui->lineEdit_3->text() << codec->toUnicode("\r\n")
                    << ui->lineEdit_4->text();
        senderIP = ui->lineEdit->text();
        senderPort = ui->lineEdit_2->text();
        recipientIP = ui->lineEdit_3->text();
        recipientPort = ui->lineEdit_4->text();
        file_config.close();
        emit sendLanSetting(senderIP, senderPort, recipientIP, recipientPort);
    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Файл настроек не cохранён");
    }  
    config::close(); //Зарыть окно настроек
}

void config::on_pushButton_2_clicked()
{
    config::close(); //Зарыть окно настроек
}



#include "config.h"
#include "ui_config.h"

config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
}

config::~config()
{
    delete ui;
}

///
/// \brief config::showEvent
/// \param event
/// Настройка полей ввода для окна настроек
/// и считыванте настроей из файла настроек
///
void config::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    mask = QRegExp("[0-9.]{0,13}"); //Макска для ввода IP
    ui->lineEdit->setValidator(new QRegExpValidator(mask));
    //Макска для ввода порта
    ui->lineEdit_2->setValidator(new QIntValidator(0, 99999, this));

    file_config.setFileName("Settings/LANsettings.cfg");
    if (file_config.open(QIODevice::ReadOnly))
    {
        IP = file_config.readLine();
        IP = IP.left(IP.indexOf("\r\n"));
        ui->lineEdit->setText(IP);
        port = file_config.readLine();
        ui->lineEdit_2->setText(port);
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
/// Сохраннение настроек IP и порта для сетевой игры в файл
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
                    << ui->lineEdit_2->text();
        file_config.close();
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



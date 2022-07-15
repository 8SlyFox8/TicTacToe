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

namespace Ui {
class config;
}

class config : public QDialog
{
    Q_OBJECT

protected:
    void showEvent(QShowEvent *event) override;

public:
    explicit config(QWidget *parent = nullptr);
    ~config();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::config *ui;
    QRegExp mask; //Макска для ввода IP
    QDir dir; //Папка для настроек
    QFile file_config; //Файл настроек
    QString IP; //IP-адрес противника в сетивой игре
    QString port; //Порт противника в сетивой игре
};

#endif // CONFIG_H

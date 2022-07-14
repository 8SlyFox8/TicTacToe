#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionBot_triggered(); // Режим игры против бота
    void on_actionOffline_player_triggered(); // Режим игры против второго игрока за одним компьютером
    void on_actionOnline_player_triggered(); // Режим игры против второго игрока удалённо
    void on_actionLAN_settings_triggered(); // Настройки LAN для удалённой игры
    void choiceOfWhoGoes(); // Метод для выбора кто ходит и какой фигурой
    void buttonLock(); // Метод для блокировки кнопок не в свой ход
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    bool choiceOfTurn; // Выбор того кто ходит первым
    QString choiceOfFigure; //Выбор кокой фигурой ходить
};

#endif // MAINWINDOW_H

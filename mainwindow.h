#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <config.h>

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
    void choiceOfWhoTurn(bool changeCurrentMove); // Метод для выбора кто ходит и какой фигурой
    void buttonLock(); // Метод для блокировки кнопок не в свой ход
    void buttonClear(); // Очистка поля при запуске/перезапуске режима игры
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void victoryCheck(bool turnCheck); // Метод для проверки победителя
    void gameModeCheck(); // Метод для проверки режима игры
    void stopGame(); // Метод для остановки игры в случае победителя
    void botTurn(); // Метод для ходов ИИ в режиме против бота

private:
    Ui::MainWindow *ui;
    bool choiceOfTurn; // Выбор того кто ходит первым
    QString choiceOfFigure; //Выбор кокой фигурой ходить
    QString field[9] = {"", "", "", "", "", "", "", "", ""}; //Значения всех клеток в игровом поле
    int cell; //Номер клетки на игровом поле
    bool newTurn; //Флаг разрешающий ходить боту в выбранную ему клетку
    int selectedCell; //Выбранная ботом клетка для хода
};

#endif // MAINWINDOW_H

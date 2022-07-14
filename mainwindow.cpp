#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionBot->setChecked(true);
    on_actionBot_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::on_actionBot_triggered
/// Режим игры против бота
///
void MainWindow::on_actionBot_triggered()
{
    ui->actionBot->setChecked(true);
    ui->actionOffline_player->setChecked(false);
    ui->actionOnline_player->setChecked(false);
    buttonClear();
    choiceOfWhoTurn(rand() % 2);
    buttonLock();
}

///
/// \brief MainWindow::on_actionOffline_player_triggered
/// Режим игры против второго игрока за одним компьютером
///
void MainWindow::on_actionOffline_player_triggered()
{
    ui->actionBot->setChecked(false);
    ui->actionOffline_player->setChecked(true);
    ui->actionOnline_player->setChecked(false);
    buttonClear();
    choiceOfWhoTurn(false);
    buttonLock();
}

///
/// \brief MainWindow::on_actionOnline_player_triggered
/// Режим игры против второго игрока удалённо
///
void MainWindow::on_actionOnline_player_triggered()
{
    ui->actionBot->setChecked(false);
    ui->actionOffline_player->setChecked(false);
    ui->actionOnline_player->setChecked(true);
    buttonClear();
    choiceOfWhoTurn(rand() % 2);
    buttonLock();
}

///
/// \brief MainWindow::on_actionLAN_settings_triggered
/// Настройки LAN для удалённой игры
///
void MainWindow::on_actionLAN_settings_triggered()
{
    ui->label->setText("Новое окно");
}

///
/// \brief MainWindow::choiceOfWhoGoes
/// Метод для выбора кто ходит и какой фигурой
///
void MainWindow::choiceOfWhoTurn(bool changeCurrentMove)
{
    choiceOfTurn = changeCurrentMove;
    if (choiceOfTurn == 1)
    {
        choiceOfFigure = "O";
    }
    else
    {
        choiceOfFigure = "X";
    }
}

///
/// \brief MainWindow::buttonLock
/// Метод для блокировки кнопок не в свой ход
///
void MainWindow::buttonLock()
{
    if (choiceOfTurn == 1)
    {
        ui->label->setText("Waiting");
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        gameModeCheck();
    }
    else
    {
        ui->label->setText("You turn");
        if (field[0]=="") {
            ui->pushButton->setEnabled(true);
        }
        if (field[1]=="") {
            ui->pushButton_2->setEnabled(true);
        }
        if (field[2]=="") {
            ui->pushButton_3->setEnabled(true);
        }
        if (field[3]=="") {
            ui->pushButton_4->setEnabled(true);
        }
        if (field[4]=="") {
            ui->pushButton_5->setEnabled(true);
        }
        if (field[5]=="") {
            ui->pushButton_6->setEnabled(true);
        }
        if (field[6]=="") {
            ui->pushButton_7->setEnabled(true);
        }
        if (field[7]=="") {
            ui->pushButton_8->setEnabled(true);
        }
        if (field[8]=="") {
            ui->pushButton_9->setEnabled(true);
        }
    }
}

///
/// \brief MainWindow::buttonClear
/// Очистка поля при запуске/перезапуске режима игры
///
void MainWindow::buttonClear()
{
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    for(cell = 0; cell < 9; cell++) {
        field[cell] = "";
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText(choiceOfFigure);
    ui->pushButton->setEnabled(false);
    field[0] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText(choiceOfFigure);
    ui->pushButton_2->setEnabled(false);
    field[1] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText(choiceOfFigure);
    ui->pushButton_3->setEnabled(false);
    field[2] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setText(choiceOfFigure);
    ui->pushButton_4->setEnabled(false);
    field[3] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setText(choiceOfFigure);
    ui->pushButton_5->setEnabled(false);
    field[4] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setText(choiceOfFigure);
    ui->pushButton_6->setEnabled(false);
    field[5] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setText(choiceOfFigure);
    ui->pushButton_7->setEnabled(false);
    field[6] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setText(choiceOfFigure);
    ui->pushButton_8->setEnabled(false);
    field[7] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setText(choiceOfFigure);
    ui->pushButton_9->setEnabled(false);
    field[8] = choiceOfFigure;
    victoryCheck();
    gameModeCheck();
}

///
/// \brief MainWindow::victoryCheck
/// Метод для проверки победителя
///
void MainWindow::victoryCheck()
{
    if ((field[0]==field[1]) && (field[0]==field[2]) && (field[0]!="")) {
        stopGame();
    }
    if ((field[3]==field[4]) && (field[3]==field[5]) && (field[3]!="")) {
        stopGame();
    }
    if ((field[6]==field[7]) && (field[6]==field[8]) && (field[6]!="")) {
        stopGame();
    }
    if ((field[0]==field[3]) && (field[0]==field[6]) && (field[0]!="")) {
        stopGame();
    }
    if ((field[1]==field[4]) && (field[1]==field[7]) && (field[1]!="")) {
        stopGame();
    }
    if ((field[2]==field[5]) && (field[2]==field[8]) && (field[2]!="")) {
        stopGame();
    }
    if ((field[0]==field[4]) && (field[0]==field[8]) && (field[0]!="")) {
        stopGame();
    }
    if ((field[2]==field[4]) && (field[2]==field[6]) && (field[2]!="")) {
        stopGame();
    }
}

///
/// \brief MainWindow::gameModeCheck
/// Метод для проверки режима игры
///
void MainWindow::gameModeCheck()
{
    if (ui->actionBot->isChecked() == true) {

    }
    if (ui->actionOffline_player->isChecked() == true) {
        if (choiceOfTurn == true) {
            choiceOfWhoTurn(false);
        }
        else {
            choiceOfWhoTurn(true);
        }

    }
    if (ui->actionOnline_player->isChecked() == true) {

    }
}

///
/// \brief MainWindow::stopGame
/// Метод для остановки игры в случае победителя
///
void MainWindow::stopGame()
{
    ui->label->setText(choiceOfFigure + " win");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
}

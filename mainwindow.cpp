#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    choiceOfWhoGoes();
    buttonLock();
}

///
/// \brief MainWindow::on_actionOffline_player_triggered
/// Режим игры против второго игрока за одним компьютером
///
void MainWindow::on_actionOffline_player_triggered()
{
    choiceOfWhoGoes();
    buttonLock();
}

///
/// \brief MainWindow::on_actionOnline_player_triggered
/// Режим игры против второго игрока удалённо
///
void MainWindow::on_actionOnline_player_triggered()
{
    choiceOfWhoGoes();
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
void MainWindow::choiceOfWhoGoes()
{
    choiceOfTurn = rand() % 2;
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
    }
    else
    {
        ui->label->setText("You turn");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText(choiceOfFigure);
    ui->pushButton->setEnabled(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText(choiceOfFigure);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText(choiceOfFigure);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setText(choiceOfFigure);
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setText(choiceOfFigure);
    ui->pushButton_5->setEnabled(false);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setText(choiceOfFigure);
    ui->pushButton_6->setEnabled(false);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setText(choiceOfFigure);
    ui->pushButton_7->setEnabled(false);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setText(choiceOfFigure);
    ui->pushButton_8->setEnabled(false);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setText(choiceOfFigure);
    ui->pushButton_9->setEnabled(false);
}

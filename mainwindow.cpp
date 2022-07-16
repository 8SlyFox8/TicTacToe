#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Запуск приложения в режиме игры с ботом
    on_actionBot_triggered();

    connect(this, &MainWindow::transmitMessage, &instanceUDP, &UDP::transmitMessage);
    connect(this, &MainWindow::sendLanSetting, &instanceUDP, &UDP::sendLanSetting);
    connect( &instanceUDP, &UDP::buttonClear, this, &MainWindow::buttonClear);
    connect( &instanceUDP, &UDP::choiceOfWhoTurn, this, &MainWindow::choiceOfWhoTurn);
    connect( &instanceUDP, &UDP::buttonLock, this, &MainWindow::buttonLock);    
    connect( &instanceUDP, &UDP::playerTurn, this, &MainWindow::playerTurn);


    file_config.setFileName("Settings/LANsettings.cfg");
    if (file_config.open(QIODevice::ReadOnly))
    {
        //Чтение настроек из файла настроек сетевой игры
        senderIP = file_config.readLine();
        senderIP = senderIP.left(senderIP.indexOf("\r\n"));
        senderPort = file_config.readLine();
        senderPort = senderPort.left(senderPort.indexOf("\r\n"));
        recipientIP = file_config.readLine();
        recipientIP = recipientIP.left(recipientIP.indexOf("\r\n"));
        recipientPort = file_config.readLine();
        file_config.close();
        // Передача данных для подключения в сетевом режиме
        emit sendLanSetting(senderIP, senderPort, recipientIP, recipientPort);
    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Файл настроек не загрузился");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief MainWindow::on_actionBot_triggered
/// \brief Режим игры против бота
///
void MainWindow::on_actionBot_triggered()
{
    //Перключение режима игры в меню
    ui->actionBot->setChecked(true);
    ui->actionOffline_player->setChecked(false);
    ui->actionOnline_player->setChecked(false);
    buttonClear(); //Очистка поля
    choiceOfWhoTurn(rand() % 2); //Выбор хода игрока
    buttonLock(choiceOfTurn);
    //Если первый ход за ботом
    if (choiceOfTurn==true) {
        gameModeCheck();
        buttonLock(!choiceOfTurn);
    }
}

///
/// \brief MainWindow::on_actionOffline_player_triggered
/// \brief Режим игры против второго игрока за одним компьютером
///
void MainWindow::on_actionOffline_player_triggered()
{
    //Перключение режима игры в меню
    ui->actionBot->setChecked(false);
    ui->actionOffline_player->setChecked(true);
    ui->actionOnline_player->setChecked(false);
    buttonClear(); //Очистка поля
    choiceOfWhoTurn(false); //Выбор хода игрока. Первые всегда X
    buttonLock(choiceOfTurn);
}

///
/// \brief MainWindow::on_actionOnline_player_triggered
/// \brief Режим игры против второго игрока удалённо
///
void MainWindow::on_actionOnline_player_triggered()
{
    //Перключение режима игры в меню
    ui->actionBot->setChecked(false);
    ui->actionOffline_player->setChecked(false);
    ui->actionOnline_player->setChecked(true);
    buttonClear(); //Очистка поля
    choiceOfWhoTurn(rand() % 2); //Выбор хода игрока
    buttonLock(choiceOfTurn);
    //Если первый ход за игроком
    if (choiceOfTurn==false) {
        //Смена режима игры для соперника
        emit transmitMessage("9");
    }
    else {
        buttonLock(true);
    }
}

///
/// \brief MainWindow::on_actionLAN_settings_triggered
/// \brief Настройки LAN для удалённой игры
///
void MainWindow::on_actionLAN_settings_triggered()
{
    config window;
    window.setModal(true);
    window.exec();
}

///
/// \brief MainWindow::choiceOfWhoTurn
/// \brief Метод для выбора кто ходит и какой фигурой
/// \param changeCurrentMove
///
void MainWindow::choiceOfWhoTurn(bool changeCurrentMove)
{
    choiceOfTurn = changeCurrentMove;
    //Выбор фигуры для хода
    if (choiceOfTurn == true)
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
/// \brief Метод для блокировки кнопок не в свой ход
/// \param unlockButtons
///
void MainWindow::buttonLock(bool unlockButtons)
{
    if (unlockButtons == false) {
        //Блокировка всех уже нажатых клеток на поле
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
    else
    {
        //Блокировка всех клеток на поле
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
}

///
/// \brief MainWindow::buttonClear
/// \brief Очистка поля при запуске/перезапуске режима игры
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
    emit transmitMessage("0");
    victoryCheck(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText(choiceOfFigure);
    ui->pushButton_2->setEnabled(false);
    field[1] = choiceOfFigure;
    emit transmitMessage("1");
    victoryCheck(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText(choiceOfFigure);
    ui->pushButton_3->setEnabled(false);
    field[2] = choiceOfFigure;
    emit transmitMessage("2");
    victoryCheck(true);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setText(choiceOfFigure);
    ui->pushButton_4->setEnabled(false);
    field[3] = choiceOfFigure;
    emit transmitMessage("3");
    victoryCheck(true);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setText(choiceOfFigure);
    ui->pushButton_5->setEnabled(false);
    field[4] = choiceOfFigure;
    emit transmitMessage("4");
    victoryCheck(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setText(choiceOfFigure);
    ui->pushButton_6->setEnabled(false);
    field[5] = choiceOfFigure;
    emit transmitMessage("5");
    victoryCheck(true);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setText(choiceOfFigure);
    ui->pushButton_7->setEnabled(false);
    field[6] = choiceOfFigure;
    emit transmitMessage("6");
    victoryCheck(true);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setText(choiceOfFigure);
    ui->pushButton_8->setEnabled(false);
    field[7] = choiceOfFigure;
    emit transmitMessage("7");
    victoryCheck(true);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setText(choiceOfFigure);
    ui->pushButton_9->setEnabled(false);
    field[8] = choiceOfFigure;
    emit transmitMessage("8");
    victoryCheck(true);

}

///
/// \brief MainWindow::victoryCheck
/// \brief Метод для проверки победителя
/// \param turnCheck
///
void MainWindow::victoryCheck(bool turnCheck)
{
    //Проверка всех выигрышных раскладов на поле 3 на 3
    if (((field[0]==field[1]) && (field[0]==field[2]) && (field[0]!="")) ||
        ((field[3]==field[4]) && (field[3]==field[5]) && (field[3]!="")) ||
        ((field[6]==field[7]) && (field[6]==field[8]) && (field[6]!="")) ||
        ((field[0]==field[3]) && (field[0]==field[6]) && (field[0]!="")) ||
        ((field[1]==field[4]) && (field[1]==field[7]) && (field[1]!="")) ||
        ((field[2]==field[5]) && (field[2]==field[8]) && (field[2]!="")) ||
        ((field[0]==field[4]) && (field[0]==field[8]) && (field[0]!="")) ||
        ((field[2]==field[4]) && (field[2]==field[6]) && (field[2]!=""))) {
        stopGame();
    }
    else {
        if (turnCheck == true) {
            //Проверка режима игры для ответа противника
            gameModeCheck();
        }
    }
}

///
/// \brief MainWindow::gameModeCheck
/// \brief Метод для проверки режима игры
///
void MainWindow::gameModeCheck()
{
    // Режим игры против бота
    if (ui->actionBot->isChecked() == true) {
        botTurn();
    }
    // Режим игры против второго игрока за одним компьютером
    if (ui->actionOffline_player->isChecked() == true) {
        if (choiceOfTurn == true) {
            choiceOfWhoTurn(false);
        }
        else {
            choiceOfWhoTurn(true);
        }

    }
    // Режим игры против второго игрока удалённо
    if (ui->actionOnline_player->isChecked() == true) {
        buttonLock(true);
    }
}

///
/// \brief MainWindow::stopGame
/// \brief Метод для остановки игры в случае победителя
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

///
/// \brief MainWindow::botTurn
/// \brief Метод для ходов ИИ в режиме против бота
///
void MainWindow::botTurn()
{
    choiceOfWhoTurn(!choiceOfTurn);
    newTurn = true;
    //Выбор пустой клетки на поле
    while (newTurn == true) {
        selectedCell = rand() % 9;
        if (field[selectedCell] == "") {
            newTurn = false;
        }
    }
    switch (selectedCell) {
    case 0:
        ui->pushButton->setText(choiceOfFigure);
        ui->pushButton->setEnabled(false);
        field[0] = choiceOfFigure;
        break;
    case 1:
        ui->pushButton_2->setText(choiceOfFigure);
        ui->pushButton_2->setEnabled(false);
        field[1] = choiceOfFigure;
        break;
    case 2:
        ui->pushButton_3->setText(choiceOfFigure);
        ui->pushButton_3->setEnabled(false);
        field[2] = choiceOfFigure;
        break;
    case 3:
        ui->pushButton_4->setText(choiceOfFigure);
        ui->pushButton_4->setEnabled(false);
        field[3] = choiceOfFigure;
        break;
    case 4:
        ui->pushButton_5->setText(choiceOfFigure);
        ui->pushButton_5->setEnabled(false);
        field[4] = choiceOfFigure;
        break;
    case 5:
        ui->pushButton_6->setText(choiceOfFigure);
        ui->pushButton_6->setEnabled(false);
        field[5] = choiceOfFigure;
        break;
    case 6:
        ui->pushButton_7->setText(choiceOfFigure);
        ui->pushButton_7->setEnabled(false);
        field[6] = choiceOfFigure;
        break;
    case 7:
        ui->pushButton_8->setText(choiceOfFigure);
        ui->pushButton_8->setEnabled(false);
        field[7] = choiceOfFigure;
        break;
    case 8:
        ui->pushButton_9->setText(choiceOfFigure);
        ui->pushButton_9->setEnabled(false);
        field[8] = choiceOfFigure;
        break;
    }
    victoryCheck(false);
    choiceOfWhoTurn(!choiceOfTurn); 
}

///
/// \brief MainWindow::playerTurn
/// \brief Метод для ходов противника в онлайн режиме
/// \param selectedCell
///
void MainWindow::playerTurn(char selectedCell)
{
    ui->actionBot->setChecked(false);
    ui->actionOffline_player->setChecked(false);
    ui->actionOnline_player->setChecked(true);
    choiceOfWhoTurn(!choiceOfTurn);
    switch (selectedCell) {
    case '0':
        ui->pushButton->setText(choiceOfFigure);
        ui->pushButton->setEnabled(false);
        field[0] = choiceOfFigure;
        break;
    case '1':
        ui->pushButton_2->setText(choiceOfFigure);
        ui->pushButton_2->setEnabled(false);
        field[1] = choiceOfFigure;
        break;
    case '2':
        ui->pushButton_3->setText(choiceOfFigure);
        ui->pushButton_3->setEnabled(false);
        field[2] = choiceOfFigure;
        break;
    case '3':
        ui->pushButton_4->setText(choiceOfFigure);
        ui->pushButton_4->setEnabled(false);
        field[3] = choiceOfFigure;
        break;
    case '4':
        ui->pushButton_5->setText(choiceOfFigure);
        ui->pushButton_5->setEnabled(false);
        field[4] = choiceOfFigure;
        break;
    case '5':
        ui->pushButton_6->setText(choiceOfFigure);
        ui->pushButton_6->setEnabled(false);
        field[5] = choiceOfFigure;
        break;
    case '6':
        ui->pushButton_7->setText(choiceOfFigure);
        ui->pushButton_7->setEnabled(false);
        field[6] = choiceOfFigure;
        break;
    case '7':
        ui->pushButton_8->setText(choiceOfFigure);
        ui->pushButton_8->setEnabled(false);
        field[7] = choiceOfFigure;
        break;
    case '8':
        ui->pushButton_9->setText(choiceOfFigure);
        ui->pushButton_9->setEnabled(false);
        field[8] = choiceOfFigure;
        break;
    }
    buttonLock(false);
    victoryCheck(false);
    choiceOfWhoTurn(!choiceOfTurn);
}


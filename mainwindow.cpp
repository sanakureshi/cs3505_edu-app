/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation of the main window class, which acts as the middleman for switching to
 *         different screens in the game.
 **/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#define changeMenu(QWidget) (ui->menuWidget->setCurrentWidget(&QWidget))

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), firstPlay(true) {
    ui->setupUi(this);

    // Initializing various menus of the game
    ui->menuWidget->addWidget(&aboutPage);
    ui->menuWidget->addWidget(&tutorialPage);
    ui->menuWidget->addWidget(&levelSelectPage);
    ui->menuWidget->addWidget(&answerPage);
    ui->menuWidget->addWidget(&winScreen);

    // Initializing screen to hold the level being played
    ui->menuWidget->addWidget(&level);

    // Connections from this to other ui
    connect(this, &MainWindow::currentLevel, &level, &Level::getLevel);
    connect(this, &MainWindow::enableAllButtons, &levelSelectPage, &LevelSelectPage::enableAllButtons);

    // Connecting ui from other pages to the stacked widget in main window UI.
    connect(&aboutPage, &AboutPage::showMainMenu, this, &MainWindow::showMainMenu);
    connect(&winScreen, &WinScreen::showMainMenu, this, &MainWindow::showMainMenu);
    connect(&levelSelectPage, &LevelSelectPage::showMainMenu, this, &MainWindow::showMainMenu);
    connect(&levelSelectPage, &LevelSelectPage::showLevel, this, &MainWindow::showLevel);
    connect(&tutorialPage, &TutorialPage::showLevel, this, &MainWindow::showLevel);

    // Level connections
    connect(&level, &Level::updateLevelNumber, &answerPage, &AnswerPage::setLevelValue);
    connect(&level, &Level::answerValidation, &answerPage, &AnswerPage::answerValidation);
    connect(&level, &Level::showWinScreen, this, &MainWindow::showWinScreen);
    connect(&level, &Level::changeDescription, &answerPage, &AnswerPage::changeDescription);
    connect(&level, &Level::answerValidation, this, &MainWindow::showAnswerPage);
    connect(&level, &Level::unlockLevel, &levelSelectPage, &LevelSelectPage::unlockLevel);
    connect(&aboutPage, &AboutPage::unlockAll, this, &MainWindow::unlockAll);
    connect(&answerPage, &AnswerPage::goToLevelSelect, this, &MainWindow::on_playButton_clicked);
    connect(&answerPage, &AnswerPage::changeLevel, this, &MainWindow::showLevel);

    changeMenu(*(ui->mainMenu)); // Ensuring the main menu is always shown first
}

MainWindow::~MainWindow() {
    delete ui;
}

/**
 * @brief: Shows the main menu
 **/
void MainWindow::showMainMenu() {
    changeMenu(*(ui->mainMenu));
}

/**
 * @brief: Shows the level that the user clicks to play
 * @param: level - level to show
 **/
void MainWindow::showLevel(int levelNumber) {
    emit currentLevel(levelNumber);
    changeMenu(level);
}

/**
 * @brief: Shows the tutorial page.
 **/
void MainWindow::showTutorial() {
    changeMenu(tutorialPage);
}

/**
 * @brief: Shows the answer page.
 **/
void MainWindow::showAnswerPage() {
    changeMenu(answerPage);
}

/**
 * @brief: Shows the win screen.
 **/
void MainWindow::showWinScreen() {
    changeMenu(winScreen);
}

/**
 * @brief: Unlocks all of the levels in the game, and disables the tutorial.
 **/
void MainWindow::unlockAll() {
    firstPlay = false;
    emit enableAllButtons();
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void MainWindow::on_playButton_clicked() {
    if (firstPlay) {
        showTutorial();
        firstPlay = false;
        return;
    }
    changeMenu(levelSelectPage);
}

void MainWindow::on_aboutButton_clicked() {
    changeMenu(aboutPage);
}

void MainWindow::on_quitButton_clicked() {
    close();
}

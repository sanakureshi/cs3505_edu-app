/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the main window.
 **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "aboutpage.h"
#include "tutorialpage.h"
#include "levelselectpage.h"
#include "answerpage.h"
#include "level.h"
#include "winscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void currentLevel(int);
    void enableAllButtons();

private slots:
    void on_playButton_clicked();
    void on_aboutButton_clicked();
    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
    bool firstPlay;
    AboutPage aboutPage;
    LevelSelectPage levelSelectPage;
    TutorialPage tutorialPage;
    AnswerPage answerPage;
    WinScreen winScreen;

    // Levels
    Level level;

    // Methods assisting in showing different pages of the stacked widget
    void showMainMenu();
    void showTutorial();
    void showAnswerPage();
    void showLevel(int);
    void unlockAll();
    void showWinScreen();
};
#endif // MAINWINDOW_H

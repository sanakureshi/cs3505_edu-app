/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the level selection page.
 **/

#ifndef LEVELSELECTPAGE_H
#define LEVELSELECTPAGE_H

#include <QWidget>

namespace Ui {
class LevelSelectPage;
}

class LevelSelectPage : public QWidget {
    Q_OBJECT

public:
    explicit LevelSelectPage(QWidget *parent = nullptr);
    ~LevelSelectPage();
    void unlockLevel(int levelNumber);
    void enableAllButtons();

signals:
    void showMainMenu();
    void showLevel(int);

private slots:
    void on_backButton_clicked();
    void levelSelected(int buttonId);
private:
    Ui::LevelSelectPage *ui;
    bool tutorialSeen;
};

#endif // LEVELSELECTPAGE_H

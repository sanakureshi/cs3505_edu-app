/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation of the level selection page.
 **/

#include "levelselectpage.h"
#include "ui_levelselectpage.h"

LevelSelectPage::LevelSelectPage(QWidget *parent) : QWidget(parent), ui(new Ui::LevelSelectPage), tutorialSeen(false) {
    ui->setupUi(this);

    // Setting IDs for each level button
    ui->levelButtons->setId(ui->level1_button, 1);
    ui->levelButtons->setId(ui->level2_button, 2);
    ui->levelButtons->setId(ui->level3_button, 3);
    ui->levelButtons->setId(ui->level4_button, 4);
    ui->levelButtons->setId(ui->level5_button, 5);
    ui->levelButtons->setId(ui->level6_button, 6);
    ui->levelButtons->setId(ui->level7_button, 7);
    ui->levelButtons->setId(ui->level8_button, 8);
    ui->levelButtons->setId(ui->level9_button, 9);
    ui->levelButtons->setId(ui->level10_button, 10);
    connect(ui->levelButtons, &QButtonGroup::idClicked, this, &LevelSelectPage::levelSelected);
}

LevelSelectPage::~LevelSelectPage() {
    delete ui;
}

/**
 * @brief: Signals the main window to switch to a given level
 * @param: levelNumber - Level the user selected.
 */
void LevelSelectPage::levelSelected(int levelNumber) {
    emit showLevel(levelNumber);
}

/**
 * @brief: Unlocks level in the selection screen.
 * @param: levelNumber - Level to unlock.
 */
void LevelSelectPage::unlockLevel(int levelNumber) {
    ui->levelButtons->button(levelNumber)->setEnabled(true);
}

/**
 * @brief: Enables all of the level buttons so all levels can be played.
 */
void LevelSelectPage::enableAllButtons() {
    for (QAbstractButton* button : ui->levelButtons->buttons()) {
        button->setEnabled(true);
    }
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void LevelSelectPage::on_backButton_clicked() {
    emit showMainMenu();
}

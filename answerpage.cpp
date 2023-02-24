/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation of the answer screen, which shows whether the user
 *         got answered correctly or incorrectly.
 **/

#include "answerpage.h"
#include "ui_answerpage.h"

AnswerPage::AnswerPage(QWidget *parent) : QWidget(parent), ui(new Ui::AnswerPage) {
    ui->setupUi(this);
}

AnswerPage::~AnswerPage() {
    delete ui;
}

/**
 * @brief: Sets the level value
 **/
void AnswerPage::setLevelValue(int levelValue) {
    level = levelValue;
}

/**
 * @brief: Validates whether or not the answer given was correct.
 **/
void AnswerPage::answerValidation(bool correct) {
    if (correct) {
        ui->answerLabel->setText("Correct!");
        ui->answerLabel->setStyleSheet("color: rgb(0, 200, 0)");

        if (level == 10)
            ui->nextLevelButton->setDisabled(true);
        else
            ui->nextLevelButton->setEnabled(true);
    }
    else {
        ui->answerLabel->setText("Incorrect.");
        ui->answerLabel->setStyleSheet("color: rgb(200, 0, 0)");
        ui->nextLevelButton->setDisabled(true);
    }
}

/**
 * @brief: Changes the description given for why the answer was correct.
**/
void AnswerPage::changeDescription(QString description) {
    ui->descriptionBox->setText(description);
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void AnswerPage::on_nextLevelButton_clicked() {
    emit changeLevel(++level);
}

void AnswerPage::on_retryButton_clicked() {
    emit changeLevel(level);
}

void AnswerPage::on_levelsButton_clicked() {
    emit goToLevelSelect();
}

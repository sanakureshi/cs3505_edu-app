/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation for the tutorial page, which is a multi-page screen that tells the user
 *         how to play the game.
 **/

#include "tutorialpage.h"
#include "ui_tutorialpage.h"

TutorialPage::TutorialPage(QWidget *parent) : QWidget(parent), ui(new Ui::TutorialPage), currentPage(0) {
    ui->setupUi(this);
    ui->tutorialPages->setCurrentIndex(0);
    QPixmap gearPixmap(QPixmap::fromImage(QImage("../a8-edu-app-tporterz/images/gear.png")));
    ui->page2Image->setPixmap(gearPixmap.scaled(ui->page2Image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

TutorialPage::~TutorialPage() {
    delete ui;
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void TutorialPage::on_okButton_clicked() {
    emit showLevel(1);
}

void TutorialPage::on_nextPageButton_clicked() {
    ui->previousPageButton->setEnabled(true);
    ui->tutorialPages->setCurrentIndex(++currentPage);
    if (currentPage == ui->tutorialPages->count() - 1) {
        ui->nextPageButton->setDisabled(true);
        ui->okButton->setEnabled(true);
    }
}

void TutorialPage::on_previousPageButton_clicked() {
    ui->nextPageButton->setEnabled(true);
    ui->tutorialPages->setCurrentIndex(--currentPage);
    if (currentPage == 0) {
        ui->previousPageButton->setDisabled(true);
    }
}


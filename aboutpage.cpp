/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation of the about page.
 **/

#include "aboutpage.h"
#include "ui_aboutpage.h"

AboutPage::AboutPage(QWidget *parent) : QWidget(parent), ui(new Ui::AboutPage) {
    ui->setupUi(this);
}

AboutPage::~AboutPage() {
    delete ui;
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void AboutPage::on_backButton_clicked() {
    emit showMainMenu();
}

void AboutPage::on_unlockAllButton_clicked() {
    emit unlockAll();
}


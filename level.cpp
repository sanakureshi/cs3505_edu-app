/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This class is the implementation of the level class, which is used universally for all levels.
 **/

#include "level.h"
#include "ui_level.h"
using std::vector;

Level::Level(QWidget *parent) : QWidget(parent), ui(new Ui::Level) {
    ui->setupUi(this);
    connect(ui->answerGroup, &QButtonGroup::buttonClicked, ui->submitButton, &QPushButton::setEnabled);
}

Level::~Level() {
    delete ui;
}

/**
 * @brief: Gets a level's .json file and ensures it exists.
 * @param levelNumber - Level to get
 **/
void Level::getLevel(int levelNumber) {
    QString level = "../a8-edu-app-tporterz/levels/level";
    level.append(QString::number(levelNumber));
    level.append(".json");
    ui->levelNumberLabel->setText(QString::number(levelNumber));

    QString levelContents;
    QFile levelFile(level);
    if (!levelFile.open(QIODevice::ReadOnly))
        return;

    currentLevel = levelNumber;
    levelContents = levelFile.readAll();
    QJsonDocument levelDocument = QJsonDocument::fromJson(levelContents.toUtf8());
    QJsonObject levelObject;
    levelObject = levelDocument.object();
    readLevel(levelObject);
    randomizeAnswers();
}

/**
 * @brief: Reads in .json file, and sets level UI values to data from it.
 * @param: levelObject - JSON data of level we're reading in
 **/
void Level::readLevel(QJsonObject& levelObject) {
    ui->questionLabel->setText(levelObject["questionText"].toString());
    hintText = levelObject["hint"].toString();
    lightbulbText = levelObject["lightbulbHint"].toString();
    correctAnswerDialogue = levelObject["correctAnswerDialogue"].toString();

    QJsonObject answers = levelObject["answers"].toObject();
    ui->correctAnswer->setText(answers["correctAnswer"].toString());
    ui->dummyAnswer1->setText(answers["dummyAnswer1"].toString());
    ui->dummyAnswer2->setText(answers["dummyAnswer2"].toString());
    ui->dummyAnswer3->setText(answers["dummyAnswer3"].toString());

    imagePath = levelObject["imagePath"].toString();
    gearImage = QImage(imagePath);
    QPixmap gearPixmap(QPixmap::fromImage(gearImage));
    int width = ui->imageLabel->width();
    int height = ui->imageLabel->height();
    ui->imageLabel->setPixmap(gearPixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

/**
 * @brief Randomizes the positions of the answers.
 **/
void Level::randomizeAnswers() {
    vector<QRect> geometries;
    // Push back all button positions
    geometries.push_back(ui->correctAnswer->geometry());
    geometries.push_back(ui->dummyAnswer1->geometry());
    geometries.push_back(ui->dummyAnswer2->geometry());
    geometries.push_back(ui->dummyAnswer3->geometry());

    // Shuffle button positions in vector and reassign them
    std::random_shuffle(geometries.begin(), geometries.end());
    ui->correctAnswer->setGeometry(geometries.at(0));
    ui->dummyAnswer1->setGeometry(geometries.at(1));
    ui->dummyAnswer2->setGeometry(geometries.at(2));
    ui->dummyAnswer3->setGeometry(geometries.at(3));
}

///////////////////////////
// Event Handler Methods //
///////////////////////////

void Level::on_hintButton_clicked() {
    QMessageBox hintBox;
    hintBox.setWindowTitle("Hint");
    hintBox.setText(hintText);
    hintBox.setInformativeText(lightbulbText);
    hintBox.exec();
}

void Level::on_submitButton_clicked() {
    emit updateLevelNumber(currentLevel);
    if (ui->correctAnswer->isChecked()) {
        if (currentLevel == 10) {
            emit showWinScreen();
        }
        else {
            emit answerValidation(true);
            emit unlockLevel(currentLevel + 1);
            emit changeDescription(correctAnswerDialogue);
        }
    }
    else {
        emit answerValidation(false);
        emit changeDescription("Please try again. Feel free to make use of the Hint button in the top-right of the screen if you are stuck.");
    }

    // Resetting buttons and UI so that the answer isn't selected when the level loads.
    ui->answerGroup->setExclusive(false);
    ui->correctAnswer->setChecked(false);
    ui->dummyAnswer1->setChecked(false);
    ui->dummyAnswer2->setChecked(false);
    ui->dummyAnswer3->setChecked(false);
    ui->answerGroup->setExclusive(true);
    ui->submitButton->setEnabled(false);
}


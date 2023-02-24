/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the level class.
 **/

#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

namespace Ui {
class Level;
}

class Level : public QWidget {
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    void getLevel(int);

signals:
    void answerValidation(bool);
    void showWinScreen();
    void changeDescription(QString);
    void unlockLevel(int level);
    void updateLevelNumber(int level);

private slots:
    void on_hintButton_clicked();
    void on_submitButton_clicked();

private:
    Ui::Level *ui;
    int currentLevel;
    QImage gearImage;
    QString imagePath;
    QString hintText;
    QString lightbulbText;
    QString correctAnswerDialogue;
    void readLevel(QJsonObject&);
    void randomizeAnswers();
};

#endif // LEVEL_H

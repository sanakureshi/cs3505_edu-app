/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: The is the header file for the answer page.
 **/

#ifndef ANSWERPAGE_H
#define ANSWERPAGE_H

#include <QWidget>

namespace Ui {
class AnswerPage;
}

class AnswerPage : public QWidget {
    Q_OBJECT

public:
    explicit AnswerPage(QWidget *parent = nullptr);
    ~AnswerPage();
    void answerValidation(bool correct);
    void changeDescription(QString description);
    void setLevelValue(int level);

private:
    Ui::AnswerPage *ui;
    int level;



signals:
    void goToLevelSelect();
    void changeLevel(int level);

private slots:
    void on_retryButton_clicked();
    void on_nextLevelButton_clicked();
    void on_levelsButton_clicked();
};

#endif // ANSWERPAGE_H

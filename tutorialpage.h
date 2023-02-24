/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the tutorial page.
 **/

#ifndef TUTORIALPAGE_H
#define TUTORIALPAGE_H

#include <QWidget>

namespace Ui {
class TutorialPage;
}

class TutorialPage : public QWidget {
    Q_OBJECT

public:
    explicit TutorialPage(QWidget *parent = nullptr);
    ~TutorialPage();

signals:
    void showLevel(int);

private slots:
    void on_okButton_clicked();
    void on_nextPageButton_clicked();
    void on_previousPageButton_clicked();

private:
    Ui::TutorialPage *ui;
    int currentPage;
};

#endif // TUTORIALPAGE_H

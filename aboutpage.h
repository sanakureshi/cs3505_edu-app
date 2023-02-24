/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the about page.
 **/

#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>

namespace Ui {
class AboutPage;
}

class AboutPage : public QWidget {
    Q_OBJECT

public:
    explicit AboutPage(QWidget *parent = nullptr);
    ~AboutPage();

signals:
    void showMainMenu();
    void unlockAll();

private slots:
    void on_backButton_clicked();
    void on_unlockAllButton_clicked();

private:
    Ui::AboutPage *ui;
};

#endif // ABOUTPAGE_H

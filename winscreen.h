/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the header file for the win screen.
 **/

#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

namespace Ui {
class WinScreen;
}

class WinScreen : public QWidget
{
    Q_OBJECT

public:
    explicit WinScreen(QWidget *parent = nullptr);
    ~WinScreen();

signals:
    void showMainMenu();
    void newHeightVal(int);

public slots:
    void updateWorld();

private slots:
    void updateHeightVals(int);
    void on_menuButton_clicked();

private:
    Ui::WinScreen *ui;
    b2Body* body;
    b2Vec2 gravity;
    b2World world;
    void setupBox2D();
};

#endif // WINSCREEN_H

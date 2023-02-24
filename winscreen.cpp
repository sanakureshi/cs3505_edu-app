/**
 * @Authors: Sasha Singh, Abby Blatter, Harley Braun, Tyler Porter, Sana Kureshi
 * @Date: December 8th, 2022
 * @Assignment Name: A8 An Educational App
 *
 * @brief: This is the implementation for the win screen, which is an animated splash screen using Box2D
 *         congratulating the user for completing the game.
 **/

#include "winscreen.h"
#include "ui_winscreen.h"

WinScreen::WinScreen(QWidget *parent) : QWidget(parent), ui(new Ui::WinScreen), gravity(0.0f, -10.0f), world(gravity) {
    ui->setupUi(this);

    // Load gear images
    QPixmap gearPixmap(QPixmap::fromImage(QImage("../a8-edu-app-tporterz/images/gear.png")));
    ui->smallGearImage->setPixmap(gearPixmap.scaled(ui->smallGearImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->smallGearImage2->setPixmap(gearPixmap.scaled(ui->smallGearImage2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->smallGearImage3->setPixmap(gearPixmap.scaled(ui->smallGearImage3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->smallGearImage4->setPixmap(gearPixmap.scaled(ui->smallGearImage4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->bigGearImage->setPixmap(gearPixmap.scaled(ui->bigGearImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->bigGearImage2->setPixmap(gearPixmap.scaled(ui->bigGearImage2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->bigGearImage3->setPixmap(gearPixmap.scaled(ui->bigGearImage3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->bigGearImage4->setPixmap(gearPixmap.scaled(ui->bigGearImage4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    setupBox2D();
    updateWorld();
}

WinScreen::~WinScreen() {
    delete ui;
}

void WinScreen::setupBox2D() {
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    bodyDef.fixedRotation = true;
    body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Override the default restitution
    fixtureDef.restitution = 1.0f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
}

void WinScreen::updateWorld() {
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world.Step(timeStep, velocityIterations, positionIterations);

    // Now print the position and angle of the body.
    b2Vec2 position = body->GetPosition();
    updateHeightVals(position.y*25);
    QTimer::singleShot(15, this, &WinScreen::updateWorld);
}

void WinScreen::updateHeightVals(int height) {
    ui->smallGearImage->move(ui->smallGearImage->x(), height);
    ui->smallGearImage2->move(ui->smallGearImage2->x(), height);
    ui->smallGearImage3->move(ui->smallGearImage3->x(), 500 - height);
    ui->smallGearImage4->move(ui->smallGearImage4->x(), 500 - height);
    ui->bigGearImage->move(ui->bigGearImage->x(), height);
    ui->bigGearImage2->move(ui->bigGearImage2->x(), height);
    ui->bigGearImage3->move(ui->bigGearImage3->x(), 500 - height);
    ui->bigGearImage4->move(ui->bigGearImage4->x(), 500 - height);
}

void WinScreen::on_menuButton_clicked() {
    emit showMainMenu();
}


#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"

class ScoreWidget : public QWidget {
    Q_OBJECT
public:
    ScoreWidget(QWidget *parent=0, GamePlay* gp=0);
    ~ScoreWidget();

protected:


private:

    QWidget* parent_;
    GamePlay* myGamePlay;

    QVBoxLayout* l;

    //Labels
    QLabel* hitpointsLabel;
    QLabel* hitpoints;

    QLabel* livesLabel;
    QLabel* lives;

    QLabel* scoreLabel;
    QLabel* score;

public slots:
    void scoreChanged();

};
#endif // SCOREWIDGET_H

#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"

class ScoreWidget : public QWidget {
    Q_OBJECT
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    ScoreWidget(QWidget *parent=0, GamePlay* gp=0);
    /** Destructor*/
    ~ScoreWidget();

protected:


private:
    /** Parent Widget*/
    QWidget* parent_;
    /** Widget for actual game play*/
    GamePlay* myGamePlay;

    /** Main layout*/
    QVBoxLayout* l;


    //=========================================================================
    //Labels
    //=========================================================================
    /** Label for hitpoints*/
    QLabel* hitpointsLabel;
    /** Label that will contain actual hitpoints number*/
    QLabel* hitpoints;

    /** Label for number of lives*/
    QLabel* livesLabel;
    /** Label that will contain actual life counts*/
    QLabel* lives;

    /** Label for score*/
    QLabel* scoreLabel;
    /** Label that will contain the actual score*/
    QLabel* score;

public slots:
    /** Take score update information from the GamePlay widget and
        send to score QLabel.*/
    void scoreChanged();

};
#endif // SCOREWIDGET_H

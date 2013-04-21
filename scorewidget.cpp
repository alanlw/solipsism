#include <iostream>
#include "scorewidget.h"

ScoreWidget::ScoreWidget(QWidget *parent, GamePlay* gp){

    parent_ = parent;
    myGamePlay = gp;
    l = new QVBoxLayout(this);

    //Make my QLabels

    QFont labelFont("Arial", 24, QFont::Bold);

    hitpointsLabel = new QLabel("Hit Points");
    hitpointsLabel->setFont(labelFont);
    hitpoints = new QLabel("000000");

    livesLabel = new QLabel("Lives");
    livesLabel->setFont(labelFont);
    lives = new QLabel("<3<3<3");

    scoreLabel = new QLabel("Score");
    scoreLabel->setFont(labelFont);
    score = new QLabel("000000");



    //Add QLabels to the layout

    l->addWidget(hitpointsLabel);
    l->addWidget(hitpoints);

        // Create a horizontal frame line
        QFrame *line1 = new QFrame( this );
        line1->setFrameStyle( QFrame::HLine | QFrame::Sunken );
        l->addWidget( line1 );

    l->addWidget(livesLabel);
    l->addWidget(lives);

        // Create a horizontal frame line
        QFrame *line2 = new QFrame( this );
        line2->setFrameStyle( QFrame::HLine | QFrame::Sunken );
        l->addWidget( line2 );

    l->addWidget(scoreLabel);
    l->addWidget(score);

}
ScoreWidget::~ScoreWidget(){
    delete l;
}

void ScoreWidget::scoreChanged(){

    //Get the updated score from the GamePlay object that holds the score.
    QString temp = QString::number(myGamePlay->getPlayerHitpoints());
    hitpoints->setText(temp);

    temp = QString::number(myGamePlay->getPlayerLives());
    lives->setText(temp);

    temp = QString::number(myGamePlay->getScore());
    score->setText(temp);


}

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
    hitpoints = new QLabel("");

    livesLabel = new QLabel("Lives");
    livesLabel->setFont(labelFont);
    lives = new QLabel("");

    scoreLabel = new QLabel("Score");
    scoreLabel->setFont(labelFont);
    score = new QLabel("");



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
    QString hearts = "";
    for(int i = 0; i < myGamePlay->getPlayerLives(); i++){
        hearts+= "<3";
    }
    if(myGamePlay->getPlayerLives() == 0){
        hearts = "</3 dead...";
    }
    lives->setText(hearts);

    temp = QString::number(myGamePlay->getScore());
    score->setText(temp);


}

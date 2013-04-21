#include <iostream>
#include "scorewidget.h"

ScoreWidget::ScoreWidget(QWidget *parent){
    std::cout << "Start of ScoreWidget constructor" << std::endl;

    parent_ = parent;
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

    std::cout << "End of ScoreWidget constructor" << std::endl;
}
ScoreWidget::~ScoreWidget(){
    delete l;
}

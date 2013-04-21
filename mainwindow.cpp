#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)  {
    

    myGamePlay = new GamePlay(this);
    myScoreWidget = new ScoreWidget(this, myGamePlay);

    myLabel = new QLabel("Some game controls will go here.");
    mainLayout = new QVBoxLayout;
    gameAndScore = new QHBoxLayout;

    mainLayout->addWidget(myLabel);

    myGamePlay->setFixedHeight(600);
    myGamePlay->setFixedWidth(600);
    gameAndScore->addWidget(myGamePlay);
    gameAndScore->addWidget(myScoreWidget);

    mainLayout->addLayout(gameAndScore);

    setLayout(mainLayout);

    //Connect the ScoreWidget to this
    connect(myGamePlay, SIGNAL(updateScore()), myScoreWidget, SLOT(scoreChanged()));

}
MainWindow::~MainWindow()
{

}
void MainWindow::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Escape){
        cout << "You pressed ESC" << endl;
    }

    switch (e->key()){
    case Qt::Key_W:
        //cout << "W pressed for up." << endl;
        myGamePlay->movePlayer(UP);
        break;
    case Qt::Key_A:
        //cout << "A pressed for left" << endl;
        myGamePlay->movePlayer(LEFT);
        break;
    case Qt::Key_S:
        //cout << "S pressed for down" << endl;
        myGamePlay->movePlayer(DOWN);
        break;
    case Qt::Key_D:
        //cout << "D pressed for right" << endl;
        myGamePlay->movePlayer(RIGHT);
        break;
    default:
        e->ignore(); //do nothing
        return;

    }
}
/*
void MainWindow::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        cout << "Left Mouse Button pressed" << endl;
        myGamePlay->clickAttack(e);
    }

}
*/




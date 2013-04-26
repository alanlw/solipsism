#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)  {
    

    myGamePlay = new GamePlay(this);
    myScoreWidget = new ScoreWidget(this, myGamePlay);

    //We will display player's name here.
    myLabel = new QLabel("");
    connect( myGamePlay, SIGNAL(nameEntered()), this, SLOT(updateMyLabel()));

    startButton = new QPushButton("Start Game", this);
    connect( startButton, SIGNAL(clicked()), myGamePlay, SLOT(launchGame()));

    quitButton = new QPushButton("Quit", this);
    connect( quitButton, SIGNAL(clicked()), qApp, SLOT(quit()) );


    mainLayout = new QVBoxLayout;
    gameAndScore = new QHBoxLayout;
    gameControls = new QHBoxLayout;


    gameControls->addWidget(startButton);
        startButton->setFixedWidth(300);
    gameControls->addWidget(quitButton);
        quitButton->setFixedWidth(300);
    gameControls->addWidget(myLabel);

    mainLayout->addLayout(gameControls);

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
        if(myGamePlay->getGamePaused()){
            cout << "Resuming gameplay." << endl;
            myGamePlay->unPauseGame();
        }
        else{
            cout << "You pressed ESC to pause the game." << endl;
            myGamePlay->pauseGame();
        }

        return;
    }

    if(myGamePlay->getGamePaused()){
        return; //Don't let player move if game is paused.
        // (By another event besides the pause function.)
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

void MainWindow::updateMyLabel(){
    //cout << "Updating label" << endl;
    myLabel->setText("Player name:\n" + myGamePlay->getPlayerName());
}





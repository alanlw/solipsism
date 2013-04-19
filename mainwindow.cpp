#include "mainwindow.h"

MainWindow::MainWindow()  {

    //Load my level
    myLevel = new GameLevel("sample_map01.gif");

    //We need a scene and a view to do graphics in QT
    startMenuScene = new QGraphicsScene();

    gamePlayScene = new QGraphicsScene();

    view = new QGraphicsView( gamePlayScene );


    viewRectX = 0;
    viewRectY = 0;
    view->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);


    /**************************************************************************
      gamePlayScene
      ************************************************************************/

    view->setWindowTitle( "Side Scroller Game");
    view->setBackgroundBrush(*myLevel->getBgImage());

    //Set timer for animation.
    myTimer = new QTimer(this);
    myTimer->setInterval(5);

    //For scrolling of screen
    connect(myTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));

    /**************************************************************************
      startMenuScene
      ************************************************************************/
    quitButton = new QPushButton("Quit");
    startMenuLayout = new QVBoxLayout( this );
    startMenuLayout->addWidget(quitButton);
    connect( quitButton, SIGNAL(clicked()), qApp, SLOT(quit()) );

}
MainWindow::~MainWindow()
{
    delete gamePlayScene;
    delete startMenuScene;

    delete view;

    delete myTimer;

    delete myLevel;
}
void MainWindow::show() {

    myTimer->start();
    //This is how we get our view displayed.
    view->show();
}

/*---------------------------------------------
               Slot Definitions
----------------------------------------------*/

void MainWindow::scrollWindow(){
    if (viewRectX<= myLevel->getBgImage()->width() - WINDOW_MAX_X*2){
        viewRectX++;
        view->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
    }
    else{
        //Once we reach the end of the map, then stop and display start menu for now.
        displayStartMenu();

    }

}

void MainWindow::displayStartMenu(){
    cout << "Timer stopped" << endl;
    myTimer->stop();
    cout << "Scene changed" << endl;
    view->setScene(startMenuScene);
    cout << "Showing this scene" << endl;
    view->setLayout(startMenuLayout);
    view->show();
}

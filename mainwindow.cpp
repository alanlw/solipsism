#include "mainwindow.h"

MainWindow::MainWindow()  {

    //Load my level
    myLevel = new GameLevel("sample_map01.gif");

    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );

    l = new QHBoxLayout( this );
    view->setLayout(l);

    viewRectX = 0;
    viewRectY = 0;
    view->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);

    view->setWindowTitle( "Side Scroller Game");
    view->setBackgroundBrush(*myLevel->getBgImage());

    //Set timer for animation.
    myTimer = new QTimer(this);
    myTimer->setInterval(15);

    //For scrolling of screen
    connect(myTimer, SIGNAL(timeout()), this, SLOT(scrollWindow()));

}
MainWindow::~MainWindow()
{
    delete scene;
    delete view;

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
    viewRectX++;
    view->setSceneRect(viewRectX, viewRectY, WINDOW_MAX_X*2, WINDOW_MAX_Y*2);
}

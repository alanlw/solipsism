#include "mainwindow.h"

MainWindow::MainWindow()  {

    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );

    l = new QHBoxLayout( this );
    view->setLayout(l);

    //This sets the size of the window and gives it a title.
    view->setWindowTitle( "Graphical Tile Puzzle");

}
MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}
void MainWindow::show() {

    //This is how we get our view displayed.
    view->show();
}


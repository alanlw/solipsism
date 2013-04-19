#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QBoxLayout>

#include <QPushButton>
#include <QKeyEvent>
#include <QMouseEvent>

#include "gamelevel.h"
#include "gameplayer.h"

#define WINDOW_MAX_X 300
#define WINDOW_MAX_Y 300


/**
MainWindow (add documentation later)

@author Alan Wong
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /**Constructor*/
    explicit MainWindow(QWidget *parent = 0);
    /**Destructor*/
    ~MainWindow();
    /**Show*/
    void show();

    void displayStartMenu();

protected:
    void keyPressEvent(QKeyEvent *e);
    
private:

    /** To display gameplay */
    QGraphicsScene* gamePlayScene;

    /** To Display Start Menu */
    QGraphicsScene* startMenuScene;
        //Start Menu Components
        /** Quit Button */
        QPushButton* quitButton;


    /** What the user sees */
    QGraphicsView *view;
    /**x coordinate of scrolling view*/
    int viewRectX;
    /**y coordinate of scrolling view*/
    int viewRectY; //I'm probably not going to be updating this.

    /**For animation*/
    QTimer* myTimer;

    /** To nicely arrange my start menu widgets*/
    QVBoxLayout * startMenuLayout ;

    /** Data of player*/
    GamePlayer* myPlayer;

    /** To hold my level data*/
    QVector<GameLevel*> myLevels;
        //Temporary, just to make this easier to test.
        GameLevel * myLevel;



public slots:
    /** Scroll the window according to myTimer*/
    void scrollWindow();


};



#endif // MAINWINDOW_H

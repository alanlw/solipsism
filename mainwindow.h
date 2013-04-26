#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"
#include "scorewidget.h"



/**
MainWindow (add documentation later)

@author Alan Wong
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================

    /** Constructor*/
    explicit MainWindow(QWidget *parent = 0);
    /** Destructor*/
    ~MainWindow();


protected:
    /** Overloaded function to send QKeyEvent to GamePlay widget*/
    void keyPressEvent(QKeyEvent *e);
    
private:
    /** Layout to hold actual gameplay and score*/
    QHBoxLayout* gameAndScore;
    /** GamePlay widget with actual gameplay*/
    GamePlay* myGamePlay;
    /** ScoreWidget that holds scores generated from GamePlay widget*/
    ScoreWidget* myScoreWidget;

    /** Label to display game status messages*/
    QLabel *myLabel;
    /** Layout for game controls*/
    QHBoxLayout* gameControls;
    /** Start Button*/
    QPushButton *startButton;
    /** Quit Button*/
    QPushButton *quitButton;

    /** Main Layout*/
    QVBoxLayout *mainLayout;


};



#endif // MAINWINDOW_H

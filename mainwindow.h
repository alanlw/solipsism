/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"
#include "scorewidget.h"

#include "scoretracker.h"


/**
MainWindow glues all the widgets together and makes sure they interact
with each other properly.

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

    //For PA6
    /** High Score Button*/
    QPushButton *highScoreButton;

    /** Main Layout*/
    QVBoxLayout *mainLayout;

    /** To keep track of High Scores*/
    ScoreTracker* tracker;

 public slots:
    /** Update label with player's name*/
    void updateMyLabel();
    /** Display High Scores*/
    void showHighScores();
    /** Update scores when a player dies*/
    void addPlayerScore();

};



#endif // MAINWINDOW_H

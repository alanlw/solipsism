/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"
/**
  This widget keeps track of the Player's score. It is connected to a GamePlay
  object via MainWindow.
  */
class ScoreWidget : public QWidget {
    Q_OBJECT
public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    ScoreWidget(QWidget *parent=0, GamePlay* gp=0);
    /** Destructor*/
    ~ScoreWidget();

protected:


private:
    /** Parent Widget*/
    QWidget* parent_;
    /** Widget for actual game play*/
    GamePlay* myGamePlay;

    /** Main layout*/
    QVBoxLayout* l;


    //=========================================================================
    //Labels
    //=========================================================================
    /** Label for hitpoints*/
    QLabel* hitpointsLabel;
    /** Label that will contain actual hitpoints number*/
    QLabel* hitpoints;

    /** Label for number of lives*/
    QLabel* livesLabel;
    /** Label that will contain actual life counts*/
    QLabel* lives;

    /** Label for score*/
    QLabel* scoreLabel;
    /** Label that will contain the actual score*/
    QLabel* score;

public slots:
    /** Take score update information from the GamePlay widget and
        send to score QLabel.*/
    void scoreChanged();

};
#endif // SCOREWIDGET_H

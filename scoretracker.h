/*
"Lapse into Solipsism" is a 2D action game.
Copyright (C) <2013> <Alan Wong>

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".
*/

#ifndef SCORETRACKER_H
#define SCORETRACKER_H

#include <fstream>
#include <iostream>
#include <QMap>
#include <string>
#include <QString>

using namespace std;

/**
  Instances of this class are capable of reading in player scores from text
  files as well as writing updated player scores to text files.
**/
class ScoreTracker{

public:
    //=========================================================================
    // Constructors and Destructor
    //=========================================================================
    /** Constructor*/
    ScoreTracker();
    /** Destructor*/
    ~ScoreTracker();

    //=========================================================================
    // Loading and Saving
    //=========================================================================
    /** Read in player scores*/
    void readScores();
    /** Write player scores stored in 'entries' to file.*/
    void writeScores();

    /** Get a QString of the high scores*/
    QString getScoreString();

    /** Add a score to the list of entries*/
    void addScore(int score, QString name);


protected:

private:
    /** Players' High Scores stored as a map*/
    QMap <int, string> entries;
};

#endif // SCORETRACKER_H


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
    /** Constructor*/
    ScoreTracker();
    /** Destructor*/
    ~ScoreTracker();

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


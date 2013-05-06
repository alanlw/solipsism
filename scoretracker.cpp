#include "scoretracker.h"
#include <string>

ScoreTracker::ScoreTracker(){

}
ScoreTracker::~ScoreTracker(){

}
void ScoreTracker::readScores(){
    ifstream fin;
    fin.open("scores.txt"); //Should the user be able to specify which file to use?
    if(!fin.is_open()){
      cout << "File failed to open." << endl;
      return;
    }

    //Temporary variable to store player's score.
    int n;
    fin >> n;

    string s;
    fin >> s;


    if (fin.fail()){
      cout << "Corrupted file, cannot extract data." << endl;
      return;
    }

    //I'll need some while loop here to iterate until I have extracted all
    //appropriate data...

    while(!fin.eof()){
        entries.insert(n, s);
        cout << "Entered: " << n  << " " << s << endl;

        fin >> n;
        fin >> s;
    }

    cout << "Testing to see if readScores() is called." << endl;
    fin.close();
}
void ScoreTracker::writeScores(){

}

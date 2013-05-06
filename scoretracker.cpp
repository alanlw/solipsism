#include "scoretracker.h"
#include <string>
#include <sstream>
#include <iomanip>

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

    /*For now I will just print out the scores I have in my map to confirm
      that they are stored properly. */
    ofstream fout;
    fout.open("scores.txt");

    cout << "In writeScores()" << endl;
    QMapIterator<int, string> i(entries);
    while (i.hasNext()) {
        i.next();
        fout << i.key() << " " << i.value() << endl;
    }

    fout.close();

    /*Okay, now I just have to make sure that when I actually display these
      that they are displayed in descending order.*/

}

QString ScoreTracker::getScoreString(){
    stringstream ss;

    QString m("Hi");
    QMapIterator<int, string> i(entries);

    int j = 0; //A counter, so we at most display 3 top scores.

    i.toBack();
    while (i.hasPrevious() && j < 3) {
        i.previous();
        ss << i.key() << " [" << i.value() << "] " << endl;
        j++;
    }

    string s = ss.str();
    //QString m(ss.str());
    m = ("\n" + QString::fromStdString(s));


    return m;
}

void ScoreTracker::addScore(int score, QString name){
    cout << "Score added: " << score << " [" << name.toStdString() << "] " << endl;
    entries.insert(score, name.toStdString());

    writeScores();
}

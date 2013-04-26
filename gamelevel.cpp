#include "gamelevel.h"
#include "contradictionmonster.h"
GameLevel::GameLevel(){
    bgImage = new QPixmap();
}
GameLevel::GameLevel(QString imageFileName, QString myLevelName){
    bgImage = new QPixmap;

    QString imagePath;
    imagePath = "graphics/maps/";
    imagePath +=imageFileName;
    cout << imagePath.toStdString() << endl;

    if(bgImage->load(imagePath)){
        cout << "Image loaded successfully" << endl;
    }
    else{
        cout << "Image failed to load." << endl;
    }

    levelName = myLevelName;


    counter = 0;
}

GameLevel::~GameLevel(){
    delete bgImage;
}

QPixmap* GameLevel::getBgImage(){
    return bgImage;
}

QVector<Monster*>& GameLevel::getMonsters(){
    return monsters;
}
int GameLevel::getCounter() const{
    return counter;
}
void GameLevel::setCounter(int n){
    counter = n;
}


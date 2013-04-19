#include "gamelevel.h"
GameLevel::GameLevel(){
    bgImage = new QPixmap();
}
GameLevel::GameLevel(QString imageFileName){
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
}

GameLevel::~GameLevel(){
    delete bgImage;
}

QPixmap* GameLevel::getBgImage(){
    return bgImage;
}

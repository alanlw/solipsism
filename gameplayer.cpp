#include "gameplayer.h"

GamePlayer::GamePlayer(){
    testImage = new QPixmap();
    if(testImage->load("graphics/player/MS_Monster_Orange_Mushroom.png")){
        cout << "Image loaded successfully" << endl;
    }
    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*testImage);
}
GamePlayer::~GamePlayer(){

}


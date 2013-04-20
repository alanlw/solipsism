#include "gameplayer.h"

GamePlayer::GamePlayer(){
    testImage = new QPixmap();
    if(testImage->load("graphics/player/brain_in_vat.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*testImage);
    testImage->scaledToWidth(100);
}
GamePlayer::~GamePlayer(){

}

int GamePlayer::getLives() const{
    return lives;
}

int GamePlayer::getHitPoints() const{
    return hitPoints;
}

void GamePlayer::setLives(int n){
    lives = n;
}
void GamePlayer::setHitPoints(int n){
    hitPoints = n;
}

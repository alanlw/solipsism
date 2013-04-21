#include "gameplayer.h"

GamePlayer::GamePlayer(){
    playerImage = new QPixmap();
    if(playerImage->load("graphics/player/brain_in_vat.png")){
        cout << "Image loaded successfully" << endl;
    }

    else{
        cout << "Image failed to load." << endl;
    }
    setPixmap(*playerImage);
    playerImage->scaledToWidth(100);

    lives = 3;
    hitPoints = 100;
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

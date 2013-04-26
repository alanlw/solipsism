#include "menugraphicsitem.h"

MenuGraphicsItem::MenuGraphicsItem(QString fileName){
    menuImage = new QPixmap();

    QString imagePath;
    imagePath = "graphics/menus/";
    imagePath +=fileName;
    //cout << imagePath.toStdString() << endl;
    if(menuImage->load(imagePath)){
        //cout << "Image loaded successfully" << endl;
    }
    else{
        cout << "Image failed to load." << endl;
    }

    setPixmap(*menuImage);
}
MenuGraphicsItem::~MenuGraphicsItem(){

}

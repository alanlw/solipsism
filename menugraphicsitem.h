#ifndef MENUGRAPHICSITEM_H
#define MENUGRAPHICSITEM_H
#include <QGraphicsPixmapItem>
#include <QString>
#include <iostream>

using namespace std;

class MenuGraphicsItem : public QGraphicsPixmapItem{
public:
    MenuGraphicsItem(QString fileName);
    ~MenuGraphicsItem();

protected:

private:
    QPixmap * menuImage;

};

#endif // MENUGRAPHICSITEM_H

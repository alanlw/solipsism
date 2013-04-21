#ifndef ATTACK_H
#define ATTACK_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>

class Attack : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Attack();
    virtual ~Attack();

protected:
    QPixmap* attackImage;

private:

};

#endif // ATTACK_H

#ifndef ATTACK_H
#define ATTACK_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Attack : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    Attack();
    virtual ~Attack();

protected:
    QPixmap* attackImage;
    QTimer* attackTimer;

private:

};

#endif // ATTACK_H

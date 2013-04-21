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

    int getAttackDuration() const;
    int getAttackCountDown() const;

    void setAttackDuration(int n);
    void setAttackCountDown(int n);

protected:
    QPixmap* attackImage;

private:

    int attackDuration;
    int attackCountDown;

};

#endif // ATTACK_H

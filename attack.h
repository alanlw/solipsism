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
    int getAttackDamage() const;

    void setAttackDuration(int n);
    void setAttackCountDown(int n);
    void setAttackDamage(int n);

protected:
    QPixmap* attackImage;

    int attackDuration;
    int attackCountDown;
    int attackDamage;

private:

};

#endif // ATTACK_H

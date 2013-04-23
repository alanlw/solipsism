#ifndef ATTACK_H
#define ATTACK_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Attack : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
    /** Constructor*/
    Attack();
    /** Destructor*/
    virtual ~Attack();
    //=========================================================================
    // Accessors and Mutators
    //=========================================================================

    /** @return Get duration of this Attack*/
    int getAttackDuration() const;
    /** @return Get how much time remains before this Attack is complete*/
    int getAttackCountDown() const;

    /** @return Get amount of damage Attack does to players*/
    int getAttackDamage() const;

    /** Set the duration of Attack*/
    void setAttackDuration(int n);
    /** Set the value of the attackCountDown.
        This can be used to speed up or slow down a particular attack.*/
    void setAttackCountDown(int n);
    /** Set the attackDamage of Attack.
        This can be used to make an attack stronger than usual.*/
    void setAttackDamage(int n);

protected:
    /** Image to be displayed for this attack*/
    QPixmap* attackImage;

    /** Duration of this attack.*/
    int attackDuration;
    /** Amount of time that remains before this attack is complete.*/
    int attackCountDown;
    /** Amount of damage this attack will do to players. */
    int attackDamage;

private:

};

#endif // ATTACK_H

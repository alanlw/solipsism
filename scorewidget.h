#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

class ScoreWidget : public QWidget {
    Q_OBJECT
public:
    ScoreWidget(QWidget *parent=0);
    ~ScoreWidget();
protected:


private:

    QWidget* parent_;
    QVBoxLayout* l;

    //Labels
    QLabel* hitpointsLabel;
    QLabel* hitpoints;

    QLabel* livesLabel;
    QLabel* lives;

    QLabel* scoreLabel;
    QLabel* score;


};
#endif // SCOREWIDGET_H

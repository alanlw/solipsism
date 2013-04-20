#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QLabel>
#include <QBoxLayout>

#include "gameplay.h"

/**
MainWindow (add documentation later)

@author Alan Wong
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /**Constructor*/
    explicit MainWindow(QWidget *parent = 0);
    /**Destructor*/
    ~MainWindow();


protected:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    
private:
    GamePlay* myGamePlay;

    QLabel *myLabel;
    QVBoxLayout *mainLayout;

};



#endif // MAINWINDOW_H

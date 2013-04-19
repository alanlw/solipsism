#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QBoxLayout>
#include <qapplication.h>

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250



/**
MainWindow (add documentation later)

@author Alan Wong
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /**Constructor*/
    explicit MainWindow();
    /**Destructor*/
    ~MainWindow();
    /**Show*/
    void show();

    
private:

    /** To display stuff */
    QGraphicsScene *scene;
    /** To display stuff*/
    QGraphicsView *view;

    /** To nicely arrange my widgets*/
    QHBoxLayout * l ;

public slots:

};



#endif // MAINWINDOW_H

#ifndef QMAIN_H
#define QMAIN_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QDebug>
#include <stack>
#include "litteral/litteral.h"
#include "intermediary.h"
#include "structures/structures.h"
#include "snapshots.h"

class QComputer : public QWidget{
        Q_OBJECT
        QLineEdit * message;
        QTableWidget * vuePile;
        QLineEdit * commande;
        QVBoxLayout * couche;
        Stack* pile;
        Controller * controleur;
    public:
        Stack* getStack(){return pile;}
        explicit QComputer(QWidget * parent = 0);
    public slots:
        void refresh();
        void getNextCommande();
        void keyboardButtonPressed(QAbstractButton* g);
        void sliderMoved(int n);
};


#endif // QMAIN_H

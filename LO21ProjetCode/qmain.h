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
#include <QShortcut>
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
        void setStack(Stack * s) {pile = s;}
        QLineEdit * accessLineEdit() {return commande;}
        ~QComputer(){delete controleur; delete pile;}
    public slots:
        void refresh();
        void getNextCommande();
        void keyboardButtonPressed(QAbstractButton* g);
        void sliderMoved(int n);
        void insertBlank();
};


#endif // QMAIN_H

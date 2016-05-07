#ifndef QMAIN_H
#define QMAIN_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <stack>
#include "litteral.h"
#include "intermediary.h"
#include "structures.h"

class QComputer : public QWidget{
        Q_OBJECT
        QLineEdit * message;
        QTableWidget * vuePile;
        QLineEdit * commande;
        QVBoxLayout * couche;
        Pile* pile;
        Controller * controleur;
    public:
        explicit QComputer(QWidget * parent = 0);
    public slots:
        void refresh();
        void getNextCommande();
};


#endif // QMAIN_H

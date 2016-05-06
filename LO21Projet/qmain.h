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

class QComputer : public QWidget{
        Q_OBJECT
        QLineEdit * message;
        QTableWidget * vuePile;
        QLineEdit * commande;
        QVBoxLayout * couche;
        stack<Litteral> * pile;
        Controleur * controleur;
    public:
        explicit QComputer(QWidget * parent = 0);
    public slots:
        void refresh();
        void getNextCommande();
};


#endif // QMAIN_H

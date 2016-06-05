#ifndef QVAREDITOR_H
#define QVAREDITOR_H

#include <QTableWidget>
#include <QHeaderView>
#include <QDebug>
#include <stack>
#include "litteral/litteral.h"
#include "intermediary.h"
#include "qprogrameditor.h"
#include "structures/identifierManager.h"
#include "snapshots.h"

class QvarEditor : public QWidget{
        Q_OBJECT
        QTableWidget * varView;
        QLineEdit * commandValue;
        QLineEdit * commandIdentifier;
        QPushButton * validation;
        QVBoxLayout * generalView;
        QHBoxLayout * commandView;
        IdentifierManager * idMng;
    public:
        explicit QvarEditor(QWidget * parent = 0);
        IdentifierManager * getIdentifierManager() {return idMng;}
        void setIdentifierManager(IdentifierManager * id){idMng=id;}
    public slots:
        void refresh();
        void getNextCommand();
        void validationButtonPressed();
        void destroyVar();
    signals:
        void stateModification();
};

#endif // QVAREDITOR_H

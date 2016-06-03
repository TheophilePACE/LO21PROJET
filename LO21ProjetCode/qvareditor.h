#ifndef QVAREDITOR_H
#define QVAREDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <stack>
#include "litteral/litteral.h"
#include "intermediary.h"
#include "structures/identifierManager.h"

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
    public slots:
        void refresh();
        void getNextCommand();
        void validationButtonPressed();
        void destroyVar();
    signals:
        void stateModification();
};

#endif // QVAREDITOR_H

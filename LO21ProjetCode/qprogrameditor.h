#ifndef QPROGRAMEDITOR_H
#define QPROGRAMEDITOR_H

#include "structures/identifierManager.h"
#include "intermediary.h"

#include <QWidget>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>

class QprogramEditor : public QWidget{
        Q_OBJECT
        QComboBox * programChoice;
        QTextEdit * programText;
        QPushButton * validation;
        QHBoxLayout * commandView;
        QVBoxLayout * generalView;

        IdentifierManager * prgMng;
    public:
        explicit QprogramEditor(QWidget * parent = 0);
    public slots:
        void choiceProgram(const QString&);
        void saveProgram();
};

#endif // QPROGRAMEDITOR_H

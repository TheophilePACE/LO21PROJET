#ifndef QPROGRAMEDITOR_H
#define QPROGRAMEDITOR_H

#include "structures/identifierManager.h"
#include "intermediary.h"
#include "litteral/litteral.h"
#include "snapshots.h"

#include <QWidget>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QStringList>
#include <QWindow>

class QWindow2 : public QWidget {
public:
    explicit QWindow2(QWidget * parent = 0):QWidget(parent){}
};

class QprogramEditor : public QWidget{
        Q_OBJECT
        QComboBox * programChoice;
        QTextEdit * programText;
        QPushButton * validation;
        QHBoxLayout * commandView;
        QVBoxLayout * generalView;
        IdentifierManager * prgMng;
        QWidget * newWindow;
        QLineEdit * newProgName;
    public:
        explicit QprogramEditor(QWidget * parent = 0);
        void setIdentifierManager(IdentifierManager * id){prgMng=id;}
        QComboBox * accessProgramChoice();
        ~QprogramEditor(){}
    public slots:
        void refresh();
        void choiceProgram(const QString&);
        void saveProgram();
        void newProgram();
        void destroyProgram();
};

#endif // QPROGRAMEDITOR_H

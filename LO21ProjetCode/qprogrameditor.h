#ifndef QPROGRAMEDITOR_H
#define QPROGRAMEDITOR_H

#include "structures/identifierManager.h"
#include "intermediary.h"
#include "litteral/litteral.h"

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

};

class QprogramEditor : public QWidget{
        Q_OBJECT
        QComboBox * programChoice;
        QTextEdit * programText;
        QPushButton * validation;
        QHBoxLayout * commandView;
        QVBoxLayout * generalView;
        IdentifierManager * prgMng;
        QWindow2 * newWindow;
        QLineEdit * newProgName;
    public:
        explicit QprogramEditor(QWidget * parent = 0);
    public slots:
        void refresh();
        void choiceProgram(const QString&);
        void saveProgram();
        void newProgram();
        void destroyProgram();
};

#endif // QPROGRAMEDITOR_H

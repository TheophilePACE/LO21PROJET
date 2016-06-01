#include "qprogrameditor.h"
#include "litteral/litteral.h"
#include <typeinfo>

QprogramEditor::QprogramEditor(QWidget *parent) : QWidget(parent)
{
    QComboBox * programChoice;
    QTextEdit * programText;
    QPushButton * validation;
    QHBoxLayout * commandView;
    QVBoxLayout * generalView;

    IdentifierManager * prgMng;

    prgMng = &(IdentifierManager::getInstance());
    programChoice = new QComboBox();
    programText = new QTextEdit();
    validation = new QPushButton();
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();

    validation->setText("Valider");
    QLabel * text1 = new QLabel;

    text1->setText("Nom Programme");

    QStringList names;
    for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
        if((typeid(*(it.getCurrent().getPValue())))==typeid(Program()))
            names<<toQString(it.getCurrent().getLib()->toString());
    programChoice->addItems(names);
    commandView->addWidget(text1);
    commandView->addWidget(programChoice);
    commandView->addWidget(validation);

    generalView->addLayout(commandView);
    generalView->addWidget(programText);

    setLayout(generalView);

   //Affectation sinaux-slots
   connect(programChoice,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(choiceProgram(const QString&)));
   connect(validation,SIGNAL(clicked()),this,SLOT(saveProgram()));

}

void QprogramEditor::choiceProgram(const QString& s) {
    for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
        if(it.getCurrent().getLib()->toString()==s.toStdString())
            programText->setText(toQString(it.getCurrent().getPValue()->toString()));
}
void QprogramEditor::saveProgram(){

    for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
        if(it.getCurrent().getLib()->toString()==programChoice->currentText().toStdString())
        {
            Program * prog = new Program(programText->toPlainText().toStdString());
            it.getCurrent().setValue(prog);
        }

}

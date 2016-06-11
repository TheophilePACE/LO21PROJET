#include "qprogrameditor.h"
#include "litteral/litteral.h"
#include <typeinfo>

QprogramEditor::QprogramEditor(QWidget *parent) : QWidget(parent)
{
    QPushButton * newProg = new QPushButton();

    newWindow = new QWindow2(parent);
    QHBoxLayout * newWLay = new QHBoxLayout(this);
    QPushButton * saveNewProg = new QPushButton(this);
    saveNewProg->setText("Créer");
    QPushButton * rmProg = new QPushButton(this);
    rmProg->setText("Supprimer");
    newProgName = new QLineEdit(this);
    QLabel * newProgLabel = new QLabel("Nom Programme", this);

    newWLay->addWidget(newProgLabel);
    newWLay->addWidget(newProgName);
    newWLay->addWidget(saveNewProg);
    newWindow->setLayout(newWLay);

    prgMng = &(IdentifierManager::getInstance());
    programChoice = new QComboBox(this);
    programText = new QTextEdit(this);
    validation = new QPushButton(this);
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();

    programChoice->setAccessibleName("programChoice");

    validation->setText("Valider");
    QLabel * text1 = new QLabel();

    text1->setText("Nom Programme");

    newProg->setText("Nouveau");

    QStringList names;
    for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
        if((typeid(*(it.getCurrent().getPValue())))==typeid(Program()))
            names<<toQString(it.getCurrent().getLib()->toString());
    programChoice->addItems(names);

    commandView->addWidget(newProg);
    commandView->addWidget(text1);
    commandView->addWidget(programChoice);
    commandView->addWidget(rmProg);
    commandView->addWidget(validation);

    generalView->addLayout(commandView);
    generalView->addWidget(programText);

    setLayout(generalView);

   //Affectation sinaux-slots
   connect(programChoice,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(choiceProgram(const QString&)));
   connect(validation,SIGNAL(clicked()),this,SLOT(saveProgram()));
   connect(newProg,SIGNAL(clicked()),newWindow,SLOT(show()));
   connect(rmProg,SIGNAL(clicked()),this,SLOT(destroyProgram()));
   connect(saveNewProg,SIGNAL(clicked()),this,SLOT(newProgram()));
}

void QprogramEditor::choiceProgram(const QString& s) {
      for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
         if(it.getCurrent().getLib()->toString()==s.toStdString())
            programText->setText(toQString(it.getCurrent().getPValue()->toString()));
}
void QprogramEditor::saveProgram(){
    try {
        if(programChoice->count()==0)
            throw ComputerException("Pas de programme sélectionné");
        if(programText->toPlainText().contains('[') || programText->toPlainText().contains(']') || programText->toPlainText().contains('_'))
            throw ComputerException("Caractères Interdits dans un Programme : '[', ']', '_'");
        for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
            if(it.getCurrent().getLib()->toString()==programChoice->currentText().toStdString())
            {
                SnapshotManager * s = &(SnapshotManager::getInstance());
                s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
                Program * prog = new Program(programText->toPlainText());
                it.getCurrent().setValue(prog);
            }
    }
    catch (ComputerException exp) {
            ExceptionWindow(exp.getInfo());
    }
    refresh();
}
void QprogramEditor::newProgram(){
    GeneralManager * mng = &(GeneralManager::getInstance());
    Parser p = Parser::getInstance();
    try {
        if(newProgName->text()=="")
            throw ComputerException("Nom Vide !");
        if(p.getType(newProgName->text()) != "Atom")
            throw ComputerException("Nom non Valide !");
        for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
            if(it.getCurrent().getLib()->toString()==newProgName->text().toStdString())
                throw ComputerException("Nom Existe déjà");
        SnapshotManager * s = &(SnapshotManager::getInstance());
        s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
        prgMng->addIdentifier(newProgName->text(),mng->createProgram("")->getPLit());
    }
    catch (ComputerException exp) {
            ExceptionWindow(exp.getInfo());
    }
    newProgName->setText("");
    newWindow->hide();
    refresh();
}

void QprogramEditor::refresh(){
    CheckButtons();
    setIdentifierManager(&(IdentifierManager::getInstance()));
    QStringList names;
    for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
        if((typeid(*(it.getCurrent().getPValue())))==typeid(Program))
            names<<toQString(it.getCurrent().getLib()->toString());
    programChoice->clear();
    programChoice->addItems(names);
}
void QprogramEditor::destroyProgram(){
    IdentifierManager::Iterator it=prgMng->getIterator();
    unsigned int nbElements = 0;
    while((!it.isDone()) && (it.getCurrent().getLib()->toString()!=programChoice->currentText().toStdString())) {
        nbElements++;
        it.next();
    }
    if(nbElements!=prgMng->size()){
        SnapshotManager  * s = &(SnapshotManager::getInstance());
        s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
        prgMng->removeIdentifier(it.getCurrent());
    }
    refresh();
}
QComboBox * QprogramEditor::accessProgramChoice() {
    return programChoice;
}

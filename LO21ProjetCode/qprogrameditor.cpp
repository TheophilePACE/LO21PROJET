#include "qprogrameditor.h"
#include "litteral/litteral.h"
#include <typeinfo>

QprogramEditor::QprogramEditor(QWidget *parent) : QWidget(parent)
{
    QPushButton * newProg = new QPushButton;

    newWindow = new QWindow2;
    QHBoxLayout * newWLay = new QHBoxLayout();
    QPushButton * saveNewProg = new QPushButton;
    saveNewProg->setText("Créer");
    QPushButton * rmProg = new QPushButton;
    rmProg->setText("Supprimer");
    newProgName = new QLineEdit;
    QLabel * newProgLabel = new QLabel("Nom Programme");

    newWLay->addWidget(newProgLabel);
    newWLay->addWidget(newProgName);
    newWLay->addWidget(saveNewProg);
    newWindow->setLayout(newWLay);

    prgMng = &(IdentifierManager::getInstance());
    programChoice = new QComboBox();
    programText = new QTextEdit();
    validation = new QPushButton();
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();

    validation->setText("Valider");
    QLabel * text1 = new QLabel;

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
            throw "Pas de programme sélectionné";
        if(programText->toPlainText().contains('[') || programText->toPlainText().contains(']') || programText->toPlainText().contains('_'))
            throw "Caractères Interdits dans un Programme : '[', ']', '_'";
        for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
            if(it.getCurrent().getLib()->toString()==programChoice->currentText().toStdString())
            {
                Program * prog = new Program(programText->toPlainText().toStdString());
                it.getCurrent().setValue(prog);
            }
    }
    catch (char const* s) {
            ExceptionWindow(s);
    }
    refresh();
}
void QprogramEditor::newProgram(){
    GeneralManager mng = GeneralManager::getInstance();
    Parser p = Parser::getInstance();
    try {
        if(newProgName->text()=="")
            throw "Nom Vide !";
        if(p.getType(newProgName->text()) != "Atom")
            throw "Nom non Valide !";
        for(IdentifierManager::Iterator it = prgMng->getIterator(); !it.isDone(); it.next())
            if(it.getCurrent().getLib()->toString()==newProgName->text().toStdString())
                throw "Nom Existe déjà";
        prgMng->addIdentifier(newProgName->text().toStdString(),mng.createProgram("")->getPLit());
    }
    catch (char const* s) {
            ExceptionWindow(s);
    }
    newProgName->setText("");
    newWindow->hide();
    refresh();
}

void QprogramEditor::refresh(){
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
    if(nbElements!=prgMng->size())
        prgMng->removeIdentifier(it.getCurrent());
    refresh();
}


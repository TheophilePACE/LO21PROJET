#include "qvareditor.h"
#include "litteral/litteral.h"
#include <typeinfo>

QvarEditor::QvarEditor(QWidget *parent) : QWidget(parent)
{
    idMng = &(IdentifierManager::getInstance());
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();
    varView = new QTableWidget(1,1,this);
    commandValue = new QLineEdit;
    commandIdentifier = new QLineEdit;
    validation = new  QPushButton;

    validation->setText("Valider");
    QLabel * text1 = new QLabel;
    QLabel * text2 = new QLabel;

    QPushButton * rmVar = new QPushButton;
    rmVar->setText("Supprimer");
    text1->setText("Nom");
    text2->setText("Valeur");
    commandView->addWidget(text1);
    commandView->addWidget(commandIdentifier);
    commandView->addWidget(text2);
    commandView->addWidget(commandValue);
    commandView->addWidget(validation);
    commandView->addWidget(rmVar);

    QStringList numberList;
    unsigned int NbElements =0;

    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next(), ++NbElements)
    {
        if(typeid(*(it.getCurrent().getPValue()))!=typeid(Program)) {
            numberList<<toQString(it.getCurrent().getLib()->toString());
            varView->setItem(NbElements-1,0,new QTableWidgetItem(""));
        }

    }
    //affectation de la liste de labels au header vertical

    varView->setVerticalHeaderLabels(numberList);
    //varView->setFixedHeight(idMng->size()*varView->rowHeight(0)+2);
    varView->setFixedHeight(6*varView->rowHeight(0)+2);
    generalView->addWidget(varView);
    varView->setStyleSheet("background : cyan; color : white");
    varView->verticalHeader()->setStyleSheet("color: orange");

    varView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    varView->horizontalHeader()->setVisible(false);
    varView->horizontalHeader()->setStretchLastSection(true);
    //controleur = new Controller(GeneralManager::getInstance(),*pile);

    //this->addLayout(couche);
    generalView->addLayout(commandView);
    setLayout(generalView);

   //Affectation sinaux-slots
   connect(validation,SIGNAL(clicked()),this,SLOT(validationButtonPressed()));
   connect(this,SIGNAL(stateModification()),this,SLOT(refresh()));
   connect(rmVar,SIGNAL(clicked()),this,SLOT(destroyVar()));

}
void stateModification(){

}

void QvarEditor::refresh()
{
    CheckButtons();
    //setIdentifierManager(&(IdentifierManager::getInstance()));
    idMng = &(IdentifierManager::getInstance());
    unsigned int NbElements =0;
    QStringList numberList;
    varView->setRowCount(idMng->sizeAtoms());
    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next())
    {
        if(typeid(*(it.getCurrent().getPValue()))!=typeid(Program)) {
            numberList<<toQString(it.getCurrent().getLib()->toString());
            varView->setItem(NbElements,0,new QTableWidgetItem(toQString(it.getCurrent().getPValue()->toString())));
             ++NbElements;
        }
    }
    commandIdentifier->setText("");
    commandValue->setText("");
    varView->setVerticalHeaderLabels(numberList);
}

void QvarEditor::validationButtonPressed() {
        if((commandIdentifier->text().toStdString() != "") && (commandValue->text().toStdString() != ""))
        {
            try {
                getNextCommand();
                stateModification();
            }
            catch (char const* s){
                ExceptionWindow(s);
            }
            refresh();
        }
}
void QvarEditor::getNextCommand(){

    idMng = &(IdentifierManager::getInstance());
    IdentifierManager::Iterator it = idMng->getIterator();
    unsigned int NbElements =0;
    Parser p = Parser::getInstance();

    if(p.getType(commandIdentifier->text()) != "Atom")
        throw "Type Error of the identifier";
    while(!it.isDone() &&
          it.getCurrent().getLib()->toString()!=commandIdentifier->text().toStdString())
    {
        it.next(); ++NbElements;
    }
    std::string type = p.getType(commandValue->text());
    if(type!="Atom" && type !="Program")
    {
        GeneralManager * mng = &(GeneralManager::getInstance());

        if(NbElements!=idMng->size())
            if(typeid(*(it.getCurrent().getPValue()))!=typeid(Program)) {
                SnapshotManager * s = &(SnapshotManager::getInstance());
                s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
                it.getCurrent().setValue(mng->createItem(commandValue->text())->getPLit());
            }

            else
                throw "Modification d'un' Programme Impossible d'ici";
        else {
            SnapshotManager * s = &(SnapshotManager::getInstance());
            s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
            idMng->addIdentifier(commandIdentifier->text().toStdString(),mng->createItem(commandValue->text())->getPLit());
        }

    }
    else
        throw "Type Error Creation Var";

}
void QvarEditor::destroyVar(){
    IdentifierManager * prgMng = &(IdentifierManager::getInstance());
    IdentifierManager::Iterator it= prgMng->getIterator();
    unsigned int nbElements = 0;
    while((!it.isDone()) && (it.getCurrent().getLib()->toString()!=commandIdentifier->text().toStdString())) {
        nbElements++;
        it.next();
    }
    if(nbElements!=prgMng->size()) {
        SnapshotManager * s = &(SnapshotManager::getInstance());
        s->addSnapshot(s->getCurrentState()->getStack(), &(IdentifierManager::getInstance()));
        prgMng->removeIdentifier(it.getCurrent());
    }
    refresh();
}

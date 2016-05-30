#include "qvareditor.h"
#include "litteral/litteral.h"
#include <typeinfo>

QvarEditor::QvarEditor(QWidget *parent) : QWidget(parent)
{
    idMng = new  IdentifierManager;
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();
    varView = new QTableWidget(4,1,this);
    commandValue = new QLineEdit;
    commandIdentifier = new QLineEdit;
    validation = new  QPushButton;

    commandView->addWidget(commandIdentifier);
    commandView->addWidget(commandValue);
    commandView->addWidget(validation);

    QStringList numberList;
    unsigned int NbElements =0;

    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next(), ++NbElements)
    {
        if((typeid(*(it.getCurrent().getPValue())).name())!="Program") {
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

}
void stateModification(){

}

void QvarEditor::refresh()
{
    unsigned int NbElements =0;
    QStringList numberList;
    varView->setRowCount(NbElements);
    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next())
    {
        numberList<<toQString(it.getCurrent().getLib()->toString());
        varView->setItem(NbElements-1,0,new QTableWidgetItem(toQString(it.getCurrent().getPValue()->toString())));
         ++NbElements;
    }

    varView->setVerticalHeaderLabels(numberList);
}

void QvarEditor::validationButtonPressed() {
        if((commandIdentifier->text().toStdString() != "") && (commandValue->text().toStdString() != ""))
            getNextCommand();
        stateModification();
        commandIdentifier->setText("");
        commandValue->setText("");
}
void QvarEditor::getNextCommand(){
    IdentifierManager::Iterator it = idMng->getIterator();
    unsigned int NbElements =0;
    while(!it.isDone() &&
          it.getCurrent().getLib()->toString()!=commandValue->text().toStdString())
    {
        it.next(); ++NbElements;
    }
    if(NbElements!=idMng->size())
    {
        Parser p = Parser::getInstance();
        GeneralManager Mng = GeneralManager::getInstance();
        std::string type = p.getType(commandValue->text());
        if(type=="Integer"||type=="Rationnal"||type=="Real"||type=="Atom"||type=="Expression")
            it.getCurrent().setValue(Mng.createSimpleItem(commandValue->text())->getPLit());
        else
            throw "Type Error";
    }
    else
    {
        Parser p = Parser::getInstance();
        GeneralManager mng = GeneralManager::getInstance();
        std::string type = p.getType(commandValue->text());
        if(type=="Integer"||type=="Rationnal"||type=="Real"||type=="Atom"||type=="Expression")
        {
            IdentifierManager::getInstance().addIdentifier(commandIdentifier->text().toStdString(),mng.createSimpleItem(commandValue->text())->getPLit());
        }
        else
            throw "Type Error";
    }
}

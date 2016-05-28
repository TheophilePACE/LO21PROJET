#include "qvareditor.h"
#include "litteral/litteral.h"

QvarEditor::QvarEditor(QWidget *parent) : QWidget(parent)
{
    idMng = new  IdentifierManager;
    generalView = new QVBoxLayout(this);
    commandView = new QHBoxLayout();
    generalView->addLayout(commandView);
    varView = new QTableWidget;
    commandValue = new QLineEdit;
    commandIdentifier = new QLineEdit;
    validation = new  QPushButton;

    commandView->addWidget(commandIdentifier);
    commandView->addWidget(commandValue);
    commandView->addWidget(validation);

    setVueVarView();
    //controleur = new Controller(GeneralManager::getInstance(),*pile);

    //this->addLayout(couche);
    setLayout(generalView);
    generalView->addLayout(commandView);

   //Affectation sinaux-slots
   connect(validation,SIGNAL(stateModification()),varView,SLOT(refresh()));

}
void QvarEditor::refresh()
{
    unsigned int NbElements =0;
    QStringList numberList;
    //effacer tout
    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next(), ++NbElements)
    {
        it.getCurrent().setLib(*(new Atom(std::string(" "))));
        it.getCurrent().setValue(new Integer(0));
    }
    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next(), ++NbElements)
    {
        numberList[NbElements] = toQString(it.getCurrent().getLib()->toString());
        varView->item(NbElements-1,0)->setText(toQString(it.getCurrent().getPValue()->toString()));
    }
}

void QvarEditor::setVueVarView(){
    QTableWidget * tab = new QTableWidget(idMng->size(),1,this);
    //liste de labels
    delete varView;
    varView = tab;
    QStringList numberList;
    unsigned int NbElements =0;
    for(IdentifierManager::Iterator it = idMng->getIterator(); !it.isDone(); it.next(), ++NbElements)
    {
        numberList[NbElements]=toQString(it.getCurrent().getLib()->toString());
        varView->setItem(NbElements-1,0,new QTableWidgetItem(""));
    }
    //affectation de la liste de labels au header vertical

    varView->setVerticalHeaderLabels(numberList);
    varView->setFixedHeight(idMng->size()*varView->rowHeight(0)+2);
    generalView->addWidget(varView);
    varView->setStyleSheet("background : cyan; color : white");
    varView->verticalHeader()->setStyleSheet("color: orange");

    varView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    varView->horizontalHeader()->setVisible(false);
    varView->horizontalHeader()->setStretchLastSection(true);
}

void QvarEditor::validationButtonPressed(QPushButton* g) {
        if((commandIdentifier->text().toStdString() != "") && (commandValue->text().toStdString() != ""))
            getNextCommand();
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
        it.getCurrent().setLib(*(new Atom(commandValue->text().toStdString())));
}

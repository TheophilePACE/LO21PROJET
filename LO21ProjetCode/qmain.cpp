#include "qmain.h"
#include "litteral/litteral.h"


QComputer::QComputer(QWidget *parent) : QWidget(parent)
{
    message = new QLineEdit(this);
    pile = new Stack;
    couche = new QVBoxLayout(this);
    commande = new QLineEdit(this);
    vuePile = new QTableWidget(pile->getNbItemsDisplayed(),1,this);
    couche->addWidget(message);

    QStringList numberList;
    for(unsigned int i=pile->getNbItemsDisplayed();i>0;i--)
    {
        QString str = QString::number(i);
        numberList<<str;
        vuePile->setItem(i-1,0,new QTableWidgetItem(""));
    }
    //affectation de la liste de labels au header vertical

    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(pile->getNbItemsDisplayed()*vuePile->rowHeight(0)+2);
    couche->addWidget(vuePile);
    vuePile->setStyleSheet("background : magenta; color : white");
    vuePile->verticalHeader()->setStyleSheet("color: orange");

    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);
    controleur = new Controller(GeneralManager::getInstance(),pile);

    couche->addWidget(commande);

    //this->addLayout(couche);
    setLayout(couche);

    // color
    message->setStyleSheet("background : blue; color : yellow");
    message->setReadOnly(true);

   //Affectation sinaux-slots
   connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));

    //Message
    pile->setMessage("Bienvenue !");

    //focus a la barre de cmd
    commande->setFocus();
}
void QComputer::refresh()
{
    CheckButtons();
    message->setText(pile->getMessage());
    //effacer tout
    for(unsigned int i=0;i<pile->getNbItemsDisplayed();i++)
        vuePile->item(i,0)->setText("");
    //mettre a jour
    unsigned int NbElements =0;
    for(Stack::iterator it = pile->begin(); it!=pile->end() && NbElements<pile->getNbItemsDisplayed(); ++it, ++NbElements)
        vuePile->item(pile->getNbItemsDisplayed()-1-NbElements,0)->setText(toQString((*it)->toString()));
}

void QComputer::getNextCommande()
{
    controleur->setStack(pile);
    pile->setMessage("");
    //recuperation du texte de la ligne de commande
    controleur->command(commande->text());
    controleur->setStack(pile);
    refresh();
}
void QComputer::keyboardButtonPressed(QAbstractButton* g) {
        if(g->text().toStdString() == "BACK")
            commande->setText(commande->text().remove(commande->text().size()-1,1));
        else if(g->text().toStdString() == "ENTER")
            getNextCommande();
        else
            commande->setText(commande->text()+g->text());
}
void QComputer::insertBlank() {
    commande->setText(commande->text() + " ");
}
void QComputer::sliderMoved(int n) {
    pile->setNbItemsDisplayed(n);
    vuePile->setRowCount(n);

    QStringList numberList;
    for(unsigned int i=pile->getNbItemsDisplayed();i>0;i--)
    {
        QString str = QString::number(i);
        str += ":";
        numberList<<str;
        vuePile->setItem(i-1,0,new QTableWidgetItem(""));
    }
    vuePile->setVerticalHeaderLabels(numberList);
    refresh();
}


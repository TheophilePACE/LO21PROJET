#include "qmain.h"
#include "litteral.h"


QComputer::QComputer(QWidget *parent) : QWidget(parent)
{
    message = new QLineEdit(this);
    pile = new Pile;
    couche = new QVBoxLayout(this);
    commande = new QLineEdit(this);

    couche->addWidget(message);
    couche->addWidget(commande);
    setVuePile();
    controleur = new Controller(GeneralManager::getInstance(),*pile);

    //this->addLayout(couche);
    setLayout(couche);

    // color
    message->setStyleSheet("background : blue; color : yellow");
    message->setReadOnly(true);

   //Affectation sinaux-slots
   connect(pile,SIGNAL(stateModification()),this,SLOT(refresh()));
   connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));

    //Message
    pile->setMessage("Bienvenue !");

    //focus a la barre de cmd
    commande->setFocus();
}
void QComputer::refresh()
{
    message->setText(pile->getMessage());
    //effacer tout
    for(unsigned int i=0;i<pile->getNbItemsDisplayed();i++)
        vuePile->item(i,0)->setText("");
    //mettre a jour
    unsigned int NbElements =0;
    for(Pile::iterator it = pile->begin(); it!=pile->end() && NbElements<pile->getNbItemsDisplayed(); ++it, ++NbElements)
        vuePile->item(pile->getNbItemsDisplayed()-1-NbElements,0)->setText(toQString((*it)->toString()));
}

void QComputer::setVuePile(){
    QTableWidget * tab = new QTableWidget(pile->getNbItemsDisplayed(),1,this);
    //liste de labels
    delete vuePile;
    vuePile = tab;
    QStringList numberList;
    for(unsigned int i=pile->getNbItemsDisplayed();i>0;i--)
    {
        QString str = QString::number(i);
        str += ":";
        vuePile->setItem(i-1,0,new QTableWidgetItem(""));
    }
    //affectation de la liste de labels au header vertical

    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(pile->getNbItemsDisplayed()*vuePile->rowHeight(0)+2);
    couche->addWidget(vuePile);
    vuePile->setStyleSheet("background : cyan; color : white");
    vuePile->verticalHeader()->setStyleSheet("color: orange");

    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);
    vuePile->horizontalHeader()->ResizeToContents();
}

void QComputer::getNextCommande()
{
    pile->setMessage("");
    //recuperation du texte de la ligne de commande
    QString c = commande->text();
    //extraction de chaqye element de la ligne
    QTextStream stream(&c);
    QString com;
    do {
        stream >> com; //extraction d'un elem
        //envoyer la commande au controller
        if(com!="") controleur->command(com);
    } while(com!="");
    commande->setText("");
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
void QComputer::sliderMoved(int n) {
    pile->setNbItemsDisplayed(n);
    setVuePile();
    refresh();
}


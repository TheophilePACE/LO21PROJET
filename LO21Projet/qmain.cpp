#include "qmain.h"
#include "litteral.h"


QComputer::QComputer(QWidget *parent) : QWidget(parent)
{
    message = new QLineEdit(this);
    pile = new <Litteral>stack;
    vuePile = new QTableWidget(pile->getNbItemsToAffiche(),1,this);
    couche = new QVBoxLayout(this);
    commande = new QLineEdit(this);

    controleur = new Controleur(GeneralManager::getInstance(), *pile);

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);

    //this->addLayout(couche);
    setLayout(couche);

    //Titre
    this->setWindowTitle("UTComputer");

    // color
    message->setStyleSheet("background : blue; color : yellow");
    message->setReadOnly(true);
    vuePile->setStyleSheet("background : cyan; color : white");
    vuePile->verticalHeader()->setStyleSheet("color: orange");

    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);

    //liste de labels
    QStringList numberList;
    for(unsigned int i=4;i>0;i--)
    {
        QString str = QString::number(i);
        str += ":";
        vuePile->setItem(i-1,0,new QTableWidgetItem(""));
    }
    //affectation de la liste de labels au header vertical

    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(4*vuePile->rowHeight(0)+2);

       //Affectation sinaux-slots
       connect(pile,SIGNAL(modificationEtat()),this,SLOT(refresh()));
       connect(commande,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));

    //Message
    //pile->setMessage("Bienvenue !");

    //focus a la barre de cmd
    commande->setFocus();

    /*QLineEdit * message;
    QTableWidget * vuePile;
    QLineEdit * commande;
    QVBoxLayout * couche;
    Pile * pile;
    Controleur * controleur;*/
}
void QComputer::refresh()
{
   // message->setText(pile->getMessage());
    //effacer tout
    for(unsigned int i=0;i<4;i++)
        vuePile->item(i,0)->setText("");
    //mettre a jour
    unsigned int NbElements =0;
    for(Pile::iterator it = pile->begin(); it!=pile->end() && NbElements<pile->getNbItemsToAffiche(); ++it, ++NbElements)
        vuePile->item(pile->getNbItemsToAffiche()-1-NbElements,0)->setText((*it).toString());
}

void QComputer::getNextCommande()
{
    //pile->setMessage("");
    //recuperation du texte de la ligne de commande
    QString c = commande->text();
    //extraction de chaqye element de la ligne
    QTextStream stream(&c);
    QString com;
    do {
        stream >> com; //extraction d'un elem
        //envoyer la commande au controller
        if(com!="") controleur->commande(com);
    } while(com!="");
    commande->setText("");
}


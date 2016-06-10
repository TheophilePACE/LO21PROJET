#ifndef GENERALMANAGER_H
#define GENERALMANAGER_H

#include "parser.h"

class Litteral;
class Item;


/*!
 * \brief The GeneralManager class : gère la création des littérales.
 * Cette classe gère les littérales qui constituent les éléments pointés par les items de la pile.
 */
class GeneralManager {
    Litteral** litterals;
    ///nombre d'éléments dans la pile.
    unsigned int nb;
    ///Nombre d'éléments pouvant être accueuilli par la pile. Peut être augmenté par increaseCap.
    unsigned int max;
    ///Augmente la taille de la pile quand le nb max d'item est atteint.
    void increaseCap();
    ///Constructeur sans éléments. la pile est déclarée au démarage du programme.
    /// Ce constructeur est privé, on ne peut obtenir qu'un seul GenManager : cette classe répond au design pattern Singleton.
    GeneralManager():litterals(nullptr),nb(0),max(0){}
    ///Implémentation du design pattern Singleton.
    struct Singleton{
        GeneralManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };

    static Singleton sing;
public:
    ///Obtenir l'unique instance du GeneralManager. Cette fonction ne peut instancier la classe qu'une seule fois.
    static GeneralManager& getInstance();
    ///Ajout d'un item sur la pile. L'ajout va générer un item
    void addLitteral(Litteral * const);
    void removeLitteral(Litteral *);
    ~GeneralManager();
    static void freeInstance();
    Item * createItem(QString s);
    Item * createProgram(QString s);
    Item * createSimpleItem(QString s); //factoriser la création de numeric
    std::string getTypeLit(QString s);
};

#endif // GENERALMANAGER_H

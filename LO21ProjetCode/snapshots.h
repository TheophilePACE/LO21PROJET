#ifndef SNAPSHOTS_H
#define SNAPSHOTS_H

#include "structures/stack.h"
#include "structures/identifierManager.h"
#include "structures/computerException.h"

/*! \name      Un snaphshot est une copie de la pile à un instant précis.
 * Les snapshots permettent d'annuler et de refaire des opérations.
 * Il contient donc une pile pour sauvegarder l'état de la pile, ainsi qu'un Identifier Manager.
 * Ce dernier sauvegarde les Identifiers enregistrés à ce moment.
*
*/

class Snapshot {
    ///Pointe vers une copie de la pile sauvegardée par le snapshot.
    Stack * stack;
    ///Pointe vers la cpoie du tableau des Identifiers
    IdentifierManager * idMng;
public:

    Snapshot(Stack *st, IdentifierManager* im):stack(new Stack(*st)),idMng(new IdentifierManager(*im)){}
    ~Snapshot();
    ///Permet de revenir à la version de la pile sauvegardée par le snaphshot.
    Stack * getStack(){return stack;}
    IdentifierManager * getIdManager(){return idMng;}
};

/*! \name      Cette classe gère les snapshots.
 * Les Snapshot sont gérés sous la forme d'un tableau de pointeurs sur snaphshots.
 *
*/

class SnapshotManager {
    Snapshot ** snapshots;
    ///Désigne le dernier snapshot sauvegardé. C'est donc le snapshot précédant qui sera restauré si on undo.(respectivement, suivant si on redo)
    unsigned int currentState;
    unsigned int nb;

    unsigned int maxi;
    void increaseCap();
    SnapshotManager():snapshots(nullptr),currentState(0),nb(0),maxi(0){}
    struct Singleton{
        SnapshotManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    ~SnapshotManager();
    void addSnapshot(Stack * st, IdentifierManager * im);
    ///Le snapshot currentState est remplacé par une sauvegarde de la pile et du IdentifiersManager dans son état actuel.
    void updateCurrentSnapshot(Stack * st, IdentifierManager * im);
    /*! \name      Tests pour savoir si la pile permet un redo/undo :
    */
    //@{
    bool redoPossible() { if(nb!=0) return currentState<nb-1; else return false;}
    bool undoPossible() {return currentState>0;}
    //@}
    ///Renvoi le snapshot "avant"après" la dernière operation
    Snapshot * redo() {if (!(redoPossible())) throw ComputerException("Erreur : Pas d'état suivant"); return snapshots[++currentState];}
    ///Renvoi le snapshot réalisé avant la deniere operation
    Snapshot * undo() {if (!(undoPossible())) throw ComputerException("Erreur : Pas d'état précédent"); return snapshots[--currentState];}
    Snapshot * getCurrentState() const {return snapshots[currentState];}
    static SnapshotManager& getInstance();
    static void freeInstance();
};

#endif // SNAPSHOTS_H

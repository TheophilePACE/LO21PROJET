#ifndef SNAPSHOTS_H
#define SNAPSHOTS_H

#include "structures/stack.h"
#include "structures/identifierManager.h"
#include "structures/computerException.h"

class Snapshot {
    Stack * stack;
    IdentifierManager * idMng;
public:

    Snapshot(Stack *st, IdentifierManager* im):stack(new Stack(*st)),idMng(new IdentifierManager(*im)){}
    ~Snapshot();
    Stack * getStack(){return stack;}
    IdentifierManager * getIdManager(){return idMng;}
};

class SnapshotManager {
    Snapshot ** snapshots;
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
    void updateCurrentSnapshot(Stack * st, IdentifierManager * im);
    bool redoPossible() { if(nb!=0) return currentState<nb-1; else return false;}
    bool undoPossible() {return currentState>0;}
    Snapshot * redo() {if (!(redoPossible())) throw ComputerException("Pas d'état suivant"); return snapshots[++currentState];}
    Snapshot * undo() {if (!(undoPossible())) throw ComputerException("Pas d'état précédent"); return snapshots[--currentState];}
    Snapshot * getCurrentState() const {return snapshots[currentState];}
    static SnapshotManager& getInstance();
    static void freeInstance();
};

#endif // SNAPSHOTS_H

#ifndef SNAPSHOTS_H
#define SNAPSHOTS_H

#include "structures/stack.h"
#include "structures/identifierManager.h"

class Snapshot {
    Stack * stack;
    IdentifierManager * idMng;
public:
    Snapshot(Stack * st, IdentifierManager * im):stack(st),idMng(im){}
    Stack * getStack(){return stack;}
    IdentifierManager * getIdManager(){return idMng;}
};

class SnapshotManager {
    Snapshot ** snapshots;
    unsigned int currentState;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    SnapshotManager():snapshots(nullptr),currentState(0),nb(0),max(0){}
    struct Singleton{
        SnapshotManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    ~SnapshotManager(){}
    void addSnapshot(Stack * st, IdentifierManager * im);
    bool redoPossible() {return currentState<nb;}
    bool undoPossible() {return currentState>1;}
    Snapshot * redo() {if (redoPossible()) throw "Pas d'état suivant"; return snapshots[++currentState];}
    Snapshot * undo() {if (undoPossible()) throw "Pas d'état précédent"; return snapshots[--currentState];}
    Snapshot * getCurrentState() const {return snapshots[currentState];}
    static SnapshotManager& getInstance();
    static void freeInstance();
};

#endif // SNAPSHOTS_H

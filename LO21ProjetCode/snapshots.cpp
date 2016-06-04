#include "snapshots.h"

void SnapshotManager::increaseCap() {
    max = max*2+1;
    Snapshot ** newtab = new Snapshot*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=snapshots[i];
    Snapshot ** old = snapshots;
    snapshots = newtab;
    /*for(unsigned int i=0;i<nb;i++)
        delete old[i];
    delete[] old;*/
}

void SnapshotManager::addSnapshot(Stack * st, IdentifierManager * im) {
    Snapshot * newsnap = new Snapshot(st,im);
    if(nb==max)
        increaseCap();
    if(nb==0)
        snapshots[0]=newsnap;
    else {
        for(unsigned int i=currentState+1;i<nb+1;i++)
            snapshots[i+1]=snapshots[i];
        snapshots[++currentState]=newsnap;
    }
    nb++;
}

SnapshotManager::Singleton SnapshotManager::sing=SnapshotManager::Singleton();
SnapshotManager& SnapshotManager::getInstance(){
    if(sing.instance==nullptr) sing.instance = new SnapshotManager;
    return *sing.instance;
}

void SnapshotManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}


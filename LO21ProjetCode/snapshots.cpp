#include "snapshots.h"

void SnapshotManager::increaseCap() {

    maxi = maxi*2+1;
    Snapshot ** newtab = new Snapshot*[maxi];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=snapshots[i];
    Snapshot ** old = snapshots;
    snapshots = newtab;

    delete[] old;
}

void SnapshotManager::addSnapshot(Stack * st, IdentifierManager * im) {
    Snapshot * newsnap = new Snapshot(st,im);

    if((nb==maxi)||(nb==maxi-1))
        increaseCap();
    if(nb==0)
        snapshots[0]=newsnap;
    else {

        for(unsigned int i=currentState;i<nb+1;i++)
            snapshots[i+1]=snapshots[i];
        snapshots[currentState]=newsnap;
        currentState++;
    }
    nb++;
}
void SnapshotManager::updateCurrentSnapshot(Stack * st, IdentifierManager * im) {
    Snapshot * newsnap = new Snapshot(st,im);
    Snapshot * old = snapshots[currentState];
    snapshots[currentState]=newsnap;
    delete old;
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


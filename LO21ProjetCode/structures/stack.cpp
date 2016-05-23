#include "stack.h"
#include "intermediary.h"

void Stack::increaseCap() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

void Stack::push(Item e){
    if (nb==nbMax) increaseCap();
    items[nb]=e;
    nb++;
    stateModification();
}

void Stack::pop(){
    nb--;
    items[nb].raz();
    stateModification();
}

void Stack::display(QTextStream& f) const{
    f<<"********************************************* \n";
    f<<"M : "<<message<<"\n";
    f<<"---------------------------------------------\n";
    for(unsigned int i=nbItemsDisplayed; i>0; i--) {
        if (i<=nb)
            {
                f<<i<<": ";
                (*(items[nb-i].getPLit())).print(f);
            }
        else f<<i<<": \n";
    }
    f<<"---------------------------------------------\n";
}


Stack::~Stack(){
    delete[] items;
}

Litteral* Stack::top() const {

    if (nb==0) throw "aucune expression sur la Stack";
    return items[nb-1].getPLit();
}


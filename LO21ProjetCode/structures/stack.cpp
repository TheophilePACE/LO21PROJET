        #include "stack.h"
    #include "intermediary.h"
    #include "structures.h"

    Stack::Stack(const Stack& s){
        Item* newtab=new Item[s.nbMax];
        for(unsigned int i=0; i<s.nb; i++) { newtab[i] = s.items[i]; }
        items = newtab;
        nbItemsDisplayed = s.nbItemsDisplayed;
        nbMax = s.nbMax;
        nb = s.nb;
    }

    void Stack::increaseCap() {
        Item* newtab=new Item[(nbMax+1)*2];
        for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
        Item* old=items;
        items=newtab;
        nbMax=(nbMax+1)*2;
        delete[] old;
    }

    void Stack::push(Item e){
        if (nb==nbMax) increaseCap();
        items[nb]=e;
        nb++;
    }

    void Stack::pop(){
        nb--;
        items[nb].raz();
    }

    const QString Stack::display() const{
        std::stringstream f;
        for(unsigned int i=0; i<nb; i++) {
                    f << (*(items[i].getPLit())).toQStringPars().toStdString();
                    if(i!=nb-1)
                        f<<"_";
        }
        return toQString(f.str());
    }


    Stack::~Stack(){
    //    for(unsigned int i=0; i<nb; i++)
    //        delete &(items[i]);
        delete[] items;
    }

    Litteral* Stack::top() const {

        if (nb==0) throw ComputerException("Erreur : Aucune Expression à Dépiler");
        return items[nb-1].getPLit();
    }


    //LAST STRUC

    void LastStruc::getOpe1(Stack* s,QString op){
        ope ="";
        ope+=op;
        item1->setLit(s->top());
        item2->setLit(nullptr);
    }

    void LastStruc::getOpe2(Stack* s,QString op){
        ope ="";
        ope+=op;
        item2->setLit(s->top());
        s->pop();
        item1->setLit(s->top());
        s->push(*item2);

    }

    void LastStruc::lastArgu (Stack* s){

        if(((item1->getPLit())!=nullptr)&&((item2->getPLit())!=nullptr))
        {
            s->push(*item1);
            s->push(*item2);
        }
        else
            throw ComputerException("Erreur : Pas d'Opérateur Utilisé");
    }

    QString LastStruc::lastOpe () const {

        if(ope!="")
            return ope;
        throw ComputerException("Erreur : Pas d'Opérateur Utilisé");

    }

#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "structures.h"

class ProgramManager {
    Program** programs;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    ProgramManager():programs(nullptr),nb(0),max(0){}
    ~ProgramManager(){}
    ProgramManager(const ProgramManager& m);
    ProgramManager& operator=(const ProgramManager& m);
    //friend class QComputer;
    struct Singleton{
        ProgramManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    void addProgram(std::string chaine);
    void removeProgram(Program& e);
    static ProgramManager& getInstance();
    static void freeInstance();
    class Iterator {
        friend class ProgramManager;
        Program** current;
        unsigned int nbRemain;
        Iterator(Program** u, unsigned nb):current(u),nbRemain(nb){}
    public:
        Iterator():current(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw "error, next on an iterator which is done";
            nbRemain--;
            current++;
        }
        Program& getCurrent() const {
            if (isDone())
                throw "error, indirection on an iterator which is done";
            return **current;
        }
    };
    Iterator getIterator() {
        return Iterator(programs,nb);
    }
};

#endif // PROGRAMMANAGER_H

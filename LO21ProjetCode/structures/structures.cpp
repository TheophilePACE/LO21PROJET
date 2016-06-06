#include "litteral/litteral.h"
#include "litteral/rationnal.h"
#include "litteral/real.h"
#include "structures/structures.h"
#include "parser.h"
#include "qmain.h"
#include <QString>
#include <QStringList>
#include "operator.h"
#include "snapshots.h"

void Controller::command(const QString& c){
    Parser p = Parser::getInstance();
    QStringList list = c.split(" ", QString::SkipEmptyParts);
    QString d = "", str;
    bool prog = false;
    bool listest = false;
    for (int i = 0; i < list.size(); ++i) {

        str = list.at(i);
        if((str[0]=='[')&&(str[str.size()-1]!=']')) {
            d = str;
            prog = true;
        }
        else if((prog)&&(str[str.size()-1]!=']'))
            d = d + " " + str;
        else if((prog)&&(str[str.size()-1]==']')) {
            prog = false;
            d = d + " " + str;
            str = d;
        }
        if((str[0]=='\'')&&(str[str.size()-1]!='\'')&&(!prog)) {
            d = str;
            listest = true;
        }
        else if((listest)&&(str[str.size()-1]!='\''))
            d = d + str;
        else if((listest)&&(str[str.size()-1]=='\'')) {
            listest = false;
            d = d + str;
            str = d;
        }

        if(((prog)== false)&&(listest==false)) {
            if(p.isOperator(str)) {
                SnapshotManager  * s = &(SnapshotManager::getInstance());
                s->addSnapshot(stack, &(IdentifierManager::getInstance()));
                try {
                    if(p.isOperatorBinary(str)){
                    if (stack->size()>=2) {
                         //récuperation des éléments

                        //SI On a un prgm ou une expression ou un atom: les évaluer.
                        //----evaluation des prgm et des expressions et des atomes
                        //Ici, il ne reste plus que des cmplx et des numeriques
                        if (str=="+")
                        {

                            Item Rslt;
                            OperatorSum OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (str=="-")
                        {

                            Item Rslt;
                            OperatorSub OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (str=="*")
                        {

                            Item Rslt;
                            OperatorMul OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (str=="/")
                        {
                            Item Rslt;
                             OperatorDivision OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (str=="DIV")
                        {
                            Item Rslt;
                            OperatorDiv OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (str=="MOD")
                        {
                            Item Rslt;
                            OperatorMod OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c==">")
                        {
                            Item Rslt;
                            OperatorSupS OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c==">=")
                        {
                            Item Rslt;
                            OperatorSupE OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="<")
                        {
                            Item Rslt;
                            OperatorLessS OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="<=")
                        {
                            Item Rslt;
                            OperatorLessE OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="=")
                        {
                            Item Rslt;
                            OperatorEqu OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="!=")
                        {
                            Item Rslt;
                            OperatorNEqu OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="$")
                        {
                            Item Rslt;
                            OperatorCplx OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="AND")
                        {
                            Item Rslt;
                            OperatorAND OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else if (c=="OR")
                        {
                            Item Rslt;
                            OperatorOR OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else {
                            stack->setMessage(toQString("Operateur Inconnu"));
                            }
                        }


                    else throw"Pas assez d elements dans la pile";}

                else if(p.isOperatorUnary(list.at(i))) {
                    if (stack->size()>=1) {
                        if (c=="NOT")
                        {

                            Item Rslt;
                            OperatorNOT OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        if (c=="NEG")
                        {

                            Item Rslt;
                            OperatorNEG OP;
                            OP.loadOperand(stack);
                            Rslt.setLit(OP.execute());
                            stack->push(Rslt);
                        }
                        else
                            throw "Operateur pas encore défini";
                    }
                    else throw" Pas assez d'argument dans la pile!";
                }
        }
        catch(char const* s)
        {
            QWidget * widgetSearched;
            foreach (QWidget *widget, QApplication::allWidgets()) {
                if(widget->accessibleName()=="ButtonNoSound")
                    widgetSearched = widget;
            }
            if(!((dynamic_cast<QAbstractButton*>(widgetSearched))->isChecked()))
                QSound::play("../wahoo.wav");
            stack->setMessage(toQString(s));
        }
        }
         else {
                try {
                    Item * I = genMng.createItem(str);
                    if(I) {
                        SnapshotManager  * s = &(SnapshotManager::getInstance());
                        s->addSnapshot(stack, &(IdentifierManager::getInstance()));
                        stack->push(*I);
                    }
                    else
                        throw "Erreur : commande inconnue";
                }
                catch(char const* s)
                {
                    QWidget * widgetSearched;
                    foreach (QWidget *widget, QApplication::allWidgets()) {
                        if(widget->accessibleName()=="ButtonNoSound")
                            widgetSearched = widget;
                    }
                    if(!((dynamic_cast<QAbstractButton*>(widgetSearched))->isChecked()))
                        QSound::play("../wahoo.wav");
                    stack->setMessage(toQString(s));
                }
            }
        }
    }
}

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
    try {
        Parser p = Parser::getInstance();
        QStringList list = c.split(" ", QString::SkipEmptyParts);
        QString d = "", str;
        bool prog = false;
        bool listest = false;
        for (int i = 0; i < list.size(); ++i) {

            str = list.at(i);
            if((str[0]=='[')&&(str[str.size()-1]!=']')&&(!listest)) {
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
            if((str[0]=='\'')&&((str[str.size()-1]!='\'')||((str+(str.size()-1))==str))&&(!prog)) {
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

            if((!prog)&&(!listest)) {
                if(p.isOperator(str)) {
                    SnapshotManager  * s = &(SnapshotManager::getInstance());
                    s->addSnapshot(stack, &(IdentifierManager::getInstance()));
                    if (str=="LASTOP")
                    {
                        str=lastStruc->lastOpe();
                    }
                    if(p.isOperatorBinary(str)){
                        if (stack->size()>=2) {
                             //récuperation des éléments
                            lastStruc->getOpe2(stack,str);
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
                            else if (str==">")
                            {
                                Item Rslt;
                                OperatorSupS OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str==">=")
                            {
                                Item Rslt;
                                OperatorSupE OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="<")
                            {
                                Item Rslt;
                                OperatorLessS OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="<=")
                            {
                                Item Rslt;
                                OperatorLessE OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="=")
                            {
                                Item Rslt;
                                OperatorEqu OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="!=")
                            {
                                Item Rslt;
                                OperatorNEqu OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="$")
                            {
                                Item Rslt;
                                OperatorCplx OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="AND")
                            {
                                Item Rslt;
                                OperatorAND OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="OR")
                            {
                                Item Rslt;
                                OperatorOR OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="STO")
                            {
                                OperatorSTO OP;
                                OP.loadOperand(stack);
                                OP.execute();
                            }
                            else if (str=="SWAP")
                            {
                                Item Rslt1, Rslt2;
                                Rslt1.setLit(stack->top());
                                stack->pop();
                                Rslt2.setLit(stack->top());
                                stack->pop();
                                stack->push(Rslt1);
                                stack->push(Rslt2);
                            }
                            else if (str=="IFT")
                            {
                                OperatorIFT OP;
                                OP.loadOperand(stack);
                                Item Rslt ;
                                Rslt.setLit(OP.execute());
                                if(Rslt.getPLit()!=nullptr){
                                    stack->push(Rslt);
                                    if(dynamic_cast<Expression*>(stack->top())){
                                    OperatorEVAL OP(this);
                                    OP.loadOperand(stack);
                                    OP.execute();}

                                }

                            }

                            else {
                                stack->setMessage(toQString("Operateur Inconnu"));
                                }
                            }


                        else throw ComputerException("Pas assez d elements dans la pile");}
                    else if(p.isOperatorUnary(str)) {
                        if (stack->size()>=1) {
                            lastStruc->getOpe1(stack,str);

                            if (str=="NOT")
                            {

                                Item Rslt;
                                OperatorNOT OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="NEG")
                            {

                                Item Rslt;
                                OperatorNEG OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="NUM")
                            {

                                Item Rslt;
                                OperatorNUM OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="DEN")
                            {

                                Item Rslt;
                                OperatorDEN OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="RE")
                            {

                                Item Rslt;
                                OperatorRE OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="IM")
                            {

                                Item Rslt;
                                OperatorIM OP;
                                OP.loadOperand(stack);
                                Rslt.setLit(OP.execute());
                                stack->push(Rslt);
                            }
                            else if (str=="DUP")
                            {

                                Item Rslt;
                                Rslt.setLit(stack->top());
                                stack->push(Rslt);
                            }
                            else if (str=="DROP")
                            {

                                stack->pop();
                            }
                            else if (str=="EVAL")
                            {
                                OperatorEVAL OP(this);
                                OP.loadOperand(stack);
                                OP.execute();
                            }
                            else if (str=="FORGET")
                            {
                                OperatorFORGET OP;
                                OP.loadOperand(stack);
                                OP.execute();
                            }
                            else if (str=="EDIT")
                            {
                                OperatorEDIT OP;
                                OP.loadOperand(stack);
                                OP.execute();
                            }
                            else if (str=="CLEAR")
                            {
                                OperatorCLEAR OP;
                                OP.loadOperand(stack);
                                OP.execute();
                            }



                            else
                                throw ComputerException("Operateur pas encore défini");
                        }
                        else throw ComputerException(" Pas assez d'argument dans la pile!");
                    }
                    else if(p.isOperatorStack(str)) {
                         if (str=="LASTARGS")
                        {
                            lastStruc->lastArgu(stack);
                        }

                    }
                    }
             else {
                        Item * I = genMng.createItem(str);
                        if(I) {
                            SnapshotManager  * s = &(SnapshotManager::getInstance());
                            s->addSnapshot(stack, &(IdentifierManager::getInstance()));
                            stack->push(*I);
                        }
                        else {
                            Identifier * id = IdentifierManager::getInstance().getIdentifier(*(new Atom(str)));
                            command(toQString((*(id->getPValue())).toString()));
                        }

                }
            }
        }
    QWidget * ui;
    foreach (QWidget *widget, QApplication::allWidgets()) {
        if(widget->accessibleName()=="MainWindow")
            ui = widget;
    }
    QTabWidget * tab = (dynamic_cast<QMainWindow*>(ui))->findChild<QTabWidget*>("tabWidget");
    QComputer * comp = tab->findChild<QComputer*>("CalcTab");
    comp->accessLineEdit()->setText("");
    }
    catch(ComputerException exp)
    {

        QWidget * widgetSearched;
        foreach (QWidget *widget, QApplication::allWidgets()) {
            if(widget->accessibleName()=="ButtonNoSound")
                widgetSearched = widget;
        }

        if(!((dynamic_cast<QAbstractButton*>(widgetSearched))->isChecked())) {
            QApplication::beep();
            QSound::play("../wahoo.wav");
        }
        stack->setMessage(exp.getInfo());
    }
}

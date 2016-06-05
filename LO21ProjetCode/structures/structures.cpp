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
    QStringList list = c.split(" ");
    for (int i = 0; i < list.size(); ++i) {
        if(p.isOperator(list.at(i))) {
            SnapshotManager  * s = &(SnapshotManager::getInstance());
            s->addSnapshot(stack, &(IdentifierManager::getInstance()));
            if (stack->size()>=2) {
                 //récuperation des éléments

                //SI On a un prgm ou une expression ou un atom: les évaluer.
                //----evaluation des prgm et des expressions et des atomes
                //Ici, il ne reste plus que des cmplx et des numeriques
                if (c=="+")
                {

                    Item Rslt;
                    OperatorSum OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else if (c=="-")
                {

                    Item Rslt;
                    OperatorSub OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else if (c=="*")
                {

                    Item Rslt;
                    OperatorMul OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else if (c=="/")
                {
                    Item Rslt;
                     OperatorDivision OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else if (c=="DIV")
                {
                    Item Rslt;
                    OperatorDiv OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else if (c=="MOD")
                {
                    Item Rslt;
                    OperatorMod OP;
                    OP.loadOperand(stack);
                    Rslt.setLit(OP.execute());
                    stack->push(Rslt);
                }
                else {
                    stack->setMessage(toQString("Operateur Inconnu"));
                    }
                }
               // Expression& e=expMng.addExpression(res);
              //  expAff.push(e);

        else{
                //throw"Erreur : pas assez d'arguments";
                break;
             //   expAff.setMessage("Erreur : pas assez d'arguments");
            }
        //else expAff.setMessage("Erreur : commande inconnue");
    }
     else {
            try {
                Item * I = genMng.createItem(list.at(i));
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
    }}


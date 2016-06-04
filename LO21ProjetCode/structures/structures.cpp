#include "litteral/litteral.h"
#include "litteral/rationnal.h"
#include "litteral/real.h"
#include "structures/structures.h"
#include "parser.h"
#include "qmain.h"

void Controller::command(const QString& c){
    Parser p = Parser::getInstance();
    QStringList list = c.split(" ");
    for (int i = 0; i < list.size(); ++i) {
        if(p.isOperator(list.at(i))) {
            /*if (stack.size()>=2) {
                int v2=2;//expAff.top().getValue();
                //expMng.removeExpression(expAff.top());
                stack.pop();
                int v1=2;//expAff.top().getValue();
                //expMng.removeExpression(expAff.top());
                stack.pop();
                int res;
                if (c=="+") res=v1+v2;
                if (c=="-") res=v1-v2;
                if (c=="*") res=v1*v2;
                if (c=="/") {
                    if (v2!=0) res=v1/v2;
                    else {
                        //expAff.setMessage("Erreur : division par zéro");
                        res=v1;
                    }
                }
               // Expression& e=expMng.addExpression(res);
              //  expAff.push(e);
            }else{
             //   expAff.setMessage("Erreur : pas assez d'arguments");
            }
       */ }//else expAff.setMessage("Erreur : commande inconnue");


     else {
            try {
                Item * I = genMng.createItem(list.at(i));
                if(I)
                    stack.push(*I);
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
                stack.setMessage(toQString(s));
            }
        }
    }
}

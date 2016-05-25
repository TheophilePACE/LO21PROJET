#include "litteral/litteral.h"
#include "intermediary.h"
#include "structures/structures.h"
#include "qmain.h"
#include "mainwindow.h"
#include <QApplication>
#include "litteral/complex.h"

int main(int argc, char* argv[]) {
   Integer A(1);
   Integer B(2);
   Complex C(&A,&B);
    /*
    QApplication app(argc, argv);
    MainWindow fenetre;
    //QComputer fenetre;
    fenetre.show();
    return app.exec();*/
    return 0;
}

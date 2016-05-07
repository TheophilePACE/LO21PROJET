#include "litteral.h"
#include "intermediary.h"
#include "structures.h"
#include "qmain.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QComputer fenetre;
    fenetre.show();
    return app.exec();
}

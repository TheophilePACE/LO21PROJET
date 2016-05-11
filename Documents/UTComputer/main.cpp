#include"qcomputer.h"
#include"computer.h"
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QComputer fenetre;
    fenetre.show();
    return app.exec();
    /*
    QVBoxLayout *layout1V = new QVBoxLayout;
            QLineEdit *ligne1 = new QLineEdit();
            layout1V->addWidget(ligne1);
            QHBoxLayout *layout2H = new QHBoxLayout;
                QVBoxLayout *layout2V = new QVBoxLayout;
                    QHBoxLayout *layout3H = new QHBoxLayout;
                        QPushButton *b1 = new QPushButton("7");
                        QPushButton *b2 = new QPushButton("8");
                        QPushButton *b3 = new QPushButton("9");
                        layout3H->addWidget(b1);
                        layout3H->addWidget(b2);
                        layout3H->addWidget(b3);
                        layout2V->addLayout(layout3H);
                    QHBoxLayout *layout4H = new QHBoxLayout;
                        QPushButton *b4 = new QPushButton("4");
                        QPushButton *b5 = new QPushButton("5");
                        QPushButton *b6 = new QPushButton("6");
                        layout4H->addWidget(b4);
                        layout4H->addWidget(b5);
                        layout4H->addWidget(b6);
                        layout2V->addLayout(layout4H);
                    QHBoxLayout *layout5H = new QHBoxLayout;
                        QPushButton *b7 = new QPushButton("1");
                        QPushButton *b8 = new QPushButton("2");
                        QPushButton *b9 = new QPushButton("3");
                        layout5H->addWidget(b7);
                        layout5H->addWidget(b8);
                        layout5H->addWidget(b9);
                        layout2V->addLayout(layout5H);
                    QPushButton *b10 = new QPushButton("0");
                    layout2V->addWidget(b10);
                QVBoxLayout *layout3V = new QVBoxLayout;
                    QPushButton *b11 = new QPushButton("+");
                    QPushButton *b12 = new QPushButton("-");
                    QPushButton *b13 = new QPushButton("*");
                    QPushButton *b14 = new QPushButton("/");
                    QPushButton *b15 = new QPushButton("Entrée");
                    layout3V->addWidget(b11);
                    layout3V->addWidget(b12);
                    layout3V->addWidget(b13);
                    layout3V->addWidget(b14);
                    layout3V->addWidget(b15);
                    b15->setFixedHeight(40);
                layout2H->addLayout(layout2V);
                layout2H->addLayout(layout3V);
        layout1V->addLayout(layout2H);

    fenetre.setLayout(layout1V);
    fenetre.show();
    */
}


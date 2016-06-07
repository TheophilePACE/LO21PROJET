#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UTComputer 2.0");
    QButtonGroup * signalGroup = new QButtonGroup;
    QComputer * calcul = ui->tabWidget->findChild<QComputer*>("CalcTab");
    QvarEditor * variableManager = ui->tabWidget->findChild<QvarEditor*>("Variables");
    QprogramEditor * programManager = ui->tabWidget->findChild<QprogramEditor*>("Programmes");
    QSlider * lignes = ui->tabWidget->findChild<QWidget*>("Parametres")->findChild<QSlider*>("horizontalSlider");
    QCheckBox * checkKeybord = ui->tabWidget->findChild<QWidget*>("Parametres")->findChild<QCheckBox*>("checkBox");

    signalGroup->addButton(ui->pushButton);
    signalGroup->addButton(ui->pushButton_2);
    signalGroup->addButton(ui->pushButton_3);
    signalGroup->addButton(ui->pushButton_4);
    signalGroup->addButton(ui->pushButton_5);
    signalGroup->addButton(ui->pushButton_6);
    signalGroup->addButton(ui->pushButton_7);
    signalGroup->addButton(ui->pushButton_8);
    signalGroup->addButton(ui->pushButton_9);
    signalGroup->addButton(ui->pushButton_10);
    signalGroup->addButton(ui->pushButton_11);
    signalGroup->addButton(ui->pushButton_12);
    signalGroup->addButton(ui->pushButton_13);
    signalGroup->addButton(ui->pushButton_14);
    signalGroup->addButton(ui->pushButton_15);
    signalGroup->addButton(ui->pushButton_16);
    // signalGroup->addButton(ui->pushButton_17); BLANK
    signalGroup->addButton(ui->pushButton_18);
    signalGroup->addButton(ui->pushButton_19);
    signalGroup->addButton(ui->pushButton_20);
    signalGroup->addButton(ui->pushButton_21);
    signalGroup->addButton(ui->pushButton_22);
    signalGroup->addButton(ui->pushButton_23);
    signalGroup->addButton(ui->pushButton_25);
    signalGroup->addButton(ui->pushButton_26);
    signalGroup->addButton(ui->pushButton_27);
    signalGroup->addButton(ui->pushButton_28);
    signalGroup->addButton(ui->pushButton_29);
    signalGroup->addButton(ui->pushButton_30);
    signalGroup->addButton(ui->pushButton_31);
    signalGroup->addButton(ui->pushButton_32);
    signalGroup->addButton(ui->pushButton_33);
    signalGroup->addButton(ui->pushButton_34);
    //signalGroup->addButton(ui->pushButton_35); UNDO
    //signalGroup->addButton(ui->pushButton_36); REDO
    signalGroup->addButton(ui->pushButton_37);
    signalGroup->addButton(ui->pushButton_38);
    signalGroup->addButton(ui->pushButton_39);
    signalGroup->addButton(ui->pushButton_40);
    signalGroup->addButton(ui->pushButton_41);
    signalGroup->addButton(ui->pushButton_42);
    signalGroup->addButton(ui->pushButton_43);
    signalGroup->addButton(ui->pushButton_44);
    signalGroup->addButton(ui->pushButton_45);
    signalGroup->addButton(ui->pushButton_46);

    connect(signalGroup,SIGNAL(buttonClicked(QAbstractButton*)),
            calcul
            ,SLOT(keyboardButtonPressed(QAbstractButton*)));
    connect(lignes,SIGNAL(sliderMoved(int)),
                calcul
                ,SLOT(sliderMoved(int)));
    connect(ui->pushButton_35,SIGNAL(clicked()),
                this
                ,SLOT(undo()));
    connect(ui->pushButton_36,SIGNAL(clicked()),
                this
                ,SLOT(redo()));
    connect(ui->pushButton_17,SIGNAL(clicked()),
                calcul
                ,SLOT(insertBlank()));
    connect(checkKeybord,SIGNAL(toggled(bool)),
                this
                ,SLOT(resized(bool)));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),
                this
                ,SLOT(stateChanged(int)));

    using namespace rapidxml;

    xml_document<> doc;
    xml_node<> * stack,* var,* prog;

    GeneralManager * genMng = &(GeneralManager::getInstance());
    std::ifstream theFile ("../UTComputer.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    //Stack Treatment
    stack = doc.first_node();
    if(stack) {
        if (toQString(stack->value())!="") {
            QStringList valuesSt = toQString(stack->value()).split("_");
            for (int i=0;  i < valuesSt.size(); ++i)
            {
                Item * I = genMng->createItem(valuesSt.at(i));
                calcul->getStack()->push(*I);
            }
        }
        calcul->refresh();
        IdentifierManager * idMng = &(IdentifierManager::getInstance());

        //Var Treatment
        var = stack->next_sibling();
        if (var) {
            if (toQString(var->value())!="") {
                QStringList valuesVar = toQString(var->value()).split(" ");

                for (int i=0;  i < valuesVar.size(); ++i)
                {
                    QStringList variables = valuesVar.at(i).split("-");
                    idMng->addIdentifier(variables.at(0),genMng->createItem(variables.at(1))->getPLit());
                }
            }
            variableManager->refresh();

            //Prog Treatment
            prog = var->next_sibling();
            if (prog) {
                if (toQString(prog->value())!="") {
                    QStringList valuesProg = toQString(prog->value()).split("_");
                    for (int i=0;  i < valuesProg.size(); ++i)
                    {
                        QStringList programmes = valuesProg.at(i).split("[");
                        QString inter = programmes.at(1);
                        inter.remove(inter.size()-1, 1);
                        idMng->addIdentifier(programmes.at(0),genMng->createProgram(inter)->getPLit());
                    }
                }
                programManager->refresh();
            }
        }
    }
    SnapshotManager * s = &(SnapshotManager::getInstance());
    s->addSnapshot(calcul->getStack(), &(IdentifierManager::getInstance()));

    QShortcut *shortcut1 = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z),this);
    QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(undo()));
    QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y),this);
    QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(redo()));


}

MainWindow::~MainWindow()
{
    using namespace rapidxml;

    xml_document<> doc;

    QComputer * calcul = ui->tabWidget->findChild<QComputer*>("CalcTab");
    Stack * stack = calcul->getStack();
    std::string s = stack->display().toStdString();

    xml_node<> *node = doc.allocate_node(node_element, "Pile", s.c_str(),4 , s.size());
    doc.append_node(node);

    IdentifierManager * idMng = &(IdentifierManager::getInstance());
    std::string s2 = idMng->displayVar().toStdString();
    xml_node<> *node2 = doc.allocate_node(node_element, "Variables", s2.c_str(),9 , s2.size());
    doc.append_node(node2);

    std::string s3 = idMng->displayProg().toStdString();
    xml_node<> *node3 = doc.allocate_node(node_element, "Programmes", s3.c_str(), 10, s3.size());
    doc.append_node(node3);

    std::ofstream theFile ("../UTComputer.xml");
    theFile << doc;
    delete ui;
}

void MainWindow::resized(bool b){
    QGroupBox* group = findChild<QGroupBox*>("groupBox");
    unsigned int widthg = group->width();
    group->setVisible(!b);
    if(b)
        resize(width()-widthg,height());
    else
        resize(width()+widthg,height());
}

void MainWindow::stateChanged(int i) {

    QComputer * calcul = ui->tabWidget->findChild<QComputer*>("CalcTab");
    QvarEditor * variableManager = ui->tabWidget->findChild<QvarEditor*>("Variables");
    QprogramEditor * programManager = ui->tabWidget->findChild<QprogramEditor*>("Programmes");

    switch (i) {
    case 0 :
        calcul->refresh();
    case 1 :
        variableManager->refresh();
    case 2 :
        programManager->refresh();
    default:
    break;
    }
}

void MainWindow::undo(){
    SnapshotManager  * s = &(SnapshotManager::getInstance());
    if(s->undoPossible()) {
        QComputer * calcul1 = ui->tabWidget->findChild<QComputer*>("CalcTab");
        s->updateCurrentSnapshot(calcul1->getStack(), &(IdentifierManager::getInstance()));
        Snapshot * snapshot = s->undo();
        QComputer * calcul = ui->tabWidget->findChild<QComputer*>("CalcTab");
        QvarEditor * variableManager = ui->tabWidget->findChild<QvarEditor*>("Variables");
        QprogramEditor * programManager = ui->tabWidget->findChild<QprogramEditor*>("Programmes");
        calcul->setStack(snapshot->getStack());
        IdentifierManager::setInstance(snapshot->getIdManager());
        calcul->refresh();
        variableManager->refresh();
        programManager->refresh();
    }
}
void MainWindow::redo(){

    SnapshotManager  * s = &(SnapshotManager::getInstance());
    if(s->redoPossible()) {
        QComputer * calcul1 = ui->tabWidget->findChild<QComputer*>("CalcTab");
        s->updateCurrentSnapshot(calcul1->getStack(), &(IdentifierManager::getInstance()));
        Snapshot * snapshot = s->redo();
        QComputer * calcul = ui->tabWidget->findChild<QComputer*>("CalcTab");
        QvarEditor * variableManager = ui->tabWidget->findChild<QvarEditor*>("Variables");
        QprogramEditor * programManager = ui->tabWidget->findChild<QprogramEditor*>("Programmes");
        calcul->setStack(snapshot->getStack());
        IdentifierManager::setInstance(snapshot->getIdManager());
        calcul->refresh();
        variableManager->refresh();
        programManager->refresh();
    }
}

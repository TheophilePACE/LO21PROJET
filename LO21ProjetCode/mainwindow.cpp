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
    QSlider * lignes = ui->tabWidget->findChild<QWidget*>("Parametres")->findChild<QSlider*>("horizontalSlider");

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
    signalGroup->addButton(ui->pushButton_17);
    signalGroup->addButton(ui->pushButton_18);
    signalGroup->addButton(ui->pushButton_19);
    signalGroup->addButton(ui->pushButton_20);
    signalGroup->addButton(ui->pushButton_21);
    signalGroup->addButton(ui->pushButton_22);
    signalGroup->addButton(ui->pushButton_23);
    signalGroup->addButton(ui->pushButton_24);
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
    signalGroup->addButton(ui->pushButton_35);
    signalGroup->addButton(ui->pushButton_36);
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


    using namespace rapidxml;

    xml_document<> doc;
    xml_node<> * root;

    GeneralManager * genMng = &(GeneralManager::getInstance());
    std::ifstream theFile ("UTComputer.xml");
    std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);

    //Stack Treatment
    root = doc.first_node("Pile");
    /*for (xml_node<> * item_node = root->first_node("Atom"); item_node; item_node = item_node->next_sibling())
        {
            Item * I = genMng->createItem(item_node->value());
            calcul->getStack()->push(*I);
        }*/
   // xml_node<> * item_node = root->first_node("Atom");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    /*if(checkBox->checkState()==0)
        groupBox->hide();
    else
        groupBox->show();*/
}
void MainWindow::resized(){
    QGroupBox* group = findChild<QGroupBox*>("groupBox");
    if (group->isVisible())
        resize(959,304);
    else
        adjustSize();
}

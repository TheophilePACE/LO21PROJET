#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UTComputer 2.0");
    QButtonGroup * signalGroup = new QButtonGroup;
    QComputer * calcul = findChild<QTabWidget*>("tabWidget")->findChild<QComputer*>("Calculatrice");
    QSlider * lignes = findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("Parametres")->findChild<QSlider*>("horizontalSlider");

    signalGroup->addButton(findChild<QPushButton*>("pushButton"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_2"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_3"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_4"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_5"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_6"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_7"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_8"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_9"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_10"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_11"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_12"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_13"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_14"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_15"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_16"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_17"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_18"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_19"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_20"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_21"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_22"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_23"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_24"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_25"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_26"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_27"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_28"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_29"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_30"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_31"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_32"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_33"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_34"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_35"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_36"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_37"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_38"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_39"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_40"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_41"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_42"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_43"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_44"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_45"));
    signalGroup->addButton(findChild<QPushButton*>("pushButton_46"));

    connect(signalGroup,SIGNAL(buttonClicked(QAbstractButton*)),
            calcul
            ,SLOT(keyboardButtonPressed(QAbstractButton*)));
    connect(lignes,SIGNAL(sliderMoved(int)),
            calcul
            ,SLOT(sliderMoved(int)));

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

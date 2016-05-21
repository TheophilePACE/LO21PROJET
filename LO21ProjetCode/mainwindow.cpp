#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

#include "litteral/litteral.h"
#include "intermediary.h"
#include "qvareditor.h"
#include "snapshots.h"

void ExceptionWindow(QString s) {
    QWindow2 *win = new QWindow2;
    QLabel * lab = new QLabel;
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(lab);
    lab->setText(s);
    win->setWindowTitle("Error Window");
    win->setLayout(layout);
    win->show();
    QWidget * widgetSearched;
    foreach (QWidget *widget, QApplication::allWidgets())
        if(widget->accessibleName()=="ButtonNoSound")
            widgetSearched = widget;
    if(!((dynamic_cast<QAbstractButton*>(widgetSearched))->isChecked()))
    {
        QApplication::beep();
        QSound::play("../wahoo.wav");
    }
}

void CheckButtons() {
    QWidget * ui;
    SnapshotManager * s = &(SnapshotManager::getInstance());
    foreach (QWidget *widget, QApplication::allWidgets())
        if(widget->accessibleName()=="MainWindow")
            ui = widget;
    if(s->undoPossible())
        dynamic_cast<QMainWindow*>(ui)->findChild<QPushButton*>("pushButton_35")->setEnabled(true);
    else
        dynamic_cast<QMainWindow*>(ui)->findChild<QPushButton*>("pushButton_35")->setEnabled(false);
    if(s->redoPossible())
        dynamic_cast<QMainWindow*>(ui)->findChild<QPushButton*>("pushButton_36")->setEnabled(true);
    else
        dynamic_cast<QMainWindow*>(ui)->findChild<QPushButton*>("pushButton_36")->setEnabled(false);

}



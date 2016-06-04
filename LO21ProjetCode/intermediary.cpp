#include "litteral/litteral.h"
#include "intermediary.h"
#include "qvareditor.h"
#include <QApplication>
#include <QCheckBox>

void ExceptionWindow(const char * s) {
    QWindow2 *win = new QWindow2;
    QLabel * lab = new QLabel;
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(lab);
    lab->setText(s);
    win->setWindowTitle("Error Window");
    win->setLayout(layout);
    win->show();
    QWidget * widgetSearched;
    foreach (QWidget *widget, QApplication::allWidgets()) {
        if(widget->accessibleName()=="ButtonNoSound")
            widgetSearched = widget;
    }
    if(!((dynamic_cast<QAbstractButton*>(widgetSearched))->isChecked()))
        QSound::play("../wahoo.wav");
}

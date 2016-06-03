#include "litteral/litteral.h"
#include "intermediary.h"
#include "qvareditor.h"
#include <QString>

void ExceptionWindow(const char * s) {
    QWindow2 *win = new QWindow2;
    QLabel * lab = new QLabel;
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(lab);
    lab->setText(s);
    win->setWindowTitle("Error Window");
    win->setLayout(layout);
    win->show();
    QSound::play("../noise.wav");
}

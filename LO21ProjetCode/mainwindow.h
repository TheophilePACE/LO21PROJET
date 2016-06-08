#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QShortcut>
#include <QtXml>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iterator>
#include "../rapidxml-1.13/rapidxml_print.hpp"
#include "litteral/litteral.h"
#include "intermediary.h"
#include "structures/structures.h"
#include "snapshots.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void resized(bool);
    void undo();
    void stateChanged(int);
    void redo();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qmain.h"
#include "qprogrameditor.h"
#include "qvareditor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QComputer *CalcTab;
    QvarEditor *Variables;
    QprogramEditor *Programmes;
    QWidget *Parametres;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_21;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_13;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_12;
    QPushButton *pushButton_20;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_15;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_22;
    QPushButton *pushButton_33;
    QPushButton *pushButton_10;
    QPushButton *pushButton_25;
    QPushButton *pushButton_31;
    QPushButton *pushButton_34;
    QPushButton *pushButton_32;
    QPushButton *pushButton_27;
    QPushButton *pushButton_30;
    QPushButton *pushButton_29;
    QPushButton *pushButton_14;
    QPushButton *pushButton_28;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_26;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_41;
    QPushButton *pushButton_40;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_42;
    QPushButton *pushButton_43;
    QPushButton *pushButton_44;
    QPushButton *pushButton_45;
    QPushButton *pushButton_46;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(976, 309);
        MainWindow->setMinimumSize(QSize(481, 291));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(481, 291));
        tabWidget->setStyleSheet(QStringLiteral(""));
        CalcTab = new QComputer();
        CalcTab->setObjectName(QStringLiteral("CalcTab"));
        CalcTab->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(CalcTab, QString());
        Variables = new QvarEditor();
        Variables->setObjectName(QStringLiteral("Variables"));
        tabWidget->addTab(Variables, QString());
        Programmes = new QprogramEditor();
        Programmes->setObjectName(QStringLiteral("Programmes"));
        tabWidget->addTab(Programmes, QString());
        Parametres = new QWidget();
        Parametres->setObjectName(QStringLiteral("Parametres"));
        verticalLayout_4 = new QVBoxLayout(Parametres);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(Parametres);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(false);

        verticalLayout->addWidget(checkBox);

        label = new QLabel(Parametres);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Parametres);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSlider = new QSlider(Parametres);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(15);
        horizontalSlider->setSliderPosition(4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        checkBox_2 = new QCheckBox(Parametres);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(false);

        verticalLayout_2->addWidget(checkBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_2);

        tabWidget->addTab(Parametres, QString());

        horizontalLayout_3->addWidget(tabWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setMinimumSize(QSize(471, 261));
        groupBox->setMaximumSize(QSize(471, 261));
        groupBox->setBaseSize(QSize(471, 261));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_3->setContentsMargins(-1, -1, -1, 0);
        pushButton_21 = new QPushButton(groupBox);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout_3->addWidget(pushButton_21, 0, 3, 1, 1);

        pushButton_16 = new QPushButton(groupBox);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_3->addWidget(pushButton_16, 2, 2, 1, 1);

        pushButton_17 = new QPushButton(groupBox);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout_3->addWidget(pushButton_17, 3, 1, 1, 1);

        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_3->addWidget(pushButton_13, 1, 3, 1, 1);

        pushButton_18 = new QPushButton(groupBox);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout_3->addWidget(pushButton_18, 3, 2, 1, 1);

        pushButton_19 = new QPushButton(groupBox);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout_3->addWidget(pushButton_19, 3, 3, 1, 1);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_3->addWidget(pushButton_11, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_3->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout_3->addWidget(pushButton_12, 1, 2, 1, 1);

        pushButton_20 = new QPushButton(groupBox);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout_3->addWidget(pushButton_20, 2, 3, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_3->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout_3->addWidget(pushButton_15, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_3->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(true);

        gridLayout_3->addWidget(pushButton_4, 0, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_22 = new QPushButton(groupBox);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));

        gridLayout->addWidget(pushButton_22, 1, 0, 1, 1);

        pushButton_33 = new QPushButton(groupBox);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));

        gridLayout->addWidget(pushButton_33, 3, 2, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 0, 1, 1, 1);

        pushButton_25 = new QPushButton(groupBox);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        gridLayout->addWidget(pushButton_25, 2, 1, 1, 1);

        pushButton_31 = new QPushButton(groupBox);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));

        gridLayout->addWidget(pushButton_31, 3, 0, 1, 1);

        pushButton_34 = new QPushButton(groupBox);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));

        gridLayout->addWidget(pushButton_34, 3, 3, 1, 1);

        pushButton_32 = new QPushButton(groupBox);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));

        gridLayout->addWidget(pushButton_32, 3, 1, 1, 1);

        pushButton_27 = new QPushButton(groupBox);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));

        gridLayout->addWidget(pushButton_27, 1, 2, 1, 1);

        pushButton_30 = new QPushButton(groupBox);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));

        gridLayout->addWidget(pushButton_30, 2, 3, 1, 1);

        pushButton_29 = new QPushButton(groupBox);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));

        gridLayout->addWidget(pushButton_29, 1, 3, 1, 1);

        pushButton_14 = new QPushButton(groupBox);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 0, 2, 1, 1);

        pushButton_28 = new QPushButton(groupBox);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));

        gridLayout->addWidget(pushButton_28, 0, 3, 1, 1);

        pushButton_23 = new QPushButton(groupBox);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        gridLayout->addWidget(pushButton_23, 2, 0, 1, 1);

        pushButton_24 = new QPushButton(groupBox);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout->addWidget(pushButton_24, 1, 1, 1, 1);

        pushButton_26 = new QPushButton(groupBox);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));

        gridLayout->addWidget(pushButton_26, 2, 2, 1, 1);

        pushButton_35 = new QPushButton(groupBox);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        pushButton_35->setEnabled(false);
        pushButton_35->setCheckable(false);
        pushButton_35->setAutoDefault(false);

        gridLayout->addWidget(pushButton_35, 4, 0, 1, 1);

        pushButton_36 = new QPushButton(groupBox);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        pushButton_36->setEnabled(false);

        gridLayout->addWidget(pushButton_36, 4, 1, 1, 1);

        pushButton_37 = new QPushButton(groupBox);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));

        gridLayout->addWidget(pushButton_37, 4, 2, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_41 = new QPushButton(groupBox);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));

        gridLayout_2->addWidget(pushButton_41, 1, 0, 1, 1);

        pushButton_40 = new QPushButton(groupBox);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));

        gridLayout_2->addWidget(pushButton_40, 0, 2, 1, 1);

        pushButton_38 = new QPushButton(groupBox);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));

        gridLayout_2->addWidget(pushButton_38, 0, 0, 1, 1);

        pushButton_39 = new QPushButton(groupBox);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));

        gridLayout_2->addWidget(pushButton_39, 0, 1, 1, 1);

        pushButton_42 = new QPushButton(groupBox);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));

        gridLayout_2->addWidget(pushButton_42, 2, 0, 1, 1);

        pushButton_43 = new QPushButton(groupBox);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));

        gridLayout_2->addWidget(pushButton_43, 1, 1, 1, 1);

        pushButton_44 = new QPushButton(groupBox);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));

        gridLayout_2->addWidget(pushButton_44, 2, 1, 1, 1);

        pushButton_45 = new QPushButton(groupBox);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));

        gridLayout_2->addWidget(pushButton_45, 1, 2, 1, 1);

        pushButton_46 = new QPushButton(groupBox);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));

        gridLayout_2->addWidget(pushButton_46, 2, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), label_2, SLOT(setNum(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_ACCESSIBILITY
        MainWindow->setAccessibleName(QApplication::translate("MainWindow", "MainWindow", 0));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        CalcTab->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CalcTab->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        CalcTab->setAccessibleName(QApplication::translate("MainWindow", "Calculatrice", 0));
#endif // QT_NO_ACCESSIBILITY
        tabWidget->setTabText(tabWidget->indexOf(CalcTab), QApplication::translate("MainWindow", "Calculatrice", 0));
        tabWidget->setTabText(tabWidget->indexOf(Variables), QApplication::translate("MainWindow", "Variables", 0));
        tabWidget->setTabText(tabWidget->indexOf(Programmes), QApplication::translate("MainWindow", "Programmes", 0));
        checkBox->setText(QApplication::translate("MainWindow", "D\303\251sactiver Clavier Virtuel", 0));
        label->setText(QApplication::translate("MainWindow", "Nombre de Lignes affich\303\251es :", 0));
        label_2->setText(QApplication::translate("MainWindow", "4", 0));
#ifndef QT_NO_ACCESSIBILITY
        checkBox_2->setAccessibleName(QApplication::translate("MainWindow", "ButtonNoSound", 0));
#endif // QT_NO_ACCESSIBILITY
        checkBox_2->setText(QApplication::translate("MainWindow", "D\303\251sactiver Sons", 0));
        tabWidget->setTabText(tabWidget->indexOf(Parametres), QApplication::translate("MainWindow", "Param\303\250tres", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Clavier", 0));
        pushButton_21->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_17->setText(QString());
        pushButton_13->setText(QApplication::translate("MainWindow", "*", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", ".", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "$", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_20->setText(QApplication::translate("MainWindow", "/", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "NEG", 0));
        pushButton_22->setText(QApplication::translate("MainWindow", "EVAL", 0));
        pushButton_33->setText(QApplication::translate("MainWindow", "LASTARGS", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "DIV", 0));
        pushButton_25->setText(QApplication::translate("MainWindow", "EDIT", 0));
        pushButton_31->setText(QApplication::translate("MainWindow", "SWAP", 0));
        pushButton_34->setText(QApplication::translate("MainWindow", "IM", 0));
        pushButton_32->setText(QApplication::translate("MainWindow", "LASTOP", 0));
        pushButton_27->setText(QApplication::translate("MainWindow", "DUP", 0));
        pushButton_30->setText(QApplication::translate("MainWindow", "RE", 0));
        pushButton_29->setText(QApplication::translate("MainWindow", "DEN", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "MOD", 0));
        pushButton_28->setText(QApplication::translate("MainWindow", "NUM", 0));
        pushButton_23->setText(QApplication::translate("MainWindow", "IFT", 0));
        pushButton_24->setText(QApplication::translate("MainWindow", "OP", 0));
        pushButton_26->setText(QApplication::translate("MainWindow", "DROP", 0));
        pushButton_35->setText(QApplication::translate("MainWindow", "UNDO", 0));
        pushButton_36->setText(QApplication::translate("MainWindow", "REDO", 0));
        pushButton_37->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButton->setText(QApplication::translate("MainWindow", "BACK", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "ENTER", 0));
        pushButton_41->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_40->setText(QApplication::translate("MainWindow", "AND", 0));
        pushButton_38->setText(QApplication::translate("MainWindow", "<", 0));
        pushButton_39->setText(QApplication::translate("MainWindow", "<=", 0));
        pushButton_42->setText(QApplication::translate("MainWindow", "=", 0));
        pushButton_43->setText(QApplication::translate("MainWindow", ">=", 0));
        pushButton_44->setText(QApplication::translate("MainWindow", "!=", 0));
        pushButton_45->setText(QApplication::translate("MainWindow", "OR", 0));
        pushButton_46->setText(QApplication::translate("MainWindow", "NOT", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

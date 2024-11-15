/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *ButonProduse;
    QPushButton *ButonComenzi;
    QPushButton *ExitButon;
    QLabel *MeniuPrincipalLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(591, 573);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        ButonProduse = new QPushButton(centralwidget);
        ButonProduse->setObjectName("ButonProduse");
        ButonProduse->setGeometry(QRect(180, 160, 241, 61));
        ButonComenzi = new QPushButton(centralwidget);
        ButonComenzi->setObjectName("ButonComenzi");
        ButonComenzi->setGeometry(QRect(180, 240, 241, 61));
        ExitButon = new QPushButton(centralwidget);
        ExitButon->setObjectName("ExitButon");
        ExitButon->setGeometry(QRect(180, 320, 241, 61));
        MeniuPrincipalLabel = new QLabel(centralwidget);
        MeniuPrincipalLabel->setObjectName("MeniuPrincipalLabel");
        MeniuPrincipalLabel->setGeometry(QRect(0, 0, 591, 161));
        MeniuPrincipalLabel->setAlignment(Qt::AlignCenter);
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 591, 26));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName("statusbar");
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        ButonProduse->setText(QCoreApplication::translate("MainMenu", "Produse", nullptr));
        ButonComenzi->setText(QCoreApplication::translate("MainMenu", "Comenzi", nullptr));
        ExitButon->setText(QCoreApplication::translate("MainMenu", "Exit", nullptr));
        MeniuPrincipalLabel->setText(QCoreApplication::translate("MainMenu", "<html><head/><body><p><span style=\" font-size:22pt;\">Meniu Principal</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

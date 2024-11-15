/********************************************************************************
** Form generated from reading UI file 'comenzi.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMENZI_H
#define UI_COMENZI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_comenzi
{
public:
    QLabel *label;
    QPushButton *AddComandaButon;
    QPushButton *MeniuInapoiButon;
    QPushButton *StergeComenziButon;
    QListWidget *listWidget;

    void setupUi(QDialog *comenzi)
    {
        if (comenzi->objectName().isEmpty())
            comenzi->setObjectName("comenzi");
        comenzi->resize(523, 574);
        label = new QLabel(comenzi);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 521, 91));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);
        AddComandaButon = new QPushButton(comenzi);
        AddComandaButon->setObjectName("AddComandaButon");
        AddComandaButon->setGeometry(QRect(20, 520, 141, 41));
        MeniuInapoiButon = new QPushButton(comenzi);
        MeniuInapoiButon->setObjectName("MeniuInapoiButon");
        MeniuInapoiButon->setGeometry(QRect(350, 520, 141, 41));
        StergeComenziButon = new QPushButton(comenzi);
        StergeComenziButon->setObjectName("StergeComenziButon");
        StergeComenziButon->setGeometry(QRect(180, 520, 151, 41));
        listWidget = new QListWidget(comenzi);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 90, 521, 411));

        retranslateUi(comenzi);

        QMetaObject::connectSlotsByName(comenzi);
    } // setupUi

    void retranslateUi(QDialog *comenzi)
    {
        comenzi->setWindowTitle(QCoreApplication::translate("comenzi", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("comenzi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">Comenzi</span></p></body></html>", nullptr));
        AddComandaButon->setText(QCoreApplication::translate("comenzi", "Adauga Comenzi", nullptr));
        MeniuInapoiButon->setText(QCoreApplication::translate("comenzi", "Meniu", nullptr));
        StergeComenziButon->setText(QCoreApplication::translate("comenzi", "Sterge Comanda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class comenzi: public Ui_comenzi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMENZI_H

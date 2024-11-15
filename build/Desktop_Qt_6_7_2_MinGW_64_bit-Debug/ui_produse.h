/********************************************************************************
** Form generated from reading UI file 'produse.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUSE_H
#define UI_PRODUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_produse
{
public:
    QPushButton *MeniuProduseButon;
    QPushButton *AddProdusButon;
    QLabel *label;
    QPushButton *StergeProduseButon;
    QListWidget *listWidget;

    void setupUi(QDialog *produse)
    {
        if (produse->objectName().isEmpty())
            produse->setObjectName("produse");
        produse->resize(521, 562);
        MeniuProduseButon = new QPushButton(produse);
        MeniuProduseButon->setObjectName("MeniuProduseButon");
        MeniuProduseButon->setGeometry(QRect(350, 500, 151, 41));
        AddProdusButon = new QPushButton(produse);
        AddProdusButon->setObjectName("AddProdusButon");
        AddProdusButon->setGeometry(QRect(10, 500, 151, 41));
        label = new QLabel(produse);
        label->setObjectName("label");
        label->setGeometry(QRect(2, 0, 521, 81));
        label->setAlignment(Qt::AlignCenter);
        StergeProduseButon = new QPushButton(produse);
        StergeProduseButon->setObjectName("StergeProduseButon");
        StergeProduseButon->setGeometry(QRect(180, 500, 151, 41));
        listWidget = new QListWidget(produse);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 80, 521, 401));

        retranslateUi(produse);

        QMetaObject::connectSlotsByName(produse);
    } // setupUi

    void retranslateUi(QDialog *produse)
    {
        produse->setWindowTitle(QCoreApplication::translate("produse", "Dialog", nullptr));
        MeniuProduseButon->setText(QCoreApplication::translate("produse", "Meniu", nullptr));
        AddProdusButon->setText(QCoreApplication::translate("produse", "Adauga Produs", nullptr));
        label->setText(QCoreApplication::translate("produse", "<html><head/><body><p><span style=\" font-size:22pt;\">Produse</span></p></body></html>", nullptr));
        StergeProduseButon->setText(QCoreApplication::translate("produse", "Sterge Produs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class produse: public Ui_produse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUSE_H

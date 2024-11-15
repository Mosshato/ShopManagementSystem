#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "produse.h"
#include "comenzi.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
    , screenComenzi(nullptr)
    , screenProduse(nullptr)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_ButonProduse_clicked()
{
    hide();
    if(!screenProduse) {
        screenProduse = new produse(this);
    }
    screenProduse->setModal(true);
    screenProduse->exec();
    show();
}

void MainMenu::on_ButonComenzi_clicked()
{
    hide();
    if (!screenComenzi) {
        screenComenzi = new comenzi(this);
    }
    screenComenzi->setModal(true);
    screenComenzi->exec();
    show();
}

void MainMenu::on_ExitButon_clicked()
{
    QApplication::exit();
}

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "comenzi.h"
#include "produse.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_ButonProduse_clicked();
    void on_ButonComenzi_clicked();
    void on_ExitButon_clicked();

private:
    Ui::MainMenu *ui;
    comenzi *screenComenzi;
    produse *screenProduse;
};

#endif // MAINMENU_H

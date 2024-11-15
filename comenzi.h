#ifndef COMENZI_H
#define COMENZI_H

#include <QDialog>

namespace Ui {
class comenzi;
}


class comenzi : public QDialog
{
    Q_OBJECT

public:
    explicit comenzi(QWidget *parent = nullptr);
    ~comenzi();

private slots:
    void on_MeniuInapoiButon_clicked();

    void on_StergeComenziButon_clicked();

    void on_AddComandaButon_clicked();

private:
    Ui::comenzi *ui;
    QWidget *mainMenu;
    void afisareComenzi();
};

#endif // COMENZI_H

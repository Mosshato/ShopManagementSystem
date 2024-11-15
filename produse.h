#ifndef PRODUSE_H
#define PRODUSE_H

#include <QDialog>

namespace Ui {
class produse;
}

class produse : public QDialog
{
    Q_OBJECT

public:
    explicit produse(QWidget *parent = nullptr);
    ~produse();

private slots:
    void on_MeniuProduseButon_clicked();
    void on_StergeProduseButon_clicked();
    void on_AddProdusButon_clicked();

private:
    Ui::produse *ui;
    QWidget *mainMenu;
    void afisareProduse();
    void scrieProduseInFisier();
};

#endif // PRODUSE_H

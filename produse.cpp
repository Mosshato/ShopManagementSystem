#include "produse.h"
#include "ui_produse.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QInputDialog>

produse::produse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::produse)
    , mainMenu(static_cast<QWidget*>(parent))
{
    ui->setupUi(this);
    afisareProduse();
}

produse::~produse()
{
    delete ui;
}

void produse::afisareProduse()
{
    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Produse.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu produsele.");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            QString productInfo = QString("Nume: %1, Cantitate: %2, Pret: %3, Cod de bare: %4")
                                      .arg(fields[0])
                                      .arg(fields[1])
                                      .arg(fields[2])
                                      .arg(fields[3]);
            ui->listWidget->addItem(productInfo);
        }
    }
    file.close();
}

void produse::scrieProduseInFisier()
{
    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Produse.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul pentru scriere.");
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        out << item->text() << "\n";
    }

    file.close();
}

void produse::on_MeniuProduseButon_clicked()
{
    mainMenu->show();
    close();
}

void produse::on_StergeProduseButon_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Eroare", "Selectati un produs pentru stergere.");
        return;
    }

    int response = QMessageBox::question(this, "Confirmare stergere", "Esti sigur ca doresti sa stergi produsul?",
                                         QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::No) {
        return;
    }

    QString itemText = item->text();
    QStringList fields = itemText.split(",");
    QString codDeBare = fields[3].split(":")[1].trimmed();

    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Produse.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu produsele.");
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.contains(codDeBare)) {
            lines.append(line);
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut rescrie fisierul cu produsele.");
        return;
    }

    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << "\n";
    }
    file.close();

    delete item;
}

void produse::on_AddProdusButon_clicked()
{
    bool ok;
    QString numeProdus = QInputDialog::getText(this, "Adaugare produs", "Nume produs:", QLineEdit::Normal, "", &ok);
    if (!ok || numeProdus.isEmpty()) return;

    QString cantitateProdus = QInputDialog::getText(this, "Adaugare produs", "Cantitate produs:", QLineEdit::Normal, "", &ok);
    if (!ok || cantitateProdus.isEmpty()) return;

    QString pretProdus = QInputDialog::getText(this, "Adaugare produs", "Pret produs:", QLineEdit::Normal, "", &ok);
    if (!ok || pretProdus.isEmpty()) return;

    QString codDeBare = QInputDialog::getText(this, "Adaugare produs", "Cod de bare:", QLineEdit::Normal, "", &ok);
    if (!ok || codDeBare.isEmpty()) return;

    QString productInfo = QString("Nume: %1, Cantitate: %2, Pret: %3, Cod de bare: %4")
                              .arg(numeProdus)
                              .arg(cantitateProdus)
                              .arg(pretProdus)
                              .arg(codDeBare);

    ui->listWidget->addItem(productInfo);
    scrieProduseInFisier();
}

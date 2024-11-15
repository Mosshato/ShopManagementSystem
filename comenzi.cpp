#include "comenzi.h"
#include "ui_comenzi.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QInputDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>

comenzi::comenzi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::comenzi)
    , mainMenu(static_cast<QWidget*>(parent))
{
    ui->setupUi(this);
    afisareComenzi();
}

comenzi::~comenzi()
{
    delete ui;
}

void comenzi::afisareComenzi()
{
    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Comenzi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu comenzi.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            QString numarComanda = fields[0].trimmed();
            QString adresaComanda = fields[1].trimmed();
            QString dataComanda = fields[2].trimmed();
            QStringList produseCuCantitati = fields[3].trimmed().split(";");

            QString commandInfo = QString("Numar comanda: %1\nAdresa: %2\nData: %3\nProduse:")
                                      .arg(numarComanda)
                                      .arg(adresaComanda)
                                      .arg(dataComanda);

            for (const QString& produs : produseCuCantitati) {
                QStringList produsSiCantitate = produs.split(":");
                if (produsSiCantitate.size() == 2) {
                    QString numeProdus = produsSiCantitate[0].trimmed();
                    QString cantitateProdus = produsSiCantitate[1].trimmed();
                    commandInfo.append(QString("\n - %1: %2 buc").arg(numeProdus).arg(cantitateProdus));
                }
            }
            ui->listWidget->addItem(commandInfo);
        }
    }

    file.close();
}

void comenzi::on_MeniuInapoiButon_clicked()
{
    mainMenu->show();
    close();
}

void comenzi::on_AddComandaButon_clicked()
{
    QString numarComanda = QInputDialog::getText(this, "Adaugare comanda", "Introduceti numarul comenzii:");
    QString adresaComanda = QInputDialog::getText(this, "Adaugare comanda", "Introduceti adresa comenzii:");
    QString dataComanda = QInputDialog::getText(this, "Adaugare comanda", "Introduceti data comenzii:");

    if (numarComanda.isEmpty() || adresaComanda.isEmpty() || dataComanda.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Toate campurile trebuie completate.");
        return;
    }

    QDialog dialog(this);
    QVBoxLayout layout(&dialog);

    QLabel label("Selectati produsele si introduceti cantitatile:");
    layout.addWidget(&label);

    QList<QPair<QString, QLineEdit*>> produseSiCantitati;
    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Produse.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu produsele.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 4) {
            QString numeProdus = fields[0];
            QLineEdit *cantitateInput = new QLineEdit(&dialog);
            produseSiCantitati.append(qMakePair(numeProdus, cantitateInput));

            QHBoxLayout *productLayout = new QHBoxLayout;
            productLayout->addWidget(new QLabel(numeProdus));
            productLayout->addWidget(cantitateInput);
            layout.addLayout(productLayout);
        }
    }
    file.close();

    QPushButton okButton("OK", &dialog);
    layout.addWidget(&okButton);
    connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    QStringList produseCuCantitati;
    for (const auto &pair : produseSiCantitati) {
        QString numeProdus = pair.first;
        QString cantitate = pair.second->text();
        if (!cantitate.isEmpty()) {
            produseCuCantitati.append(numeProdus + ":" + cantitate);
        }
    }

    if (produseCuCantitati.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Trebuie sa adaugati cel putin un produs.");
        return;
    }

    QString comandaInfo = QString("%1,%2,%3,%4")
                              .arg(numarComanda)
                              .arg(adresaComanda)
                              .arg(dataComanda)
                              .arg(produseCuCantitati.join(";"));

    QFile comenziFile("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Comenzi.txt");
    if (!comenziFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu comenzile.");
        return;
    }

    QTextStream out(&comenziFile);
    out << comandaInfo << "\n";
    comenziFile.close();

    ui->listWidget->addItem(QString("Numar comanda: %1\nAdresa: %2\nData: %3\nProduse:\n%4")
                                .arg(numarComanda)
                                .arg(adresaComanda)
                                .arg(dataComanda)
                                .arg(produseCuCantitati.join("\n")));
}

void comenzi::on_StergeComenziButon_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Eroare", "Nu a fost selectata nicio comanda pentru stergere.");
        return;
    }

    QString commandInfo = selectedItem->text();
    QStringList commandLines = commandInfo.split("\n");
    if (commandLines.size() < 4) {
        QMessageBox::warning(this, "Eroare", "Informatiile comenzii sunt incorecte.");
        return;
    }

    QString numarComanda = commandLines[0].split(":")[1].trimmed();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Stergere comanda", "Esti sigur ca doresti sa stergi comanda?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    QFile file("C:\\Users\\thres\\OneDrive\\Documents\\ShopProiect\\Comenzi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu comenzi.");
        return;
    }

    QStringList allCommands;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.startsWith(numarComanda)) {
            allCommands.append(line);
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fisierul cu comenzi pentru scriere.");
        return;
    }

    QTextStream out(&file);
    for (const QString &command : allCommands) {
        out << command << "\n";
    }
    file.close();

    delete selectedItem;
}

# Shop Management System

A desktop GUI application built with **C++ and Qt** for managing an online shop's products and orders. Data is persisted in plain text files (`Produse.txt`, `Comenzi.txt`).

## Features

- **Products screen** — view, add, and delete products
- **Orders screen** — view, add, and delete orders
- Main menu with navigation between screens

## Tech Stack

- C++ / Qt 6.7
- Qt Widgets (QMainWindow, QDialog)
- Qt Creator / qmake
- MinGW 64-bit

## Project Structure

```
├── main.cpp              # Entry point
├── mainmenu.cpp/.h/.ui   # Main menu window
├── produse.cpp/.h/.ui    # Products screen
├── comenzi.cpp/.h/.ui    # Orders screen
├── Produse.txt           # Product data storage
├── Comenzi.txt           # Order data storage
└── ShopProiect.pro       # qmake project file
```

## Build & Run

**Prerequisites**: Qt 6.7+ with MinGW 64-bit

```bash
# From Qt Creator: open ShopProiect.pro and hit Run
# Or from command line:
qmake ShopProiect.pro
mingw32-make
./ShopProiect.exe
```

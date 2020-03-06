#include "AddObjectDialog.h"

#include <QDebug>

AddObjectDialog::AddObjectDialog(QWidget *parent) : QDialog(parent)
{
    vbox = new QVBoxLayout(this);
    save = new QPushButton("Übernehmen");
    connect(save, SIGNAL(pressed()), this, SLOT(savePressed()));
}

void AddObjectDialog::insertWidget(QWidget *w)
{
    layout()->addWidget(w);
    layout()->addWidget(save);
}

void AddObjectDialog::savePressed() { accept(); }

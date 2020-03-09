#include "EditTableDialog.h"

#include "Dialogs/AddObjectDialog.h"
#include "Widgets/AddTextFieldWidget.h"

EditTableDialog::EditTableDialog(TableWidget *input, QWidget *parent) : QDialog(parent)
{
    tableWidget = input;

    vbox = new QVBoxLayout(this);

    buttonWidget = new QWidget();
    buttonLayout = new QHBoxLayout(buttonWidget);
    addRow = new QPushButton("Neue Zeile");
    addColumn = new QPushButton("Neue Überschrift");
    save = new QPushButton("Speichern");

    buttonLayout->addWidget(addRow);
    buttonLayout->addWidget(addColumn);
    buttonLayout->addWidget(save);


    vbox->addWidget(tableWidget);
    vbox->addWidget(buttonWidget);

    connect(save, SIGNAL(pressed()), this, SLOT(savePressed()));
    connect(addRow, SIGNAL(pressed()), this, SLOT(addRowPressed()));
    connect(addColumn, SIGNAL(pressed()), this, SLOT(addColumnPressed()));
}

void EditTableDialog::savePressed()
{
    tableWidget->setHeaderListToData();
    accept();
}

void EditTableDialog::addRowPressed() { tableWidget->addRow(); }

void EditTableDialog::addColumnPressed()
{

    AddObjectDialog *dia = new AddObjectDialog();
    AddTextFieldWidget *w = new AddTextFieldWidget();

    dia->insertWidget(w);

    if (dia->exec() == QDialog::Accepted)
    {
        tableWidget->addColumn(w->getLineEdit());
        dia->close();
    }
}

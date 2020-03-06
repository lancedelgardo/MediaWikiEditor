#include "WidgetsController.h"

#include "Dialogs/AddObjectDialog.h"
#include "Widgets/AddTextFieldWidget.h"
#include "Widgets/AddBoolWidget.h"
#include "Widgets/AddTableWidget.h"

#include "Widgets/TableWidget.h"
#include "Dialogs/EditTableDialog.h"


WidgetsController::WidgetsController(QObject *parent) : QObject(parent)
{
    inputWidget = new InputWidget();
    connect(inputWidget, SIGNAL(s_tableButtonPressed(TableData *)), this, SLOT(onTableButtonPressed(TableData *)));
}

void WidgetsController::addTextField()
{
    AddObjectDialog *dia = new AddObjectDialog();
    AddTextFieldWidget *w = new AddTextFieldWidget();

    dia->insertWidget(w);

    if (dia->exec() == QDialog::Accepted)
    {
        textFieldAdded(w->getLineEdit());
        dia->close();
    }
}

void WidgetsController::addBool()
{
    AddObjectDialog *dia = new AddObjectDialog();
    AddBoolWidget *w = new AddBoolWidget();

    dia->insertWidget(w);

    if (dia->exec() == QDialog::Accepted)
    {
        boolAdded(w->getLineEdit());
        dia->close();
    }
}

void WidgetsController::addTable()
{
    AddObjectDialog *dia = new AddObjectDialog();
    AddTableWidget *w = new AddTableWidget();

    dia->insertWidget(w);

    if (dia->exec() == QDialog::Accepted)
    {
        tableAdded(w->getLineEdit());
        dia->close();
    }
}

void WidgetsController::textFieldAdded(const QString &name) { inputWidget->addTextField(name); }

void WidgetsController::boolAdded(const QString &name) { inputWidget->addBool(name); }

void WidgetsController::tableAdded(const QString &name) { inputWidget->addTable(name); }

InputWidget *WidgetsController::getInputWidget() const { return inputWidget; }

void WidgetsController::onTableButtonPressed(TableData *data)
{
    TableWidget *w = new TableWidget(data);
    EditTableDialog *dia = new EditTableDialog(w);

    if (dia->exec() == QDialog::Accepted)
    {
        dia->close();
    }
}

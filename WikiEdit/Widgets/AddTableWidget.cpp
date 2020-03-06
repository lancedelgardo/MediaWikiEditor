#include "AddTableWidget.h"

AddTableWidget::AddTableWidget(QWidget *parent) : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    lineEdit = new QLineEdit();
    label = new QLabel("Name");

    vbox->addWidget(label);
    vbox->addWidget(lineEdit);
}

QString AddTableWidget::getLineEdit() const { return lineEdit->text(); }

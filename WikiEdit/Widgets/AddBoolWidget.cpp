#include "AddBoolWidget.h"

AddBoolWidget::AddBoolWidget(QWidget *parent) : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    lineEdit = new QLineEdit();
    label = new QLabel("Name");

    vbox->addWidget(label);
    vbox->addWidget(lineEdit);
}

QString AddBoolWidget::getLineEdit() const { return lineEdit->text(); }

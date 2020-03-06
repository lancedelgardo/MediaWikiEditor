#include "AddTextFieldWidget.h"

AddTextFieldWidget::AddTextFieldWidget(QWidget *parent) : QWidget(parent)
{
    vbox = new QVBoxLayout(this);
    lineEdit = new QLineEdit();
    label = new QLabel("Name");

    vbox->addWidget(label);
    vbox->addWidget(lineEdit);
}

QString AddTextFieldWidget::getLineEdit() const { return lineEdit->text(); }

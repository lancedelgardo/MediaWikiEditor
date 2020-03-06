#include "InputWidget.h"

#include <QTextEdit>
#include <QCheckBox>


#include <QDebug>

InputWidget::InputWidget(QWidget *parent) : QWidget(parent) { formLayout = new QFormLayout(this); }

void InputWidget::addTextField(const QString &name)
{
    QTextEdit *te = new QTextEdit(this);
    widgets.append(te);
    te->setObjectName(QString::number(widgets.size()) + name);
    formLayout->addRow(name, te);
}

void InputWidget::addBool(const QString &name)
{
    QCheckBox *cb = new QCheckBox(this);
    widgets.append(cb);
    cb->setObjectName(QString::number(widgets.size()) + name);
    formLayout->addRow(name, cb);
}

void InputWidget::addTable(const QString &name)
{
    QPushButton *pb = new QPushButton("Bearbeiten", this);
    widgets.append(pb);
    pb->setObjectName(QString::number(widgets.size()) + name);
    formLayout->addRow(name, pb);

    TableData *td = new TableData();

    tableDatas.insert(pb, td);

    connect(pb, SIGNAL(pressed()), this, SLOT(onTableButtonPressed()));
}

void InputWidget::onTableButtonPressed()
{
    QPushButton *pb = static_cast< QPushButton * >(sender());

    s_tableButtonPressed(tableDatas.value(pb));
}

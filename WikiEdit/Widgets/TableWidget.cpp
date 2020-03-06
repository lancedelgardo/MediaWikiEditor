#include "TableWidget.h"

TableWidget::TableWidget(QWidget *parent) : QTableWidget(parent)
{
    setShowGrid(true);
    setEditTriggers(QAbstractItemView::DoubleClicked);

    setAlternatingRowColors(true);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setColumnCount(1);
}

TableWidget::TableWidget(TableData *data, QWidget *parent)
{
    tableData = data;

    setShowGrid(true);
    setEditTriggers(QAbstractItemView::DoubleClicked);

    setAlternatingRowColors(true);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setColumnCount(tableData->getColumns());
}

void TableWidget::addRow()
{
    int row = rowCount();

    for (int i = 0; i < columnCount(); i++)
    {
        setItem(row, i, new QTableWidgetItem(""));
    }

    setRowCount(rowCount() + 1);
}

void TableWidget::addColumn(const QString &name)
{
    tableData->addColumn(name);

    setColumnCount(tableData->getColumnNames().count());

    QStringList headerlist;

    for (int i = 0; i < tableData->getColumnNames().count(); i++)
    {
        headerlist << tableData->getColumnNames()[i];
    }

    setHorizontalHeaderLabels(headerlist);
}

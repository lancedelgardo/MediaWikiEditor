#include "TableWidget.h"

TableWidget::TableWidget(QWidget *parent) : QTableWidget(parent)
{
    setShowGrid(true);
    setEditTriggers(QAbstractItemView::DoubleClicked);

    setAlternatingRowColors(true);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setColumnCount(1);
    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(onCellChanged(int, int)));
}

TableWidget::TableWidget(TableData *data, QWidget *parent)
{
    tableData = data;

    setShowGrid(true);
    setEditTriggers(QAbstractItemView::DoubleClicked);

    setAlternatingRowColors(true);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setColumnCount(tableData->getColumnCount());
    setRowCount(tableData->getRowCount());


    if (!tableData->getCellData().isEmpty())
    {
        foreach (auto it, tableData->getCellData())
        {
            setItem(it->getRow(), it->getColumn(), new QTableWidgetItem(it->getText()));
        }
    }

    if (!tableData->getHeaderLabels().isEmpty())
    {
        setHorizontalHeaderLabels(tableData->getHeaderLabels());
    }

    connect(this, SIGNAL(cellChanged(int, int)), this, SLOT(onCellChanged(int, int)));
}

void TableWidget::addRow()
{
    int row = rowCount();

    for (int i = 0; i < columnCount(); i++)
    {
        setItem(row, i, new QTableWidgetItem(""));
    }

    setRowCount(rowCount() + 1);

    tableData->setRowCount(rowCount());
}

void TableWidget::addColumn(const QString &name)
{
    tableData->addColumn(name);

    setColumnCount(columnCount() + 1);

    tableData->setColumnCount(columnCount());

    //    QStringList headerlist;

    //    for (int i = 0; i < tableData->getHeaderLabels().count(); i++)
    //    {
    //        headerlist << tableData->getHeaderLabels()[i];
    //    }

    setHorizontalHeaderLabels(tableData->getHeaderLabels());
}

void TableWidget::addRow(const QString &text)
{
    int row = rowCount();

    for (int i = 0; i < columnCount(); i++)
    {
        setItem(row, i, new QTableWidgetItem(text));
    }

    setRowCount(rowCount() + 1);

    tableData->setRowCount(rowCount());
}

QStringList TableWidget::setHeaderListToData()
{
    QStringList headerLabels;

    for (int i = 0; i < columnCount(); i++)
    {
        headerLabels << horizontalHeaderItem(i)->text();
    }

    if (tableData) tableData->setHeaderLabels(headerLabels);

    return headerLabels;
}

void TableWidget::setRowToData() {}

void TableWidget::onCellChanged(int row, int column) { tableData->addCellData(new TableRowData(row, column, item(row, column)->text())); }

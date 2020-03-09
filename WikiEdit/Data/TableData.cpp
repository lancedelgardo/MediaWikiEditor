#include "TableData.h"

TableData::TableData(QObject *parent) : QObject(parent) {}

void TableData::addColumn(const QString &name) { headerLabels.append(name); }

QStringList TableData::getHeaderLabels() const { return headerLabels; }

void TableData::setHeaderLabels(const QStringList &value) { headerLabels = value; }

int TableData::getRowCount() const { return rowCount; }

void TableData::setRowCount(int value) { rowCount = value; }

int TableData::getColumnCount() const { return columnCount; }

void TableData::setColumnCount(int value) { columnCount = value; }

QList< TableRowData * > TableData::getCellData() const { return cellData; }

void TableData::addCellData(TableRowData *data)
{
    //

    foreach (auto cd, cellData)
    {
        if (cd->getRow() == data->getRow() && cd->getColumn() == data->getColumn())
        {
            cd->setText(data->getText());
            return;
        }
    }

    cellData.append(data);
}

TableRowData *TableData::getCellData(int row, int column)
{
    foreach (auto cd, cellData)
    {
        if (cd->getRow() == row && cd->getColumn() == column)
        {
            return cd;
        }
    }
}

void TableData::clearCellData() { cellData.clear(); }

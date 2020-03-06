#include "TableData.h"

TableData::TableData(QObject *parent) : QObject(parent) {}

void TableData::addColumn(const QString &name) { columnNames.append(name); }

int TableData::getColumns() { return columnNames.count(); }

QList< QString > TableData::getColumnNames() const { return columnNames; }

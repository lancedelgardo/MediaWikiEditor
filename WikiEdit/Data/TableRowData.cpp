#include "TableRowData.h"

TableRowData::TableRowData(int row, int column, const QString &text, QObject *parent) : QObject(parent)
{
    this->row = row;
    this->column = column;
    this->text = text;
}

int TableRowData::getRow() const { return row; }

void TableRowData::setRow(int value) { row = value; }

int TableRowData::getColumn() const { return column; }

void TableRowData::setColumn(int value) { column = value; }

QString TableRowData::getText() const { return text; }

void TableRowData::setText(const QString &value) { text = value; }

void TableRowData::toJson(QJsonObject &json)
{
    json["Text"] = text;
    json["Row"] = row;
    json["Column"] = column;
}

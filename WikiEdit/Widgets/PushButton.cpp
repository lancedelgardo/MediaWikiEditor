#include "PushButton.h"

#include <QJsonArray>

PushButton::PushButton(const QString &text, QWidget *parent) : QPushButton(text, parent), LayoutItem()
{
    type = LayoutItem::Type::PB;
    label = text;
}

void PushButton::toJson(TableData *data, QJsonObject &json)
{
    QJsonArray array;

    QString headerString;

    foreach (auto s, data->getHeaderLabels())
    {
        headerString += s;
        headerString += ",";
    }

    foreach (auto cd, data->getCellData())
    {
        QJsonObject jsonCellData;
        cd->toJson(jsonCellData);
        array.append(jsonCellData);
    }

    //    json["Name"] = label;
    json["Header"] = headerString;
    json["CellData"] = array;
    json["Type"] = type;
}

void PushButton::toJsonModel(TableData *data, QJsonObject &json)
{
    QJsonArray array;

    QString headerString;

    foreach (auto s, data->getHeaderLabels())
    {
        headerString += s;
        headerString += ",";
    }

    json["Header"] = headerString;
    json["CellData"] = array;
    json["Type"] = type;
}

void PushButton::fromJson(TableData *data, QJsonObject &json)
{
    QString header;
    if (json.contains("Header")) header = json["Header"].toString();

    QStringList sl = header.split(",");
    sl.removeLast();

    data->setHeaderLabels(sl);


    if (!json.contains("CellData") || !json["CellData"].isArray()) return;

    auto cellArray = json["CellData"].toArray();

    int rowCount = 0;
    foreach (auto cellArrayData, cellArray)
    {
        if (!cellArrayData.isObject()) return;
        auto cellArrayObject = cellArrayData.toObject();
        int row;
        int column;
        QString text;

        if (cellArrayObject.contains("Row")) row = cellArrayObject["Row"].toInt();
        if (cellArrayObject.contains("Column")) column = cellArrayObject["Column"].toInt();
        if (cellArrayObject.contains("Text")) text = cellArrayObject["Text"].toString();

        TableRowData *cd = new TableRowData(row, column, text);

        data->addCellData(cd);

        if (row > rowCount) rowCount = row;
    }

    data->setColumnCount(sl.size());
    data->setRowCount(rowCount + 1);
}

QString PushButton::getLabel() const { return label; }

void PushButton::setLabel(const QString &value) { label = value; }

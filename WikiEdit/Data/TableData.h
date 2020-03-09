#ifndef TABLEDATA_H
#define TABLEDATA_H

#include "TableRowData.h"

#include <QObject>

class TableData : public QObject
{
    Q_OBJECT
  public:
    explicit TableData(QObject *parent = nullptr);

    void addColumn(const QString &name);
    int getColumns();

    QStringList getHeaderLabels() const;
    void setHeaderLabels(const QStringList &value);

    int getRowCount() const;
    void setRowCount(int value);

    int getColumnCount() const;
    void setColumnCount(int value);

    QList< TableRowData * > getCellData() const;
    void addCellData(TableRowData *data);
    TableRowData *getCellData(int row, int column);

    void clearCellData();

  signals:

  public slots:

  private:
    QStringList headerLabels;
    QList< TableRowData * > cellData;

    int rowCount = 0;
    int columnCount = 0;
};

#endif  // TABLEDATA_H

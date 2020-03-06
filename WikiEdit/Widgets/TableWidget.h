#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include "Data/TableData.h"

#include <QTableWidget>

class TableWidget : public QTableWidget
{
    Q_OBJECT
  public:
    explicit TableWidget(QWidget *parent = nullptr);
    explicit TableWidget(TableData *data, QWidget *parent = nullptr);

    void addRow();
    void addColumn(const QString &name);

  signals:

  public slots:

  private:
    TableData *tableData = Q_NULLPTR;
};

#endif  // TABLEWIDGET_H

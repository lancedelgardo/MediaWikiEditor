#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <QObject>

class TableData : public QObject
{
    Q_OBJECT
  public:
    explicit TableData(QObject *parent = nullptr);

    void addColumn(const QString &name);
    int getColumns();

    QList< QString > getColumnNames() const;

  signals:

  public slots:

  private:
    QList< QString > columnNames;
};

#endif  // TABLEDATA_H

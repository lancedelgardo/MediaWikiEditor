#ifndef TABLEROWDATA_H
#define TABLEROWDATA_H

#include <QObject>
#include <QJsonObject>

class TableRowData : public QObject
{
    Q_OBJECT
  public:
    explicit TableRowData(int row, int column, const QString &text, QObject *parent = nullptr);

    int getRow() const;
    void setRow(int value);

    int getColumn() const;
    void setColumn(int value);

    QString getText() const;
    void setText(const QString &value);

    void toJson(QJsonObject &json);

  signals:

  public slots:

  private:
    int row = -1;
    int column = -1;
    QString text;
};

#endif  // TABLEROWDATA_H

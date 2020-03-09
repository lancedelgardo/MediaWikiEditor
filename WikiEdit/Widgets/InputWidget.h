#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include "Data/TableData.h"
#include "LayoutItem.h"

#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QMap>
#include <QJsonObject>

class InputWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit InputWidget(QWidget *parent = nullptr);

    void addTextField(const QString &name);
    void addBool(const QString &name);
    void addTable(const QString &name);

    void insertTextField();
    void insertBool();
    void insertTable();

    void save(const QString &filename);
    void saveModel(const QString &filename);
    bool load(const QString &filename);

    void clearAll();

    QList< LayoutItem * > getWidgets() const;

    QMap< LayoutItem *, TableData * > getTableDatas() const;

    void toJsonModel(QJsonObject &json);


  signals:
    void s_tableButtonPressed(TableData *data);


  public slots:

  private slots:
    void onTableButtonPressed();

  private:
    void fromJson(const QJsonObject &json);
    void toJson(QJsonObject &json);

    QFormLayout *formLayout = Q_NULLPTR;

    QList< LayoutItem * > widgets;
    QMap< LayoutItem *, TableData * > tableDatas;
};

#endif  // INPUTWIDGET_H

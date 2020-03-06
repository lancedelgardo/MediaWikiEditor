#ifndef WIDGETSCONTROLLER_H
#define WIDGETSCONTROLLER_H

#include "Widgets/InputWidget.h"

#include <QObject>

class WidgetsController : public QObject
{
    Q_OBJECT
  public:
    explicit WidgetsController(QObject *parent = nullptr);

    void addTextField();
    void addBool();
    void addTable();

    InputWidget *getInputWidget() const;

  signals:

  public slots:

  private slots:
    void onTableButtonPressed(TableData *data);

  private:
    void textFieldAdded(const QString &name);
    void boolAdded(const QString &name);
    void tableAdded(const QString &name);

    InputWidget *inputWidget = Q_NULLPTR;
};

#endif  // WIDGETSCONTROLLER_H

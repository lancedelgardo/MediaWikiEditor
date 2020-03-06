#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include "Data/TableData.h"

#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QMap>

class InputWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit InputWidget(QWidget *parent = nullptr);

    void addTextField(const QString &name);
    void addBool(const QString &name);
    void addTable(const QString &name);

  signals:
    void s_tableButtonPressed(TableData *data);


  public slots:

  private slots:
    void onTableButtonPressed();

  private:
    QFormLayout *formLayout = Q_NULLPTR;

    QList< QWidget * > widgets;
    QMap< QPushButton *, TableData * > tableDatas;
};

#endif  // INPUTWIDGET_H

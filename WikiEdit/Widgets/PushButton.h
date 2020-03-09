#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "LayoutItem.h"
#include "Data/TableData.h"

#include <QPushButton>
#include <QJsonObject>

class PushButton : public QPushButton, public LayoutItem
{
  public:
    PushButton(const QString &text, QWidget *parent = Q_NULLPTR);

    void toJson(TableData *data, QJsonObject &json);
    void fromJson(TableData *data, QJsonObject &json);

    QString getLabel() const;
    void setLabel(const QString &value);

    void toJsonModel(TableData *data, QJsonObject &json);

  private:
    QString label;
};

#endif  // PUSHBUTTON_H

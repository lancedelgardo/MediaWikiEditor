#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "LayoutItem.h"

#include <QCheckBox>

class CheckBox : public QCheckBox, public LayoutItem
{
  public:
    CheckBox(QWidget *parent = Q_NULLPTR);
};

#endif  // CHECKBOX_H

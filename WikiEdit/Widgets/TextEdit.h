#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "LayoutItem.h"
#include "Data/TableData.h"

#include <QTextEdit>

class TextEdit : public QTextEdit, public LayoutItem
{
  public:
    TextEdit(QWidget *parent = Q_NULLPTR);
};

#endif  // TEXTEDIT_H

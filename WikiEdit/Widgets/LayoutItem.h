#ifndef LAYOUTITEM_H
#define LAYOUTITEM_H

#include <QWidget>

class LayoutItem
{

  public:
    enum Type
    {
        PB,
        Text,
        CheckBox
    };

    explicit LayoutItem();


    Type getType() const;

  signals:

  public slots:

  protected:
    Type type;
};

#endif  // LAYOUTITEM_H

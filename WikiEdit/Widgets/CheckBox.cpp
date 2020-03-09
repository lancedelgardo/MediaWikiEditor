#include "CheckBox.h"

CheckBox::CheckBox(QWidget *parent) : QCheckBox(parent), LayoutItem() { type = LayoutItem::Type::CheckBox; }

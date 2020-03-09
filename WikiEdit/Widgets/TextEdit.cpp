#include "TextEdit.h"

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent), LayoutItem() { type = LayoutItem::Type::Text; }

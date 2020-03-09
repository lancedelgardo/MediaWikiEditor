#include "OutputGenerator.h"

#include "Widgets/TextEdit.h"
#include "Widgets/CheckBox.h"
#include "Widgets/PushButton.h"

OutputGenerator::OutputGenerator() {}

QStringList OutputGenerator::generateOutput(QList< LayoutItem * > widgets, QMap< LayoutItem *, TableData * > tableDatas)
{
    QStringList str;

    foreach (auto w, widgets)
    {
        switch (w->getType())
        {
            case LayoutItem::Type::PB:
                genTableOutput(str, w, tableDatas);
                break;
            case LayoutItem::Type::Text:
                genTextFieldOutput(str, w);
                break;
            case LayoutItem::Type::CheckBox:
                genBoolOutput(str, w);
                break;
        }
    }

    return str;
}

void OutputGenerator::genTableOutput(QStringList &strlist, LayoutItem *layoutItem, QMap< LayoutItem *, TableData * > tableDatas)
{
    QString str;
    PushButton *pb = static_cast< PushButton * >(layoutItem);

    str = "=";
    str += pb->objectName();
    str += "=";

    strlist.append(str);
    strlist.append("\n");

    strlist.append("<tab class=wikitable sep=bar head=top>");
    strlist.append("\n");

    TableData *tb = tableDatas.value(layoutItem);
    str = "";
    for (int i = 0; i < tb->getHeaderLabels().size(); i++)
    {
        str += tb->getHeaderLabels()[i];
        if (i < tb->getHeaderLabels().size() - 1) str += " | ";
    }

    strlist.append(str);
    strlist.append("\n");
    str = "";

    int columns = tb->getHeaderLabels().size();
    int count = 0;


    foreach (auto cd, tb->getCellData())
    {
        if (count != columns)
        {
            str += cd->getText();
            count++;
            if (count != columns) str += " | ";
        }
        else
        {
            strlist.append(str);
            str = "";
            strlist.append("\n");
            count = 0;
            str += cd->getText();
            count++;
            if (count != columns) str += " | ";
        }
    }

    strlist.append(str);
    str = "";


    strlist.append("\n");
    strlist.append("</tab>");
    strlist.append("\n");
    strlist.append("\n");
    //
}

void OutputGenerator::genTextFieldOutput(QStringList &strlist, LayoutItem *layoutItem)
{
    QString str;
    TextEdit *te = static_cast< TextEdit * >(layoutItem);

    str = "=";
    str += te->objectName();
    str += "=";

    strlist.append(str);
    strlist.append("\n");

    strlist.append(te->toPlainText());
    strlist.append("\n");
    strlist.append("\n");
    //
}


void OutputGenerator::genBoolOutput(QStringList &strlist, LayoutItem *layoutItem)
{
    QString str;
    CheckBox *cb = static_cast< CheckBox * >(layoutItem);

    str = "=";
    str += cb->objectName();
    str += "=";

    strlist.append(str);
    strlist.append("\n");

    if (cb->isChecked())
        strlist.append("Ja");
    else
        strlist.append("Nein");
    strlist.append("\n");
    strlist.append("\n");
}

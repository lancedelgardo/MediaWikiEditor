#ifndef OUTPUTGENERATOR_H
#define OUTPUTGENERATOR_H

#include "Widgets/LayoutItem.h"
#include "Data/TableData.h"

#include <QString>
#include <QMap>
#include <QList>

class OutputGenerator
{
  public:
    OutputGenerator();

    QStringList generateOutput(QList< LayoutItem * > widgets, QMap< LayoutItem *, TableData * > tableDatas);

  private:
    void genTableOutput(QStringList &strlist, LayoutItem *layoutItem, QMap< LayoutItem *, TableData * > tableDatas);
    void genTextFieldOutput(QStringList &strlist, LayoutItem *layoutItem);
    void genBoolOutput(QStringList &strlist, LayoutItem *layoutItem);
};

#endif  // OUTPUTGENERATOR_H

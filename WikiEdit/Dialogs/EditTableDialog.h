#ifndef EDITTABLEDIALOG_H
#define EDITTABLEDIALOG_H

#include "Widgets/TableWidget.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class EditTableDialog : public QDialog
{
    Q_OBJECT
  public:
    EditTableDialog(TableWidget *input, QWidget *parent = Q_NULLPTR);

  private slots:
    void savePressed();
    void addRowPressed();
    void addColumnPressed();


  private:
    TableWidget *tableWidget = Q_NULLPTR;

    QVBoxLayout *vbox = Q_NULLPTR;

    QWidget *buttonWidget = Q_NULLPTR;
    QHBoxLayout *buttonLayout = Q_NULLPTR;
    QPushButton *addRow = Q_NULLPTR;
    QPushButton *addColumn = Q_NULLPTR;
    QPushButton *save = Q_NULLPTR;
};

#endif  // EDITTABLEDIALOG_H

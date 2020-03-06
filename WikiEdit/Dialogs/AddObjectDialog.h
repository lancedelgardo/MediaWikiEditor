#ifndef ADDOBJECTDIALOG_H
#define ADDOBJECTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>

class AddObjectDialog : public QDialog
{
    Q_OBJECT
  public:
    AddObjectDialog(QWidget *parent = Q_NULLPTR);
    void insertWidget(QWidget *w);

  private slots:
    void savePressed();

  private:
    QVBoxLayout *vbox = Q_NULLPTR;
    QPushButton *save = Q_NULLPTR;
};

#endif  // ADDOBJECTDIALOG_H

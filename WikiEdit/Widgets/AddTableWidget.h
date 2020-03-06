#ifndef ADDTABLEWIDGET_H
#define ADDTABLEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class AddTableWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit AddTableWidget(QWidget *parent = nullptr);

    QString getLineEdit() const;

  signals:

  public slots:

  private:
    QVBoxLayout *vbox = Q_NULLPTR;
    QLineEdit *lineEdit = Q_NULLPTR;
    QLabel *label = Q_NULLPTR;
};

#endif  // ADDTABLEWIDGET_H

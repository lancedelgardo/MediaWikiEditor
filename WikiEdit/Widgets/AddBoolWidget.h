#ifndef ADDBOOLWIDGET_H
#define ADDBOOLWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class AddBoolWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit AddBoolWidget(QWidget *parent = nullptr);

    QString getLineEdit() const;

  signals:

  public slots:

  private:
    QVBoxLayout *vbox = Q_NULLPTR;
    QLineEdit *lineEdit = Q_NULLPTR;
    QLabel *label = Q_NULLPTR;
};

#endif  // ADDBOOLWIDGET_H

#ifndef ADDTEXTFIELDWIDGET_H
#define ADDTEXTFIELDWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class AddTextFieldWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit AddTextFieldWidget(QWidget *parent = nullptr);

    QString getLineEdit() const;

  signals:

  public slots:

  private:
    QVBoxLayout *vbox = Q_NULLPTR;
    QLineEdit *lineEdit = Q_NULLPTR;
    QLabel *label = Q_NULLPTR;
};

#endif  // ADDTEXTFIELDWIDGET_H

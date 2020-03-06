#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Controller/WidgetsController.h"

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    void on_addTextfield_triggered();

    void on_addBool_triggered();

    void on_addTable_triggered();

  private:
    Ui::MainWindow *ui;

    WidgetsController *widgetController = Q_NULLPTR;
};

#endif  // MAINWINDOW_H

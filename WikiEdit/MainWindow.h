#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Controller/WidgetsController.h"
#include "Controller/OutputGenerator.h"


#include <QMainWindow>
#include <QDir>


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

    void on_actionSave_triggered();

    void on_generateOutput_triggered();

    void on_actionSaveModel_triggered();

    void on_actionLoad_triggered();

    void on_actionNew_triggered();

  private:
    Ui::MainWindow *ui;

    WidgetsController *widgetController = Q_NULLPTR;

    OutputGenerator *outputGenerator = Q_NULLPTR;

    QString lastOpenedPath = QDir::homePath();
};

#endif  // MAINWINDOW_H

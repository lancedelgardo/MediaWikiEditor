#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgetController = new WidgetsController(this);

    ui->centralWidget->layout()->addWidget(widgetController->getInputWidget());
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_addTextfield_triggered() { widgetController->addTextField(); }

void MainWindow::on_addBool_triggered() { widgetController->addBool(); }

void MainWindow::on_addTable_triggered() { widgetController->addTable(); }

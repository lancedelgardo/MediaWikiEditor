#include "MainWindow.h"
#include "ui_MainWindow.h"


#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgetController = new WidgetsController(this);

    ui->inputWidget->layout()->addWidget(widgetController->getInputWidget());

    outputGenerator = new OutputGenerator();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_addTextfield_triggered() { widgetController->addTextField(); }

void MainWindow::on_addBool_triggered() { widgetController->addBool(); }

void MainWindow::on_addTable_triggered() { widgetController->addTable(); }

void MainWindow::on_actionSave_triggered()
{
    QFileDialog configExportDialog(this);
    QString exportPath = configExportDialog.getSaveFileName(this, QObject::tr("Eintrag Speichern"), lastOpenedPath, QObject::tr("JSON (*.json)"));
    if (exportPath == "") return;
    if (!exportPath.contains("json")) exportPath.append(".json");

    widgetController->save(exportPath);

    QFileInfo fileInfo(exportPath);
    QString _path(fileInfo.path());
    lastOpenedPath = _path;
}

void MainWindow::on_generateOutput_triggered()
{

    QStringList str = outputGenerator->generateOutput(widgetController->getInputWidget()->getWidgets(), widgetController->getInputWidget()->getTableDatas());

    QString text;

    ui->plainTextEdit->clear();

    foreach (auto s, str)
    {
        text += s;
    }

    ui->plainTextEdit->insertPlainText(text);
}

void MainWindow::on_actionSaveModel_triggered()
{
    QFileDialog configExportDialog(this);
    QString exportPath = configExportDialog.getSaveFileName(this, QObject::tr("Vorlage Speichern"), lastOpenedPath, QObject::tr("JSON (*.json)"));
    if (exportPath == "") return;
    if (!exportPath.contains("json")) exportPath.append(".json");

    widgetController->saveModel(exportPath);

    QFileInfo fileInfo(exportPath);
    QString _path(fileInfo.path());
    lastOpenedPath = _path;
}

void MainWindow::on_actionLoad_triggered()
{
    on_actionNew_triggered();

    QFileDialog configExportDialog(this);
    QString exportPath = configExportDialog.getOpenFileName(this, QObject::tr("Vorlage Laden"), lastOpenedPath, QObject::tr("JSON (*.json)"));
    if (exportPath == "") return;
    if (!exportPath.contains("json")) exportPath.append(".json");

    widgetController->load(exportPath);

    QFileInfo fileInfo(exportPath);
    QString _path(fileInfo.path());
    lastOpenedPath = _path;
}

void MainWindow::on_actionNew_triggered() { widgetController->clearAll(); }

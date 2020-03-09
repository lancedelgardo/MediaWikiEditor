#include "InputWidget.h"

#include "PushButton.h"
#include "TextEdit.h"
#include "CheckBox.h"
#include "Data/TableData.h"

#include <QTextEdit>
#include <QCheckBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

#include <QDebug>

InputWidget::InputWidget(QWidget *parent) : QWidget(parent) { formLayout = new QFormLayout(this); }

void InputWidget::addTextField(const QString &name)
{
    LayoutItem *te = new TextEdit(this);
    widgets.append(te);
    static_cast< TextEdit * >(te)->setObjectName(/*QString::number(widgets.size()) + */ name);
    formLayout->addRow(name, static_cast< TextEdit * >(te));
}

void InputWidget::addBool(const QString &name)
{
    LayoutItem *cb = new CheckBox(this);
    widgets.append(cb);
    static_cast< CheckBox * >(cb)->setObjectName(/*QString::number(widgets.size()) +*/ name);
    formLayout->addRow(name, static_cast< CheckBox * >(cb));
}

void InputWidget::addTable(const QString &name)
{
    LayoutItem *pb = new PushButton("Bearbeiten", this);
    widgets.append(pb);
    static_cast< PushButton * >(pb)->setObjectName(/*QString::number(widgets.size()) +*/ name);

    formLayout->addRow(name, static_cast< PushButton * >(pb));

    TableData *td = new TableData();

    tableDatas.insert(pb, td);

    connect(static_cast< PushButton * >(pb), SIGNAL(pressed()), this, SLOT(onTableButtonPressed()));
}

void InputWidget::save(const QString &filename)
{
    QJsonObject rootObject;

    toJson(rootObject);

    QJsonDocument doc;
    doc.setObject(rootObject);

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.flush();
    file.close();
    qInfo() << "Konfiguration in Datei gespeichert " << filename;
}

void InputWidget::saveModel(const QString &filename)
{
    QJsonObject rootObject;

    toJsonModel(rootObject);

    QJsonDocument doc;
    doc.setObject(rootObject);

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.flush();
    file.close();
    qInfo() << "Konfiguration in Datei gespeichert " << filename;
}

bool InputWidget::load(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonObject rootObject = doc.object();

    fromJson(rootObject);

    return true;
}

void InputWidget::clearAll()
{
    foreach (LayoutItem *w, widgets)
    {
        foreach (TableData *d, tableDatas.values(w))
        {
            d = Q_NULLPTR;
            delete d;
        }

        w = Q_NULLPTR;
        delete w;

        formLayout->removeRow(0);
    }
    widgets.clear();
    tableDatas.clear();
}

void InputWidget::fromJson(const QJsonObject &json)
{
    widgets.clear();
    tableDatas.clear();
    if (!json.contains("Data") || !json["Data"].isArray()) return;

    auto array = json["Data"].toArray();

    foreach (auto arrayItem, array)
    {
        if (!arrayItem.isObject()) continue;
        auto jsonData = arrayItem.toObject();

        int type;

        if (jsonData.contains("Type")) type = jsonData["Type"].toInt();

        switch (type)
        {
            case LayoutItem::Type::PB:
            {
                QString name;

                if (jsonData.contains("Name")) name = jsonData["Name"].toString();

                LayoutItem *pb = new PushButton(name, this);
                widgets.append(pb);

                static_cast< PushButton * >(pb)->setObjectName(/*QString::number(widgets.size()) + */ name);

                formLayout->addRow(name, static_cast< TextEdit * >(pb));

                TableData *td = new TableData();

                static_cast< PushButton * >(pb)->fromJson(td, jsonData);

                tableDatas.insert(pb, td);

                connect(static_cast< PushButton * >(pb), SIGNAL(pressed()), this, SLOT(onTableButtonPressed()));
            }
            break;
            case LayoutItem::Type::Text:
            {
                QString name;
                QString text;

                if (jsonData.contains("Name")) name = jsonData["Name"].toString();
                if (jsonData.contains("Text")) text = jsonData["Text"].toString();

                LayoutItem *te = new TextEdit(this);
                widgets.append(te);
                static_cast< TextEdit * >(te)->setObjectName(/*QString::number(widgets.size()) + */ name);
                static_cast< TextEdit * >(te)->setText(/*QString::number(widgets.size()) + */ text);
                formLayout->addRow(name, static_cast< TextEdit * >(te));
            }
            break;
            case LayoutItem::Type::CheckBox:
            {
                QString name;
                bool value;

                if (jsonData.contains("Name")) name = jsonData["Name"].toString();
                if (jsonData.contains("Value")) value = jsonData["Value"].toBool();

                LayoutItem *cb = new CheckBox(this);

                widgets.append(cb);
                static_cast< CheckBox * >(cb)->setObjectName(/*QString::number(widgets.size()) + */ name);
                static_cast< CheckBox * >(cb)->setChecked(/*QString::number(widgets.size()) + */ value);
                formLayout->addRow(name, static_cast< CheckBox * >(cb));
            }
            break;
        }
    }
}

void InputWidget::insertTextField() {}

void InputWidget::toJsonModel(QJsonObject &json)
{
    QJsonArray array;
    foreach (auto w, widgets)
    {
        QJsonObject jObject;
        switch (w->getType())
        {
            case LayoutItem::Type::PB:
            {
                PushButton *pb = static_cast< PushButton * >(w);
                pb->toJsonModel(tableDatas.value(pb), jObject);
                jObject["Name"] = pb->objectName();
            }
            break;
            case LayoutItem::Type::Text:
            {
                TextEdit *te = static_cast< TextEdit * >(w);

                jObject["Type"] = te->getType();
                jObject["Name"] = te->objectName();
            }
            break;
            case LayoutItem::Type::CheckBox:
            {
                CheckBox *cb = static_cast< CheckBox * >(w);
                jObject["Type"] = cb->getType();
                jObject["Name"] = cb->objectName();
            }
            break;
        }
        array.append(jObject);
    }
    json["Data"] = array;
}

void InputWidget::toJson(QJsonObject &json)
{
    QJsonArray array;
    foreach (auto w, widgets)
    {
        QJsonObject jObject;
        switch (w->getType())
        {
            case LayoutItem::Type::PB:
            {
                PushButton *pb = static_cast< PushButton * >(w);
                pb->toJson(tableDatas.value(pb), jObject);
                jObject["Name"] = pb->objectName();
            }
            break;
            case LayoutItem::Type::Text:
            {
                TextEdit *te = static_cast< TextEdit * >(w);

                jObject["Type"] = te->getType();
                jObject["Name"] = te->objectName();
                jObject["Text"] = te->toPlainText();
            }
            break;
            case LayoutItem::Type::CheckBox:
            {
                CheckBox *cb = static_cast< CheckBox * >(w);
                jObject["Type"] = cb->getType();
                jObject["Name"] = cb->objectName();
                jObject["Value"] = cb->isChecked();
            }
            break;
        }
        array.append(jObject);
    }
    json["Data"] = array;
}

QMap< LayoutItem *, TableData * > InputWidget::getTableDatas() const { return tableDatas; }

QList< LayoutItem * > InputWidget::getWidgets() const { return widgets; }

void InputWidget::onTableButtonPressed()
{
    PushButton *pb = static_cast< PushButton * >(sender());
    s_tableButtonPressed(tableDatas.value(pb));
}

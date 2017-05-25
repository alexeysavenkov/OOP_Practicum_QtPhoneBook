#include "EditableStringList.h"
#include "ui_editablestringlist.h"
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QModelIndex>

EditableStringList::EditableStringList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringList),
    newItemPlaceholderText(""),
    model(0)
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onSelectionChanged()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(onItemRemoveClicked()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(onItemModifyClicked()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(onBtnAddClicked()));
}

void EditableStringList::setNewItemPlaceholderText(const QString& text) {
    newItemPlaceholderText = text;
}

void EditableStringList::onSelectionChanged() {
    qDebug() << "kek";

    QModelIndex index = ui->listWidget->currentIndex();
    if(index.isValid()) {
        ui->btnDelete->setEnabled(true);
        ui->btnModify->setEnabled(true);
    } else {
        ui->btnDelete->setEnabled(false);
        ui->btnModify->setEnabled(false);
    }

    emit onItemSelect(index);
}

void EditableStringList::onItemRemoveClicked() {
    qDebug() << "kak";
    int currentRow = ui->listWidget->currentRow();
    qDeleteAll(ui->listWidget->selectedItems());
    ui->listWidget->clearSelection();
    model->deleteStringAt(currentRow);
    //ui->listWidget->
    //
}

void EditableStringList::onItemModifyClicked() {

    qDebug() << "kak3 ";

    int currentRow = ui->listWidget->currentRow();
    QListWidgetItem *listItem = ui->listWidget->item(currentRow);

    QString newItemName = showInputDialog("Change '" + listItem->text() + "'", "New item name: ", listItem->text());

    if(!newItemName.isEmpty()) {
        listItem->setText(newItemName);
        model->setStringAt(currentRow, newItemName);
    }
}

void EditableStringList::onBtnAddClicked() {

    qDebug() << "kak4 ";

    QString newItemName = showInputDialog("Add new item", "New item name: ", newItemPlaceholderText);

    if(!newItemName.isEmpty()) {
        ui->listWidget->addItem(newItemName);
        qDebug() << "11";
        model->appendString(newItemName);
        qDebug() << "22";
    }
}

QString EditableStringList::showInputDialog(QString dialogHeader, QString prompt, QString placeholder) {
    bool ok;
    QString text = QInputDialog::getText(this, dialogHeader,
                                         prompt, QLineEdit::Normal,
                                         placeholder, &ok);
    if(!ok) {
        return "";
    }

    return text;
}

void EditableStringList::setModel(EditableStringListModel* model) {
    this->model = model;

    ui->listWidget->clear();

    if(model) {
        for(int i = 0; i < model->count(); i++) {
            ui->listWidget->addItem(model->getStringAt(i));
        }
        ui->btnAdd->setEnabled(true);
    } else {
        ui->btnAdd->setEnabled(false);
    }
}


EditableStringList::~EditableStringList()
{
    delete ui;
}

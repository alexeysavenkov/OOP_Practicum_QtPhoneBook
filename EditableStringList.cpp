#include "EditableStringList.h"
#include "ui_editablestringlist.h"
#include <QDebug>
#include <QInputDialog>
#include <QDir>
#include <QModelIndex>

EditableStringList::EditableStringList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringList),
    placeholderText("Placeholder not set")
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onSelectionChanged()));
    connect(ui->btnDelete, SIGNAL(clicked()), this, SLOT(onItemRemoveClicked()));
    connect(ui->btnModify, SIGNAL(clicked()), this, SLOT(onItemModifyClicked()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(onBtnAddClicked()));
}

void EditableStringList::setPlaceholderText(const QString& text) {
    placeholderText = text;
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
}

void EditableStringList::onItemRemoveClicked() {
    qDebug() << "kak";
    qDeleteAll(ui->listWidget->selectedItems());
}

void EditableStringList::onItemModifyClicked() {

    qDebug() << "kak3 ";

    auto listItem = ui->listWidget->selectedItems().at(0);

    QString newItemName = showInputDialog("Change name of '" + listItem->text() + "'", "New item name: ");

    if(!newItemName.isEmpty()) {
        listItem->setText(newItemName);
    }
}

void EditableStringList::onBtnAddClicked() {

    qDebug() << "kak4 ";

    QString newItem = showInputDialog("Add new item", "New item name: ");

    if(!newItem.isEmpty()) {
        ui->listWidget->addItem(newItem);
    }
}

QString EditableStringList::showInputDialog(QString dialogHeader, QString prompt) {
    bool ok;
    QString text = QInputDialog::getText(this, dialogHeader,
                                         prompt, QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if(!ok) {
        return "";
    }

    return text;
}



EditableStringList::~EditableStringList()
{
    delete ui;
}

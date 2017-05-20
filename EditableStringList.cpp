#include "EditableStringList.h"
#include "EditableStringListPlaceholder.h"
#include "ui_editablestringlist.h"

EditableStringList::EditableStringList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringList)
{
    ui->setupUi(this);
    ui->listWidget->addItem(generateLabel());
}

void EditableStringList::setPlaceholderText(const QString& text) {
    placeholderText = text;
}

QListWidgetItem* EditableStringList::generateLabel() {
    QWidget *placeholder = new EditableStringListPlaceholder(placeholderText, this);
    QListWidgetItem *listItem = new QListWidgetItem();
    ui->listWidget->setItemWidget(listItem, placeholder);
    return listItem;
}

EditableStringList::~EditableStringList()
{
    delete ui;
}

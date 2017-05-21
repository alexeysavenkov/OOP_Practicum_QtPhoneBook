#include "EditableStringList.h"
#include "EditableStringListItem.h"
#include "ui_editablestringlist.h"

EditableStringList::EditableStringList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringList),
    placeholderText("Placeholder not set")
{
    ui->setupUi(this);
    ui->listWidget->addItem(generateEmptyItem());
}

void EditableStringList::setPlaceholderText(const QString& text) {
    placeholderText = text;
    for(int i = 0; i < ui->listWidget->count(); i++) {
        EditableStringListItem *item = (EditableStringListItem*)ui->listWidget->item(i);
        item->setPlaceholderText(placeholderText);
    }
}

QListWidgetItem* EditableStringList::generateEmptyItem() {
    QWidget *placeholder = new EditableStringListItem("", placeholderText, this);
    QListWidgetItem *listItem = new QListWidgetItem();
    //listItem->setFlags( listItem->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable );
    //listItem->setSizeHint();
    ui->listWidget->setItemWidget(listItem, placeholder);
    return listItem;
}

EditableStringList::~EditableStringList()
{
    delete ui;
}

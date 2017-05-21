#include "EditableStringListItem.h"
#include "ui_EditableStringListItem.h"

EditableStringListItem::EditableStringListItem(const QString& text, const QString& placeholderText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringListItem)
{
    ui->setupUi(this);
    ui->stringEdit->setText(text);
    ui->stringEdit->setPlaceholderText(placeholderText);
    this->updateVisibilities();
}

void EditableStringListItem::setPlaceholderText(const QString& placeholderText) {
    ui->stringEdit->setPlaceholderText(placeholderText);
}

EditableStringListItem::~EditableStringListItem()
{
    delete ui;
}

void EditableStringListItem::updateVisibilities() {
    bool containsText = ui->stringEdit->text().isEmpty();
    ui->removeButton->setVisible(containsText);
}

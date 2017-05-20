#include "EditableStringListPlaceholder.h"
#include "ui_EditableStringListPlaceholder.h"

EditableStringListPlaceholder::EditableStringListPlaceholder(const QString& text, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringListPlaceholder)
{
    ui->setupUi(this);
    ui->label->setText(text);
}

EditableStringListPlaceholder::~EditableStringListPlaceholder()
{
    delete ui;
}

#include "EditableStringListItem.h"
#include "ui_EditableStringListItem.h"
#include <QDebug>

EditableStringListItem::EditableStringListItem(const QString& text, const QString& placeholderText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringListItem),
    prevText(text)
{
    ui->setupUi(this);
    ui->stringEdit->setText(text);
    ui->stringEdit->setPlaceholderText(placeholderText);
    this->updateVisibilities();

    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(onRemoveButtonClicked()));
    connect(ui->stringEdit, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onCursorPositionChanged(int, int)));
    connect(ui->stringEdit, SIGNAL(textEdited(QString)), this, SLOT(onTextEdited(QString)));
}

void EditableStringListItem::setPlaceholderText(const QString& placeholderText) {
    ui->stringEdit->setPlaceholderText(placeholderText);
}

EditableStringListItem::~EditableStringListItem()
{
    delete ui;
}

void EditableStringListItem::onCursorPositionChanged(int, int) {
    emit focusIn();
}

void EditableStringListItem::onTextEdited(QString newText) {
    if(prevText.isEmpty() != newText.isEmpty()) {
        if(newText.isEmpty()) {
            emit textCleared();
        } else {
            emit textFilled();
        }
    }

    qDebug() << newText;

    prevText = newText;
    updateVisibilities();
}

void EditableStringListItem::onRemoveButtonClicked() {
    emit removeButtonClicked();
}

void EditableStringListItem::updateVisibilities() {
    bool textIsEmpty = ui->stringEdit->text().isEmpty();

    qDebug() << !textIsEmpty;

    ui->removeButton->setVisible(!textIsEmpty);
}

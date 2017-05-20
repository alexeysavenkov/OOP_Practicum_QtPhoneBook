#ifndef EDITABLESTRINGLIST_H
#define EDITABLESTRINGLIST_H

#include <QWidget>
#include <QListWidgetItem>
#include "EditableStringListPlaceholder.h"

namespace Ui {
class EditableStringList;
}

class EditableStringList : public QWidget
{
    Q_OBJECT

public:
    explicit EditableStringList(QWidget *parent = 0);
    void setPlaceholderText(const QString& text);
    ~EditableStringList();

private:
    Ui::EditableStringList *ui;
    QString placeholderText;
    EditableStringListPlaceholder *placeholder;

    QListWidgetItem* generateLabel();
};

#endif // EDITABLESTRINGLIST_H

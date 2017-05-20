#ifndef EDITABLESTRINGLISTPLACEHOLDER_H
#define EDITABLESTRINGLISTPLACEHOLDER_H

#include <QWidget>

namespace Ui {
class EditableStringListPlaceholder;
}

class EditableStringListPlaceholder : public QWidget
{
    Q_OBJECT

public:
    explicit EditableStringListPlaceholder(const QString& text = "New XXX", QWidget *parent = 0);
    ~EditableStringListPlaceholder();

private:
    Ui::EditableStringListPlaceholder *ui;
};

#endif // EDITABLESTRINGLISTPLACEHOLDER_H

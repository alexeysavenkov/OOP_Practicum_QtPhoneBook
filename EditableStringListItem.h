#ifndef EDITABLESTRINGLISTITEM_H
#define EDITABLESTRINGLISTITEM_H

#include <QWidget>

namespace Ui {
class EditableStringListItem;
}

class EditableStringListItem : public QWidget
{
    Q_OBJECT

public:
    explicit EditableStringListItem(const QString& text, const QString& placeholder, QWidget *parent = 0);
    ~EditableStringListItem();

    void setPlaceholderText(const QString& placeholderText);

private:
    Ui::EditableStringListItem *ui;

    void updateVisibilities();
};

#endif // EDITABLESTRINGLISTITEM_H

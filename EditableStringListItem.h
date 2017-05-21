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

signals:
    void focusIn();
    void textFilled();
    void textCleared();
    void removeButtonClicked();

private slots:
    void onCursorPositionChanged(int, int);
    void onTextEdited(QString);
    void onRemoveButtonClicked();

private:
    Ui::EditableStringListItem *ui;
    QString prevText;

    void updateVisibilities();
};

#endif // EDITABLESTRINGLISTITEM_H

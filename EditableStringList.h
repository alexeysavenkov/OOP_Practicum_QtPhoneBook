#ifndef EDITABLESTRINGLIST_H
#define EDITABLESTRINGLIST_H

#include <QWidget>
#include <QListWidgetItem>

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

private slots:
    void onSelectionChanged();
    void onItemRemoveClicked();
    void onItemModifyClicked();
    void onBtnAddClicked();

private:
    Ui::EditableStringList *ui;
    QString placeholderText;

    QString showInputDialog(QString dialogHeader, QString prompt);
};

#endif // EDITABLESTRINGLIST_H

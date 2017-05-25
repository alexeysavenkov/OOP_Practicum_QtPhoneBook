#ifndef EDITABLESTRINGLIST_H
#define EDITABLESTRINGLIST_H

#include <QWidget>
#include <QListWidgetItem>
#include <QModelIndex>
#include "EditableStringListModel.h"

namespace Ui {
class EditableStringList;
}

class EditableStringList : public QWidget
{
    Q_OBJECT

public:
    explicit EditableStringList(QWidget *parent = 0);
    void setNewItemPlaceholderText(const QString& text);
    ~EditableStringList();
    void setModel(EditableStringListModel*);

private slots:
    void onSelectionChanged();
    void onItemRemoveClicked();
    void onItemModifyClicked();
    void onBtnAddClicked();

signals:
    void onItemSelect(QModelIndex index);

private:
    Ui::EditableStringList *ui;
    QString newItemPlaceholderText;

    EditableStringListModel *model;

    QString showInputDialog(QString dialogHeader, QString prompt, QString placeholder);
};

#endif // EDITABLESTRINGLIST_H

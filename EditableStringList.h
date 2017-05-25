#ifndef EDITABLESTRINGLIST_H
#define EDITABLESTRINGLIST_H

#include <QWidget>
#include <QListWidgetItem>
#include "EditableStringListModel.h"

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
    void setModel(EditableStringListModel*);

private slots:
    void onSelectionChanged();
    void onItemRemoveClicked();
    void onItemModifyClicked();
    void onBtnAddClicked();

signals:
    void onItemSelect(int index);

private:
    Ui::EditableStringList *ui;
    QString placeholderText;

    EditableStringListModel *model;

    QString showInputDialog(QString dialogHeader, QString prompt);
};

#endif // EDITABLESTRINGLIST_H

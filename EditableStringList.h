#ifndef EDITABLESTRINGLIST_H
#define EDITABLESTRINGLIST_H

#include <QWidget>

namespace Ui {
class EditableStringList;
}

class EditableStringList : public QWidget
{
    Q_OBJECT

public:
    explicit EditableStringList(QWidget *parent = 0);
    ~EditableStringList();

private:
    Ui::EditableStringList *ui;
};

#endif // EDITABLESTRINGLIST_H

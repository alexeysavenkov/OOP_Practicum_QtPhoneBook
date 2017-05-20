#include "EditableStringList.h"
#include "ui_editablestringlist.h"

EditableStringList::EditableStringList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditableStringList)
{
    ui->setupUi(this);

}

EditableStringList::~EditableStringList()
{
    delete ui;
}

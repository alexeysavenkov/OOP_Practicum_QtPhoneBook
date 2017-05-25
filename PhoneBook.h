#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QWidget>
#include <QModelIndex>
#include "ContactListModel.h"

namespace Ui {
class PhoneBook;
}

class PhoneBook : public QWidget
{
    Q_OBJECT

public:
    explicit PhoneBook(QWidget *parent = 0);
    ~PhoneBook();

private slots:
    void onContactSelect(QModelIndex index);

private:
    Ui::PhoneBook *ui;

    ContactListModel contactListModel;
};

#endif // PHONEBOOK_H

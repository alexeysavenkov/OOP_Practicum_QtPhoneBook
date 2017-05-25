#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QWidget>
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
    void onContactSelect(int index);

private:
    Ui::PhoneBook *ui;

    ContactListModel contactListModel;
};

#endif // PHONEBOOK_H

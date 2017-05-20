#include "PhoneBook.h"
#include "ui_phonebook.h"

PhoneBook::PhoneBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhoneBook)
{
    ui->setupUi(this);
}

PhoneBook::~PhoneBook()
{
    delete ui;
}

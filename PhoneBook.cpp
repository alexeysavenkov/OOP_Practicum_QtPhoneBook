#include "PhoneBook.h"
#include "ui_phonebook.h"
#include "PhoneListModel.h"

PhoneBook::PhoneBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhoneBook)
{
    ui->setupUi(this);

    ui->listContacts->setModel(&contactListModel);
    connect(ui->listContacts, SIGNAL(onItemSelect(int)), this, SLOT(onContactSelect(int)));
}

PhoneBook::~PhoneBook()
{
    delete ui;
}

void PhoneBook::onContactSelect(int index) {
    ui->listPhoneNumbers->setModel(contactListModel.getContactAt(index).getPhoneListModel());
}

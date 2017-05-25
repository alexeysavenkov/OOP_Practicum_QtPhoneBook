#include "PhoneBook.h"
#include "ui_phonebook.h"
#include "PhoneListModel.h"
#include <QDebug>

PhoneBook::PhoneBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhoneBook)
{
    ui->setupUi(this);

    ui->listContacts->setNewItemPlaceholderText("New Contact Name");
    ui->listPhoneNumbers->setNewItemPlaceholderText("New Phone Number Name");

    ui->listContacts->setModel(&contactListModel);
    connect(ui->listContacts, SIGNAL(onItemSelect(QModelIndex)), this, SLOT(onContactSelect(QModelIndex)));
}

PhoneBook::~PhoneBook()
{
    delete ui;
}

void PhoneBook::onContactSelect(QModelIndex index) {
    qDebug() << "Setting model";
    if(index.isValid()) {
        ui->listPhoneNumbers->setModel(contactListModel.getContactAt(index.row())->getPhoneListModel());
    } else {
        ui->listPhoneNumbers->setModel(0);
    }
}

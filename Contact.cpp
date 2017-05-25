#include "Contact.h"
#include "PhoneListModel.h"
#include <QDebug>

Contact::Contact(QString _name) : name(_name)
{
    qDebug() << "kekek";
    this->phoneListModel = new PhoneListModel();
    qDebug() << "kekek2";
}

QString Contact::getName() const {
    return this->name;
}

void Contact::setName(QString name) {
    this->name = name;
}

PhoneListModel* Contact::getPhoneListModel() {
    return this->phoneListModel;
}

Contact::~Contact() {
    delete this->phoneListModel;
}

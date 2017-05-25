#include "ContactListModel.h"
#include <QDebug>

ContactListModel::ContactListModel()
{

}

QString ContactListModel::getStringAt(int index) const {
    return this->contacts[index]->getName();
}
void ContactListModel::setStringAt(int index, QString newString) {
    this->contacts[index]->setName(newString);
}

void ContactListModel::deleteStringAt(int index) {
    this->contacts.remove(index);
}

void ContactListModel::appendString(QString str) {
    qDebug() << "dsaf";
    //this->contacts.append(Contact());
    qDebug() << "dsaf 1";
    this->contacts.append(new Contact(str));
    qDebug() << "dsaf 2";
}

int ContactListModel::count() const {
    return this->contacts.count();
}

Contact ContactListModel::getContactAt(int index) {
    return *(this->contacts[index]);
}

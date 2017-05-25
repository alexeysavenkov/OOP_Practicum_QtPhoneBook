#include "PhoneListModel.h"

PhoneListModel::PhoneListModel()
{

}

QString PhoneListModel::getStringAt(int index) const {
    return this->phoneNumbers[index];
}
void PhoneListModel::setStringAt(int index, QString newString) {
    this->phoneNumbers[index] = newString;
}

void PhoneListModel::deleteStringAt(int index) {
    this->phoneNumbers.remove(index);
}

void PhoneListModel::appendString(QString str) {
    this->phoneNumbers.append(str);
}

int PhoneListModel::count() const {
    return this->phoneNumbers.count();
}

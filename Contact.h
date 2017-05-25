#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include "PhoneListModel.h"

class Contact
{
    PhoneListModel *phoneListModel;
    QString name;
public:
    Contact() {}
    Contact(QString _name);
    QString getName() const;
    void setName(QString);
    PhoneListModel* getPhoneListModel();
    ~Contact();
};

#endif // CONTACT_H

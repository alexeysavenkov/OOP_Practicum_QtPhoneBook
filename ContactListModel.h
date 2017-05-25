#ifndef CONTACTLISTMODEL_H
#define CONTACTLISTMODEL_H

#include <QVector>
#include "Contact.h"


class ContactListModel : public EditableStringListModel
{
private:
    QVector<Contact*> contacts;

public:
    ContactListModel();
    virtual QString getStringAt(int index) const override;
    virtual void setStringAt(int index, QString newString) override;
    virtual void deleteStringAt(int index) override;
    virtual void appendString(QString str) override;
    virtual int count() const override;

    Contact* getContactAt(int index);
};

#endif // CONTACTLISTMODEL_H

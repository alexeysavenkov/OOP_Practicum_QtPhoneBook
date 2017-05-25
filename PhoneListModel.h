#ifndef PHONELISTMODEL_H
#define PHONELISTMODEL_H

#include "EditableStringListModel.h"
#include <QVector>


class PhoneListModel : public EditableStringListModel
{
    QVector<QString> phoneNumbers;
public:
    PhoneListModel();

    virtual QString getStringAt(int index) const override;
    virtual void setStringAt(int index, QString newString) override;
    virtual void deleteStringAt(int index) override;
    virtual void appendString(QString str) override;
    virtual int count() const override;
};

#endif // PHONELISTMODEL_H

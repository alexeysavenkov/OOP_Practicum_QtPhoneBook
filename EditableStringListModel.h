#ifndef EDITABLESTRINGLISTMODEL_H
#define EDITABLESTRINGLISTMODEL_H

#include <QObject>

class EditableStringListModel
{
public:
    virtual QString getStringAt(int index) const = 0;
    virtual void setStringAt(int index, QString newString) = 0;
    virtual void deleteStringAt(int index) = 0;
    virtual void appendString(QString str) = 0;
    virtual int count() const = 0;
};

#endif // EDITABLESTRINGLISTMODEL_H

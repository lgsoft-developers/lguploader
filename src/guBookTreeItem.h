#ifndef GUBOOKTREEITEM_H
#define GUBOOKTREEITEM_H

#include <QTreeWidgetItem>
#include <QtGui>
#include "dataStructures.h"

class guBookTreeItem : public QTreeWidgetItem
{
public:
    guBookTreeItem(ebook Book);//QTreeWidget * parent,
    QString getMD5();
    void setBook(ebook Book);
    void setData ( int column, int role, const QVariant & value );
    void setUploadProgress(int persent);

    void setUploadStarted();

private:
    QVariant data(int column, int role) const;
    QString bookItem;
    ebook Book;
    int uploadProgress;
    bool uploadStarted;
};

#endif // GUBOOKTREEITEM_H

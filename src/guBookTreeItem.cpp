#include "guBookTreeItem.h"
#include <QtCore>
#include <QtGui>
guBookTreeItem::guBookTreeItem(ebook Book)//QTreeWidget * parent, : QTreeWidgetItem(parent)
{
    this->Book = Book;
    uploadStarted = false;
    uploadProgress = 0;
}
QString guBookTreeItem::getMD5()
{
    return Book.MD5;
}
void guBookTreeItem::setBook(ebook Book)
{
    this->Book = Book;
}
void guBookTreeItem::setUploadProgress(int persent)
{
    uploadProgress = persent;
    qDebug() << "upload progress" + QString::number(persent);
}
void guBookTreeItem::setUploadStarted()
{
    uploadStarted = true;
    qDebug() << "upload started";
}

void guBookTreeItem::setData ( int column, int role, const QVariant & value )
{
    switch (role)
    {
    case Qt::CheckStateRole:
        if (column == 0)
        {
            if(value == Qt::Checked)
            {
                Book.toUpload = true;
            }
            else
            {
                Book.toUpload = false;
            }
        }
        break;
    };
}
QVariant guBookTreeItem::data(int column, int role) const
{
    QString iconFileName;
    QString fileSizeStr;
    QString fileSizePrefix;
    int sizePrefixIndex = 0;
    int fileSizeNorm;
    switch (role)
    {
    case Qt::CheckStateRole:
        if (column == 0)
        {
            if(Book.biblioSetted)
            {
                if(Book.toUpload)
                    return Qt::Checked;
                else
                    return Qt::Unchecked;
            }
        }
        break;
    case Qt::DisplayRole:
        if (column == 1)
            return Book.fileName;
        if (column == 2)
            return Book.fileExtension;
        if (column == 3)
        {
            fileSizeNorm = Book.fileSize;
            while (fileSizeNorm > 1024)
            {
                fileSizeNorm = fileSizeNorm/1024;
                sizePrefixIndex++;
            }
            fileSizeStr.setNum(fileSizeNorm);
            switch(sizePrefixIndex)
            {
            case 0:
                fileSizePrefix = "byte";
                break;
            case 1:
                fileSizePrefix = "Kb";
                break;
            case 2:
                fileSizePrefix = "Mb";
                break;
            case 3:
                fileSizePrefix = "Gb";
                break;
            };
            return fileSizeStr + " " + fileSizePrefix;
        }
        if (column == 4)
        {
            //return Book.MD5;
        }
        if (column == 0)
        {

            if(Book.fileSize > (209715200))//1048576 * 200
            {
                return QObject::tr("200Mб<");
            }
            if (uploadStarted && this->uploadProgress == 0)
            {
                return QObject::tr("в очереди");
            }
            if (uploadProgress == 100)
            {
                return QObject::tr("загружено");
            }
            if( this->uploadProgress > 0)
            {
                return QString::number(uploadProgress) + "%";
            }
            if (Book.inLib)
            {
                return QObject::tr("libgen");
            }else
            {
                return QObject::tr("новое");
            }
            //return Book.inLib;
        }

        break;
    case Qt::DecorationRole:
        if (column == 2)
        {
            if(Book.fileExtension == "pdf")
            {
                iconFileName = ":/file_types/file_types/pdf_22.png";
            }else if (Book.fileExtension == "chm")
            {
                iconFileName = ":/file_types/file_types/help-contents.png";
            }else if (Book.fileExtension == "djvu")
            {
                iconFileName = ":/file_types/file_types/djvu_22.png";
            }else
            {
                iconFileName = ":/file_types/file_types/unknown_file_22.png";
            }
            return QIcon(QPixmap(iconFileName, "PNG"));
        }
        break;
     case Qt::BackgroundColorRole:
        if (Book.uploaded)
        {
            return QColor(163, 211, 156, 255);
        }else if (Book.biblioSetted)
        {
            return QColor(28,  187, 180, 255);
        }else if(!Book.ISBNs.isEmpty() && !Book.inLib)
        {
            return QColor(131, 147, 202, 255);
        }
        else if(Book.inLib)
        {
            return QColor(245, 152, 157, 255);
        }
        return Qt::white;
    }
    return QVariant();
    /*

    switch (role) {

    case Qt::DisplayRole:
    case Qt::EditRole:
        if (index.column() == 0)
            return value.toString();//.prepend(tr("№"));
        else if (index.column() == 2 && role == Qt::DisplayRole)
            return value.toString();//toDate().toString("dd.MM.yyyy");
        else if (index.column() == 3 && role == Qt::DisplayRole)
            return value.toString();//tr("%1").arg(value.toDouble(), 0, 'f', 2);
        else if (index.column() == 4 && role == Qt::DisplayRole)
            return "";//toInt() != 0 ? tr("Да") : tr("Нет");
        else if (index.column() == 6 && role == Qt::DisplayRole)
            return "";//QImage( ":/styles/style/up.png","PNG");//toInt() != 0 ? tr("Да") : tr("Нет");
        else
            return value;

    case Qt::TextColorRole:
        //if(index.column() == 1)
        //    return qVariantFromValue(QColor(Qt::blue));
        //else
        return value;

    case Qt::TextAlignmentRole:
        if(index.column() == 2 || index.column() == 4|| index.column() == 3)
            return int(Qt::AlignHCenter | Qt::AlignVCenter);
        else
            return int(Qt::AlignLeft | Qt::AlignVCenter);

    case Qt::FontRole:
        //if(index.column() == 1) {
        //QFont font = QFont("Helvetica", 10, QFont::Bold);
        //return qVariantFromValue(font);
        //}else
        return value;

    case Qt::BackgroundColorRole: {
            int a = (index.row() % 2) ? 14 : 0;
            //if(index.column() == 0)
            return qVariantFromValue(QColor(220,240-a,230-a));
            //else if(index.column() == 4)
            //    return qVariantFromValue(QColor(200,220-a,255-a));
            //else
            //    return value;
        }
    case Qt::CheckStateRole:
        //if (index.column() == 4)
        //    return (QSqlQueryModel::data(index).toInt() != 0) ?
        //            Qt::Checked : Qt::Unchecked;
        //else
        return value;
    case Qt::DecorationRole:
        if (index.column() == 4)
        {
            //qDebug() << "media column -- " << QSqlQueryModel::data(index, Qt::EditRole).toString();
            switch(QSqlQueryModel::data(index, Qt::DisplayRole).toInt())
            {
            case 1:
                return QIcon(":/type_icons/type_icons/book_32.png");//return QIcon("");
                break;
            case 2:
                return QIcon(":/type_icons/type_icons/cdr_32.png");//return QIcon("");
                break;
            default:
                return QIcon(":/type_icons/type_icons/cdr_32.png");//QIcon();
                break;
            }
        }
        if (index.column() == 6)
        {
            return QIcon(":/file_types/file_types/djvu_22.png");//return QIcon("");
        }
        else return QIcon();
    case Qt::SizeHintRole:
        switch (index.column())
        {
        case 0:
            return QSize(300, 5);
            break;
        case 1:
            return QSize(150, 5);
            break;
        case 2:
            return QSize(40, 5);
            break;
        case 3:
            return QSize(50, 5);
            break;
        case 4:
            return QSize(20, 5);
            break;
        case 5:
            return QSize(50, 5);
            break;
        case 6:
            return QSize(20, 5);
            break;
        default:
            return QSize(100, 5);
        }
     case Qt::ToolTipRole:
        {
            return QString("<h3>"+ (data(index.row(),0, Qt::DisplayRole)).toString() +"</h3>" +"<p>"+ (data(index.row(),1,Qt::DisplayRole)).toString()) +"</p>";
            //return tooltip;
        }
    }
    return value;
    */
}
//notes
//void	sortChildren ( int column, Qt::SortOrder order )

//tree widget
//void	sortItems ( int column, Qt::SortOrder order )

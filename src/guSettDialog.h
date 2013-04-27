#ifndef GUSETTDIALOG_H
#define GUSETTDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QString>
#include <QColor>
#include <QButtonGroup>

namespace Ui {
    class guSettDialog;
}

class guSettDialog : public QDialog {
    Q_OBJECT
public:
    guSettDialog(QWidget *parent = 0);
    ~guSettDialog();

protected:
    void changeEvent(QEvent *e);
    void initColors();     //задание цветов по умолчанию
    void loadSettings(); //загрузка существующих настроек

private:
    Ui::guSettDialog *ui;

    QButtonGroup  *inLibFileActions;
    //colors
    QColor dublicateColor; //цвет дубликатов
    QColor isbnColor;      //цвет книг с найденным ИСБН
    QColor biblioColor;    //цвет книг с заполненной библиографией
    QColor uploadedColor;  //цвет книг, загруженных на сервер
    QColor categoryColor;  //цвет индикации категории для книги

    QString colorToStyle(QColor color); //функция формирования стиля для кнопки


private slots:

    void currentSettGroupChanged(int currentIndex); //выбор группы настроек в списке групп
    void onSaveSettings();             //сохранение настроек
    //изменение цвета
    void onChangeDublicateColor();
    void onChangeIsbnColor();
    void onChangeBiblioColor();
    void onChangeUploadColor();
    void onChangeCategoryColor();
};

#endif // GUSETTDIALOG_H

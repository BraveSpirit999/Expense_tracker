#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QDialog *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void setDialogStyle();

};

#endif // DIALOG_H

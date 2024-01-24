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
private slots:
    void on_pushButton_clicked();
private:
    Ui::Dialog *ui;
    void setDialogStyle();
signals:
    void signal(QString,QString,QString,QString,QString);
};

#endif // DIALOG_H

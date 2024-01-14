#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
 #include <QtSql/QSqlDatabase>
 #include <QtSql/QSqlError>
 #include <QtSql/QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_1_clicked();

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
   QSqlDatabase db;
};
#endif // WIDGET_H

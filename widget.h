#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QSettings>
#include "dialog.h"
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
    QString wLineEdit_description;
    QString wLineEdit_balance;
    QString wCategory;
    QString wDateEdit;
    QString wIncome_or_Outcome;
    ~Widget();
public slots:
    void slot(QString category, QString data, QString about, QString balance,QString status);
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    Dialog* dialog;
    void setInterfaceStyle();
    void readSettings();
    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
    int outcome_balance = 0;
    int income_balance = 0;
    int current_balance = 0;
    int groceries_balance = 0;
    int entertainment_balance = 0;
    int auto_balance = 0;
    int other_balance = 0;
};
#endif // WIDGET_H

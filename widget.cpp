#include "widget.h"
#include "dialog.h"
#include "QStringList"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QDebug"
#include "./ui_widget.h"
#include "stylehelper.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setInterfaceStyle();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../transaction.db");
    if(db.open()){
        qDebug()<<"Успешно открыли";
    }
    else{
        qDebug()<<"Не успешно открыли";
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::setInterfaceStyle()
{
    ui->balance_frame->setStyleSheet(StyleHelper::GetBalance_frameStyle());
    ui->label->setStyleSheet(StyleHelper::GetNameLabelStyle());
    ui->label_9->setStyleSheet(StyleHelper::GetNameLabelStyle());
    ui->label_2->setStyleSheet(StyleHelper::GetCountBalanceStyle());
    ui->label_3->setStyleSheet(StyleHelper::GetOtherCountBalanceStyle());
    ui->label_5->setStyleSheet(StyleHelper::GetOtherCountBalanceStyle());
    ui->label_4->setStyleSheet(StyleHelper::GetIncomeAndOutcomeStyle());
    ui->label_6->setStyleSheet(StyleHelper::GetIncomeAndOutcomeStyle());
    ui->label_7->setStyleSheet(StyleHelper::GetIconForIncomeAndOutcome());
    ui->label_8->setStyleSheet(StyleHelper::GetIconForIncomeAndOutcome());
    ui->categories_frame->setStyleSheet(StyleHelper::GetBalance_frameStyle());
    ui->label_10->setStyleSheet(StyleHelper::GetCategoriesIconStyle());
    ui->label_14->setStyleSheet(StyleHelper::GetCategoriesIconStyle());
    ui->label_16->setStyleSheet(StyleHelper::GetCategoriesIconStyle());
    ui->label_19->setStyleSheet(StyleHelper::GetCategoriesIconStyle());
    ui->label_11->setStyleSheet(StyleHelper::GetNameCategoriesStyle());
    ui->label_13->setStyleSheet(StyleHelper::GetNameCategoriesStyle());
    ui->label_17->setStyleSheet(StyleHelper::GetNameCategoriesStyle());
    ui->label_20->setStyleSheet(StyleHelper::GetNameCategoriesStyle());
    ui->label_12->setStyleSheet(StyleHelper::GetCountCategoriesStyle());
    ui->label_15->setStyleSheet(StyleHelper::GetCountCategoriesStyle());
    ui->label_18->setStyleSheet(StyleHelper::GetCountCategoriesStyle());
    ui->label_21->setStyleSheet(StyleHelper::GetCountCategoriesStyle());
    ui->pushButton_1->setStyleSheet(StyleHelper::GetTransactionStyle());
    ui->pushButton_2->setStyleSheet(StyleHelper::GetTransactionStyle());
    ui->pushButton_3->setStyleSheet(StyleHelper::GetTransactionStyle());
    ui->tableView->setStyleSheet(StyleHelper::GetTableStyle());
}

void Widget::on_pushButton_1_clicked()
{
    Dialog d;
    d.show();
    return a.exec();
}


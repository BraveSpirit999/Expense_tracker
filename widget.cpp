#include "widget.h"
#include "dialog.h"
#include "QSqlQuery"
#include "QSettings"
#include "QStringList"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QDebug"
#include "QString"
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
    readSettings();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../transaction.db");
    if(db.open()){
        qDebug()<<"Успешно открыли";
        model = new QSqlTableModel(this,db);
        model->setTable("Users");
        model->select();
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        ui->tableView->setColumnWidth(0,50);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSortingEnabled(true);
        QHeaderView* header = ui->tableView->horizontalHeader();
        header->setStyleSheet(StyleHelper::GetTableStyle());
    }
    else{
        qDebug()<<"Не успешно открыли";
    }
}

Widget::~Widget()
{
    db.close();
    delete ui;
}
//Получение данных из диалогового окна
void Widget::slot(QString category, QString data, QString about, QString balance, QString status)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    QSettings settings("MyCompany", "MyApp");
    int x = balance.toInt();
    if(category != "Work"){
        current_balance = settings.value("Current_balance",0).toInt();
        current_balance -= x;
        ui->label_2->setText("$" + QString::number(current_balance));
        settings.setValue("Current_balance",current_balance);
    }
    if(status == "Outcome"){
        outcome_balance = settings.value("Outcome_balance",0).toInt();
        outcome_balance += x;
        ui->label_5->setText("$" + QString::number(outcome_balance));
        settings.setValue("Outcome_balance",outcome_balance);
    }
    else{
        income_balance = settings.value("Income_balance",0).toInt();
        income_balance += x;
        ui->label_3->setText("$" + QString::number(income_balance));
        settings.setValue("Income_balance",income_balance);
    }
    if(category == "Groceries"){
        groceries_balance = settings.value("Groceries",0).toInt();
        groceries_balance += x;
        ui->label_12->setText("-" + QString::number(groceries_balance)+"$");
        settings.setValue("Groceries",groceries_balance);
    }
    else{
        if(category == "Entertainment"){
            entertainment_balance = settings.value("Entertainment",0).toInt();
            entertainment_balance += x;
            ui->label_15->setText("-" + QString::number(entertainment_balance)+"$");
            settings.setValue("Entertainment",entertainment_balance);
        }
        else{
            if(category == "Auto"){
                auto_balance = settings.value("Auto",0).toInt();
                auto_balance += x;
                ui->label_18->setText("-" + QString::number(auto_balance)+"$");
                settings.setValue("Auto",auto_balance);
            }
            else{
                if(category == "Work"){
                    current_balance = settings.value("Current_balance",0).toInt();
                    current_balance += x;
                    ui->label_2->setText("$" + QString::number(current_balance));
                    settings.setValue("Current_balance",current_balance);
                }else{
                    other_balance = settings.value("Other",0).toInt();
                    other_balance += x;
                    ui->label_21->setText("-" + QString::number(other_balance)+"$");
                    settings.setValue("Other",other_balance);
                }
            }
        }
    }

    query.prepare("INSERT INTO USERS(Category, Date, Description, Balance, Status) VALUES (:Category, :Date, :Description, :Balance, :Status)");
    query.bindValue(":Category", category);
    query.bindValue(":Date", data);
    query.bindValue(":Description", about);
    query.bindValue(":Balance", balance);
    query.bindValue(":Status", status);

    if(!query.exec()) {
        qDebug("Ошибка вставки");
    }
    model->select();
    if(!db.open()){
        qDebug("БД не открыто в функции добавления данных");
    }
    db.close();
}
// Стиль приложения
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
// Сохранение переменных в файл
void Widget::readSettings()
{
    QSettings settings("MyCompany", "MyApp");
    ui->label_2->setText("$"+settings.value("Current_balance",0).toString());
    ui->label_3->setText("$"+settings.value("Income_balance",0).toString());
    ui->label_5->setText("$"+settings.value("Outcome_balance",0).toString());
    ui->label_12->setText("-"+settings.value("Groceries",0).toString()+"$");
    ui->label_15->setText("-"+settings.value("Entertainment",0).toString()+"$");
    ui->label_18->setText("-"+settings.value("Auto",0).toString()+"$");
    ui->label_21->setText("-"+settings.value("Other",0).toString()+"$");
}
// Добавление транзакций
void Widget::on_pushButton_1_clicked()
{
    dialog = new Dialog;
    dialog->show();
    connect(dialog,&Dialog::signal,this,&Widget::slot);
}
// Удаление транзакций
void Widget::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSettings settings("MyCompany", "MyApp");
    QString id = model->data(model->index(currentRow, 0)).toString();
    QString date = model->data(model->index(currentRow, 1)).toString();
    QString category = model->data(model->index(currentRow, 2)).toString();  // Предполагается, что столбец с категорией находится в 0-м индексе
    QString description = model->data(model->index(currentRow, 3)).toString();
    QString balance = model->data(model->index(currentRow, 4)).toString();
    QString status = model->data(model->index(currentRow, 5)).toString();
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM USERS WHERE Category = :Category AND Date = :Date AND Description = :Description AND Balance = :Balance AND Status = :Status");
    deleteQuery.bindValue(":ID", id);
    deleteQuery.bindValue(":Category", category);
    deleteQuery.bindValue(":Date", date);
    deleteQuery.bindValue(":Description", description);
    deleteQuery.bindValue(":Balance", balance);
    deleteQuery.bindValue(":Status", status);
    if(!deleteQuery.exec()) {
        qDebug("Ошибка удаления");
    } else {
        model->select();
    }
    int x = balance.toInt();
    if(category != "Work"){
        current_balance = settings.value("Current_balance",0).toInt();
        current_balance += x;
        ui->label_2->setText("$" + QString::number(current_balance));
        settings.setValue("Current_balance",current_balance);
    }
    if(status == "Outcome"){
        outcome_balance = settings.value("Outcome_balance",0).toInt();
        outcome_balance -= x;
        ui->label_5->setText("$" + QString::number(outcome_balance));
        settings.setValue("Outcome_balance",outcome_balance);
    }
    else{
        income_balance = settings.value("Income_balance",0).toInt();
        income_balance -= x;
        ui->label_3->setText("$" + QString::number(income_balance));
        settings.setValue("Income_balance",income_balance);
    }
    if(category == "Groceries"){
        groceries_balance = settings.value("Groceries",0).toInt();
        groceries_balance -= x;
        ui->label_12->setText("-" + QString::number(groceries_balance)+"$");
        settings.setValue("Groceries",groceries_balance);
    }
    else{
        if(category == "Entertainment"){
            entertainment_balance = settings.value("Entertainment",0).toInt();
            entertainment_balance -= x;
            ui->label_15->setText("-" + QString::number(entertainment_balance)+"$");
            settings.setValue("Entertainment",entertainment_balance);
        }
        else{
            if(category == "Auto"){
                auto_balance = settings.value("Auto",0).toInt();
                auto_balance -= x;
                ui->label_18->setText("-" + QString::number(auto_balance)+"$");
                settings.setValue("Auto",auto_balance);
            }
            else{
                if(category == "Work"){
                    current_balance = settings.value("Current_balance",0).toInt();
                    current_balance -= x;
                    ui->label_2->setText("$" + QString::number(current_balance));
                    settings.setValue("Current_balance",current_balance);
                }else{
                    other_balance = settings.value("Other",0).toInt();
                    other_balance -= x;
                    ui->label_21->setText("-" + QString::number(other_balance)+"$");
                    settings.setValue("Other",other_balance);
                }
            }
        }
    }
    db.close();
}
// Получение сигнала клика по таблице
void Widget::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row(); 
}
// Новый месяц
void Widget::on_pushButton_2_clicked()
{
    QSettings settings("MyCompany", "MyApp");
    settings.clear();
    ui->label_12->setText("-0$");
    ui->label_15->setText("-0$");
    ui->label_18->setText("-0$");
    ui->label_21->setText("-0$");
    ui->label_2->setText("$0");
    ui->label_3->setText("$0");
    ui->label_5->setText("$0");
}


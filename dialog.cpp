#include "dialog.h"
#include "widget.h"
#include "./ui_dialog.h"
#include "stylehelper.h"

Dialog::Dialog(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setDialogStyle();
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setDialogStyle()
{
    ui->label->setStyleSheet(StyleHelper::GetNameLabelStyle());
    ui->dialog_frame->setStyleSheet(StyleHelper::GetBalance_frameStyle());
    ui->comboBox->setStyleSheet(StyleHelper::GetDialog_frameStyle());
    ui->comboBox_2->setStyleSheet(StyleHelper::GetDialog_frameStyle());
    ui->dateEdit->setStyleSheet(StyleHelper::GetDialogDataStyle());
    ui->lineEdit->setStyleSheet(StyleHelper::GetDialogLineEditrStyle());
    ui->lineEdit_2->setStyleSheet(StyleHelper::GetDialogLineEditrStyle());
    ui->pushButton->setStyleSheet(StyleHelper::GetTransactionStyle());
}

void Dialog::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() ||
        ui->comboBox->currentText().isEmpty() ||
        ui->dateEdit->text().isEmpty() ||
        ui->lineEdit_2->text().isEmpty() ||
        ui->comboBox_2->currentText().isEmpty()) {
        ui->label->setText("Заполни все поля");
        return; // Не продолжать, если хотя бы одно поле пустое
    }
    ui->label->setText("New transaction");
    Widget widgetInstance;
    widgetInstance.wLineEdit_description = ui->lineEdit->text();
    widgetInstance.wCategory = ui->comboBox->currentText();
    widgetInstance.wDateEdit = ui->dateEdit->text();
    widgetInstance.wLineEdit_balance = ui->lineEdit_2->text();
    widgetInstance.wIncome_or_Outcome = ui->comboBox_2->currentText();
    qDebug() << "✅ Значение переменных:" <<
        "1:" << widgetInstance.wLineEdit_description <<
        "2:" << widgetInstance.wCategory <<
        "3:" << widgetInstance.wDateEdit <<
        "4:" << widgetInstance.wLineEdit_balance <<
        "5:" << widgetInstance.wIncome_or_Outcome;
    emit signal(widgetInstance.wCategory, widgetInstance.wDateEdit, widgetInstance.wLineEdit_description, widgetInstance.wLineEdit_balance, widgetInstance.wIncome_or_Outcome);
    close();
}


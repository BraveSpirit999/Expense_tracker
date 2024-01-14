#include "dialog.h"
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

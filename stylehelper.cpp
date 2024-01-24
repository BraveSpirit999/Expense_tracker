#include "stylehelper.h"

QString StyleHelper::GetBalance_frameStyle()
{
    return  "QFrame{"
            "background-color:rgba(255,255,255,40);"
            "border:1px solid rgba(255,255,255,40);"
            "border-radius:7px;"
           "}";
}

QString StyleHelper::GetNameLabelStyle()
{
    return  "QLabel{"
            "color:white;"
            "background-color:none;"
            "font-weight:bold;"
            "font-size:20px;"
            "border:none;"
            "}";
}

QString StyleHelper::GetCountBalanceStyle()
{
    return  "QLabel{"
            "color:white;"
            "background-color:none;"
            "font-size:30px;"
            "border:none;"
           "}";
}

QString StyleHelper::GetOtherCountBalanceStyle()
{
    return  "QLabel{"
           "color:white;"
           "background-color:none;"
           "font-size:20px;"
           "border:none;"
           "}";
}

QString StyleHelper::GetIncomeAndOutcomeStyle()
{
    return  "QLabel{"
           "color:white;"
           "background-color:none;"
           "font-weight:bold;"
           "font-size:16px;"
           "border:none;"
           "padding-top:10px;"
           "}";
}

QString StyleHelper::GetIconForIncomeAndOutcome()
{
    return "QLabel{"
           "background-color:none;"
           "border:none;"
           "padding-top:10px;"
           "}";
}

QString StyleHelper::GetCategoriesIconStyle()
{
    return "QLabel{"
           "background-color:none;"
           "border:none;"
           "}";
}

QString StyleHelper::GetNameCategoriesStyle()
{
    return "QLabel{"
           "color:white;"
           "font-weight:bold;"
           "font-size:16px;"
           "background-color:none;"
           "border:none;"
           "}";
}

QString StyleHelper::GetCountCategoriesStyle()
{
    return "QLabel{"
           "color:white;"
           "font-size:20px;"
           "background-color:none;"
           "border:none;"
           "}";
}

QString StyleHelper::GetTransactionStyle()
{
    return  "QPushButton{"
            "color:white;"
            "background-color:rgba(255,255,255,30);"
            "border:1px solid rgba(255,255,255,40);"
            "border-radius:7px;"
            "width:230px;"
            "height:50;"
            "}"
            "QPushButton::hover{"
            "background-color:rgba(255,255,255,40);"
            "}"
            "QPushButton::pressed{"
            "background-color:rgba(255,255,255,70);"
           "}";
}

QString StyleHelper::GetTableStyle()
{
    return  "QTableView {"
           "background-color: rgba(255,255,255,30);"
           "border: 1px solid rgba(255,255,255,40);"
           "border-bottom-right-radius: 7px;"
           "border-bottom-left-radius: 7px;"
           "}"
           "QHeaderView::section {"
           "background-color: rgb(53,53,53);"
           "color: white;"
           "border: none;"
           "height: 50px;"
           "font-size: 14px;"
           "}"
           "QTableView::item {"
           "border: 1px solid rgba(0, 0, 0, 0.1);"
           "}"
           "QTableView::item:selected {"
           "border: none;"
           "color: rgba(255,25,255);"
           "background-color: rgba(255,255,255,50);"
           "}";
}
QString StyleHelper::GetGialogCountBalanceStyle()
{
    return "QFrame{"
           "background-color:rgba(255,255,255,40);"
           "border:1px solid rgba(255,255,255,40);"
           "border-radius:7px;"
           "}";
}

QString StyleHelper::GetDialog_frameStyle()
{
    return "QComboBox{"
           "background-color:rgba(255,255,255,40);"
           "border:1px solid rgba(255,255,255,40);"
           "border-radius:7px;"
           "font-size:16px;"
           "color:white;"
           "padding-left:10px;"
           "}"
           "QComboBox::item{"
           "color:black;"
           "}";

}

QString StyleHelper::GetDialogLineEditrStyle()
{
    return "QLineEdit{"
           "background-color:rgba(255,255,255,40);"
           "border:1px solid rgba(255,255,255,40);"
           "border-radius:7px;"
           "color:white;"
           "font-size:16px;"
           "padding-left:10px;"
           "}";
}

QString StyleHelper::GetDialogDataStyle()
{
    return "QDateEdit{"
           "background-color:rgba(255,255,255,40);"
           "border:1px solid rgba(255,255,255,40);"
           "border-radius:7px;"
           "color:white;"
           "font-size:16px;"
           "padding-left:10px;"
           "}";
}


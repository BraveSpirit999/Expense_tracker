#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include<QString>
class StyleHelper
{
public:
    static QString GetBalance_frameStyle(); // стиль верхних окон
    static QString GetNameLabelStyle(); // главные названия
    static QString GetCountBalanceStyle(); // стиль кол-ва денег на кошельке
    static QString GetOtherCountBalanceStyle(); // стиль кол-ва денег income and outcome
    static QString GetIncomeAndOutcomeStyle();
    static QString GetIconForIncomeAndOutcome(); // стиль стрелки
    static QString GetCategoriesIconStyle();// стиль иконок категорий
    static QString GetNameCategoriesStyle();// название категорий
    static QString GetCountCategoriesStyle(); // стиль кол-ва денег в расходах
    static QString GetTransactionStyle();
    static QString GetTableStyle();// стиль таблицы


    static QString GetGialogCountBalanceStyle();// стиль октрывающегося окна
    static QString GetDialog_frameStyle(); // стиль comboBox on dialog_frame
    static QString GetDialogLineEditrStyle(); // стиль line окон
    static QString GetDialogDataStyle(); // стиль даты
};

#endif // STYLEHELPER_H

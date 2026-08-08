#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsShowCurrencyScreen :protected clsScreen
{
private:
	//Promot list
	//----------------------------//
	static void _PrintCurrencyList() {
		clsCurrenciesListScreen::PrintCurrencyList();
	}
	static void _FindCurrency() {
		clsFindCurrencyScreen::FindCurrencyScreen();
	}
	static void _UpdateRate() {
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _CurrencyCalculator() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	//----------------------------//
	enum enCurrencyOption {
		eListCurrency=1,eFindCurrency=2
		,eUpdateRate=3,eCurrencyCalc=4
		,eExit=5
	};
	static short _ReadCurrencyOption() {
		cout << setw(36) << left << "" << "Choose what do you want to do? [1:5]? ";
		short option = clsInputValidate::ReadIntNumberBetween(1,5,"Please,choose from chois [1:5]");
		return option;
	}
	static void _PrintOptions() {
		system("cls");
		clsScreen::_DrawScreenHeader("\aCurrency Screen");
		cout << setw(36) << left << "" << "=========================================" << endl;
		cout << setw(39) << left<<""<<"[1] List currencies\n";
		cout << setw(39) << left<<""<<"[2] Find currency\n";
		cout << setw(39) << left<<""<<"[3] Update Rate\n";
		cout << setw(39) << left<<""<<"[4] Currency Calculator\n";
		cout << setw(39) << left<<""<<"[5] Exit\n";
		cout << setw(36) << left << "" << "=========================================" << endl;
	}
	static void _PerformCurrencyScreen(enCurrencyOption option) {
		switch (option) {
			case enCurrencyOption::eListCurrency:
			{
				system("cls");
				_PrintCurrencyList();
				clsScreen::_Back_Currency_minue();
				return;
			}
			case enCurrencyOption::eFindCurrency:
			{
				system("cls");
				_FindCurrency();
				clsScreen::_Back_Currency_minue();
				return;
			}
			case enCurrencyOption::eUpdateRate :
			{
				system("cls");
				_UpdateRate();
				clsScreen::_Back_Currency_minue();
				return;
			}
			case enCurrencyOption::eCurrencyCalc:
			{
				system("cls");
				_CurrencyCalculator();
				clsScreen::_Back_Currency_minue();
				return;
			}
			case enCurrencyOption::eExit:
			{
				return;
			}
		}
	}
public:
	static void ShowCurrencyScreen() {
		short option = 0;
		do {
			_PrintOptions();
			option = _ReadCurrencyOption();
			_PerformCurrencyScreen(enCurrencyOption(option));
		} while (option!=5);
	}
};


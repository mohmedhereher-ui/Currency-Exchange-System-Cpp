#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen :protected clsScreen
{
private:
	enum enChoice {
		ecode = 1, ecountry = 2
	};
	static void _PrintCurrencyCard(clsCurrency& currency) {
		cout << "\nCurrency Card";
		cout << "\n----------------------------";
		cout << "\nCountry : " << currency.GetContryName();
		cout << "\nCode : " << currency.GetCurrencyCode();
		cout << "\nName : " << currency.GetCurrencyName();
		cout << "\nRate(1$): " << currency.GetRate();
		cout << "\n----------------------------";
	}
	static void _ShowResult(clsCurrency& Currency) {
		if (Currency.IsEmpty()) {
			cout << "\nCurrency not found :-(\n";
			_PrintCurrencyCard(Currency);
		}
		else {
			cout << "\nCurrency  found :-)\n";
			_PrintCurrencyCard(Currency);
		}
	}
public:
	static void FindCurrencyScreen() {
		clsScreen::_DrawScreenHeader("Find Currency");
		short chois = 0;
		cout << "\nFind By : [1] code [2] country ? ";
		chois = clsInputValidate::ReadIntNumberBetween(1, 2);
		switch ((enChoice)chois) {
		case enChoice::ecode:
		{
			string code = "";
			cout << "\nPlease enter currently code : ";
			code = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCode(code);
			_ShowResult(currency);
			return;
		}
		case enChoice::ecountry:
		{
			string country = "";
			cout << "\nPlease enter country name : ";
			country = clsInputValidate::ReadString();
			clsCurrency currency = clsCurrency::FindByCountry(country);
			_ShowResult(currency);
			return;
		}
		};
	}
};


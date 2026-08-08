#pragma once
#include <iostream>
#include<iomanip>
#include<vector>
#include"clsCurrency.h"
#include"clsScreen.h"
using namespace std;
class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency &Currency) {
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetContryName();
		cout << "| " << setw(8) << left << Currency.GetCurrencyCode();
		cout << "| " << setw(45) << left << Currency.GetCurrencyName();
		cout << "| " << setw(10) << left << Currency.GetRate() << "\n\n";
	}
public:
	static void PrintCurrencyList() {
		vector<clsCurrency>Currencies = clsCurrency::GetCurrencyList();
		clsScreen::_DrawScreenHeader("Currency List");
		cout << endl<<setw(8) << left << ""<< "======================================================================================================\n";
		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(45) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)";
		cout <<endl<<setw(8) << left << ""<<"======================================================================================================\n\n";
		for (clsCurrency &C: Currencies) {
			_PrintCurrencyRecord(C);
		}
		cout << setw(8) << left << ""<<"======================================================================================================\n";
	}
};


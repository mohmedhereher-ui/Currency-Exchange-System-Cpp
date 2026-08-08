#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string title) {
		cout << setw(36) << left << "" << "=========================================" << endl;
		cout << setw(36) << left << "" << "\t\t" << title << "\n";
		cout << setw(36) << left << "" << "=========================================" << endl;
	}
	static void _Back_Currency_minue() {
		cout << "\n\n\npress any key to go back to Currency menue...\a";
		system("pause");
	}
};


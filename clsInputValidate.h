#pragma once
#include<iostream>
#include "clsUtility.h";
class clsInputValidate
{
public:
	static bool IsNumberBetween(int number, int from, int to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(double number, double from, double to) {
		return (number >= from && number <= to);
	}
	
	static int ReadIntNumber(string ErrorMessage = "Invalid Number , Please Enter again\n") {
		int num = 0;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return num;
	}
	static int ReadIntNumberBetween(int from, int to, string ErrorMessage = "Invalid Number , Please Enter in range\n") {
		int num = ReadIntNumber();
		while (!IsNumberBetween(num, from, to)) {
			cout << ErrorMessage;
			num = ReadIntNumber();
		}
		return num;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number , Please Enter again\n") {
		double num = 0;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return num;
	}
	static int ReadDblNumberBetween(double from, double to, string ErrorMessage = "Invalid Number , Please Enter in range\n") {
		double num = ReadIntNumber();
		while (!IsNumberBetween(num, from, to)) {
			cout << ErrorMessage;
			num = ReadIntNumber();
		}
		return num;
	}
	static float ReadFloatNumber(string ErrorMessage = "Invalid Number , Please Enter again\n") {
		float num = 0;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return num;
	}
	static string ReadString(string ErrorMessage = "Invalid text , Please Enter again\n")
	{
		string  S1 = "";
		while (true)
		{
			if (!getline(cin >> ws, S1))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
				continue;
			}
			if (S1.empty())
			{
				cout << ErrorMessage;
				continue;
			}
			return S1;
		}
	}
	static char ReadChar(string ErrorMessage = "Invalid character , Please Enter again\n") {
		char C = '0';
		while (!(cin >> C)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return C;
	}
};

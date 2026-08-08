#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
class clsCurrency
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;

	string _Contry;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	enum enStructLine {
		enContry=0,enCurrencyCode=1
		,enCurrencyName=2,enRate=3
	};

	static clsCurrency _ConvertLineToCurrencyRecoerd(string line) {
		vector<string>structer = clsString::Split(line,"#//#");
		return clsCurrency(enMode::UpdateMode,structer.at(enStructLine::enContry),
			structer.at(enStructLine::enCurrencyCode),structer.at(enStructLine::enCurrencyName)
			,stof(structer.at(enStructLine::enRate)));
	}

	static string _ConvertCurrencyRecordToLine(clsCurrency Record,string separetor="#//#") {
		string line = "";
		line += Record.GetContryName() + separetor;
		line += Record.GetCurrencyCode() + separetor;
		line += Record.GetCurrencyName() + separetor;
		line += to_string(Record.GetRate());
		return line;
	}

	static vector<clsCurrency>_GetCurrencyList(string file_name="Currencies.txt") {
		vector<clsCurrency> CurrencyList;
		fstream File;
		File.open(file_name,ios::in);
		if (File.is_open()) {
			string line = "";
			while (getline(File,line)) {
				CurrencyList.push_back(_ConvertLineToCurrencyRecoerd(line));
			}
			File.close();
		}
		return  CurrencyList;
	}

	static void _LoadCurrencyDataTofile(vector<clsCurrency>&Currencies) {
		fstream File;
		File.open("Currencies.txt", ios::out);
		if (File.is_open()) {
			string line = "";
			for (clsCurrency& C : Currencies) {
				line = _ConvertCurrencyRecordToLine(C);
				File <<line<<endl;
			}
			File.close();
		}
	}

	void _Update() {
		vector<clsCurrency>Currencies = _GetCurrencyList();
	    for (clsCurrency &C: Currencies) {
		    if (C.GetContryName()==this->GetContryName()){
				   C = *this;
				   return;
			}
		}
		_LoadCurrencyDataTofile(Currencies);
	}

	static clsCurrency _EmptyOpject() {
		return clsCurrency(enMode::EmptyMode,"","","",0);
	}
public:
	clsCurrency(enMode Mode, string Contry, string CurrencyCode,
		string CurrencyName, float Rate) {
		_Mode= Mode;
		_Contry= Contry;
		_CurrencyCode= CurrencyCode;
		_CurrencyName= CurrencyName;
		_Rate= Rate;
	}
	bool IsEmpty() {
		return (this->GetMode() == enMode::EmptyMode);
	}
	//-----------------------------------------------------------//
	string GetContryName() {
		return  _Contry;
	}
	string GetCurrencyCode() {
		return  _CurrencyCode;
	}
	string GetCurrencyName() {
		return  _CurrencyName;
	}
	enMode GetMode() {
		return _Mode;
	}

	float GetRate() {
		return _Rate;
	}
	void UpdateRate(float new_rate) {
		_Rate = new_rate;
		_Update();
	}
	//-----------------------------------------------------------//
	static clsCurrency FindByCode(string currency_code) {
		currency_code = clsString::UpperAllString(currency_code);
		vector<clsCurrency>Currencies = _GetCurrencyList();
		for (clsCurrency& C : Currencies) {
			if (C.GetCurrencyCode() == currency_code) {
				return C;
			}
		}
		return _EmptyOpject();
	}
	static clsCurrency FindByCountry(string country) {
		country = clsString::UpperAllString(country);
		vector<clsCurrency>Currencies = _GetCurrencyList();
		for (clsCurrency& C : Currencies) {
			if (clsString::UpperAllString(C.GetContryName()) == country) {
				return C;
			}
		}
		return _EmptyOpject();
	}
	static bool IsCurrencyExist(string currency_code) {
		clsCurrency currency = clsCurrency::FindByCode(currency_code);
		return !(currency.IsEmpty());
	}
	static vector<clsCurrency>GetCurrencyList() {
		return _GetCurrencyList();
	}
	float ConvertAmountTo(clsCurrency &currency,float amount) {
		float amount_usd = amount/this->GetRate();
		return amount_usd * currency.GetRate();
	}
};
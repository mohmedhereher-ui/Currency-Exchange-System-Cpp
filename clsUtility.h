#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
class clsUtility
{
public:

	static const short Upperchar = 1;
	static const short Lowerchar = 2;
	static const short Digitchar = 3;
	static const short Mixedchar = 4;

	static int RandomNumber(const short& from, const short& to) {
		int Random = 0;
		Random = from + rand() % (to - from + 1);
		return Random;
	}
private:
	inline static short  __Begin = 65;
	inline static short __End = 90;
	static void __SetRange(const short& type) {
		switch (type) {
		case Upperchar:
			__Begin = 65; __End = 90;
			return;
		case Lowerchar:
			__Begin = 97; __End = 122;
			return;
		case Digitchar:
			__Begin = 48; __End = 57;
			return;
		case Mixedchar:
			__SetRange(RandomNumber(1, 3));
			return;
		};
	}
	static char __GetChar(const short& from, const short& to) {
		return char(RandomNumber(from, to));
	}
public:
	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static char GetRandomCharacter(const short& type) {
		__SetRange(type);
		return __GetChar(__Begin, __End);
	}
	static string GenerateWord(const short& type, short lenth) {
		string word = "";
		for (int i = 0; lenth > i; i++) {
			word += GetRandomCharacter(type);
		}
		return word;
	}
	static string GenerateKey(const short& type) {
		string word = "";
		for (int i = 0; 3 > i; i++) {
			word += (GenerateWord(type, 4) + "-");
		}
		word += GenerateWord(type, 4);
		return word;
	}
	static void GenerateKeys(short number_of_key, const short& type) {
		for (int i = 1; number_of_key >= i; i++) {
			cout << "key [" << i << "] " << GenerateKey(type) << endl;
		}
	}
	static void swap(int& num1, int& num2) {
		int  temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void swap(double& num1, double& num2) {
		double  temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void swap(bool& state1, bool& state2) {
		bool  temp = state1;
		state1 = state2;
		state2 = temp;
	}
	static void swap(string& text1, string& text2) {
		string  temp = text1;
		text1 = text2;
		text2 = temp;
	}
	static void  ShuffleVector(vector<int>& Array) {
		int Size = Array.size() - 1;
		for (int i = 0; Size >= i; i++) {
			swap(Array.at(i), Array.at(RandomNumber(0, Size)));
		}
	}
	static void  ShuffleVector(vector<string>& Array) {
		int Size = Array.size() - 1;
		for (int i = 0; Size >= i; i++) {
			swap(Array.at(i), Array.at(RandomNumber(0, Size)));
		}
	}
	static void  FillArrayWithRandomNumbers(int Array[], int from, int to, int lenth) {
		for (int i = 0; lenth > i; i++) {
			Array[i] = RandomNumber(from, to);
		}
	}
	static void  FillArrayWithRandomKeys(string Array[], const int& type, int size) {
		for (int i = 0; size > i; i++) {
			Array[i] = GenerateKey(type);
		}
	}
	static void Tabs(short tabs) {
		while (tabs--) {
			cout << "\t";
		}
	}
	static string Encryption(string word, int key = 10) {
		for (char& c : word) {
			c = char(int(c) + key);
		}
		return word;
	}
	static string Decryption(string word, int key = 10) {
		for (char& c : word) {
			c = char(int(c) - key);
		}
		return word;
	}
};




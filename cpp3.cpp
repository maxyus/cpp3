#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void CHANGE_CAPITAL(map<string, string>& dr, string old_country, string old_capital)
{
	auto it = dr.find(old_country);
	auto it2 = dr.find(old_capital);
	if (it == dr.end())
	{
		cout << "Introduce new country " << old_country << " with the capital " << old_capital << endl;
		dr[old_country] = old_capital;
	}
	else
	{
		cout << "Введите новое название страны" << endl;
		string new_country;
		cin >> new_country;
		cout << "Введите новое название столицы" << endl;
		string new_capital;
		cin >> new_capital;
		if (new_capital == old_capital)
		{
			cout << "Country " << old_country << " hasn't changed its capital " << endl;
		}
		else if (new_capital != old_capital)
		{
			cout << "Country " << old_country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
			dr[old_country] = new_capital;
		}
	}
}

void RENAME(map<string, string>& dr, string old_country)
{
	auto it = dr.find(old_country);
	string capital = it->second;
	cout << "Введите новое название страны" << endl;
	string new_country;
	cin >> new_country;
	if (new_country == old_country)
	{
		cout << "Incorrect rename, skip" << endl;
	}
	else
	{
		dr.erase(old_country);
		cout << "Country " << old_country << " with the capital " << capital << " has been renamed to " << new_country << endl;
		dr[new_country] = capital;
	}
}

void ABOUT(map<string, string>& dr, string country) 
{
	auto it = dr.find(country);
	if (it != dr.end()) 
	{
		cout << "Country " << country << " has capital " << it->second << endl;
	}
	else 
	{
		cout << "Country " << country << " doesn't exist" << endl;
	}
}

void DUMP(map<string, string>& dr) 
{
	if (dr.empty())
	{
		cout << "There are no countries in the world" << endl;
	}
	else
	{
		for (auto it = dr.begin(); it != dr.end(); ++it)
		{
			cout << (*it).first << "\t" << (*it).second << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int CountOperations;
	cout << "Введите количество операций \n";
	cin >> CountOperations;
	map<string, string> directory = { {"Russia", "Moscow"}, {"UK", "London"}, {"Germany", "Berlin"}, {"Norway", "Oslo"} };
	//map<string, string> directory = { };
	for (int i = 0; i < CountOperations; i++) 
	{
		cout << "Выберите команду" << endl;
		string country;
		string capital;
		string old_country;
		string old_capital;
		string new_country;
		string new_capital;
		string comand;
		cin >> comand;
		if (comand == "CHANGE_CAPITAL")
		{
			cout << "Введите страну" << endl;
			cin >> new_country;
			cout << "Введите столицу" << endl;
			cin >> new_capital;
			CHANGE_CAPITAL(directory, new_country, new_capital);
		}
		else if (comand == "RENAME") 
		{
			cout << "Введите страну" << endl;
			cin >> country;
			RENAME(directory, country);
		}
		else if (comand == "ABOUT") 
		{
			cin >> country;
			ABOUT(directory, country);
		}
		else if (comand == "DUMP")
		{
				DUMP(directory);
		}
	}
}

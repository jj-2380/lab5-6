#pragma once
#include <string>
#include <fstream>
#include "exception.h"
using namespace std;


class Account { //Класс для аккаунтов
public:
	string name;
	string email;
	string password;

	Account(){}

	Account(string email, string password, string full_name) { //Конструктор
		this->email = email;
		this->password = password;
		this->name = full_name;
	}

	Account(string str) { //Конструктор для создания аккаунта считанного из файла
		string obj[3];
		for (size_t i = 0, p = 0, q = 0; p != str.npos; p = q, ++i) {
			obj[i] = str.substr(p + (p != 0), (q = str.find(';', p + 1)) - p - (p != 0));
		}
		name = obj[0];
		email = obj[1];
		password = obj[2];
		}


	bool comparison(string email, string password) { //Функция для сравнения аккаунтов
		if (this->email == email && this->password == password) return true;
		else return false;
	}

	
	void operator =(const Account& other) { //Перегруженный оператор присвоения
		this->name = other.name;
		this->email = other.email;
		this->password = other.password;
	}
	
	void save() { //Запись в файл
		ofstream file("account.txt", std::ios::app);
		file << name << ";" << email << ";" << password << endl;
		file.close();
	}
};


bool find_account(Account& local_account, string email, string password) { //Функция поиска аккаунта в файле
	ifstream file_accounts("account.txt");
	if (!file_accounts.is_open()) throw ErrorOpeningFile("Ошибка, не удалось проверить наличие аккаунта.");
	string str;
	while (getline(file_accounts, str)) {
		Account tmp(str);
		if (tmp.comparison(email, password)) {
			local_account = tmp;
			file_accounts.close();
			return true;
		}
	}
	file_accounts.close();
	return false;
}

bool find_account(string email) { //Функция поиска аккаунта в файле с указанным email
	ifstream file_accounts("account.txt");
	if (!file_accounts.is_open()) throw ErrorOpeningFile("Ошибка, не удалось проверить наличие аккаунта.");
	string str;
	while (getline(file_accounts, str)) {
		Account tmp(str);
		if (tmp.email == email) {
			file_accounts.close();
			return true;
		}
	}
	file_accounts.close();
	return false;
}
#include <iostream>
#include "account.h"
#include "vehicle.h"
using namespace std;

Account local_account;

int main() {
	setlocale(LC_ALL, "ru");

start:												// start
	{
		cout << "Выберите действие: " << endl;
		cout << "1) Вход" << endl;
		cout << "2) Регистрация" << endl;
		cout << "Ваш выбор: ";
		int move;
		cin >> move;
		cout << endl;

		if (move == 1) {
			string email;
			string password;

			cout << "Введите почту: ";
			cin >> email;
			cout << "Введите пароль: ";
			cin >> password;
			cout << endl;

			if (find_account(local_account, email, password)) {
				cout << "Вы вошли в аккаунт." << endl;
			}
			else {
				cout << "Неправильный email или пароль." << endl;
				goto start;
			}


		}
		else if (move == 2) {
			
			string email;
			cout << "Введите почту: ";
			cin >> email;
			cout << endl;

			if (find_account(email)) {
				cout << "Аккаунт с таким email уже существует." << endl;
				goto start;
			}

			string password;
			string name;

			cout << "Введите пароль: ";
			cin >> password;
			cout << "Введите имя: ";
			cin >> name;
			cout << endl;

			local_account = Account(email, password, name);
			local_account.save();
			cout << "Вы вошли в аккаунт." << endl;
		}
		else {
			cout << "Неправильное действие." << endl;
			goto start;
		}
	}

moves:
	{
		cout << "Выберите действие: " << endl;
		cout << "1) Сдать в аренду транспорт" << endl;
		cout << "2) Взять в аренду транспорт" << endl;
		cout << "3) Выйти из аккаунта" << endl;
		cout << "Ваше действие: ";
		int move;
		cin >> move;
		cout << endl;

		if (move == 1) {
			cout << "Какой тип транспорта вы хотите сдать в аренду?" << endl;
			cout << "1) Мотоцикл" << endl;
			cout << "2) Автомобиль" << endl;
			cout << "3) Грузовик" << endl;
			cout << "Ваш выбор: " << endl;
			cout << endl;
			int type;
			cin >> type;
			if (type == 1) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string wheels;
				string kind;

				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите количество колёс: ";
				cin >> wheels;
				cout << "Введите тип мотоцикла: ";
				cin >> kind;
				cout << endl;
				Motorcycle tmp(brand, model, year, power, mileage, number, rent_price, wheels, kind);

				tmp.print();
				cout << "Верны ли данные?(y/n): ";
				char res;
				cin >> res;
				cout << endl;
				if (res == 'y') {
					tmp.save();
				}
				else {
					goto moves;
				}
				
				cout << "Транспорт зарегистрирован." << endl;
				MaintenanceRecord MR;
				goto moves;
			}
			else if (type == 2) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string doors;
				string gearbox_type;

				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите количество дверей: ";
				cin >> doors;
				cout << "Введите тип кузова: ";
				cin >> gearbox_type;
				cout << endl;
				Car tmp(brand, model, year, power, mileage, number, rent_price, doors, gearbox_type);
				tmp.print();
				cout << "Верны ли данные?(y/n): ";
				char res;
				cin >> res;
				cout << endl;
				if (res == 'y') {
					tmp.save();
				}
				else {
					goto moves;
				}

				cout << "Транспорт зарегистрирован." << endl;
				MaintenanceRecord MR;
				goto moves;
			}
			else if (type == 3) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string load_capacity;
				string axles;

				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите грузоподъёмность: ";
				cin >> load_capacity;
				cout << "Введите количество осей: ";
				cin >> axles;
				cout << endl;
				Truck tmp(brand, model, year, power, mileage, number, rent_price, load_capacity, axles);
				tmp.print();
				cout << "Верны ли данные?(y/n): ";
				char res;
				cin >> res;
				cout << endl;
				if (res == 'y') {
					tmp.save();
				}
				else {
					goto moves;
				}

				cout << "Транспорт зарегистрирован." << endl;
				MaintenanceRecord MR;
				goto moves;
			}
			else {
				cout << "Ошибка, неверное действие." << endl;
				goto moves;
			}
			MaintenanceRecord MR();
			cout << "Транспорт зарегистрирован." << endl;
			goto moves;

		}
		else if (move == 2) {
			cout << "Какой тип транспорта вы хотите взять в аренду?" << endl;
			cout << "1) Мотоцикл" << endl;
			cout << "2) Автомобиль" << endl;
			cout << "3) Грузовик" << endl;
			cout << "4) Выйти" << endl;
			cout << "Ваш выбор: " << endl;
			int type;
			cin >> type;

			if (type == 1) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string wheels;
				string kind;

				cout << "Введите какие характеристики вам нужны. Если вам не важна указанная характеристика, введите 0" << endl;
				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите количество колёс: ";
				cin >> wheels;
				cout << "Введите тип мотоцикла: ";
				cin >> kind;
				Motorcycle tmp(brand, model, year, power, mileage, number, rent_price, wheels, kind);
				find_motorcycle(tmp);
			}
			else if (type == 2) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string doors;
				string gearbox_type;

				cout << "Введите какие характеристики вам нужны. Если вам не важна указанная характеристика, введите 0" << endl;
				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите количество дверей: ";
				cin >> doors;
				cout << "Введите тип корпуса: ";
				cin >> gearbox_type;
				cout << endl;
				Car tmp(brand, model, year, power, mileage, number, rent_price, doors, gearbox_type);
				find_car(tmp);
			}
			else if (type == 3) {
				string brand;
				string model;
				string year;
				string power;
				string mileage;
				string number;
				string rent_price;
				string load_capacity;
				string axles;

				cout << "Введите какие характеристики вам нужны. Если вам не важна указанная характеристика, введите 0" << endl;
				cout << "Введите марку: ";
				cin >> brand;
				cout << "Введите модель: ";
				cin >> model;
				cout << "Введите возраст: ";
				cin >> year;
				cout << "Введите мощность в лошадиных силах: ";
				cin >> power;
				cout << "Введите пробег в км: ";
				cin >> mileage;
				cout << "Введите номер: ";
				cin >> number;
				cout << "Введите цену за день: ";
				cin >> rent_price;
				cout << "Введите количество дверей: ";
				cin >> load_capacity;
				cout << "Введите тип корпуса: ";
				cin >> axles;
				cout << endl;
				Truck tmp(brand, model, year, power, mileage, number, rent_price, load_capacity, axles);
				find_truck(tmp);
			}
			else goto moves;
		}
		else if (move == 3) {
			local_account = Account();
			cout << "Вы вышли из аккаунта." << endl;
			goto start;
		}
		else {
			cout << "Неправильное действие." << endl;
			goto moves;
		}
	}
	return 0;
}
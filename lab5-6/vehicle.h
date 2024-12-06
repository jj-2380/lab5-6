#pragma once
#include <string>
#include <iostream>
using namespace std;

class Engine{};
Engine engine;
class Body{};
Body body;
class Oil{};
Oil oil;

class MaintenanceRecord { //Сервисное обслуивание
public:
	string type_of_service;

	MaintenanceRecord() {
		cout << "Нужно ли какое-либо техническое обслуживание транспорту?(y/n): ";
		char ans;
		cin >> ans;
		if (ans == 'y') {
			cout << "Выберите какой тип обслуживания необходим: " << endl;
			cout << "1) Ремонт двигателя" << endl;
			cout << "2) Кузовной ремонт" << endl;
			cout << "3) Замена масла" << endl;
			cout << "Ваш выбор: ";
			int ans1;
			cin >> ans1;
			if (ans1 == 1) {
				this->service(engine);
			}
			else if (ans1 == 2) {
				this->service(body);
			}
			else if (ans1 = 3) {
				this->service(oil);
			}
			else {
				cout << "Тип обслуживания не выбран." << endl;
				type_of_service = "None";
			}
		}
		else type_of_service = "None";
	}

	~MaintenanceRecord(){} //Деструктор

	//Перегруженные функции сервисного обслуживания

	void service(Engine e) {
		cout << "Ремонт двигателя выполнен. Вы получите счёт за обслуживание позже." << endl;
		this->type_of_service = "Engine service";
	}
	void service(Body e) {
		cout << "Кузовной ремонт выполнен. Вы получите счёт за обслуживание позже." << endl;
		this->type_of_service = "Body service";
	}
	void service(Oil e) {
		cout << "Замена масла выполнена. Вы получите счёт за обслуживание позже." << endl;
		this->type_of_service = "Oil change";
	}

};

class Vehicle {
public:
	string brand;
	string model;
	string year;
	string power;
	string mileage;
	string number;
	string rent_price;
	Vehicle() { //Дефолтный конструктор
		this->brand = "0";
		this->model = "0";
		this->year = "0";
		this->power = "0";
		this->mileage = "0";
		this->number = "0";
		this->rent_price = "0";
	}
	Vehicle(string brand, string model, string year, string power, string mileage, string number, string rent_price) {//Конструктор
		this->brand = brand;
		this->model = model;
		this->year = year;
		this->power = power;
		this->mileage = mileage;
		this->number = number;
		this->rent_price = rent_price;
	}

	//Виртуальные функции
	virtual void save() {}
	virtual void print() {}
};



class Motorcycle :public Vehicle { //Класс мотоциклов
public:
	string wheels;
	string kind;

	Motorcycle() :Vehicle(){
		this->wheels = "0";
		this->kind = "0";
	}

	Motorcycle(string brand, string model, string year, string power, string mileage, string number, string rent_price, string wheels, string kind) :Vehicle(brand, model, year, power, mileage, number, rent_price) {
		this->wheels = wheels;
		this->kind = kind;
	}

	Motorcycle(string str) { //Конструктор для создания считанного из файла мотоцикла
		string obj[9];
		for (size_t i = 0, p = 0, q = 0; p != str.npos; p = q, ++i) {
			obj[i] = str.substr(p + (p != 0), (q = str.find(';', p + 1)) - p - (p != 0));
		}
		this->brand = obj[0];
		this->model = obj[1];
		this->year = obj[2];
		this->power = obj[3];
		this->mileage = obj[4];
		this->number = obj[5];
		this->rent_price = obj[6];
		this->wheels = obj[7];
		this->kind = obj[8];

	}

	~Motorcycle(){} //Деструктор

	void save() { //Запись в файл
		ofstream file_motorcycles("motorcycle.txt", std::ios::app);
		file_motorcycles << brand << ";" << model << ";" << year << ";" << power << ";" << mileage << ";" << number << ";" << rent_price << ";" << wheels << ";" << kind << endl;
		file_motorcycles.close();
	}

	void print() { //Выведение
		cout << "Марка: " << this->brand << endl;
		cout << "Модель: " << this->model << endl;
		cout << "Возраст: " << this->year << endl;
		cout << "Мощность: " << this->power << endl;
		cout << "Пробег: " << this->mileage << endl;
		cout << "Номер: " << this->number << endl;
		cout << "Цена: " << this->rent_price << endl;
		cout << "Количество колёс: " << this->wheels << endl;
		cout << "Тип мотоцикла: " << this->kind << endl;
	}

	bool operator ==(Motorcycle& other) { //Перегрузка оператора сравнения
		if (!(this->brand == other.brand || other.brand == "0")) return false;
		if (!(this->model == other.model || other.model == "0")) return false;
		if (!(this->year == other.year || other.year == "0")) return false;
		if (!(this->power == other.power || other.power == "0")) return false;
		if (!(this->mileage == other.mileage || other.mileage == "0")) return false;
		if (!(this->number == other.number || other.number == "0")) return false;
		if (!(this->rent_price == other.rent_price || other.rent_price == "0")) return false;
		if (!(this->wheels == other.wheels || other.wheels == "0")) return false;
		if (!(this->kind == other.kind || other.kind == "0")) return false;
		return true;
	}
};




class Car :public Vehicle { //Класс автомобилей
public:
	string doors;
	string gearbox_type;

	Car(string brand, string model, string year, string power, string mileage, string number, string rent_price, string doors, string gearbox_type) :Vehicle(brand, model, year, power, mileage, number, rent_price) {
		this->doors = doors;
		this->gearbox_type = gearbox_type;
	}
	Car(string str) {//Конструктор чтения из файла 
		string obj[9];
		for (size_t i = 0, p = 0, q = 0; p != str.npos; p = q, ++i) {
			obj[i] = str.substr(p + (p != 0), (q = str.find(';', p + 1)) - p - (p != 0));
		}
		this->brand = obj[0];
		this->model = obj[1];
		this->year = obj[2];
		this->power = obj[3];
		this->mileage = obj[4];
		this->number = obj[5];
		this->rent_price = obj[6];
		this->doors = obj[7];
		this->gearbox_type = obj[8];
	}

	~Car(){} //Деструктор

	void save() { //Запись в файл
		ofstream file_cars("car.txt", std::ios::app);
		file_cars << brand << ";" << model << ";" << year << ";" << power << ";" << mileage << ";" << number << ";" << rent_price << ";" << doors << ";" << gearbox_type << endl;
		file_cars.close();
	}

	void print() { //Выведение
		cout << "Марка: " << this->brand << endl;
		cout << "Модель: " << this->model << endl;
		cout << "Возраст: " << this->year << endl;
		cout << "Мощность: " << this->power << endl;
		cout << "Пробег: " << this->mileage << endl;
		cout << "Номер: " << this->number << endl;
		cout << "Цена: " << this->rent_price << endl;
		cout << "Количество дверей: " << this->doors << endl;
		cout << "Тип корпуса: " << this->gearbox_type << endl;
	}

	bool operator ==(Car& other) { //Сравнение
		if (!(this->brand == other.brand || other.brand == "0")) return false;
		if (!(this->model == other.model || other.model == "0")) return false;
		if (!(this->year == other.year || other.year == "0")) return false;
		if (!(this->power == other.power || other.power == "0")) return false;
		if (!(this->mileage == other.mileage || other.mileage == "0")) return false;
		if (!(this->number == other.number || other.number == "0")) return false;
		if (!(this->rent_price == other.rent_price || other.rent_price == "0")) return false;
		if (!(this->doors == other.doors || other.doors == "0")) return false;
		if (!(this->gearbox_type == other.gearbox_type || other.gearbox_type == "0")) return false;
		return true;
	}
};



class Truck :public Vehicle { //Класс грузовиков
public:
	string load_capacity;
	string axles;

	Truck(string brand, string model, string year, string power, string mileage, string number, string rent_price, string load_capacity, string axles) :Vehicle(brand, model, year, power, mileage, number, rent_price) {
		this->load_capacity = load_capacity;
		this->axles = axles;
	}
	Truck(string str) { //Конструктор чтением из файла
		string obj[9];
		for (size_t i = 0, p = 0, q = 0; p != str.npos; p = q, ++i) {
			obj[i] = str.substr(p + (p != 0), (q = str.find(';', p + 1)) - p - (p != 0));
		}
		this->brand = obj[0];
		this->model = obj[1];
		this->year = obj[2];
		this->power = obj[3];
		this->mileage = obj[4];
		this->number = obj[5];
		this->rent_price = obj[6];
		this->load_capacity = obj[7];
		this->axles = obj[8];
	}

	~Truck(){} //Деструктор

	bool operator ==(Truck& other) { //Сравнение
		if (!(this->brand == other.brand || other.brand == "0")) return false;
		if (!(this->model == other.model || other.model == "0")) return false;
		if (!(this->year == other.year || other.year == "0")) return false;
		if (!(this->power == other.power || other.power == "0")) return false;
		if (!(this->mileage == other.mileage || other.mileage == "0")) return false;
		if (!(this->number == other.number || other.number == "0")) return false;
		if (!(this->rent_price == other.rent_price || other.rent_price == "0")) return false;
		if (!(this->load_capacity == other.load_capacity || other.load_capacity == "0")) return false;
		if (!(this->axles == other.axles || other.axles == "0")) return false;
		return true;
	}

	void save() { //Запись в файл
		ofstream file_trucks("motorcycle.txt", std::ios::app);
		file_trucks << brand << ";" << model << ";" << year << ";" << power << ";" << mileage << ";" << number << ";" << rent_price << ";" << load_capacity << ";" << axles << endl;
		file_trucks.close();
	}

	void print() { //Выведение
		cout << "Марка: " << this->brand << endl;
		cout << "Модель: " << this->model << endl;
		cout << "Возраст: " << this->year << endl;
		cout << "Мощность: " << this->power << endl;
		cout << "Пробег: " << this->mileage << endl;
		cout << "Номер: " << this->number << endl;
		cout << "Цена: " << this->rent_price << endl;
		cout << "Грузоподъёмность: " << this->load_capacity << endl;
		cout << "Количество осей: " << this->axles << endl;
	}
};



//Функции поиска подходящего транспорта

void find_motorcycle(Motorcycle example) {
	ifstream file_motorcycles("truck.txt");
	string str;
	if (!file_motorcycles.is_open()) throw ErrorOpeningFile("Ошибка, не удалось найти мотоциклы.");
	while (getline(file_motorcycles, str)) {
		Motorcycle tmp(str);
		if (tmp == example) {
			tmp.print();
			cout << "Подходит ли вам этот мотоцикл?(y/n): ";
			char ans;
			cin >> ans;
			if (ans == 'y') {
				file_motorcycles.close();
				cout << "Транспорт арендован." << endl;
				cout << "Ваш счёт: " << tmp.rent_price << endl;
				break;
			}
		}
	}
	cout << "Вариантов закончились." << endl;
	file_motorcycles.close();
}


void find_car(Car example) {
	ifstream file_cars("car.txt");
	string str;
	if (!file_cars.is_open()) throw ErrorOpeningFile("Ошибка, не удалось найти автомобили.");
	while (getline(file_cars, str)) {
		Car tmp(str);
		if (tmp == example) {
			tmp.print();
			cout << "Подходит ли вам этот автомобиль?(y/n): ";
			char ans;
			cin >> ans;
			if (ans == 'y') {
				file_cars.close();
				cout << "Транспорт арендован." << endl;
				cout << "Ваш счёт: " << tmp.rent_price << endl;
				break;
			}
		}
	}
	cout << "Вариантов закончились." << endl;
	file_cars.close();
}


void find_truck(Truck example) {
	ifstream file_trucks("truck.txt");
	string str;
	if (!file_trucks.is_open()) throw ErrorOpeningFile("Ошибка, не удалось найти грузовики.");
	while (getline(file_trucks, str)) {
		Truck tmp(str);
		if (tmp == example) {
			tmp.print();
			cout << "Подходит ли вам этот грузовик?(y/n): ";
			char ans;
			cin >> ans;
			if (ans == 'y') {
				file_trucks.close();
				cout << "Транспорт арендован." << endl;
				cout << "Ваш счёт: " << tmp.rent_price << endl;
				break;
			}
		}
	}
	cout << "Вариантов закончились." << endl;
	file_trucks.close();
}
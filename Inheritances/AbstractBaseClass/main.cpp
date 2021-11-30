#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() const = 0; // Чисто виртуальный метод
	//именно этод метод делает класс абстрактным
};

class GroundVehicle :public Vehicle
{
	//абстрактный класс
};
class WaterVehicle :public Vehicle
{
	//абстрактный класс
};
class AirVehicle :public Vehicle
{
	int height;//абстрактный класс
};
class Bike :public GroundVehicle
{
public:
	//Конкретный класс, поскольку он определяет чисто виртуальный метод move
	void move() const
	{
		cout << "Мотоцикл едет на двух колесах" << endl;
	}
};
class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "Машина едет на четырех колесах" << endl;
	}
};

class Boat :public WaterVehicle
{
public:
	void move() const
	{
		cout << "Лодка плывет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v; //Не возможно создать экземпляр абстрактного класса
	//GroundVehicle gv;// это класс также является абстрактным поскольку он не определяет метод move
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();
	Boat h;
	h.move();
}
#include <iostream>
#include <string>

using namespace std;

class Car
{
	string model;
	string frame;
	unsigned int engine;
	unsigned short wheels;
	string transmission;
public:
	void SetFrame(string frame)
	{
		this->frame = frame;
	}
	string GetFrame()
	{
		return this->frame;
	}
	void SetEngine(unsigned int engine)
	{
		this->engine = engine;
	}
	unsigned int GetEngine()
	{
		return this->engine;
	}
	void SetWheels(unsigned short wheels)
	{
		this->wheels = wheels;
	}
	unsigned short GetWheels()
	{
		return this->wheels;
	}
	void SetTransmission(string transmission)
	{
		this->transmission = transmission;
	}
	string GetTransmission()
	{
		return this->transmission;
	}
	void SetModel(string model)
	{
		this->model = model;
	}
	string GetModel()
	{
		return this->model;
	}
	void ShowCar()
	{
		cout << this->model << endl;
		cout << "Frame: " << this->frame << endl;
		cout << "Engine (h. p.): " << this->engine << endl;
		cout << "Wheel size: " << this->wheels << endl;
		cout << "Transmission: " << this->transmission << endl << endl;
	}
};

   // Abstract Builder задает абстрактный интерфейс (класс) для создания частей объекта Product
   /** "Abstract Builder" */
class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildModel() abstract;
	virtual void BuildFrame() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildTransmission() abstract;
};

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

class LanosCarBuilder: public CarBuilder
{
public:
	void BuildModel() override
	{
		car.SetModel("Daewoo Lanos");
	}
	void BuildFrame() override
	{
		car.SetFrame("Sedan");
	}
	void BuildEngine() override
	{
		car.SetEngine(98);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildTransmission() override
	{
		car.SetTransmission("5 Manual");
	}
};

class ProbeCarBuilder : public CarBuilder
{
public:
	void BuildModel() override
	{
		car.SetModel("Ford Probe");
	}
	void BuildFrame() override
	{
		car.SetFrame("coupe");
	}
	void BuildEngine() override
	{
		car.SetEngine(160);
	}
	void BuildWheels() override
	{
		car.SetWheels(14);
	}
	void BuildTransmission() override
	{
		car.SetTransmission("4 Auto");
	}
};

class UAZCarBuilder : public CarBuilder
{
public:
	void BuildModel() override
	{
		car.SetModel("UAZ Patriot");
	}
	void BuildFrame() override
	{
		car.SetFrame("Universal");
	}
	void BuildEngine() override
	{
		car.SetEngine(120);
	}
	void BuildWheels() override
	{
		car.SetWheels(16);
	}
	void BuildTransmission() override
	{
		car.SetTransmission("4 Manual");
	}
};
class GetzCarBuilder : public CarBuilder
{
public:
	void BuildModel() override
	{
		car.SetModel("Hyundai Getz");
	}
	void BuildFrame() override
	{
		car.SetFrame("Hatch-back");
	}
	void BuildEngine() override
	{
		car.SetEngine(66);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
	void BuildTransmission() override
	{
		car.SetTransmission("4 Auto");
	}
};
class Shop
{
	CarBuilder *carBuilder;
public:
	void SetCarBuilder(CarBuilder* pb)
	{
		carBuilder = pb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildModel();
		carBuilder->BuildFrame();
		carBuilder->BuildEngine();
		carBuilder->BuildWheels();
		carBuilder->BuildTransmission();
	}
};

// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
void client(CarBuilder * builder)
{
	Shop shop;
	shop.SetCarBuilder(builder);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

void main()
{
	CarBuilder * builder = new LanosCarBuilder();
	client(builder);
	delete builder;
	builder = new ProbeCarBuilder();
	client(builder);
	delete builder;

	builder = new UAZCarBuilder();
	client(builder);
	delete builder;

	builder = new GetzCarBuilder();
	client(builder);
	delete builder;
	system("pause");
}
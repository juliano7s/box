
#include <iostream>
#include <vector>

using namespace std;
class Vehicle {
	public:
		virtual ~Vehicle();
};

Vehicle::~Vehicle()
{ }

class Car : public Vehicle {
	public:
		virtual void startEngine();
		virtual void openTrunk();
};

void Car::startEngine()
{ cout << "starting a Car...\n"; }

void Car::openTrunk()
{ cout << "opening Car trunk...\n"; }


class NuclearSubmarine : public Vehicle {
	public:
		virtual void startReactor();
		virtual void launchMissile();
};
void NuclearSubmarine::launchMissile()
{ cout << "starting a War...\n"; }

void NuclearSubmarine::startReactor()
{ cout << "starting a nuclear reactor...\n"; }

class VehicleContainer
{
	public:
		void insert(Vehicle &v) { mVehicles.push_back(&v); }

	protected:
		std::vector<Vehicle*> mVehicles;

};

class CarContainer
	: public VehicleContainer
{
public:
	void insertCar(Car &c) { mVehicles.push_back(&c); }
	Car &get(int index) { 
		return static_cast<Car&>(*mVehicles[index]);
	}
};

int main()
{
	CarContainer cars;
	Car c1, c2, c3;
	NuclearSubmarine n1;

	cars.insertCar(c1);
	cars.insertCar(c2);
	cars.insert(n1);
	cars.insertCar(c3);

	for (int i = 0; i < 4; i++)
	{
		Car &c = cars.get(i);
		c.openTrunk();
	}

	return 0;
}

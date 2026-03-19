#include<iostream>

using namespace std;

class Vehicle{
	public:
		int vehicleID;
		string manufac;
		string model;
		int year;
	static int totalvehi;
		Vehicle(){
			vehicleID = 0;
			manufac = "";
			model = "";
			year = 0;
		}
		
		Vehicle(int id, string mf, string mod, int year){
			vehicleID = id;
			manufac = mf;
			model = mod;
			this->year = year;
			totalvehi++;
		}
		
		void input(){
			cout << "Enter Vehicle ID :- ";
			cin >> vehicleID;
			cout << "Enter The Manufacturer :- ";
			cin >> manufac;
			cout << "Enter The Model :- ";
			cin >> model;
			cout << "Enter The Year :- ";
			cin >> year;
		}
		void output(){
			cout << "Vehicle ID :- " << vehicleID << endl;
			cout << "The Manufacturer :- " << manufac << endl;
			cout << "The Model :- " << model << endl;
			cout << "The Year :- " << year << endl;
			cout << "NUmber Of Vehicles :- " << totalvehi << endl;
		}	
};

int Vehicle::totalvehi=0;

class Car : public Vehicle{
	public:
		string fueltype;
		void input(){
			Vehicle::input();
			cout << "Enter Fuel Type :- ";
			cin >> fueltype;
		}
		void output(){
			Vehicle::output();
			cout << "Fuel Type :- " << fueltype << endl;
		}
};
class ElectricCar : public Car{
		string batteryCapacity;
		void input(){
			Vehicle::input();
			cout << "Enter BatteryCapacity :- ";
			cin >> batteryCapacity;
		}
		void output(){
		Vehicle::output();
		cout << "BatteryCapacity :- " << batteryCapacity << endl;
		}
};
class Aircraft : public Vehicle{
		int flightRange;
		void input(){
			Vehicle::input();
			cout << "Enter Flight Range :- ";
			cin >> flightRange;
		}
		void output(){
		Vehicle::output();
		cout << "Flight Range :- " << flightRange << endl;
		}
};
class FlyingCar : public Car, public Aircraft{

};
class SportsCar : public ElectricCar{
		int topSpeed;
		void input(){
			Vehicle::input();
			cout << "Enter Top Speed :- ";
			cin >> topSpeed;
		}
		void output(){
		Vehicle::output();
		cout << "Top Speed :- " << topSpeed << endl;
		}
};
class Sedan : public Car{

};
class SUV : public Car{

};

class VehicleRegistry{
	
};


int main(){
	
	cout << "Aand Bhaat Khayega";
	
	return 0;
}
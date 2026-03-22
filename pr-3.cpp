#include<iostream>

using namespace std;

class Vehicle{
	protected:
		int vehicleID;
		string manufac;
		string model;
		int year;

		static int totalvehi;
		static int nextID;

	public:
		Vehicle(){
			vehicleID = ++nextID;  
			manufac = "";
			model = "";
			year = 0;
			totalvehi++;
		}
		
		virtual void input(){
			cout << "Vechile ID will be assigned automatically :- " << Vehicle::nextID << endl;
			cout << "Enter The Manufacturer :- ";
			cin >> manufac;
			cout << "Enter The Model :- ";
			cin >> model;
			cout << "Enter The Year :- ";
			cin >> year;
		}
		virtual void output(){
			cout << "Vehicle ID :- " << vehicleID << endl;
			cout << "The Manufacturer :- " << manufac << endl;
			cout << "The Model :- " << model << endl;
			cout << "The Year :- " << year << endl;
			cout << "Total Number Of Vehicles :- " << totalvehi << endl;
		}
		int getID(){
			return vehicleID;
		}
		
		virtual ~Vehicle(){} // Destructer
};

int Vehicle::totalvehi=0;
int Vehicle::nextID=100;

class Car : virtual public Vehicle{
	protected:
		string fueltype;
	public:
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
	protected:
		string batteryCapacity;
	public:
		void input(){
			Car::input();
			cout << "Enter BatteryCapacity :- ";
			cin >> batteryCapacity;
		}
		void output(){
		Car::output();
		cout << "BatteryCapacity :- " << batteryCapacity << "KWH" << endl;
		}
};
class Aircraft : virtual public Vehicle{
	protected:
		int flightRange;
	public:
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
public:
void input(){
    Vehicle::input();   
    cout << "Enter Fuel Type :- ";
    cin >> fueltype;
    cout << "Enter Flight Range :- ";
    cin >> flightRange;
}

    void output(){
		Vehicle::output();
		cout << "Fuel Type :- " << fueltype << endl;
		cout << "Flight Range :- " << flightRange << endl;
    }
};
class SportsCar : public ElectricCar{
		int topSpeed;
	public:
		void input(){
			ElectricCar::input();
			cout << "Enter Top Speed :- ";
			cin >> topSpeed;
		}
		void output(){
		ElectricCar::output();
		cout << "Top Speed :- " << topSpeed << endl;
		}
};
class Sedan : public Car{

};
class SUV : public Car{

};

class VehicleRegistry{
	Vehicle*vehicles[50];
	int count;
	public:
		VehicleRegistry(){
			count = 0;
		}
		void addVehicle(int type){
			if(count >= 50){
				cout << "Registry Full!" << endl;
				return;
			}

			if(type == 1) vehicles[count] = new Car();
			else if(type == 2) vehicles[count] = new ElectricCar();
			else if(type == 3) vehicles[count] = new SportsCar();
			else if(type == 4) vehicles[count] = new Aircraft();
			else if(type == 5) vehicles[count] = new FlyingCar();
			else if(type == 6) vehicles[count] = new Sedan();
			else if(type == 7) vehicles[count] = new SUV();

			vehicles[count]->input();
			count++;
		}
		void displayAll(){
        	for(int i=0; i<count; i++){
            	cout << "\n----- Vehicle " << i+1 << " -----\n";
            	vehicles[i]->output();
        	}
    	}
void searchbyID(){
        int id;
        cout << "Enter Vehicle ID to Search :- ";
        cin >> id;

        for(int i = 0; i<count; i++){
            if(vehicles[i]->getID() == id){
                cout << "\nVehicle Found:\n";
                vehicles[i]->output();
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};


int main(){
    VehicleRegistry vr;
    int choice, type;

    do{
        cout << "\n1. Add Vehicle";
        cout << "\n2. Display All";
        cout << "\n3. Search by ID";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "\nSelect Car Type:";
                cout << "\n1. Basic Car";
                cout << "\n2. Electric Car";
                cout << "\n3. Sports Car";
                cout << "\n4. Aircraft";
                cout << "\n5. Flying Car";
				cout << "\n6. Sedan";
				cout << "\n7. SUV";
                cout << "\nEnter :- ";
                cin >> type;
                vr.addVehicle(type);
                break;

            case 2:
                vr.displayAll();
                break;

            case 3:
                vr.searchbyID();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid!\n";
        }

    }while(choice != 4);

    return 0;
}

#include <iostream>
using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
    }

    ~Train()
    {
        trainCount--;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> trainName;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Train Time: ";
        cin >> trainTime;

        trainCount++;
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;



class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        if(totalTrains == 0)
        {
            cout << "No train records\n";
            return;
        }

        for(int i=0;i<totalTrains;i++)
        {
            cout << "\nTrain " << i+1 << " details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for(int i=0;i<totalTrains;i++)
        {
            if(trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train with number " << number << " not found!\n";
    }
};



int main()
{
    RailwaySystem rs;
    int choice;
    int num;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                rs.addTrain();
                break;

            case 2:
                rs.displayAllTrains();
                break;

            case 3:
                cout << "Enter Train Number to search: ";
                cin >> num;
                rs.searchTrainByNumber(num);
                break;

            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
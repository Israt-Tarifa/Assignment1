#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
    string name;
    string model;
    int year;

public:
    Car(string name, string model, int year) : name(name), model(model), year(year) {}

    void displayCarInfo() const
    {
        cout << "Car Information:" << endl;
        cout << year << " " << name << " " << model << endl;
    }
};

class ElectricCar : public Car
{
private:
    int b_Capacity;

public:
    ElectricCar(string name, string model, int year, int batteryCapacity)
        : Car(name, model, year), b_Capacity(batteryCapacity) {}

    void displayCarInfo() const
    {
        Car::displayCarInfo();
        cout << "Battery Capacity: " << b_Capacity << " kWh" << endl;
    }
};

class GasCar : public Car
{
private:
    double fuelEfficiency;

public:
    GasCar(string name, string model, int year, double fuelEfficiency)
        : Car(name, model, year), fuelEfficiency(fuelEfficiency) {}

    void displayCarInfo() const
    {
        Car::displayCarInfo();
        cout << "Fuel Efficiency: " << fuelEfficiency << " MPG" << endl;
    }
};

int main()
{
    string carType;
    string name,model;
    int year;

    while (1)
    {
        cout << "Enter car type (Electric/Gas):";
        cin >> carType;

        if (carType != "Electric" && carType != "electric" && carType != "gas" && carType != "Gas" )
        {
            cout << "Invalid car type. Please enter Electric or Gas." << endl;
            continue;
        }

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter model: ";
        char c;
        cin >> c;
        getline( cin, model );
        model= c + model;
        cout << "Enter year: ";
        cin >> year;

        if (carType == "Electric")
        {
            int b_Capacity;
            cout << "Enter battery capacity (kWh): ";
            cin >> b_Capacity;

            ElectricCar electricCar(name, model, year, b_Capacity);
            electricCar.displayCarInfo();
        }
        else
        {
            double fuelEfficiency;
            cout << "Enter fuel efficiency (MPG): ";
            cin >> fuelEfficiency;

            GasCar gasCar(name, model, year, fuelEfficiency);
            gasCar.displayCarInfo();
        }
    }

    return 0;
}

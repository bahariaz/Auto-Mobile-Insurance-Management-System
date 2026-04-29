#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle() {}

Vehicle::Vehicle(string vehicleId, string customerId, string make, string model,
                 string year, string licensePlate, string color)
    : vehicleId(vehicleId), customerId(customerId), make(make), model(model),
      year(year), licensePlate(licensePlate), color(color) {}

string Vehicle::getVehicleId() const { return vehicleId; }
string Vehicle::getCustomerId() const { return customerId; }
string Vehicle::getMake() const { return make; }
string Vehicle::getModel() const { return model; }
string Vehicle::getYear() const { return year; }
string Vehicle::getLicensePlate() const { return licensePlate; }
string Vehicle::getColor() const { return color; }

void Vehicle::setVehicleId(string id) { vehicleId = id; }
void Vehicle::setCustomerId(string id) { customerId = id; }
void Vehicle::setMake(string make) { this->make = make; }
void Vehicle::setModel(string model) { this->model = model; }
void Vehicle::setYear(string year) { this->year = year; }
void Vehicle::setLicensePlate(string plate) { licensePlate = plate; }
void Vehicle::setColor(string color) { this->color = color; }

void Vehicle::displayInfo() const {
    cout << "Vehicle ID   : " << vehicleId << endl;
    cout << "Customer ID  : " << customerId << endl;
    cout << "Make         : " << make << endl;
    cout << "Model        : " << model << endl;
    cout << "Year         : " << year << endl;
    cout << "License Plate: " << licensePlate << endl;
    cout << "Color        : " << color << endl;
}

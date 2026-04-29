#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
private:
    string vehicleId;
    string customerId;
    string make;
    string model;
    string year;
    string licensePlate;
    string color;

public:
    Vehicle();
    Vehicle(string vehicleId, string customerId, string make, string model,
            string year, string licensePlate, string color);

    string getVehicleId() const;
    string getCustomerId() const;
    string getMake() const;
    string getModel() const;
    string getYear() const;
    string getLicensePlate() const;
    string getColor() const;

    void setVehicleId(string id);
    void setCustomerId(string id);
    void setMake(string make);
    void setModel(string model);
    void setYear(string year);
    void setLicensePlate(string plate);
    void setColor(string color);

    void displayInfo() const;
};

#endif

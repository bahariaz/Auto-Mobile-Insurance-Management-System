#include "Workshop.h"
#include <iostream>
using namespace std;

Workshop::Workshop() {}

Workshop::Workshop(string workshopId, string name, string address, string phone,
                   string ownerName, string registrationDate)
    : workshopId(workshopId), name(name), address(address), phone(phone),
      ownerName(ownerName), registrationDate(registrationDate) {}

string Workshop::getWorkshopId() const { return workshopId; }
string Workshop::getName() const { return name; }
string Workshop::getAddress() const { return address; }
string Workshop::getPhone() const { return phone; }
string Workshop::getOwnerName() const { return ownerName; }
string Workshop::getRegistrationDate() const { return registrationDate; }

void Workshop::setWorkshopId(string id) { workshopId = id; }
void Workshop::setName(string name) { this->name = name; }
void Workshop::setAddress(string address) { this->address = address; }
void Workshop::setPhone(string phone) { this->phone = phone; }
void Workshop::setOwnerName(string name) { ownerName = name; }
void Workshop::setRegistrationDate(string date) { registrationDate = date; }

void Workshop::displayInfo() const {
    cout << "Workshop ID       : " << workshopId << endl;
    cout << "Name              : " << name << endl;
    cout << "Address           : " << address << endl;
    cout << "Phone             : " << phone << endl;
    cout << "Owner             : " << ownerName << endl;
    cout << "Registration Date : " << registrationDate << endl;
}

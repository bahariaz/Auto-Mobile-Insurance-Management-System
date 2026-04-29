#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {}

Person::Person(string id, string name, string cnic, string phone, string email)
    : id(id), name(name), cnic(cnic), phone(phone), email(email) {}

string Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getCnic() const { return cnic; }
string Person::getPhone() const { return phone; }
string Person::getEmail() const { return email; }

void Person::setId(string id) { this->id = id; }
void Person::setName(string name) { this->name = name; }
void Person::setCnic(string cnic) { this->cnic = cnic; }
void Person::setPhone(string phone) { this->phone = phone; }
void Person::setEmail(string email) { this->email = email; }

void Person::displayInfo() const {
    cout << "ID: " << id << "\nName: " << name << "\nCNIC: " << cnic
         << "\nPhone: " << phone << "\nEmail: " << email << endl;
}

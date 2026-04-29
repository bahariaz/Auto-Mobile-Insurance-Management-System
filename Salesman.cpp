#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman() {}

Salesman::Salesman(string id, string name, string cnic, string phone, string email,
                   string department, string hireDate)
    : Person(id, name, cnic, phone, email), department(department), hireDate(hireDate) {}

string Salesman::getDepartment() const { return department; }
string Salesman::getHireDate() const { return hireDate; }
void Salesman::setDepartment(string department) { this->department = department; }
void Salesman::setHireDate(string date) { hireDate = date; }

void Salesman::login() {
    cout << "Salesman " << name << " logged in." << endl;
}

void Salesman::displayInfo() const {
    Person::displayInfo();
    cout << "Department : " << department << endl;
    cout << "Hire Date  : " << hireDate << endl;
}

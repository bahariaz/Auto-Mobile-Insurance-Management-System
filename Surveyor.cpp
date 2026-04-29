#include "Surveyor.h"
#include <iostream>
using namespace std;

Surveyor::Surveyor() {}

Surveyor::Surveyor(string id, string name, string cnic, string phone, string email,
                   string specialization, string certificationDate)
    : Person(id, name, cnic, phone, email), specialization(specialization),
      certificationDate(certificationDate) {}

string Surveyor::getSpecialization() const { return specialization; }
string Surveyor::getCertificationDate() const { return certificationDate; }
void Surveyor::setSpecialization(string spec) { specialization = spec; }
void Surveyor::setCertificationDate(string date) { certificationDate = date; }

void Surveyor::login() {
    cout << "Surveyor " << name << " logged in." << endl;
}

void Surveyor::displayInfo() const {
    Person::displayInfo();
    cout << "Specialization     : " << specialization << endl;
    cout << "Certification Date : " << certificationDate << endl;
}

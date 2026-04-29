#include "Customer.h"
#include "InsuranceSystem.h"
#include <iostream>
using namespace std;

Customer::Customer() {}

Customer::Customer(string id, string name, string cnic, string phone, string email,
                   string address, string registrationDate)
    : Person(id, name, cnic, phone, email), address(address),
      registrationDate(registrationDate) {}

string Customer::getAddress() const { return address; }
string Customer::getRegistrationDate() const { return registrationDate; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setRegistrationDate(string date) { registrationDate = date; }

void Customer::login() {
    cout << "Customer " << name << " logged in." << endl;
}

void Customer::displayInfo() const {
    Person::displayInfo();
    cout << "Address           : " << address << endl;
    cout << "Registration Date : " << registrationDate << endl;
}

void Customer::viewProfile() const {
    cout << "\n===== CUSTOMER PROFILE =====" << endl;
    displayInfo();
}

void Customer::viewVehicles(InsuranceSystem& sys) const {
    sys.displayCustomerVehicles(id);
}

void Customer::viewPolicies(InsuranceSystem& sys) const {
    sys.displayCustomerPolicies(id);
}

void Customer::viewClaims(InsuranceSystem& sys) const {
    sys.displayCustomerClaims(id);
}

void Customer::checkClaimStatus(InsuranceSystem& sys) const {
    string claimId;
    cout << "Enter Claim ID: ";
    cin >> claimId;
    sys.displayClaimStatus(claimId, id);
}

void Customer::viewWorkshopDetails(InsuranceSystem& sys) const {
    sys.displayWorkshopForClaim(id);
}

void Customer::viewInspectionSummary(InsuranceSystem& sys) const {
    sys.displayInspectionSummary(id);
}

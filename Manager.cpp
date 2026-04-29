#include "Manager.h"
#include "InsuranceSystem.h"
#include <iostream>
using namespace std;

Manager::Manager() {}

Manager::Manager(string id, string name, string cnic, string phone, string email,
                 string designation, string joinDate)
    : Person(id, name, cnic, phone, email), designation(designation), joinDate(joinDate) {}

string Manager::getDesignation() const { return designation; }
string Manager::getJoinDate() const { return joinDate; }
void Manager::setDesignation(string designation) { this->designation = designation; }
void Manager::setJoinDate(string date) { joinDate = date; }

void Manager::login() {
    cout << "Manager " << name << " logged in." << endl;
}

void Manager::displayInfo() const {
    Person::displayInfo();
    cout << "Designation : " << designation << endl;
    cout << "Join Date   : " << joinDate << endl;
}

void Manager::viewMonthlyCustomers(InsuranceSystem& sys, string month) const {
    sys.displayMonthlyCustomers(month);
}

void Manager::viewPendingClaims(InsuranceSystem& sys) const {
    sys.displayPendingClaims();
}

void Manager::viewInspectionReports(InsuranceSystem& sys) const {
    sys.displayAllInspectionReports();
}

void Manager::approveClaim(InsuranceSystem& sys, string claimId) const {
    if (sys.approveClaim(claimId))
        cout << "Claim " << claimId << " approved successfully." << endl;
    else
        cout << "Cannot approve claim. Inspection report missing or claim not found." << endl;
}

void Manager::rejectClaim(InsuranceSystem& sys, string claimId) const {
    if (sys.rejectClaim(claimId))
        cout << "Claim " << claimId << " rejected." << endl;
    else
        cout << "Claim not found." << endl;
}

void Manager::viewCustomerClaimHistory(InsuranceSystem& sys, string customerId) const {
    sys.displayCustomerClaimHistory(customerId);
}

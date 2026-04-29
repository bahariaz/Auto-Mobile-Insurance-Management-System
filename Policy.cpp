#include "Policy.h"
#include <iostream>
using namespace std;

Policy::Policy() : premiumAmount(0), coverageAmount(0) {}

Policy::Policy(string policyId, string customerId, string vehicleId,
               string policyType, string startDate, string endDate,
               double premiumAmount, double coverageAmount, string status)
    : policyId(policyId), customerId(customerId), vehicleId(vehicleId),
      policyType(policyType), startDate(startDate), endDate(endDate),
      premiumAmount(premiumAmount), coverageAmount(coverageAmount), status(status) {}

string Policy::getPolicyId() const { return policyId; }
string Policy::getCustomerId() const { return customerId; }
string Policy::getVehicleId() const { return vehicleId; }
string Policy::getPolicyType() const { return policyType; }
string Policy::getStartDate() const { return startDate; }
string Policy::getEndDate() const { return endDate; }
double Policy::getPremiumAmount() const { return premiumAmount; }
double Policy::getCoverageAmount() const { return coverageAmount; }
string Policy::getStatus() const { return status; }

void Policy::setPolicyId(string id) { policyId = id; }
void Policy::setCustomerId(string id) { customerId = id; }
void Policy::setVehicleId(string id) { vehicleId = id; }
void Policy::setPolicyType(string type) { policyType = type; }
void Policy::setStartDate(string date) { startDate = date; }
void Policy::setEndDate(string date) { endDate = date; }
void Policy::setPremiumAmount(double amount) { premiumAmount = amount; }
void Policy::setCoverageAmount(double amount) { coverageAmount = amount; }
void Policy::setStatus(string status) { this->status = status; }

void Policy::displayInfo() const {
    cout << "Policy ID       : " << policyId << endl;
    cout << "Customer ID     : " << customerId << endl;
    cout << "Vehicle ID      : " << vehicleId << endl;
    cout << "Type            : " << policyType << endl;
    cout << "Start Date      : " << startDate << endl;
    cout << "End Date        : " << endDate << endl;
    cout << "Premium Amount  : " << premiumAmount << endl;
    cout << "Coverage Amount : " << coverageAmount << endl;
    cout << "Status          : " << status << endl;
}

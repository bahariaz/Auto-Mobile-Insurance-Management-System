#include "Claim.h"
#include <iostream>
using namespace std;

Claim::Claim() : estimatedDamage(0) {}

Claim::Claim(string claimId, string policyId, string customerId, string workshopId,
             string claimDate, string description, double estimatedDamage, string status)
    : claimId(claimId), policyId(policyId), customerId(customerId), workshopId(workshopId),
      claimDate(claimDate), description(description), estimatedDamage(estimatedDamage),
      status(status) {}

string Claim::getClaimId() const { return claimId; }
string Claim::getPolicyId() const { return policyId; }
string Claim::getCustomerId() const { return customerId; }
string Claim::getWorkshopId() const { return workshopId; }
string Claim::getClaimDate() const { return claimDate; }
string Claim::getDescription() const { return description; }
double Claim::getEstimatedDamage() const { return estimatedDamage; }
string Claim::getStatus() const { return status; }

void Claim::setClaimId(string id) { claimId = id; }
void Claim::setPolicyId(string id) { policyId = id; }
void Claim::setCustomerId(string id) { customerId = id; }
void Claim::setWorkshopId(string id) { workshopId = id; }
void Claim::setClaimDate(string date) { claimDate = date; }
void Claim::setDescription(string desc) { description = desc; }
void Claim::setEstimatedDamage(double amt) { estimatedDamage = amt; }
void Claim::setStatus(string status) { this->status = status; }

void Claim::displayInfo() const {
    cout << "Claim ID        : " << claimId << endl;
    cout << "Policy ID       : " << policyId << endl;
    cout << "Customer ID     : " << customerId << endl;
    cout << "Workshop ID     : " << workshopId << endl;
    cout << "Claim Date      : " << claimDate << endl;
    cout << "Description     : " << description << endl;
    cout << "Estimated Damage: " << estimatedDamage << endl;
    cout << "Status          : " << status << endl;
}

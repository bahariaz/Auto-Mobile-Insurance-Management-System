#include "InsuranceSystem.h"
#include <iostream>
#include <sstream>
using namespace std;

InsuranceSystem::InsuranceSystem()
    : customerCount(0), salesmanCount(0), surveyorCount(0),
      vehicleCount(0), policyCount(0), claimCount(0),
      inspectionCount(0), workshopCount(0), repairJobCount(0) {}

string InsuranceSystem::generateId(string prefix, int count) {
    stringstream ss;
    ss << prefix << (count + 1);
    return ss.str();
}

bool InsuranceSystem::workshopExists(string workshopId) {
    for (int i = 0; i < workshopCount; i++) {
        if (workshops[i].getWorkshopId() == workshopId)
            return true;
    }
    return false;
}

bool InsuranceSystem::policyExists(string policyId) {
    for (int i = 0; i < policyCount; i++) {
        if (policies[i].getPolicyId() == policyId)
            return true;
    }
    return false;
}

bool InsuranceSystem::customerExists(string customerId) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getId() == customerId)
            return true;
    }
    return false;
}

bool InsuranceSystem::claimExists(string claimId) {
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getClaimId() == claimId)
            return true;
    }
    return false;
}

bool InsuranceSystem::inspectionExistsForClaim(string claimId) {
    for (int i = 0; i < inspectionCount; i++) {
        if (inspections[i].getClaimId() == claimId)
            return true;
    }
    return false;
}

void InsuranceSystem::loadAllData() {
    customerCount  = fileManager.loadCustomers(customers, MAX_SIZE);
    salesmanCount  = fileManager.loadSalesmen(salesmen, MAX_SIZE);
    surveyorCount  = fileManager.loadSurveyors(surveyors, MAX_SIZE);
    vehicleCount   = fileManager.loadVehicles(vehicles, MAX_SIZE);
    policyCount    = fileManager.loadPolicies(policies, MAX_SIZE);
    claimCount     = fileManager.loadClaims(claims, MAX_SIZE);
    inspectionCount= fileManager.loadInspections(inspections, MAX_SIZE);
    workshopCount  = fileManager.loadWorkshops(workshops, MAX_SIZE);
    repairJobCount = fileManager.loadRepairJobs(repairJobs, MAX_SIZE);
}

void InsuranceSystem::saveAllData() {
    fileManager.saveCustomers(customers, customerCount);
    fileManager.saveSalesmen(salesmen, salesmanCount);
    fileManager.saveSurveyors(surveyors, surveyorCount);
    fileManager.saveVehicles(vehicles, vehicleCount);
    fileManager.savePolicies(policies, policyCount);
    fileManager.saveClaims(claims, claimCount);
    fileManager.saveInspections(inspections, inspectionCount);
    fileManager.saveWorkshops(workshops, workshopCount);
    fileManager.saveRepairJobs(repairJobs, repairJobCount);
}

bool InsuranceSystem::addCustomer(string name, string cnic, string phone,
                                   string email, string address, string registrationDate) {
    if (customerCount >= MAX_SIZE) return false;
    string newId = generateId("C", customerCount);
    customers[customerCount++] = Customer(newId, name, cnic, phone, email,
                                          address, registrationDate);
    fileManager.saveCustomers(customers, customerCount);
    return true;
}

bool InsuranceSystem::addVehicle(string customerId, string make, string model,
                                  string year, string licensePlate, string color) {
    if (!customerExists(customerId)) {
        cout << "Customer ID not found." << endl;
        return false;
    }
    if (vehicleCount >= MAX_SIZE) return false;
    string newId = generateId("V", vehicleCount);
    vehicles[vehicleCount++] = Vehicle(newId, customerId, make, model,
                                       year, licensePlate, color);
    fileManager.saveVehicles(vehicles, vehicleCount);
    return true;
}

bool InsuranceSystem::createPolicy(string customerId, string vehicleId,
                                    string policyType, string startDate,
                                    string endDate, double premiumAmount,
                                    double coverageAmount) {
    if (!customerExists(customerId)) {
        cout << "Customer ID not found." << endl;
        return false;
    }
    bool vehicleFound = false;
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i].getVehicleId() == vehicleId &&
            vehicles[i].getCustomerId() == customerId) {
            vehicleFound = true;
            break;
        }
    }
    if (!vehicleFound) {
        cout << "Vehicle not found for this customer." << endl;
        return false;
    }
    if (policyCount >= MAX_SIZE) return false;
    string newId = generateId("POL", policyCount);
    policies[policyCount++] = Policy(newId, customerId, vehicleId, policyType,
                                     startDate, endDate, premiumAmount,
                                     coverageAmount, "Active");
    fileManager.savePolicies(policies, policyCount);
    return true;
}

bool InsuranceSystem::fileClaim(string policyId, string customerId, string workshopId,
                                 string claimDate, string description,
                                 double estimatedDamage) {
    if (!policyExists(policyId)) {
        cout << "Policy not found." << endl;
        return false;
    }
    if (!customerExists(customerId)) {
        cout << "Customer not found." << endl;
        return false;
    }
    if (!workshopExists(workshopId)) {
        cout << "Workshop not registered. Cannot file claim." << endl;
        return false;
    }
    if (claimCount >= MAX_SIZE) return false;
    string newId = generateId("CLM", claimCount);
    claims[claimCount++] = Claim(newId, policyId, customerId, workshopId,
                                  claimDate, description, estimatedDamage, "Pending");
    fileManager.saveClaims(claims, claimCount);
    return true;
}

bool InsuranceSystem::addInspection(string claimId, string surveyorId,
                                     string inspectionDate, string findings,
                                     double repairCost, string recommendation) {
    if (!claimExists(claimId)) {
        cout << "Claim not found." << endl;
        return false;
    }
    if (inspectionCount >= MAX_SIZE) return false;
    string newId = generateId("INS", inspectionCount);
    inspections[inspectionCount++] = Inspection(newId, claimId, surveyorId,
                                                  inspectionDate, findings,
                                                  repairCost, recommendation);
    fileManager.saveInspections(inspections, inspectionCount);
    return true;
}

bool InsuranceSystem::addWorkshop(string name, string address, string phone,
                                   string ownerName, string registrationDate) {
    if (workshopCount >= MAX_SIZE) return false;
    string newId = generateId("W", workshopCount);
    workshops[workshopCount++] = Workshop(newId, name, address, phone,
                                          ownerName, registrationDate);
    fileManager.saveWorkshops(workshops, workshopCount);
    return true;
}

bool InsuranceSystem::addRepairJob(string claimId, string workshopId,
                                    string vehicleId, string startDate,
                                    string endDate, double repairCost) {
    if (!claimExists(claimId)) {
        cout << "Claim not found." << endl;
        return false;
    }
    if (!workshopExists(workshopId)) {
        cout << "Workshop not registered." << endl;
        return false;
    }
    if (repairJobCount >= MAX_SIZE) return false;
    string newId = generateId("RJ", repairJobCount);
    repairJobs[repairJobCount++] = RepairJob(newId, claimId, workshopId, vehicleId,
                                              startDate, endDate, repairCost, "InProgress");
    fileManager.saveRepairJobs(repairJobs, repairJobCount);
    return true;
}

bool InsuranceSystem::approveClaim(string claimId) {
    if (!inspectionExistsForClaim(claimId)) return false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getClaimId() == claimId) {
            claims[i].setStatus("Approved");
            fileManager.saveClaims(claims, claimCount);
            return true;
        }
    }
    return false;
}

bool InsuranceSystem::rejectClaim(string claimId) {
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getClaimId() == claimId) {
            claims[i].setStatus("Rejected");
            fileManager.saveClaims(claims, claimCount);
            return true;
        }
    }
    return false;
}

void InsuranceSystem::displayCustomerProfile(string customerId) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getId() == customerId) {
            customers[i].displayInfo();
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void InsuranceSystem::displayCustomerVehicles(string customerId) {
    cout << "\n===== VEHICLES =====" << endl;
    bool found = false;
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i].getCustomerId() == customerId) {
            vehicles[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No vehicles found." << endl;
}

void InsuranceSystem::displayCustomerPolicies(string customerId) {
    cout << "\n===== POLICIES =====" << endl;
    bool found = false;
    for (int i = 0; i < policyCount; i++) {
        if (policies[i].getCustomerId() == customerId) {
            policies[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No policies found." << endl;
}

void InsuranceSystem::displayCustomerClaims(string customerId) {
    cout << "\n===== CLAIMS =====" << endl;
    bool found = false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getCustomerId() == customerId) {
            claims[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No claims found." << endl;
}

void InsuranceSystem::displayClaimStatus(string claimId, string customerId) {
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getClaimId() == claimId &&
            claims[i].getCustomerId() == customerId) {
            cout << "Claim ID : " << claimId << endl;
            cout << "Status   : " << claims[i].getStatus() << endl;
            return;
        }
    }
    cout << "Claim not found for this customer." << endl;
}

void InsuranceSystem::displayWorkshopForClaim(string customerId) {
    cout << "\n===== WORKSHOP DETAILS FOR YOUR CLAIMS =====" << endl;
    bool found = false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getCustomerId() == customerId) {
            string wid = claims[i].getWorkshopId();
            for (int j = 0; j < workshopCount; j++) {
                if (workshops[j].getWorkshopId() == wid) {
                    cout << "Claim ID : " << claims[i].getClaimId() << endl;
                    workshops[j].displayInfo();
                    cout << "--------------------" << endl;
                    found = true;
                }
            }
        }
    }
    if (!found) cout << "No workshop details found." << endl;
}

void InsuranceSystem::displayInspectionSummary(string customerId) {
    cout << "\n===== INSPECTION SUMMARY =====" << endl;
    bool found = false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getCustomerId() == customerId) {
            for (int j = 0; j < inspectionCount; j++) {
                if (inspections[j].getClaimId() == claims[i].getClaimId()) {
                    inspections[j].displayInfo();
                    cout << "--------------------" << endl;
                    found = true;
                }
            }
        }
    }
    if (!found) cout << "No inspection reports found." << endl;
}

void InsuranceSystem::displayMonthlyCustomers(string month) {
    cout << "\n===== NEW CUSTOMERS IN MONTH: " << month << " =====" << endl;
    bool found = false;
    for (int i = 0; i < customerCount; i++) {
        string regDate = customers[i].getRegistrationDate();
        if (regDate.size() >= 7 && regDate.substr(0, 7) == month) {
            customers[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No customers found for this month." << endl;
}

void InsuranceSystem::displayPendingClaims() {
    cout << "\n===== PENDING CLAIMS =====" << endl;
    bool found = false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getStatus() == "Pending") {
            claims[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No pending claims." << endl;
}

void InsuranceSystem::displayAllInspectionReports() {
    cout << "\n===== ALL INSPECTION REPORTS =====" << endl;
    if (inspectionCount == 0) {
        cout << "No inspection reports found." << endl;
        return;
    }
    for (int i = 0; i < inspectionCount; i++) {
        inspections[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

void InsuranceSystem::displayCustomerClaimHistory(string customerId) {
    cout << "\n===== CLAIM HISTORY FOR CUSTOMER: " << customerId << " =====" << endl;
    bool found = false;
    for (int i = 0; i < claimCount; i++) {
        if (claims[i].getCustomerId() == customerId) {
            claims[i].displayInfo();
            cout << "--------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "No claims found for this customer." << endl;
}

void InsuranceSystem::displayAllWorkshops() {
    cout << "\n===== REGISTERED WORKSHOPS =====" << endl;
    if (workshopCount == 0) {
        cout << "No workshops registered." << endl;
        return;
    }
    for (int i = 0; i < workshopCount; i++) {
        workshops[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

void InsuranceSystem::displayAllCustomers() {
    cout << "\n===== ALL CUSTOMERS =====" << endl;
    if (customerCount == 0) {
        cout << "No customers found." << endl;
        return;
    }
    for (int i = 0; i < customerCount; i++) {
        customers[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

void InsuranceSystem::displayAllVehicles() {
    cout << "\n===== ALL VEHICLES =====" << endl;
    if (vehicleCount == 0) {
        cout << "No vehicles found." << endl;
        return;
    }
    for (int i = 0; i < vehicleCount; i++) {
        vehicles[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

void InsuranceSystem::displayAllPolicies() {
    cout << "\n===== ALL POLICIES =====" << endl;
    if (policyCount == 0) {
        cout << "No policies found." << endl;
        return;
    }
    for (int i = 0; i < policyCount; i++) {
        policies[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

void InsuranceSystem::displayAllClaims() {
    cout << "\n===== ALL CLAIMS =====" << endl;
    if (claimCount == 0) {
        cout << "No claims found." << endl;
        return;
    }
    for (int i = 0; i < claimCount; i++) {
        claims[i].displayInfo();
        cout << "--------------------" << endl;
    }
}

Customer* InsuranceSystem::findCustomerById(string id) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].getId() == id)
            return &customers[i];
    }
    return nullptr;
}

int InsuranceSystem::getCustomerCount() const {
    return customerCount;
}

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int FileManager::loadCustomers(Customer customers[], int maxSize) {
    ifstream file("customers.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, cnic, phone, email, address, date;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, cnic, '|');
        getline(ss, phone, '|');
        getline(ss, email, '|');
        getline(ss, address, '|');
        getline(ss, date, '|');
        customers[count++] = Customer(id, name, cnic, phone, email, address, date);
    }
    return count;
}

void FileManager::saveCustomers(Customer customers[], int count) {
    ofstream file("customers.txt");
    for (int i = 0; i < count; i++) {
        file << customers[i].getId() << "|"
             << customers[i].getName() << "|"
             << customers[i].getCnic() << "|"
             << customers[i].getPhone() << "|"
             << customers[i].getEmail() << "|"
             << customers[i].getAddress() << "|"
             << customers[i].getRegistrationDate() << "\n";
    }
}

int FileManager::loadSalesmen(Salesman salesmen[], int maxSize) {
    ifstream file("salesmen.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, cnic, phone, email, dept, date;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, cnic, '|');
        getline(ss, phone, '|');
        getline(ss, email, '|');
        getline(ss, dept, '|');
        getline(ss, date, '|');
        salesmen[count++] = Salesman(id, name, cnic, phone, email, dept, date);
    }
    return count;
}

void FileManager::saveSalesmen(Salesman salesmen[], int count) {
    ofstream file("salesmen.txt");
    for (int i = 0; i < count; i++) {
        file << salesmen[i].getId() << "|"
             << salesmen[i].getName() << "|"
             << salesmen[i].getCnic() << "|"
             << salesmen[i].getPhone() << "|"
             << salesmen[i].getEmail() << "|"
             << salesmen[i].getDepartment() << "|"
             << salesmen[i].getHireDate() << "\n";
    }
}

int FileManager::loadSurveyors(Surveyor surveyors[], int maxSize) {
    ifstream file("surveyors.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, cnic, phone, email, spec, date;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, cnic, '|');
        getline(ss, phone, '|');
        getline(ss, email, '|');
        getline(ss, spec, '|');
        getline(ss, date, '|');
        surveyors[count++] = Surveyor(id, name, cnic, phone, email, spec, date);
    }
    return count;
}

void FileManager::saveSurveyors(Surveyor surveyors[], int count) {
    ofstream file("surveyors.txt");
    for (int i = 0; i < count; i++) {
        file << surveyors[i].getId() << "|"
             << surveyors[i].getName() << "|"
             << surveyors[i].getCnic() << "|"
             << surveyors[i].getPhone() << "|"
             << surveyors[i].getEmail() << "|"
             << surveyors[i].getSpecialization() << "|"
             << surveyors[i].getCertificationDate() << "\n";
    }
}

int FileManager::loadVehicles(Vehicle vehicles[], int maxSize) {
    ifstream file("vehicles.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string vid, cid, make, model, year, plate, color;
        getline(ss, vid, '|');
        getline(ss, cid, '|');
        getline(ss, make, '|');
        getline(ss, model, '|');
        getline(ss, year, '|');
        getline(ss, plate, '|');
        getline(ss, color, '|');
        vehicles[count++] = Vehicle(vid, cid, make, model, year, plate, color);
    }
    return count;
}

void FileManager::saveVehicles(Vehicle vehicles[], int count) {
    ofstream file("vehicles.txt");
    for (int i = 0; i < count; i++) {
        file << vehicles[i].getVehicleId() << "|"
             << vehicles[i].getCustomerId() << "|"
             << vehicles[i].getMake() << "|"
             << vehicles[i].getModel() << "|"
             << vehicles[i].getYear() << "|"
             << vehicles[i].getLicensePlate() << "|"
             << vehicles[i].getColor() << "\n";
    }
}

int FileManager::loadPolicies(Policy policies[], int maxSize) {
    ifstream file("policies.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string pid, cid, vid, type, start, end, premStr, covStr, status;
        getline(ss, pid, '|');
        getline(ss, cid, '|');
        getline(ss, vid, '|');
        getline(ss, type, '|');
        getline(ss, start, '|');
        getline(ss, end, '|');
        getline(ss, premStr, '|');
        getline(ss, covStr, '|');
        getline(ss, status, '|');
        policies[count++] = Policy(pid, cid, vid, type, start, end,
                                   stod(premStr), stod(covStr), status);
    }
    return count;
}

void FileManager::savePolicies(Policy policies[], int count) {
    ofstream file("policies.txt");
    for (int i = 0; i < count; i++) {
        file << policies[i].getPolicyId() << "|"
             << policies[i].getCustomerId() << "|"
             << policies[i].getVehicleId() << "|"
             << policies[i].getPolicyType() << "|"
             << policies[i].getStartDate() << "|"
             << policies[i].getEndDate() << "|"
             << policies[i].getPremiumAmount() << "|"
             << policies[i].getCoverageAmount() << "|"
             << policies[i].getStatus() << "\n";
    }
}

int FileManager::loadClaims(Claim claims[], int maxSize) {
    ifstream file("claims.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string clid, polid, cid, wid, date, desc, estStr, status;
        getline(ss, clid, '|');
        getline(ss, polid, '|');
        getline(ss, cid, '|');
        getline(ss, wid, '|');
        getline(ss, date, '|');
        getline(ss, desc, '|');
        getline(ss, estStr, '|');
        getline(ss, status, '|');
        claims[count++] = Claim(clid, polid, cid, wid, date, desc,
                                stod(estStr), status);
    }
    return count;
}

void FileManager::saveClaims(Claim claims[], int count) {
    ofstream file("claims.txt");
    for (int i = 0; i < count; i++) {
        file << claims[i].getClaimId() << "|"
             << claims[i].getPolicyId() << "|"
             << claims[i].getCustomerId() << "|"
             << claims[i].getWorkshopId() << "|"
             << claims[i].getClaimDate() << "|"
             << claims[i].getDescription() << "|"
             << claims[i].getEstimatedDamage() << "|"
             << claims[i].getStatus() << "\n";
    }
}

int FileManager::loadInspections(Inspection inspections[], int maxSize) {
    ifstream file("inspections.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string iid, clid, sid, date, findings, costStr, rec;
        getline(ss, iid, '|');
        getline(ss, clid, '|');
        getline(ss, sid, '|');
        getline(ss, date, '|');
        getline(ss, findings, '|');
        getline(ss, costStr, '|');
        getline(ss, rec, '|');
        inspections[count++] = Inspection(iid, clid, sid, date, findings,
                                          stod(costStr), rec);
    }
    return count;
}

void FileManager::saveInspections(Inspection inspections[], int count) {
    ofstream file("inspections.txt");
    for (int i = 0; i < count; i++) {
        file << inspections[i].getInspectionId() << "|"
             << inspections[i].getClaimId() << "|"
             << inspections[i].getSurveyorId() << "|"
             << inspections[i].getInspectionDate() << "|"
             << inspections[i].getFindings() << "|"
             << inspections[i].getEstimatedRepairCost() << "|"
             << inspections[i].getRecommendation() << "\n";
    }
}

int FileManager::loadWorkshops(Workshop workshops[], int maxSize) {
    ifstream file("workshops.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string wid, name, address, phone, owner, date;
        getline(ss, wid, '|');
        getline(ss, name, '|');
        getline(ss, address, '|');
        getline(ss, phone, '|');
        getline(ss, owner, '|');
        getline(ss, date, '|');
        workshops[count++] = Workshop(wid, name, address, phone, owner, date);
    }
    return count;
}

void FileManager::saveWorkshops(Workshop workshops[], int count) {
    ofstream file("workshops.txt");
    for (int i = 0; i < count; i++) {
        file << workshops[i].getWorkshopId() << "|"
             << workshops[i].getName() << "|"
             << workshops[i].getAddress() << "|"
             << workshops[i].getPhone() << "|"
             << workshops[i].getOwnerName() << "|"
             << workshops[i].getRegistrationDate() << "\n";
    }
}

int FileManager::loadRepairJobs(RepairJob repairJobs[], int maxSize) {
    ifstream file("repairjobs.txt");
    int count = 0;
    string line;
    while (getline(file, line) && count < maxSize) {
        if (line.empty()) continue;
        stringstream ss(line);
        string rjid, clid, wid, vid, start, end, costStr, status;
        getline(ss, rjid, '|');
        getline(ss, clid, '|');
        getline(ss, wid, '|');
        getline(ss, vid, '|');
        getline(ss, start, '|');
        getline(ss, end, '|');
        getline(ss, costStr, '|');
        getline(ss, status, '|');
        repairJobs[count++] = RepairJob(rjid, clid, wid, vid, start, end,
                                        stod(costStr), status);
    }
    return count;
}

void FileManager::saveRepairJobs(RepairJob repairJobs[], int count) {
    ofstream file("repairjobs.txt");
    for (int i = 0; i < count; i++) {
        file << repairJobs[i].getRepairJobId() << "|"
             << repairJobs[i].getClaimId() << "|"
             << repairJobs[i].getWorkshopId() << "|"
             << repairJobs[i].getVehicleId() << "|"
             << repairJobs[i].getStartDate() << "|"
             << repairJobs[i].getEndDate() << "|"
             << repairJobs[i].getRepairCost() << "|"
             << repairJobs[i].getStatus() << "\n";
    }
}

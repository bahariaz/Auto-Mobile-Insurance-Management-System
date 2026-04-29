#ifndef INSURANCESYSTEM_H
#define INSURANCESYSTEM_H

#include "FileManager.h"

const int MAX_SIZE = 200;

class InsuranceSystem {
private:
    Customer customers[MAX_SIZE];
    Salesman salesmen[MAX_SIZE];
    Surveyor surveyors[MAX_SIZE];
    Vehicle vehicles[MAX_SIZE];
    Policy policies[MAX_SIZE];
    Claim claims[MAX_SIZE];
    Inspection inspections[MAX_SIZE];
    Workshop workshops[MAX_SIZE];
    RepairJob repairJobs[MAX_SIZE];

    int customerCount;
    int salesmanCount;
    int surveyorCount;
    int vehicleCount;
    int policyCount;
    int claimCount;
    int inspectionCount;
    int workshopCount;
    int repairJobCount;

    FileManager fileManager;

    string generateId(string prefix, int count);
    bool workshopExists(string workshopId);
    bool policyExists(string policyId);
    bool customerExists(string customerId);
    bool claimExists(string claimId);
    bool inspectionExistsForClaim(string claimId);

public:
    InsuranceSystem();

    void loadAllData();
    void saveAllData();

    bool addCustomer(string name, string cnic, string phone, string email,
                     string address, string registrationDate);
    bool addVehicle(string customerId, string make, string model,
                    string year, string licensePlate, string color);
    bool createPolicy(string customerId, string vehicleId, string policyType,
                      string startDate, string endDate,
                      double premiumAmount, double coverageAmount);
    bool fileClaim(string policyId, string customerId, string workshopId,
                   string claimDate, string description, double estimatedDamage);
    bool addInspection(string claimId, string surveyorId, string inspectionDate,
                       string findings, double repairCost, string recommendation);
    bool addWorkshop(string name, string address, string phone,
                     string ownerName, string registrationDate);
    bool addRepairJob(string claimId, string workshopId, string vehicleId,
                      string startDate, string endDate, double repairCost);

    bool approveClaim(string claimId);
    bool rejectClaim(string claimId);

    void displayCustomerProfile(string customerId);
    void displayCustomerVehicles(string customerId);
    void displayCustomerPolicies(string customerId);
    void displayCustomerClaims(string customerId);
    void displayClaimStatus(string claimId, string customerId);
    void displayWorkshopForClaim(string customerId);
    void displayInspectionSummary(string customerId);

    void displayMonthlyCustomers(string month);
    void displayPendingClaims();
    void displayAllInspectionReports();
    void displayCustomerClaimHistory(string customerId);
    void displayAllWorkshops();
    void displayAllCustomers();
    void displayAllVehicles();
    void displayAllPolicies();
    void displayAllClaims();

    Customer* findCustomerById(string id);
    int getCustomerCount() const;
};

#endif

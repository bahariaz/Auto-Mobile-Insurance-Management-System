#include "RepairJob.h"
#include <iostream>
using namespace std;

RepairJob::RepairJob() : repairCost(0) {}

RepairJob::RepairJob(string repairJobId, string claimId, string workshopId,
                     string vehicleId, string startDate, string endDate,
                     double repairCost, string status)
    : repairJobId(repairJobId), claimId(claimId), workshopId(workshopId),
      vehicleId(vehicleId), startDate(startDate), endDate(endDate),
      repairCost(repairCost), status(status) {}

string RepairJob::getRepairJobId() const { return repairJobId; }
string RepairJob::getClaimId() const { return claimId; }
string RepairJob::getWorkshopId() const { return workshopId; }
string RepairJob::getVehicleId() const { return vehicleId; }
string RepairJob::getStartDate() const { return startDate; }
string RepairJob::getEndDate() const { return endDate; }
double RepairJob::getRepairCost() const { return repairCost; }
string RepairJob::getStatus() const { return status; }

void RepairJob::setRepairJobId(string id) { repairJobId = id; }
void RepairJob::setClaimId(string id) { claimId = id; }
void RepairJob::setWorkshopId(string id) { workshopId = id; }
void RepairJob::setVehicleId(string id) { vehicleId = id; }
void RepairJob::setStartDate(string date) { startDate = date; }
void RepairJob::setEndDate(string date) { endDate = date; }
void RepairJob::setRepairCost(double cost) { repairCost = cost; }
void RepairJob::setStatus(string status) { this->status = status; }

void RepairJob::displayInfo() const {
    cout << "Repair Job ID : " << repairJobId << endl;
    cout << "Claim ID      : " << claimId << endl;
    cout << "Workshop ID   : " << workshopId << endl;
    cout << "Vehicle ID    : " << vehicleId << endl;
    cout << "Start Date    : " << startDate << endl;
    cout << "End Date      : " << endDate << endl;
    cout << "Repair Cost   : " << repairCost << endl;
    cout << "Status        : " << status << endl;
}

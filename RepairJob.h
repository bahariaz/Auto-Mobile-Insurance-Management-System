#ifndef REPAIRJOB_H
#define REPAIRJOB_H

#include <string>
using namespace std;

class RepairJob {
private:
    string repairJobId;
    string claimId;
    string workshopId;
    string vehicleId;
    string startDate;
    string endDate;
    double repairCost;
    string status;

public:
    RepairJob();
    RepairJob(string repairJobId, string claimId, string workshopId,
              string vehicleId, string startDate, string endDate,
              double repairCost, string status);

    string getRepairJobId() const;
    string getClaimId() const;
    string getWorkshopId() const;
    string getVehicleId() const;
    string getStartDate() const;
    string getEndDate() const;
    double getRepairCost() const;
    string getStatus() const;

    void setRepairJobId(string id);
    void setClaimId(string id);
    void setWorkshopId(string id);
    void setVehicleId(string id);
    void setStartDate(string date);
    void setEndDate(string date);
    void setRepairCost(double cost);
    void setStatus(string status);

    void displayInfo() const;
};

#endif

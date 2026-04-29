#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Customer.h"
#include "Salesman.h"
#include "Surveyor.h"
#include "Manager.h"
#include "Vehicle.h"
#include "Policy.h"
#include "Claim.h"
#include "Inspection.h"
#include "Workshop.h"
#include "RepairJob.h"

const int MAX_RECORDS = 200;

class FileManager {
public:
    int loadCustomers(Customer customers[], int maxSize);
    void saveCustomers(Customer customers[], int count);

    int loadSalesmen(Salesman salesmen[], int maxSize);
    void saveSalesmen(Salesman salesmen[], int count);

    int loadSurveyors(Surveyor surveyors[], int maxSize);
    void saveSurveyors(Surveyor surveyors[], int count);

    int loadVehicles(Vehicle vehicles[], int maxSize);
    void saveVehicles(Vehicle vehicles[], int count);

    int loadPolicies(Policy policies[], int maxSize);
    void savePolicies(Policy policies[], int count);

    int loadClaims(Claim claims[], int maxSize);
    void saveClaims(Claim claims[], int count);

    int loadInspections(Inspection inspections[], int maxSize);
    void saveInspections(Inspection inspections[], int count);

    int loadWorkshops(Workshop workshops[], int maxSize);
    void saveWorkshops(Workshop workshops[], int count);

    int loadRepairJobs(RepairJob repairJobs[], int maxSize);
    void saveRepairJobs(RepairJob repairJobs[], int count);
};

#endif

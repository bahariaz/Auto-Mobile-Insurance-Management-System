#ifndef MENUUI_H
#define MENUUI_H

#include "InsuranceSystem.h"

class MenuUI {
private:
    InsuranceSystem sys;

    void showMainMenu();
    void showManagerMenu();
    void showStaffMenu();
    void showCustomerMenu();

    void handleManagerMenu();
    void handleStaffMenu();
    void handleCustomerLogin();

    void managerAddCustomerFlow();
    void managerViewReports();
    void managerApproveClaim();
    void managerRejectClaim();
    void managerViewCustomerHistory();

    void staffAddCustomer();
    void staffAddVehicle();
    void staffCreatePolicy();
    void staffFileClaim();
    void staffAddInspection();
    void staffAddWorkshop();
    void staffAddRepairJob();
    void staffViewWorkshops();
    void staffViewAllCustomers();
    void staffViewAllVehicles();
    void staffViewAllPolicies();
    void staffViewAllClaims();

public:
    MenuUI();
    void run();
};

#endif

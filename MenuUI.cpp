#include "MenuUI.h"
#include <iostream>
#include <limits>
using namespace std;

MenuUI::MenuUI() {
    sys.loadAllData();
}

void MenuUI::showMainMenu() {
    cout << "\n========================================" << endl;
    cout << "   AUTO INSURANCE INFORMATION SYSTEM    " << endl;
    cout << "========================================" << endl;
    cout << " 1. Manager Login" << endl;
    cout << " 2. Staff Login" << endl;
    cout << " 3. Customer Login" << endl;
    cout << " 0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter option: ";
}

void MenuUI::showManagerMenu() {
    cout << "\n===== MANAGER MENU =====" << endl;
    cout << " 1. View Monthly New Customers" << endl;
    cout << " 2. View Pending Claims" << endl;
    cout << " 3. View All Inspection Reports" << endl;
    cout << " 4. Approve Claim" << endl;
    cout << " 5. Reject Claim" << endl;
    cout << " 6. View Customer Claim History" << endl;
    cout << " 7. View All Workshops" << endl;
    cout << " 0. Logout" << endl;
    cout << "========================" << endl;
    cout << "Enter option: ";
}

void MenuUI::showStaffMenu() {
    cout << "\n===== STAFF MENU =====" << endl;
    cout << " 1.  Add Customer" << endl;
    cout << " 2.  Add Vehicle" << endl;
    cout << " 3.  Create Policy" << endl;
    cout << " 4.  File Claim" << endl;
    cout << " 5.  Add Inspection Report" << endl;
    cout << " 6.  Add Workshop" << endl;
    cout << " 7.  Add Repair Job" << endl;
    cout << " 8.  View All Customers" << endl;
    cout << " 9.  View All Vehicles" << endl;
    cout << " 10. View All Policies" << endl;
    cout << " 11. View All Claims" << endl;
    cout << " 12. View All Workshops" << endl;
    cout << " 0.  Logout" << endl;
    cout << "======================" << endl;
    cout << "Enter option: ";
}

void MenuUI::showCustomerMenu() {
    cout << "\n===== CUSTOMER MENU =====" << endl;
    cout << " 1. View Profile" << endl;
    cout << " 2. View My Vehicles" << endl;
    cout << " 3. View My Policies" << endl;
    cout << " 4. View My Claims" << endl;
    cout << " 5. Check Claim Status" << endl;
    cout << " 6. View Workshop Details" << endl;
    cout << " 7. View Inspection Summary" << endl;
    cout << " 0. Logout" << endl;
    cout << "=========================" << endl;
    cout << "Enter option: ";
}

void MenuUI::managerApproveClaim() {
    string claimId;
    cout << "Enter Claim ID to approve: ";
    cin >> claimId;
    Manager anjum("M1", "Anjum", "33333-3333333-3", "0333-3333333",
                  "anjum@ins.com", "Senior Manager", "2018-01-01");
    anjum.approveClaim(sys, claimId);
}

void MenuUI::managerRejectClaim() {
    string claimId;
    cout << "Enter Claim ID to reject: ";
    cin >> claimId;
    Manager anjum("M1", "Anjum", "33333-3333333-3", "0333-3333333",
                  "anjum@ins.com", "Senior Manager", "2018-01-01");
    anjum.rejectClaim(sys, claimId);
}

void MenuUI::managerViewCustomerHistory() {
    string customerId;
    cout << "Enter Customer ID: ";
    cin >> customerId;
    Manager anjum("M1", "Anjum", "33333-3333333-3", "0333-3333333",
                  "anjum@ins.com", "Senior Manager", "2018-01-01");
    anjum.viewCustomerClaimHistory(sys, customerId);
}

void MenuUI::handleManagerMenu() {
    Manager anjum("M1", "Anjum", "33333-3333333-3", "0333-3333333",
                  "anjum@ins.com", "Senior Manager", "2018-01-01");
    anjum.login();
    int managerOption;
    do {
        showManagerMenu();
        cin >> managerOption;
        if (managerOption == 1) {
            string month;
            cout << "Enter month (YYYY-MM): ";
            cin >> month;
            anjum.viewMonthlyCustomers(sys, month);
        } else if (managerOption == 2) {
            anjum.viewPendingClaims(sys);
        } else if (managerOption == 3) {
            anjum.viewInspectionReports(sys);
        } else if (managerOption == 4) {
            managerApproveClaim();
        } else if (managerOption == 5) {
            managerRejectClaim();
        } else if (managerOption == 6) {
            managerViewCustomerHistory();
        } else if (managerOption == 7) {
            sys.displayAllWorkshops();
        } else if (managerOption != 0) {
            cout << "Invalid option." << endl;
        }
    } while (managerOption != 0);
    cout << "Manager logged out." << endl;
}

void MenuUI::staffAddCustomer() {
    string name, cnic, phone, email, address, date;
    cout << "Name: "; cin.ignore(); getline(cin, name);
    cout << "CNIC: "; getline(cin, cnic);
    cout << "Phone: "; getline(cin, phone);
    cout << "Email: "; getline(cin, email);
    cout << "Address: "; getline(cin, address);
    cout << "Registration Date (YYYY-MM-DD): "; getline(cin, date);
    if (sys.addCustomer(name, cnic, phone, email, address, date))
        cout << "Customer added successfully." << endl;
    else
        cout << "Failed to add customer." << endl;
}

void MenuUI::staffAddVehicle() {
    string customerId, make, model, year, plate, color;
    cout << "Customer ID: "; cin >> customerId;
    cout << "Make: "; cin.ignore(); getline(cin, make);
    cout << "Model: "; getline(cin, model);
    cout << "Year: "; getline(cin, year);
    cout << "License Plate: "; getline(cin, plate);
    cout << "Color: "; getline(cin, color);
    if (sys.addVehicle(customerId, make, model, year, plate, color))
        cout << "Vehicle added successfully." << endl;
    else
        cout << "Failed to add vehicle." << endl;
}

void MenuUI::staffCreatePolicy() {
    string customerId, vehicleId, type, start, end;
    double premium, coverage;
    cout << "Customer ID: "; cin >> customerId;
    cout << "Vehicle ID: "; cin >> vehicleId;
    cout << "Policy Type (Comprehensive/Third-Party): "; cin.ignore(); getline(cin, type);
    cout << "Start Date (YYYY-MM-DD): "; getline(cin, start);
    cout << "End Date (YYYY-MM-DD): "; getline(cin, end);
    cout << "Premium Amount: "; cin >> premium;
    cout << "Coverage Amount: "; cin >> coverage;
    if (sys.createPolicy(customerId, vehicleId, type, start, end, premium, coverage))
        cout << "Policy created successfully." << endl;
    else
        cout << "Failed to create policy." << endl;
}

void MenuUI::staffFileClaim() {
    string policyId, customerId, workshopId, date, description;
    double damage;
    cout << "Policy ID: "; cin >> policyId;
    cout << "Customer ID: "; cin >> customerId;
    cout << "Workshop ID: "; cin >> workshopId;
    cout << "Claim Date (YYYY-MM-DD): "; cin.ignore(); getline(cin, date);
    cout << "Description: "; getline(cin, description);
    cout << "Estimated Damage: "; cin >> damage;
    if (sys.fileClaim(policyId, customerId, workshopId, date, description, damage))
        cout << "Claim filed successfully." << endl;
    else
        cout << "Failed to file claim." << endl;
}

void MenuUI::staffAddInspection() {
    string claimId, surveyorId, date, findings, recommendation;
    double repairCost;
    cout << "Claim ID: "; cin >> claimId;
    cout << "Surveyor ID: "; cin >> surveyorId;
    cout << "Inspection Date (YYYY-MM-DD): "; cin.ignore(); getline(cin, date);
    cout << "Findings: "; getline(cin, findings);
    cout << "Estimated Repair Cost: "; cin >> repairCost;
    cout << "Recommendation: "; cin.ignore(); getline(cin, recommendation);
    if (sys.addInspection(claimId, surveyorId, date, findings, repairCost, recommendation))
        cout << "Inspection report added successfully." << endl;
    else
        cout << "Failed to add inspection report." << endl;
}

void MenuUI::staffAddWorkshop() {
    string name, address, phone, owner, date;
    cout << "Workshop Name: "; cin.ignore(); getline(cin, name);
    cout << "Address: "; getline(cin, address);
    cout << "Phone: "; getline(cin, phone);
    cout << "Owner Name: "; getline(cin, owner);
    cout << "Registration Date (YYYY-MM-DD): "; getline(cin, date);
    if (sys.addWorkshop(name, address, phone, owner, date))
        cout << "Workshop registered successfully." << endl;
    else
        cout << "Failed to register workshop." << endl;
}

void MenuUI::staffAddRepairJob() {
    string claimId, workshopId, vehicleId, start, end;
    double cost;
    cout << "Claim ID: "; cin >> claimId;
    cout << "Workshop ID: "; cin >> workshopId;
    cout << "Vehicle ID: "; cin >> vehicleId;
    cout << "Start Date (YYYY-MM-DD): "; cin.ignore(); getline(cin, start);
    cout << "End Date (YYYY-MM-DD): "; getline(cin, end);
    cout << "Repair Cost: "; cin >> cost;
    if (sys.addRepairJob(claimId, workshopId, vehicleId, start, end, cost))
        cout << "Repair job added successfully." << endl;
    else
        cout << "Failed to add repair job." << endl;
}

void MenuUI::staffViewWorkshops() {
    sys.displayAllWorkshops();
}

void MenuUI::staffViewAllCustomers() {
    sys.displayAllCustomers();
}

void MenuUI::staffViewAllVehicles() {
    sys.displayAllVehicles();
}

void MenuUI::staffViewAllPolicies() {
    sys.displayAllPolicies();
}

void MenuUI::staffViewAllClaims() {
    sys.displayAllClaims();
}

void MenuUI::handleStaffMenu() {
    Salesman bilal("S1", "Bilal", "22222-2222222-2", "0322-2222222",
                   "bilal@ins.com", "Sales", "2020-06-01");
    bilal.login();
    int staffOption;
    do {
        showStaffMenu();
        cin >> staffOption;
        if      (staffOption == 1)  staffAddCustomer();
        else if (staffOption == 2)  staffAddVehicle();
        else if (staffOption == 3)  staffCreatePolicy();
        else if (staffOption == 4)  staffFileClaim();
        else if (staffOption == 5)  staffAddInspection();
        else if (staffOption == 6)  staffAddWorkshop();
        else if (staffOption == 7)  staffAddRepairJob();
        else if (staffOption == 8)  staffViewAllCustomers();
        else if (staffOption == 9)  staffViewAllVehicles();
        else if (staffOption == 10) staffViewAllPolicies();
        else if (staffOption == 11) staffViewAllClaims();
        else if (staffOption == 12) staffViewWorkshops();
        else if (staffOption != 0)  cout << "Invalid option." << endl;
    } while (staffOption != 0);
    cout << "Staff logged out." << endl;
}

void MenuUI::handleCustomerLogin() {
    string customerId;
    cout << "Enter your Customer ID: ";
    cin >> customerId;
    Customer* found = sys.findCustomerById(customerId);
    if (found == nullptr) {
        cout << "Customer ID not found." << endl;
        return;
    }
    found->login();
    int customerOption;
    do {
        showCustomerMenu();
        cin >> customerOption;
        if (customerOption == 1) {
            found->viewProfile();
        } else if (customerOption == 2) {
            found->viewVehicles(sys);
        } else if (customerOption == 3) {
            found->viewPolicies(sys);
        } else if (customerOption == 4) {
            found->viewClaims(sys);
        } else if (customerOption == 5) {
            found->checkClaimStatus(sys);
        } else if (customerOption == 6) {
            found->viewWorkshopDetails(sys);
        } else if (customerOption == 7) {
            found->viewInspectionSummary(sys);
        } else if (customerOption != 0) {
            cout << "Invalid option." << endl;
        }
    } while (customerOption != 0);
    cout << "Customer logged out." << endl;
}

void MenuUI::run() {
    int option;
    do {
        showMainMenu();
        cin >> option;
        if      (option == 1) handleManagerMenu();
        else if (option == 2) handleStaffMenu();
        else if (option == 3) handleCustomerLogin();
        else if (option != 0) cout << "Invalid option. Try again." << endl;
    } while (option != 0);
    sys.saveAllData();
    cout << "\nSystem exited. Data saved. Goodbye!" << endl;
}

#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"

class InsuranceSystem;

class Manager : public Person {
private:
    string designation;
    string joinDate;

public:
    Manager();
    Manager(string id, string name, string cnic, string phone, string email,
            string designation, string joinDate);

    string getDesignation() const;
    string getJoinDate() const;
    void setDesignation(string designation);
    void setJoinDate(string date);

    void login() override;
    void displayInfo() const override;

    void viewMonthlyCustomers(InsuranceSystem& sys, string month) const;
    void viewPendingClaims(InsuranceSystem& sys) const;
    void viewInspectionReports(InsuranceSystem& sys) const;
    void approveClaim(InsuranceSystem& sys, string claimId) const;
    void rejectClaim(InsuranceSystem& sys, string claimId) const;
    void viewCustomerClaimHistory(InsuranceSystem& sys, string customerId) const;
};

#endif

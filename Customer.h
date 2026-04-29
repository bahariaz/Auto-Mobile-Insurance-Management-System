#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class InsuranceSystem;

class Customer : public Person {
private:
    string address;
    string registrationDate;

public:
    Customer();
    Customer(string id, string name, string cnic, string phone, string email,
             string address, string registrationDate);

    string getAddress() const;
    string getRegistrationDate() const;
    void setAddress(string address);
    void setRegistrationDate(string date);

    void login() override;
    void displayInfo() const override;

    void viewProfile() const;
    void viewVehicles(InsuranceSystem& sys) const;
    void viewPolicies(InsuranceSystem& sys) const;
    void viewClaims(InsuranceSystem& sys) const;
    void checkClaimStatus(InsuranceSystem& sys) const;
    void viewWorkshopDetails(InsuranceSystem& sys) const;
    void viewInspectionSummary(InsuranceSystem& sys) const;
};

#endif

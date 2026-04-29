#ifndef POLICY_H
#define POLICY_H

#include <string>
using namespace std;

class Policy {
private:
    string policyId;
    string customerId;
    string vehicleId;
    string policyType;
    string startDate;
    string endDate;
    double premiumAmount;
    double coverageAmount;
    string status;

public:
    Policy();
    Policy(string policyId, string customerId, string vehicleId,
           string policyType, string startDate, string endDate,
           double premiumAmount, double coverageAmount, string status);

    string getPolicyId() const;
    string getCustomerId() const;
    string getVehicleId() const;
    string getPolicyType() const;
    string getStartDate() const;
    string getEndDate() const;
    double getPremiumAmount() const;
    double getCoverageAmount() const;
    string getStatus() const;

    void setPolicyId(string id);
    void setCustomerId(string id);
    void setVehicleId(string id);
    void setPolicyType(string type);
    void setStartDate(string date);
    void setEndDate(string date);
    void setPremiumAmount(double amount);
    void setCoverageAmount(double amount);
    void setStatus(string status);

    void displayInfo() const;
};

#endif

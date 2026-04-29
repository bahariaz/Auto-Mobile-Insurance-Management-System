#ifndef CLAIM_H
#define CLAIM_H

#include <string>
using namespace std;

class Claim {
private:
    string claimId;
    string policyId;
    string customerId;
    string workshopId;
    string claimDate;
    string description;
    double estimatedDamage;
    string status;

public:
    Claim();
    Claim(string claimId, string policyId, string customerId, string workshopId,
          string claimDate, string description, double estimatedDamage, string status);

    string getClaimId() const;
    string getPolicyId() const;
    string getCustomerId() const;
    string getWorkshopId() const;
    string getClaimDate() const;
    string getDescription() const;
    double getEstimatedDamage() const;
    string getStatus() const;

    void setClaimId(string id);
    void setPolicyId(string id);
    void setCustomerId(string id);
    void setWorkshopId(string id);
    void setClaimDate(string date);
    void setDescription(string desc);
    void setEstimatedDamage(double amt);
    void setStatus(string status);

    void displayInfo() const;
};

#endif

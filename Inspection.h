#ifndef INSPECTION_H
#define INSPECTION_H

#include <string>
using namespace std;

class Inspection {
private:
    string inspectionId;
    string claimId;
    string surveyorId;
    string inspectionDate;
    string findings;
    double estimatedRepairCost;
    string recommendation;

public:
    Inspection();
    Inspection(string inspectionId, string claimId, string surveyorId,
               string inspectionDate, string findings,
               double estimatedRepairCost, string recommendation);

    string getInspectionId() const;
    string getClaimId() const;
    string getSurveyorId() const;
    string getInspectionDate() const;
    string getFindings() const;
    double getEstimatedRepairCost() const;
    string getRecommendation() const;

    void setInspectionId(string id);
    void setClaimId(string id);
    void setSurveyorId(string id);
    void setInspectionDate(string date);
    void setFindings(string findings);
    void setEstimatedRepairCost(double cost);
    void setRecommendation(string rec);

    void displayInfo() const;
};

#endif

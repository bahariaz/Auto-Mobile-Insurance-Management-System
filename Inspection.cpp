#include "Inspection.h"
#include <iostream>
using namespace std;

Inspection::Inspection() : estimatedRepairCost(0) {}

Inspection::Inspection(string inspectionId, string claimId, string surveyorId,
                       string inspectionDate, string findings,
                       double estimatedRepairCost, string recommendation)
    : inspectionId(inspectionId), claimId(claimId), surveyorId(surveyorId),
      inspectionDate(inspectionDate), findings(findings),
      estimatedRepairCost(estimatedRepairCost), recommendation(recommendation) {}

string Inspection::getInspectionId() const { return inspectionId; }
string Inspection::getClaimId() const { return claimId; }
string Inspection::getSurveyorId() const { return surveyorId; }
string Inspection::getInspectionDate() const { return inspectionDate; }
string Inspection::getFindings() const { return findings; }
double Inspection::getEstimatedRepairCost() const { return estimatedRepairCost; }
string Inspection::getRecommendation() const { return recommendation; }

void Inspection::setInspectionId(string id) { inspectionId = id; }
void Inspection::setClaimId(string id) { claimId = id; }
void Inspection::setSurveyorId(string id) { surveyorId = id; }
void Inspection::setInspectionDate(string date) { inspectionDate = date; }
void Inspection::setFindings(string findings) { this->findings = findings; }
void Inspection::setEstimatedRepairCost(double cost) { estimatedRepairCost = cost; }
void Inspection::setRecommendation(string rec) { recommendation = rec; }

void Inspection::displayInfo() const {
    cout << "Inspection ID   : " << inspectionId << endl;
    cout << "Claim ID        : " << claimId << endl;
    cout << "Surveyor ID     : " << surveyorId << endl;
    cout << "Date            : " << inspectionDate << endl;
    cout << "Findings        : " << findings << endl;
    cout << "Repair Cost Est : " << estimatedRepairCost << endl;
    cout << "Recommendation  : " << recommendation << endl;
}

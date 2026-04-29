#ifndef SURVEYOR_H
#define SURVEYOR_H

#include "Person.h"

class Surveyor : public Person {
private:
    string specialization;
    string certificationDate;

public:
    Surveyor();
    Surveyor(string id, string name, string cnic, string phone, string email,
             string specialization, string certificationDate);

    string getSpecialization() const;
    string getCertificationDate() const;
    void setSpecialization(string spec);
    void setCertificationDate(string date);

    void login() override;
    void displayInfo() const override;
};

#endif

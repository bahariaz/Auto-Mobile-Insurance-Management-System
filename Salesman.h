#ifndef SALESMAN_H
#define SALESMAN_H

#include "Person.h"

class Salesman : public Person {
private:
    string department;
    string hireDate;

public:
    Salesman();
    Salesman(string id, string name, string cnic, string phone, string email,
             string department, string hireDate);

    string getDepartment() const;
    string getHireDate() const;
    void setDepartment(string department);
    void setHireDate(string date);

    void login() override;
    void displayInfo() const override;
};

#endif

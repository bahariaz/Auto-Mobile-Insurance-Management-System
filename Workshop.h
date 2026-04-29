#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <string>
using namespace std;

class Workshop {
private:
    string workshopId;
    string name;
    string address;
    string phone;
    string ownerName;
    string registrationDate;

public:
    Workshop();
    Workshop(string workshopId, string name, string address, string phone,
             string ownerName, string registrationDate);

    string getWorkshopId() const;
    string getName() const;
    string getAddress() const;
    string getPhone() const;
    string getOwnerName() const;
    string getRegistrationDate() const;

    void setWorkshopId(string id);
    void setName(string name);
    void setAddress(string address);
    void setPhone(string phone);
    void setOwnerName(string name);
    void setRegistrationDate(string date);

    void displayInfo() const;
};

#endif

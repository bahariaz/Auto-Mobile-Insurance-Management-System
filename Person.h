#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string id;
    string name;
    string cnic;
    string phone;
    string email;

public:
    Person();
    Person(string id, string name, string cnic, string phone, string email);
    virtual ~Person() {}

    string getId() const;
    string getName() const;
    string getCnic() const;
    string getPhone() const;
    string getEmail() const;

    void setId(string id);
    void setName(string name);
    void setCnic(string cnic);
    void setPhone(string phone);
    void setEmail(string email);

    virtual void login() = 0;
    virtual void displayInfo() const;
};

#endif

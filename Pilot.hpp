#include<string>
#include<iostream>
#include "Plane.hpp"
using namespace std;

class Pilot {
private:
    string name;

public:
    // Pointer to an object of the Plane class
    shared_ptr<Plane> myPlane;

    // Constructor
    Pilot(const string& pilotN) : name(pilotN), myPlane(nullptr) {
        cout << "Pilot " << name << "created at " << this << ", at the gate, ready to board the plane." << endl;        // Output pilots name, memory address, and that they are ready to board
    }

    // Destructor
    ~Pilot() {
        cout << "Pilot " << name << " is out of the plane." << endl;                // Outputting that the pilot is off the plane
    }

    // Getter function for pilot name
    string getName() const {return name;}
};
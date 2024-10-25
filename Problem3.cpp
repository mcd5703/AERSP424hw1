#include "Problem2.hpp"
#include "Problem2.cpp"

class Plane {
private:
    // Declaring variables as private
    double pos;
    double vel;
    double dist;
    bool at_SC;
    string origin;
    string dest;    

public:
    // Constructor that takes in two strings
    Plane(string from, string to) {
        origin = from;
        dest = to;
        pos = 0.0;
        vel = 0.0;
        dist = 0.0;
        at_SC = (from == "SCE");

        // Add int flight distances to destination strings
        flightDistances["PHL"] = 160;
        flightDistances["ORD"] = 640;
        flightDistances["EWR"] = 220;

        // Use the container to set flight distances
        if (flightDistances.find(to) != flightDistances.end()) {
            dist = flightDistances[to];} 
        else {
            dist = 0.0;}} 

    // Destructor
    ~Plane() {
        cout << "Plane from " << origin << " to " << dest << " destroyed." << endl;}

    // Function that would take an input of dt and compute new position
    void operate(double dt) {
        pos += vel * dt;
        cout << "Plane operated for " << dt << " seconds. Current position: " << pos << endl;}

    // Getter functions
    double getPos() const{return pos;}
    string getOrigin() const{return origin;}
    string getDestination() const{return dest;}
    bool getAtSCE() const{return at_SC;}

    // Getter and setter functions
    double getVel() const {return vel;}
    void setVel(double newVel) {vel = newVel;}};

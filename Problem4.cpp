#include <iostream>
#include <cmath>   
#include <string>  
using namespace std;

class Plane {
private:
    string origin;
    string dest;
    double dist;
    double pos;
    double velo;
    double at_SC;

public:
    // Constructor
    Plane(const std::string& from, const std::string& to) 
        : origin(from), dest(to), pos(0), velo(0), at_SC(0) {
        dist = calculateDistance(origin, dest);
        std::cout << "Plane Created at " << this << std::endl;}

    // Destructor
    ~Plane() {
        cout << "Plane Destroyed" << endl;}

    // Getter functions
    string getOrigin() const { return origin; }
    string getDest() const { return dest; }
    double getDist() const { return dist; }
    double getPos() const { return pos; }
    double getVelo() const { return velo; }
    double getAtSC() const { return at_SC; }

    // Setter functions
    void setPos(double position) {pos = position >= 0 ? position : 0;}
    void setVelo(double velocity) {velo = velocity >= 0 ? velocity : 0;}
    void setAtSC(double timeAtSC) {at_SC = timeAtSC >= 0 ? timeAtSC : 0;}

    // Method to calculate distance between two airports
    double calculateDistance(const std::string& from, const std::string& to) {
        // Dummy implementation - replace with actual logic based on Q2
        return abs(static_cast<int>(from.length() - to.length())) * 100.0;}

    // Operate function (based on a presumed flowchart)
    void operate(double timeStep) {
        if (timeStep < 0) {
            timeStep = 0;}
        pos += velo * timeStep;
        if (pos > dist) {
            pos = dist; // Plane has reached dest
            velo = 0;} // Plane stops
        // Update other variables
        at_SC -= timeStep;
        if (at_SC < 0) {
            at_SC = 0;}}};

int main() {
    // Create a plane object
    Plane plane("LAX", "JFK");

    // Example usage of setters and operate function
    //plane.setVelo(600);  // Set velocity to 600 units (km/h or m/s depending on your unit)
    //plane.operate(5);        // Simulate 5 seconds of operation
    //cout << "Plane position after 5 seconds: " << plane.getPos() << endl;
    //return 0;}

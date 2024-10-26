#include "Problem2.hpp"

class Plane {
private:
    // Declaring variables as private
    double pos;
    double velo;
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
        velo = 0.0;
        dist = 0.0;
        at_SC = (from == "SCE");
        // Add int flight distances to destination strings
        flight_dist["PHL"] = 160;
        flight_dist["ORD"] = 640;
        flight_dist["EWR"] = 220;
        // Use the container to set flight distances
        if (flight_dist.find(to) != flight_dist.end()) {
            dist = flight_dist[to];} 
        else {
            dist = 0.0;}} 

    // Destructor
    ~Plane() {
        cout << "Plane from " << origin << " to " << dest << " destroyed." << endl;}

    // Function that would take an input of dt and compute new position
    void operate(double dt) {
        pos += velo * dt;
        cout << "Plane operated for " << dt << " seconds. Current position: " << pos << endl;}

    // Getter functions
    double getPos() const{return pos;}
    string getOrigin() const{return origin;}
    string getDest() const{return dest;}
    bool getAtSC() const{return at_SC;}

    // Getter and setter functions
    double getVel() const {return velo;}
    void setVelo(double new_Velo) {velo = new_Velo;}};
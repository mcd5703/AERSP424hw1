// Plane.hpp
#include "Problem2.hpp"
#include <iostream>
#include <string>
#include <algorithm> // For swap
using namespace std;

// Thr plane class of Problem 3 is defined here
class Plane {
private:
    string origin;
    string dest;
    double dist;
    double pos;
    double velo;
    bool at_SCE;

    // Method to calculate distance between two airports
    double calculateDistance(const string& from, const string& to) {
        if (from == "SCE") {
            if (flight_dist.find(to) != flight_dist.end()) {
                return flight_dist[to];
            } else {
                return 0.0;
            }
        } else if (to == "SCE") {
            if (flight_dist.find(from) != flight_dist.end()) {
                return flight_dist[from];
            } else {
                return 0.0;
            }
        } else {
            // No direct distance available between non-SCE airports
            return 0.0;
        }
    }

public:
    // Constructor
    Plane(const string& from, const string& to)
        : origin(from), dest(to), pos(0), velo(0), at_SCE(false) {
        dist = calculateDistance(origin, dest);
        cout << "Plane Created at " << this << endl;
    }

    // Destructor
    ~Plane() {
        cout << "Plane Destroyed" << endl;
    }

    // Getter functions
    string getOrigin() const { return origin; }
    string getDest() const { return dest; }
    double getDist() const { return dist; }
    double getPos() const { return pos; }
    double getVelo() const { return velo; }
    bool getAtSCE() const { return at_SCE; }

    // Setter functions
    void setPos(double position) { pos = position >= 0 ? position : 0; }
    void setVelo(double velocity) { velo = velocity >= 0 ? velocity : 0; }
    void setAtSCE(bool value) { at_SCE = value; }

    // Operate function
    void operate(double dt) {
        if (dt < 0) {
            dt = 0; // Time cannot be negative
        }

        if (pos < dist) {
            pos += velo * dt;
            if (pos > dist) {
                pos = dist; // Cap position at distance
            }
            at_SCE = false;
        } else {
            if (dest == "SCE") {
                at_SCE = true;
            }
            // Swap origin and destination
            swap(origin, dest);
            // Recalculate distance after swapping
            dist = calculateDistance(origin, dest);
            pos = 0;
        }
    }
};

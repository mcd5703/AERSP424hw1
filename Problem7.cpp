#include "Plane.hpp"
#include "pilot.hpp"
#include "Problem2.cpp"


int main() {
    // Flight speed, timestep, and maxIterations
    double flightSpeed = 450.0; // mph

    // Create shared_ptr to Plane
    auto plane = make_shared<Plane>("SCE", "EWR");
    plane->setVelo(flightSpeed);

    double dt = 20.0; // minutes
    int maxIterations = 1500;
    dt /= 60.0; // convert minutes to hours

    // Create two Pilot objects
    Pilot pilot1("Captain Smith");
    Pilot pilot2("First Officer Jones");

    // Assign the plane to the first pilot's myPlane
    pilot1.myPlane = plane;
    pilot2.myPlane = nullptr;

    // Pointer to current pilot
    Pilot* currentPilot = &pilot1;

    // Main loop
    for (int i = 0; i < maxIterations; ++i) {
        // Before starting an iteration, print out pilots' info
        cout << "Pilot: " << currentPilot->getName() << ", Address: " << currentPilot
        << ", Controlling Plane at: " << currentPilot->myPlane.get() << endl;

        // Operate the plane
        plane->operate(dt);

        // Print plane position
        cout << "Time step " << i << ": Plane position = " << plane->getPos() << " miles" << endl;

        // Check if plane is at SCE
        if (plane->getAtSCE()) {
            cout << "Plane at " << plane.get() << " has landed at SCE." << endl;

            // Swap control of the plane between pilots
            if (currentPilot == &pilot1) {
                // Pilot1 relinquishes control
                pilot1.myPlane = nullptr;
                // Pilot2 takes control
                pilot2.myPlane = plane;
                currentPilot = &pilot2;
                cout << "Now " << pilot2.getName() << " is controlling the plane at "
                << pilot2.myPlane.get() << endl;
            } else {
                // Pilot2 relinquishes control
                pilot2.myPlane = nullptr;
                // Pilot1 takes control
                pilot1.myPlane = plane;
                currentPilot = &pilot1;
                cout << "Now " << pilot1.getName() << " is controlling the plane at "
                << pilot1.myPlane.get() << endl;
            }
        }
    }
    return 0;
}
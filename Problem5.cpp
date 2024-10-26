#include "Plane.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Flight Speed between 400 and 500 mph
    double fspeed = 400 + (rand() % 101); // Randomly chooses between 400 and 500

    // Timestep between 10 and 100 seconds
    int tstep = 10 + (rand() % 91); // Randomly chooses between 10 and 100 seconds

    // Maximum Iterations between 1000 and 2000
    int max_iter = 1000 + (rand() % 1001); // Randomly chooses between 1000 and 2000

    // Instantiate a Plane object
    Plane plane("SCE", "PHL");
    
    // Set the speed of the plane in m/s (converted from mph)
    plane.setVelo(fspeed);

    cout << "################## QUESTION 2 ####################" << endl;
    cout << "Plane Created with a tail number at " << &plane << endl;

    // Iterate, calling the operate function
    int telapsed = 0;
    for (int i = 0; i < max_iter; i++) {
        // Print the current time and position
        cout << "Time: " << telapsed << " seconds, Position: " << plane.getPos() << " miles" << endl;

        // Operate the plane for this timestep
        plane.operate(tstep);
        
        // Check if the plane has reached the destination
        if (plane.getPos() >= plane.getDist()) {
            cout << "\nNavigation from " << plane.getOrigin() << " to " << plane.getDest()
                << " has been completed. On to the next leg!" << endl;
            break;
        }
        // Increment the time by timestep
        telapsed += tstep;
    }
    // Indicate that the plane should be destroyed
    return 0; // Destructor will be called here
}
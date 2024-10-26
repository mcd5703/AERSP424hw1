#include "Plane.hpp"
using namespace std;

// Problem 5 main function
int main() 
{
    double fspeed = 450;   // Choose Flight Speed between 400 and 500 mph
    int tstep = 50;        // Choose Timestep between 10 and 100 seconds
    int max_iter = 1010;   // Choose Maximum Iterations between 1000 and 2000
    Plane plane("SCE", "PHL");      // Instantiate a Plane object
    plane.setVel(fspeed/3600.0);    // Set the speed of the plane

    // BEGIN ITERATIONS
    int telapsed = 0;
    for (int i = 0; i < max_iter; i++) // Iterate, calling the operate function
    {
        // Print the current time and position
        cout << "Time: " << telapsed << " seconds, Position: " << plane.getPos() << " miles" << endl;
        // Check if the plane has reached the destination
        if (plane.getPos() >= plane.getDist()) 
        { 
            cout << "Navigation from " << plane.getOrigin() << " to " << plane.getDest()
                << " has been completed. On to the next leg!" << endl;
        }
        plane.operate(tstep);   // Operate the plane for this timestep
        telapsed += tstep;      // Increment the time by timestep
    }
    return 0; 
}
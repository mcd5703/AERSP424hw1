// main.cpp
#include "Plane.hpp"

int main() {
    // Create a plane object
    Plane plane("SCE", "PHL");

    // Set velocity
    plane.setVel(200); // Units per second (example value)

    // Operate the plane for a certain time
    plane.operate(1); // Operate for 1 second
    std::cout << "Position after 1 second: " << plane.getPos() << std::endl;

    // Operate until it reaches or exceeds the distance
    plane.operate(1000); // Large dt to ensure it reaches destination
    std::cout << "Position after reaching destination: " << plane.getPos() << std::endl;
    std::cout << "At SCE: " << plane.getAtSCE() << std::endl;

    // Check origin and destination after swap
    std::cout << "New Origin: " << plane.getOrigin() << std::endl;
    std::cout << "New Destination: " << plane.getDest() << std::endl;

    return 0;
}
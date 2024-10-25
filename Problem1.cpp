#include "Problem1.hpp"

// Function to Calculate Moment
double calculateMoment(double weight, double arm) {
    return weight * arm;
}

int main() {
    // Input airplane empty weight and moment
    cout << "Enter the airplane empty weight (lbs): ";
    cin >> empty_weight;
    cout << "Enter the airplane empty-weight moment (lbs-inches): ";
    cin >> empty_weight_moment;

    // Input front seat occupants and moment arm
    cout << "Enter the number of front seat occupants: ";
    cin >> num_front_occupants;
    for (int i = 0; i < num_front_occupants; ++i) {
        cout << "Enter the weight of front seat occupant " << i+1 << " (lbs): ";
        cin >> front_occupant_weights[i];
    }
    cout << "Enter the front seat moment arm (inches): ";
    cin >> front_seat_arm;

    // Input rear seat occupants and moment arm
    cout << "Enter the number of rear seat occupants: ";
    cin >> num_rear_occupants;
    for (int i = 0; i < num_rear_occupants; ++i) {
        cout << "Enter the weight of rear seat occupant " << i+1 << " (lbs): ";
        cin >> rear_occupant_weights[i];
    }
    cout << "Enter the rear seat moment arm (inches): ";
    cin >> rear_seat_arm;

    // Input fuel information
    cout << "Enter the number of gallons of usable fuel: ";
    cin >> gallons_of_fuel;
    cout << "Enter the usable fuel weight per gallon (lbs): ";
    cin >> fuel_weight_per_gallon;
    cout << "Enter the fuel tank moment arm (inches): ";
    cin >> fuel_tank_arm;

    // Input baggage weight and moment arm
    cout << "Enter the baggage weight (lbs): ";
    cin >> baggage_weight;
    cout << "Enter the baggage moment arm (inches): ";
    cin >> baggage_arm;

    // Calculate total weight and moment for front occupants
    for (int i = 0; i < num_front_occupants; ++i) {
        total_front_weight += front_occupant_weights[i];
    }
    double total_front_moment = calculateMoment(total_front_weight, front_seat_arm);

    // Calculate total weight and moment for rear occupants
    for (int i = 0; i < num_rear_occupants; ++i) {
        total_rear_weight += rear_occupant_weights[i];
    }
    double total_rear_moment = calculateMoment(total_rear_weight, rear_seat_arm);

    // Calculate total weight and moment for fuel
    double total_fuel_weight = gallons_of_fuel * fuel_weight_per_gallon;
    double total_fuel_moment = calculateMoment(total_fuel_weight, fuel_tank_arm);

    // Calculate total weight and moment for baggage
    double total_baggage_moment = calculateMoment(baggage_weight, baggage_arm);

    // Calculate total gross weight and total moment
    double gross_weight = empty_weight + total_front_weight + total_rear_weight + total_fuel_weight + baggage_weight;
    double total_moment = empty_weight_moment + total_front_moment + total_rear_moment + total_fuel_moment + total_baggage_moment;

    // Calculate Center of Gravity (CG)
    double CG = total_moment / gross_weight;

    // Display gross weight and CG
    cout << fixed << setprecision(2);
    cout << "Gross weight: " << gross_weight << " lbs" << endl;
    cout << "Center of Gravity (CG): " << CG << " inches" << endl;

    // Check if gross weight and CG are within limits
    if (gross_weight > MAX_GROSS_WEIGHT || CG < FORWARD_CG_LIMIT || CG > AFT_CG_LIMIT) {
        cout << "Error: Gross Weight and/or Center of Gravity are out of max allowable design limits!" << endl;
        
        // Adjust fuel to bring gross weight and CG within limits
        double new_gallons_of_fuel = gallons_of_fuel;
        bool success = false;
        while (new_gallons_of_fuel >= 0) 
        {
            total_fuel_weight = new_gallons_of_fuel * fuel_weight_per_gallon;
            total_fuel_moment = calculateMoment(total_fuel_weight, fuel_tank_arm);
            gross_weight = empty_weight + total_front_weight + total_rear_weight + total_fuel_weight + baggage_weight;
            total_moment = empty_weight_moment + total_front_moment + total_rear_moment + total_fuel_moment + total_baggage_moment;
            CG = total_moment / gross_weight;

            if (gross_weight <= MAX_GROSS_WEIGHT && CG >= FORWARD_CG_LIMIT && CG <= AFT_CG_LIMIT) {
                success = true;
                break;
            }

            new_gallons_of_fuel -= 0.01; // Drain fuel
            if (new_gallons_of_fuel < 0)
                new_gallons_of_fuel = 0;
        }

        if (success) {
            cout << "Adjusted fuel amount to meet limits: " << new_gallons_of_fuel << " gallons" << endl;
            cout << "New Gross weight: " << gross_weight << " lbs" << endl;
            cout << "New Center of Gravity (CG): " << CG << " inches" << endl;
        } else {
            cout << "Unable to adjust fuel to meet gross weight and CG limits." << endl;
        }
    } else {
        cout << "Gross weight and CG are within limits." << endl;
    }
    return 0;
}
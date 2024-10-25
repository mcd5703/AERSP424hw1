#include "Problem1.hpp"

// Function to Calculate Moment
double calculateMoment(double weight, double arm) {
    return weight * arm;
}

int main() {
    // Ouput and Input sequence for all necessary values
    cout << "Enter the airplane empty weight (lbs): " << endl; cin >> Empty_W;
    cout << "Enter the airplane empty-weight moment (lbs-inches): " << endl; cin >> Empty_WM;
    cout << "Enter the number of front seat occupants: " << endl; cin >> num_focc;
    for (int i = 0; i < num_focc; ++i) {
        cout << "Enter the weight of front seat occupant: " << i+1 << " (lbs): " << endl; cin >> foccw[i];}
    cout << "Enter the front seat moment arm (inches): " << endl; cin >> fr_arm;
    cout << "Enter the number of rear seat occupants: " << endl; 
    cout << "Enter the number of rear seat occupants: " << endl; cin >> num_rocc;
    for (int i = 0; i < num_rocc; ++i) {
        cout << "Enter the weight of rear seat occupant " << i+1 << " (lbs): " << endl; cin >> roccw[i];}
    cout << "Enter the rear seat moment arm (inches): " << endl; cin >> r_arm;
    cout << "Enter the number of gallons of usable fuel: " << endl; cin >> fuel_gal;
    cout << "Enter the usable fuel weight per gallon (lbs): " << endl; cin >> fuel_WPG;
    cout << "Enter the fuel tank moment arm (inches): " << endl; cin >> fuel_arm;
    cout << "Enter the baggage weight (lbs): " << endl; cin >> bag_w;
    cout << "Enter the baggage moment arm (inches): " << endl; cin >> bag_arm;

    for (int i = 0; i < num_focc; ++i) {
        tot_FW += foccw[i];}
    tot_fmom = calculateMoment(tot_FW, fr_arm);
    for (int i = 0; i < num_rocc; ++i) {
        tot_RW += roccw[i];}
    tot_rmom = calculateMoment(tot_RW, r_arm);
    tot_FW = fuel_gal * fuel_WPG;
    tot_FMom = calculateMoment(tot_FW, fuel_arm);
    tot_bagmom = calculateMoment(bag_w, bag_arm);
    gross_w = Empty_W + tot_FW + tot_RW + tot_FW + bag_w;
    tot_mom = Empty_WM + tot_fmom + tot_rmom + tot_FMom + tot_bagmom;
    CG = tot_mom / gross_w;
    // Display gross weight and CG
    cout << fixed << setprecision(2);
    cout << "Gross Weight = " << gross_w << " lbs." << endl;
    cout << "Center of Gravity = : " << CG << " in." << endl;

    // Check if gross weight and CG are within limits
    if (gross_w > Max_GW || CG < Forward_CGL || CG > Aft_CGL) {
        cout << "Error: Gross Weight and/or Center of Gravity are out of max allowable design limits!" << endl;
        // Adjust fuel to bring gross weight and CG within limits
        double new_fuelgal = fuel_gal;
        bool success = false;
        while (new_fuelgal >= 0) {
            tot_FW = new_fuelgal * fuel_WPG;
            tot_FMom = calculateMoment(tot_FW, fuel_arm);
            gross_w = Empty_W + tot_FW + tot_RW + tot_FW + bag_w;
            tot_mom = Empty_WM + tot_fmom + tot_rmom + tot_FMom + tot_bagmom;
            CG = tot_mom / gross_w;
            if (gross_w <= Max_GW && CG >= Forward_CGL && CG <= Aft_CGL) {
                success = true;
                break;}
            new_fuelgal -= 0.01; // Drain fuel to lower weight
            if (new_fuelgal < 0)
                new_fuelgal = 0;}
        if (success) {
            cout << "Adjusted fuel amount to meet design limits = " << new_fuelgal << " gal." << endl;
            cout << "New Gross Weight = " << gross_w << " lbs." << endl;
            cout << "New Center of Gravity = " << CG << " in." << endl;
        } else {
            cout << "Unable to adjust fuel to meet gross weight and CG design limits." << endl;}
    } else {
        cout << "Gross weight and CG are within design limits." << endl;}
    return 0;
}
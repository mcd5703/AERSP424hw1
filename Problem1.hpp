#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

// Declaring variables for calculations
double empty_weight, empty_weight_moment;
int num_front_occupants;
int num_rear_occupants;
double front_seat_arm, rear_seat_arm;
double fuel_weight_per_gallon, fuel_tank_arm;
double baggage_weight, baggage_arm;
double gallons_of_fuel;

// Declaring max allowed design limits
const double MAX_GROSS_WEIGHT = 2950.0;
const double FORWARD_CG_LIMIT = 82.1;
const double AFT_CG_LIMIT = 84.7;

vector<double> front_occupant_weights(num_front_occupants);
vector<double> rear_occupant_weights(num_rear_occupants);
double total_front_weight = 0.0;
double total_rear_weight = 0.0;

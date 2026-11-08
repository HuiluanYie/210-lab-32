// COMSC-210 | Lab 33 | Huiluan Yie
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;
const int P = 55;

const int NUM_LANES = 4;

// Function prototype
void display_cars(const deque < Car > & );
void display_lanes(deque < Car > [], int);
void simu(deque < Car > & );

int main() {
    srand(time(0));

    deque < Car > cars;
    Car c;
    int time = 0;

    // Create the array
    deque<Car> lanes[NUM_LANES];

    // Tests operations
    // another car joins the queue
    lanes[0].push_back(Car());
    display_lanes(lanes, NUM_LANES);

    // car pays its toll and leaves

    // rear car shift lanes

    




/*
    // initialize cars
    for (int i = 0; i < INITIAL_SIZE; i++) {
        c = Car();
        cars.push_back(c);
    }
    cout << "Initial queue:\n";
    display_cars(cars);

    // Run the simulation
    while (!cars.empty()) {
        time++;
        cout << "\nTime: " << time;
        simu(cars);

        cout << "Queue:\n";
        display_cars(cars);
    }
*/

    return 0;
}

// Function definition
void display_cars(const deque < Car > & cars) {
    // display_cars() displays every car in the deque.
    // arguments: a deque of Cars object
    // returns: none
    if (cars.empty()) {
        cout << "\tEmpty\n";
    }

    for (Car c: cars) {
        cout << '\t';
        c.print();
    }
}

void display_lanes(deque < Car > lanes[], int l)
{
    // display_lanes() displays all lanes.
    // arguments: an array of lanes and number of lanes
    // returns: none

    for (int i = 0; i < l; i++)
    {
        cout
        for (Car& car : lanes[i])
        {
            cout << '\t';
            car.print();
        }
    }
    
}

void simu(deque < Car > & cars) {
    // simu() runs a simulation of 1 operation occuring
    // arguments: a deque of Cars object
    // returns: none
    int p = rand() % 100;

    cout << " Operation: ";
    if (p < P) {
        cout << "Car paid: ";
        cars.front().print();
        cars.pop_front();
    } else {
        cout << "Joined lane: ";
        cars.push_back(Car());
        cars.back().print();
    }
}
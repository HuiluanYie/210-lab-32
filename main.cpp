// COMSC-210 | Lab 33 | Huiluan Yie
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;
const int P = 50,
    P1 = 46,
    P2 = 39,
    M = 100;
const int NUM_LANES = 4;
const int PERIOD = 20;

// Function prototype
void display_cars(const deque < Car > & );
void display_lanes(deque < Car > [], int);
void simu1(deque < Car > & , deque < Car > [], int);
void simu2(deque < Car > & );

int main() {
    srand(time(0));
    Car c;

    // Create the array
    deque < Car > lanes[NUM_LANES];

    // initialize cars
    for (int j = 0; j < NUM_LANES; j++) {
        for (int i = 0; i < INITIAL_SIZE; i++) {
            c = Car();
            lanes[j].push_back(c);
        }
    }
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << ":\n";
        display_cars(lanes[i]);
    }
    cout << endl;

    // Run the simulation
    for (int t = 0; t < PERIOD; t++) {
        cout << "\nTime: " << t + 1 << endl;
        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane: " << i + 1;
            if (lanes[i].empty()) {
                simu2(lanes[i]);
            } else {
                simu1(lanes[i], lanes, i);
            }
        }
        display_lanes(lanes, NUM_LANES);
    }

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

void display_lanes(deque < Car > lanes[], int l) {
    // display_lanes() displays all lanes.
    // arguments: an array of lanes and number of lanes
    // returns: none
    for (int i = 0; i < l; i++) {
        cout << "Lane " << i + 1 << " Queue:\n";
        display_cars(lanes[i]);
    }
    cout << endl;
}

void simu1(deque < Car > & cars, deque < Car > lanes[], int i) {
    // simu1() runs a simulation of three possible operations
    // arguments: a deque of Cars object and the array of car lane
    // returns: none
    int p = rand() % M;

    if (p < P1) {
        cout << " Paid: ";
        cars.front().print();
        cars.pop_front();
    } else if (p < P2 + P1) {
        cout << " Joined: ";
        cars.push_back(Car());
        cars.back().print();
    } else {
        int l;
        do {
            l = rand() % NUM_LANES;
        } while (l == i);

        cout << " Switched: ";
        Car c = cars.back();
        c.print();
        cars.pop_back();
        lanes[l].push_back(c);
    }
}

void simu2(deque < Car > & cars) {
    // simu2() runs a simulation of 50/50 of the car joining the deque
    // arguments: a deque of Cars object
    // returns: none
    int p = rand() % M;

    if (p < P) {
        cout << " Joined: ";
        cars.push_back(Car());
        cars.back().print();
    } else cout << endl;
}
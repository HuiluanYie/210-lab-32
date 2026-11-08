// COMSC-210 | Lab 33 | Huiluan Yie
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;
const int P = 50, P1 = 46, P2 = 39, M = 100;
const int NUM_LANES = 4;
const int PERIOD = 20;

// Function prototype
void display_cars(const deque < Car > & );
void display_lanes(deque < Car > [], int);
void simu1(deque < Car > &, deque < Car > []);
void simu2(deque < Car > & );

int main() {
    srand(time(0));

    Car c;
    int time = 0;

    // Create the array
    deque<Car> lanes[NUM_LANES];

    /*
    lanes[0].push_back(Car());
    // Tests operations
    // another car joins the queue
    lanes[0].push_back(Car());
    display_lanes(lanes, NUM_LANES);

    // car pays its toll and leaves
    cout << "paid: ";
    lanes[0].front().print();
    lanes[0].pop_front();
    display_lanes(lanes, NUM_LANES);

    // rear car shift lanes
    Car mcar = lanes[0].back();
    lanes[0].pop_back();
    lanes[2].push_back(mcar);
    display_lanes(lanes, NUM_LANES);
    */

    // initialize cars
    for (int j = 0; j < NUM_LANES; j++)
    {
        for (int i = 0; i < INITIAL_SIZE; i++) 
        {
            c = Car();
            lanes[j].push_back(c);
        }
    }
    cout << "Initial queue:\n";
    display_lanes(lanes, NUM_LANES);

    /*
    // 50/50 loop
    for (int t = 0; t < PERIOD; t++)
    {
        cout << "\nTime: " << t + 1 << endl;
        for (int l = 0; l < NUM_LANES; l++)
        {
            cout << "Lane: " << l + 1;
            simu2(lanes[l]);
        }
        display_lanes(lanes, NUM_LANES);
    }
    */

    for (int t = 0; t < PERIOD; t++)
    {
        cout << "\nTime: " << t + 1 << endl;
        for (int i = 0; i < NUM_LANES; i++)
        {
            cout << "Lane: " << i + 1;
            deque < Car > l = lanes[i];
            if (l.empty())
            {
                simu2(l);
            }
            else
            {
                simu1(l, lanes);
            }
            
        }
        display_lanes(lanes, NUM_LANES);
    }

    /*
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
        cout << "Lane " << i + 1 << ":\n";
        display_cars(lanes[i]);
    }
    cout << endl;
}


void simu1(deque < Car > & cars, deque < Car > lanes[]) {
    // simu1() runs a simulation of three possible operations
    // arguments: a deque of Cars object and the array of car lane
    // returns: none
    int p = rand() % M;
    int l = rand() % NUM_LANES;

    if (p < P1) {
        cout << " Paid: ";
        cars.front().print();
        cars.pop_front();
    } 
    else if (p < P2) {
        cout << " Joined: ";
        cars.push_back(Car());
        cars.back().print();
    }
    else 
    {
        Car c = cars.back();
        cars.pop_back();
        lanes[l].push_back(c);
        display_lanes(lanes, NUM_LANES);
    }
}

void simu2(deque < Car > & cars) {
    // simu2() runs a simulation of 50/50 of the car paying/leaving (when empty, nothing happen)
    //                               and of the car joining the deque
    // arguments: a deque of Cars object
    // returns: none
    int p = rand() % M;

    if (p < P) {
        if (!cars.empty())
        {
            cout << " Paid: ";
            cars.front().print();
            cars.pop_front();
        }
        else cout << endl;
    } else {
        cout << " Joined: ";
        cars.push_back(Car());
        cars.back().print();
    }
}
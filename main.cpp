// COMSC-210 | Lab 28 | Huiluan Yie

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;
const int P;

// Function prototype
void display_cars(const deque<Car>&);
void simu(deque<Car>&);

int main() 
{
    deque<Car> cars;
    Car c;
    int time = 0;

    // initialize cars
    for (int i = 0; i < INITIAL_SIZE; i++)
    {
        c = Car();
        cars.push_back(c);
    }
    cout << "Initial queue:\n";
    display_cars(cars);

    // Run the simulation
    while (!cars.empty())
    {
        time++;
        int p = rand() % 100 + 1;
        
    }
    

    return 0;
}

// Function definition
void display_cars(const deque<Car>& cars)
{
    // display_cars() displays every car in the deque.
    // arguments: a deque of Cars object
    // returns: none
    for (Car c : cars)
    {
        cout << '\t';
        c.print();
    }
}

void simu(deque<Car>&)
{
    
}
// COMSC-210 | Lab 28 | Huiluan Yie

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;

// Function prototype
void display_cars(const deque<Car>&);

int main() 
{
    deque<Car> cars;
    Car c;
    for (int i = 0; i < INITIAL_SIZE; i++)
    {
        c = Car();
        cars.push_back(c);
    }
    cout << "Initial queue:\n";
    display_cars(cars);

    //exercise deque methods
    cars.front().print();
    cars.back().print();
    cars[0].print();
    cars.pop_front();
    display_cars(cars);
    cars.pop_back();
    display_cars(cars);
    cout << cars.size();

    return 0;
}

// Function definition
void display_cars(const deque<Car>& cars)
{

    for (Car c : cars)
    {
        cout << '\t';
        c.print();
    }
}
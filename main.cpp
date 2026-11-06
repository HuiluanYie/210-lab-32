// COMSC-210 | Lab 28 | Huiluan Yie

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

const int INITIAL_SIZE = 2;

int main() 
{
    deque<Car> cars;
    Car c;
    for (int i = 0; i < INITIAL_SIZE; i++)
    {
        c = Car();
        cars.push_back(c);
    }

    return 1;
}
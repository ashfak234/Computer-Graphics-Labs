#include <iostream>
#include "Car.hpp"

int main()
{
    //// Define car object
    //Car delorean;
    //delorean.make = "Delorean";
    //delorean.model = "DMC-12";
    //delorean.year = 1981;

    Car delorean("DeLorean", "DMC-12", 1981);
    std::cout << "\nClasses\n-------" << std::endl; // "Classes: "
    delorean.outputDetails();

    // Accelerate the Delorean up to 88 mph
    delorean.accelerate(88.0f);

    // Convert speed from mph to kph
    std::cout << "\n" << 88 << " mph is equivalent to " << Car::mph2kph(88.0f) << " kph." << std::endl;

    return 0; 
} 

#include <iostream>

class Car {
public:
    std::string make;
    std::string model;
    int year;
    float speed = 0.0f;
    // Methods
    void outputDetails();
    void accelerate(const float);

    // Constructor
    Car();
    Car(const std::string, const std::string, const int);

    static float mph2kph(const float);
};


Car::Car()
{
    std::cout << "\nCar object created" << std::endl;
}

Car::Car(const std::string makeInput, const std::string modelInput, const int yearInput)
{
    make = makeInput;
    model = modelInput;
    year = yearInput;
    std::cout << "\nCar object created" << std::endl;
}

float Car::mph2kph(const float speed)
{
    return speed * 1.60934f;
}

void Car::outputDetails()
{
    std::cout << "\nMake: " << make
        << "\nModel: " << model
        << "\nYear: " << year << std::endl;
}

void Car::accelerate(const float increment)
{
    speed = +increment;
    std::cout << "\nThe car has accelerated to " << speed << " mph." << std::endl;
}

int main()
{
    std::cout << "hello world\n" << std::endl;


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
//Morgan Frans
//CIS.1202.501
//Assignment 14
//04/21/2024
//Submitted 

//Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
    //private members
protected:
    std::string manufacturer;
    int yearBuilt;
    //public members
public:
    Vehicle(const std::string& manufacturer, int yearBuilt);
    const std::string& getManufacturer() const;
    int getYearBuilt() const;
    void setManufacturer(const std::string& manufacturer);
    void setYearBuilt(int yearBuilt);
    virtual void displayInfo() const;
};//end Vehicle class

#endif

//Vehicle.cpp
#include "Vehicle.h"

//Vehicle constructor
Vehicle::Vehicle(const std::string & manufacturer, int yearBuilt)
    : manufacturer(manufacturer), yearBuilt(yearBuilt) {}

//getters and setters
const std::string& Vehicle::getManufacturer() const {
    return manufacturer;
}//end getManufacturer

int Vehicle::getYearBuilt() const {
    return yearBuilt;
}//end getYearBuilt

void Vehicle::setManufacturer(const std::string & manufacturer) {
    this->manufacturer = manufacturer;
}//end setManufacturer

void Vehicle::setYearBuilt(int yearBuilt) {
    this->yearBuilt = yearBuilt;
}//end setYearBuilt

//method to display Vehicle info
void Vehicle::displayInfo() const {
    std::cout << "Manufacturer: " << manufacturer << ", Year: " << yearBuilt;
}//end displayInfo

//Car.h
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
    //private members
private:
    int numDoors;
    //public members
public:
    Car(const std::string& manufacturer, int yearBuilt, int numDoors);
    int getNumDoors() const;
    void setNumDoors(int numDoors);
    void displayInfo() const override;
};//end Car class

#endif

//Car.cpp
#include "Car.h"

//Car constructor
Car::Car(const std::string & manufacturer, int yearBuilt, int numDoors)
    : Vehicle(manufacturer, yearBuilt), numDoors(numDoors) {}

//getters and setters
int Car::getNumDoors() const {
    return numDoors;
}//end getNumDoors

void Car::setNumDoors(int numDoors) {
    this->numDoors = numDoors;
}//end setNumDoors

//method to display Car info
void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << ", Doors: " << numDoors << std::endl;
}//end displayInfo

//Truck.h
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

//Truck class
class Truck : public Vehicle {
    //private members
private:
    int towingCapacity;
    //public members
public:
    Truck(const std::string& manufacturer, int yearBuilt, int towingCapacity);
    int getTowingCapacity() const;
    void setTowingCapacity(int towingCapacity);
    void displayInfo() const override;
};//end Truck class

#endif

//Truck.cpp
#include "Truck.h"

//Truck constructor
Truck::Truck(const std::string & manufacturer, int yearBuilt, int towingCapacity)
    : Vehicle(manufacturer, yearBuilt), towingCapacity(towingCapacity) {}

int Truck::getTowingCapacity() const {
    return towingCapacity;
}//end getTowingCapacity

void Truck::setTowingCapacity(int towingCapacity) {
    this->towingCapacity = towingCapacity;
}//end setTowingCapacity

//method to display Truck info
void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << ", Towing Capacity: " << towingCapacity << std::endl;
}//end displayInfo

//main.cpp
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

//main function
int main() {
    //declare variables
    std::string manufacturer;
    int yearBuilt, numDoors, towingCapacity;

    //gather input for Vehicle
    std::cout << "Enter Vehicle manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter year built: ";
    std::cin >> yearBuilt;
    Vehicle vehicle(manufacturer, yearBuilt);
    std::cout << "Vehicle Info: ";
    vehicle.displayInfo();

    //gather input for Car
    std::cout << "\nEnter Car manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter year built: ";
    std::cin >> yearBuilt;
    std::cout << "Enter number of doors: ";
    std::cin >> numDoors;
    Car car(manufacturer, yearBuilt, numDoors);
    std::cout << "Car Info: ";
    car.displayInfo();

    //gather input for Truck
    std::cout << "\nEnter Truck manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter year built: ";
    std::cin >> yearBuilt;
    std::cout << "Enter towing capacity: ";
    std::cin >> towingCapacity;
    Truck truck(manufacturer, yearBuilt, towingCapacity);
    std::cout << "Truck Info: ";
    truck.displayInfo();

    //reset return value
    return 0;
}//end main
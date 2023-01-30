// Oviya Seeniraj 3400652
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;
// #include .......

Car::Car()
{
    this->manufacturer = NULL;
    this->model = NULL;
    this->zeroToSixtyNs = 0;
    this->headonDragCoeff = 0;
    this->horsepower = 0;
    this->backseatDoors = None;
    this->seatCount = 0;
}

Car::Car(char const *const manufacturerName, char const *const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign)
{
    manufacturer = new char[strlen(manufacturerName) + 1];
    strcpy(manufacturer, manufacturerName);

    model = new char[strlen(modelName) + 1];
    strcpy(model, modelName);

    this->seatCount = numSeats;
    this->backseatDoors = backseatDoorDesign;
    this->zeroToSixtyNs = perf.zeroToSixtyNs;
    this->headonDragCoeff = perf.headonDragCoeff;
    this->horsepower = perf.horsepower;
}

Car::Car(Car const &o)
{
    manufacturer = new char[strlen(o.getManufacturer()) + 1];
    strcpy(manufacturer, o.getManufacturer());

    model = new char[strlen(o.getModel()) + 1];
    strcpy(model, o.getModel());

    this->seatCount = o.seatCount;
    this->backseatDoors = o.backseatDoors;
    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
}

Car::~Car()
{
    delete[] this->manufacturer;
    delete[] this->model;
}

Car &Car::operator=(Car const &o)
{
    this->manufacturer = o.manufacturer;
    this->model = o.model;
    this->seatCount = o.seatCount;
    this->backseatDoors = o.backseatDoors;
    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
}

char const *Car::getManufacturer() const
{
    return this->manufacturer;
}

char const *Car::getModel() const
{
    return this->model;
}

PerformanceStats Car::getStats() const
{
    return PerformanceStats(this->horsepower, this->zeroToSixtyNs, this->headonDragCoeff);
}

uint8_t Car::getSeatCount() const
{
    return this->seatCount;
}

DoorKind Car::getBackseatDoors() const
{
    return this->backseatDoors;
}

void Car::manufacturerChange(char const *const newManufacturer)
{
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
}

void Car::modelNameChange(char const *const newModelName)
{
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats)
{
    this->zeroToSixtyNs = newStats.zeroToSixtyNs;
    this->headonDragCoeff = newStats.headonDragCoeff;
    this->horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount)
{
    this->seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind)
{
    this->backseatDoors = newDoorKind;
}

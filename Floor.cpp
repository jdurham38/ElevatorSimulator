// File: Floor.cpp
// Author: Josh
// Date: 08/10/2023
// Description: 
#include "Floor.h"

Floor::Floor(int number, int totalFloors) : floorNumber(number), hasRequest(false), totalFloors(totalFloors) {}

int Floor::getFloorNumber() const {
    return floorNumber;
}

bool Floor::hasRequestPending() const {
    return hasRequest;
}

void Floor::addRequest() {
    hasRequest = true;
}

void Floor::clearRequest() {
    hasRequest = false;
}

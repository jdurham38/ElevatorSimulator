// File: Elevator.cpp
// Author: Josh
// Date: 08/10/2023
// Description: 
//_________________________________________________________________________________________________________________



#include "Elevator.h"
#include <iostream>

Elevator::Elevator(Floor* floorsArray, int totalFloors)
    : currentFloor(1), direction(0), floors(floorsArray), totalFloors(totalFloors) {
    // Initialize the array of floors
    // No need to assign values here, the array is already initialized with the Floor instances
}


void Elevator::addRequest(int floor) {
    requests.insertAny(floor);

    // Adjust direction if needed
    if (floor > currentFloor) {
        direction = 1;  // Going up
    } else if (floor < currentFloor) {
        direction = -1; // Going down
    }
}

void Elevator::move() {
    if (direction == 0) {
        return;  // Elevator is idle
    }

    currentFloor += direction;

    // Check if a request is completed
    if (floors[currentFloor - 1].hasRequestPending()) {
        floors[currentFloor - 1].clearRequest();
    }

    // Change direction if needed
    if (requests.isEmpty()) {
        direction = 0;  // Elevator becomes idle
    } else if (currentFloor == 1) {
        direction = 1;  // Start going up
    } else if (currentFloor == totalFloors) { // Use totalFloors here
        direction = -1; // Start going down
    }
}

void Elevator::displayStatus() {
    std::cout << "Current Floor: " << currentFloor << " | Direction: ";
    if (direction == -1) {
        std::cout << "Down";
    } else if (direction == 1) {
        std::cout << "Up";
    } else {
        std::cout << "Idle";
    }
    std::cout << std::endl;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

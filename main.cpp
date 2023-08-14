#include <iostream>
#include <vector>
#include <cstdlib>  // Include this for rand() function
#include "Elevator.h"
#include "Floor.h"

int main() {
    const int numFloors = 5;  // Change this to the number of floors in your simulation
    
    // Create a vector of Floor instances
    std::vector<Floor> floors;
    for (int i = 0; i < numFloors; ++i) {
        floors.push_back(Floor(i + 1, numFloors)); // Floor numbers are 1-based
    }
    
    Elevator elevator(floors.data(), numFloors); // Pass the pointer to the first element
    
    // Simulate elevator behavior
    for (int i = 0; i < numFloors; ++i) {
        int randomFloor = rand() % numFloors + 1;  // Random floor for someone to get on
        
        if (randomFloor != elevator.getCurrentFloor()) {
            elevator.addRequest(randomFloor);
        }
        
        while (elevator.getCurrentFloor() != randomFloor) {
            elevator.move();
            elevator.displayStatus();
        }
        
        floors[randomFloor - 1].addRequest();
        elevator.move();
        elevator.displayStatus();
        
        int userExitFloor;
        std::cout << "Enter the floor you want to get off on: " << std::flush;
        std::cin.ignore(); // Clear input buffer
        std::cin >> userExitFloor;
        
        while (elevator.getCurrentFloor() != userExitFloor) {
            elevator.move();
            elevator.displayStatus();
        }
        
        floors[userExitFloor - 1].clearRequest();
        elevator.move();
        elevator.displayStatus();
    }

    return 0;
}

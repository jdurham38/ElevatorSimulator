// File: Floor.h
// Author: Josh
// Date: 08/10/2023
// Description: 

#ifndef FLOOR_H
#define FLOOR_H

class Floor {
private:
    int floorNumber;
    bool hasRequest;
    int totalFloors; // Add totalFloors as a member

public:
    Floor(int number, int totalFloors); // Update constructor declaration
    int getFloorNumber() const;
    bool hasRequestPending() const;
    void addRequest();
    void clearRequest();
};

#endif // FLOOR_H

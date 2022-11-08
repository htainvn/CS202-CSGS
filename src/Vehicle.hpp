//
//  Vehicle.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "src/ResourceManager.hpp"

class Vehicle {
private:
    sf::Sprite sprite;
    int position_x = 0;
public:
    Vehicle() = default;
    Vehicle(ResourceManager& resource_manager) {}
    void go_to_position(int x) {}
};

class Log : public Vehicle {
private:
    
public:
    Log(ResourceManager& resource_manager) {}
    void go_to_position(int x) {}
};

#endif /* Vehicle_hpp */

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
    int position_x = 0;
    int velocity; // speed
    std::string get_car_texture(int dir, int index);
public:
    sf::Sprite sprite;
    Vehicle() = default;
    Vehicle(ResourceManager& resource_manager, int dir, int speed, int y); 
    void go_to_position(int x, int y = 0);
    int see_velocity();
};

class Log : public Vehicle {
private:
    
public:
    Log(ResourceManager& resource_manager) {}
    void go_to_position(int x) {}
};

#endif /* Vehicle_hpp */

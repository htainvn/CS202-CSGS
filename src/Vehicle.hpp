//
//  Vehicle.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "src/definition_library.hpp"
#include "src/Position.hpp"
#include "src/Handler.hpp"

class Vehicle {
    
public:
/* CONSTRUCTORS & DESTRUCTORS */
    
    Vehicle() = default;
    
    Vehicle(handler_ptr _tools) : tools(_tools) {}
    
    Vehicle(handler_ptr _tools, int dir, int speed, int y);
    
    ~Vehicle() {}
    
/* END HERE */
    
/* BEHAVIOUR */
    
    void locate_at(float x, float y = 0);
    
    int get_speed();
    
    void draw();
    
    Position position();
    
/* END HERE */
    
    Sprite sprite;
    
private:
    
    handler_ptr tools;
    
    int speed = 0;
    
    
private:
    
    std::string get_car_texture(const int dir, const int index);
    
};

#endif /* Vehicle_hpp */

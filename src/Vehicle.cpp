//
//  Vehicle.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 06/11/2022.
//

#include <string.h>
#include <time.h>
#include "Vehicle.hpp"

const int car_number = 9;
const int MAX_SPEED = 36; // maximum speed


Vehicle::Vehicle(Handler *_tools, int dir, int speed, int x) {
    tools = _tools;
    
    this->speed = speed;
    
    sprite.setTexture(tools->resource_manager.get_texture(get_car_texture(dir, rand() % car_number)));
    
    locate_at(x, 0);
}

void Vehicle::locate_at(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
    
}

Position Vehicle::position()
{
    return Position(sprite.getPosition().x, sprite.getPosition().y);
}

int Vehicle::get_speed() {
    return speed * (!redlight) * ( 1 - yellowlight * 0.7 );
}

std::string Vehicle::get_car_texture(const int dir, const int index) { 
    std::string res = "";
    res = res + "C" + ((!dir) ? "L" : "R") + "_" + char(48 + index);
    return res;
}

void Vehicle::draw() { 
    tools->window.draw(sprite);
}

void Vehicle::traffic_light(int light) { // 0 green 1 yellow 2 red
    if (light == 0) {
        redlight = yellowlight = false;
        return;
    }
    if (light == 1) {
        yellowlight = true;
        return;
    }
    if (light == 2) {
        redlight = true;
        return;
    }
}

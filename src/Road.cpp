//
//  Road.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Road.hpp"
#include <string>
#include <algorithm>


Road::Road(handler_ptr _tools, int another_dir, int &changed_type, Position pos) : Lane(_tools, pos) {
    
    this->change_status(1, (this->dir = rand() % 2), this->dir == another_dir ? 1 : 2);
    
    changed_type = this->bottom_type;
    
    spawn();
    
}

void Road::change_status(int _position, int _dir, int _bottom, int _top) {
    
    ((_position != -1) && (position = _position));
    
    ((_dir != -1) && (dir = _dir));
    
    ((_bottom != -1) && (bottom_type = _bottom));
    
    ((_top != -1) && (top_type = _top));
    
    reset_texture();
    
    spawn();
    
}

void Road::reset_texture() {
    
    Lane::change_image(tools->resource_manager.get_texture(get_texture_code()));
    
}

void Road::spawn() { 
    
    const int MAX_SPEED = 300;
    
    if (vehicles.size() == CAR_PER_LANE) return;
    
    if (vehicles.empty())
    {
        int speed = rand() % (MAX_SPEED * 3 / 2) - MAX_SPEED;
        
        std::vector<int> rand_position;
        
        while (true)
        {
            int index = rand() % 10;
            
            if (std::find(rand_position.begin(), rand_position.end(), index) == rand_position.end())
            {
                rand_position.push_back(index);
            }
            
            if (rand_position.size() == CAR_PER_LANE) break;
        }
        
        sort(rand_position.begin(), rand_position.end(), [&](float a, float b) {
            
            return (!dir) ? (a < b) : (a > b);
            
        });
        
        for (int i = 0; i <= 2; ++i)
        {
            Vehicle* new_vehicle = new Vehicle(tools, dir, speed, rand_position[i] * 100);
            
            new_vehicle->locate_at(new_vehicle->sprite.getPosition().x, Lane::position().get_y() + 25);
            
            vehicles.push_back(new_vehicle);
        }
            
    }
    
    else if (vehicles.size() < CAR_PER_LANE)
    {
        Vehicle* new_vehicle = new Vehicle(tools, dir, vehicles[0]->get_speed(), -100);
        
        new_vehicle->locate_at(new_vehicle->sprite.getPosition().x, Lane::position().get_y() + 25);
        
        vehicles.push_back(new_vehicle);
    }
    
}

std::string Road::get_texture_code() {
    
    std::string res = "ROAD_";
    
    res += ((this->dir == 0) ? "LEFT_" : "RIGHT_");
    
    std::string typedash[9] = {"NOLINE", "TOPDASH", "NODASH", "BOTTOMDASH", "FULLDASH", "BOTTOMDASH", "NODASH", "TOPDASH", "NODASH"};
    
    std::string typepos[3] = {"_BOTTOM", "_NORMAL", "_TOP"};
    
    return (res = res + typedash[bottom_type * 3 + top_type] + ((bottom_type | top_type) ? typepos[position] : ""));
}

void Road::adjust_objects() {
    
    Lane::adjust_objects();
    
    for (auto& each: vehicles)
    {
        
        each->locate_at(each->position().get_x(), Lane::position().get_y() + 25);

    }
    
}

void Road::draw() {
    
    Lane::draw();
    
    for (auto& each : vehicles)
    {
        each->draw();
    }
    
}

Road::Road(handler_ptr _tools) : Lane(_tools)
{
    this->dir = rand() % 2;
    Lane::change_image(_tools->resource_manager.get_texture(get_texture_code()));
    
    spawn();
    
}

Road::Road(handler_ptr _tools, int _position, int _dir, int _bottom, int _top, Position pos) : Lane(_tools, pos), position(_position), dir(_dir), bottom_type(_bottom), top_type(_top)
{
    this->dir = rand() % 2;
    Lane::change_image(_tools->resource_manager.get_texture(get_texture_code()));
    
    spawn();
}

void Road::stop() {
    
}

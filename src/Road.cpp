//
//  Road.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Road.hpp"
#include <string>
#include <algorithm>


Road::Road(handler_ptr _tools, int another_dir, int& changed_type, Level level, Position pos) : Lane(_tools,  pos, level) {

    Lane::set_level(level);

    this->dir = rand() % 2;
    
    this->change_status(1, this->dir, this->dir == another_dir ? 1 : 2);
    
    changed_type = this->bottom_type;
    
    set_maxcar();

    spawn();
    
}

void Road::set_maxcar() {

    int used = (lev.lev() + 2) / 3;
    used -= lev.road_remain();

    if (lev.lev() <= 3) {
        max_car = lev.lev();
        return;
    }

    if ((lev.road_remain() == 2 && lev.lev() - used * 3 <= 4) || (lev.road_remain() == 1 && lev.lev() - used * 3 <= 2) ) {
        max_car = 2;
        return;
    }
    
    max_car = 3;
}

void Road::change_status(int _position, int _dir, int _bottom, int _top) {
    
    ((_position != -1) && (position = _position));
    
    ((_dir != -1) && (dir = _dir));
    
    ((_bottom != -1) && (bottom_type = _bottom));
    
    ((_top != -1) && (top_type = _top));
    
    reset_texture();
    
}

void Road::reset_texture()
{
    
    Lane::change_image(tools->resource_manager.get_texture(get_texture_code()));
    
}

void Road::spawn()
{
    
    const int MAX_SPEED = 500;
    
    if (vehicles.size() == max_car) return;
    
    if (vehicles.empty() )
    {
        int speed = rand() % MAX_SPEED + 100;

        speed *= dir * 2 - 1;

        if (max_car == 1)
        {
            Vehicle* new_vehicle = new Vehicle(tools, dir, speed, -100 + (!dir) * 1100);

            new_vehicle->locate_at(new_vehicle->sprite.getPosition().x, Lane::position().get_y() + 25);

            vehicles.push_back(new_vehicle);
            /*
            for (int i = 0; i < vehicles.size(); i++) {
                for (int j = i+1; j < vehicles.size(); j++) {
                    if (abs(vehicles[i]->position().get_x() - vehicles[j]->position().get_x()) <= 100) {
                        std::cout << "\nProblems 1!!!!!!!!!!!!!!!!!!!\n" << i << " " << j;
                        
                        return;
                    }
                }
            }
            */
            return;
        }

        std::vector<int> rand_position;
        
        while (true)
        {
            int index = rand() % 10;
            
            /*if (std::find(rand_position.begin(), rand_position.end(), index) == rand_position.end())
            {
                rand_position.push_back(index);
            }*/

            bool check = true;
            
            for (int i = 0; i < rand_position.size(); ++i) 
                if( (rand_position[i] == index) || (rand_position[i] + 1 == index) || (rand_position[i] - 1 == index) ) check = false;
            
            if (check)
            {
                rand_position.push_back(index);
            }

            if (rand_position.size() == max_car) break;
        }
        
        sort(rand_position.begin(), rand_position.end(), [&](int a, int b) {
            
            return (!dir) ? (a < b) : (a > b);
            
        });
        
        for (int i = 0; i < max_car; ++i)
        {
            Vehicle* new_vehicle = new Vehicle(tools, dir, speed, rand_position[i] * 100);
            
            new_vehicle->locate_at(new_vehicle->sprite.getPosition().x, Lane::position().get_y() + 25);
            
            vehicles.push_back(new_vehicle);
        }
        
        return;
    }
    
    if (vehicles.size() < max_car)
    {
        
        Vehicle* new_vehicle = new Vehicle(tools, dir, vehicles[0]->get_speed(), -100 + (!dir)*1100);
        
        new_vehicle->locate_at(new_vehicle->sprite.getPosition().x, Lane::position().get_y() + 25);
        
        vehicles.push_back(new_vehicle);
        
        return;
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
        
        each->locate_at(each->position().get_x() + each->get_speed() * FRAME_RATE_SECOND, Lane::position().get_y() + 25);
    }
    
    // Deallocate
    if (!vehicles.empty())
    {
        if (!dir && vehicles[0]->position().get_x() < -100)
        {
            // std::cout << "Left" << '\n';
            delete vehicles[0];
            vehicles.erase(vehicles.begin());
            spawn();
            return;
        }
        if (dir && vehicles[0]->position().get_x() > 1000)
        {
            // std::cout << "Right" << '\n';
            delete vehicles[0];
            vehicles.erase(vehicles.begin());
            spawn();
            return;
        }
    }
    
}

void Road::draw() {
    
    Lane::draw();
    
    for (auto& each : vehicles)
    {
        each->draw();
    }
    
}

Road::Road(handler_ptr _tools, Level level) : Lane(_tools, level )
{
    Lane::set_level(level);
    
    this->dir = rand() % 2;
    
    Lane::change_image(_tools->resource_manager.get_texture(get_texture_code()));
    
    set_maxcar();
    
    spawn();
    
}

Road::Road(handler_ptr _tools, int _position, int _dir, int _bottom, int _top, Level level, Position pos) : Lane(_tools, pos, level), position(_position), dir(_dir), bottom_type(_bottom), top_type(_top)
{
    Lane::set_level(level);

    this->dir = rand() % 2;
    
    Lane::change_image(_tools->resource_manager.get_texture(get_texture_code()));
    
    set_maxcar();
    
    spawn();
}

void Road::stop() {
    
}

bool Road::check_lost() {
    Position people_pos = people_position(), veh_pos;;
    for(int i=0; i<vehicles.size(); i++){
        veh_pos = vehicles[i]->position();
        if(veh_pos.get_x() + 100 <= people_pos.get_x()+142 && veh_pos.get_x() + 100 >= people_pos.get_x())
            return true;
    }
    return false;
}

Road::~Road() {
    while (!vehicles.empty()) {
        if (vehicles[0]) {
            delete vehicles[0];
            vehicles[0] = nullptr;
        }
        vehicles.erase(vehicles.begin());
    }
    max_car = 0;
}

void Road::traffic_light(int light) { // 0 green 1 yellow 2 red
    for (auto& each : vehicles) each->traffic_light(light);
}
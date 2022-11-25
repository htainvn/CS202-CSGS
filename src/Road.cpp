//
//  Road.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Road.hpp"
#include <string>
#include <algorithm>

/*

int Road::get_lane_type() {
    return ROAD_TYPE;
}

std::string Road::get_texture_code() {
    //td::cout << this->position << " " << this->dir << " " << this->bottom_type << " " << this->top_type << "\n";
    
}

Road::Road(ResourceManager& resource_manager) {
    srand((int) time(0));
    this->position = 0;
    this->dir = rand() % 2;
    this->bottom_type = 0;
    this->top_type = 0;
    sprite.setTexture(resource_manager.get_texture(this->get_texture_code()));
}

void Road::allocate_lane_position(ResourceManager& resource_manager, float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
    spawn(resource_manager);
}

void Road::adjust_objects() {
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i]->go_to_position(vehicles[i]->sprite.getPosition().x, sprite.getPosition().y + 25);
    }
}

std::vector<sf::Sprite> Road::all_relative_object() {
    std::vector<sf::Sprite> res;
    for (int i = 0; i < vehicles.size(); ++i) res.push_back(vehicles[i]->sprite);
    return res;
}

Road::Road(ResourceManager& resource_manager, int another_dir, int& changed_type) {
    
}

int Road::see_position() {
    return this->position;
}

int Road::see_dir() {
    return this->dir;
}

void Road::change_bottom_type(int x) {
    this->bottom_type = x;
}

void Road::change_top_type(int x) {
    this->top_type = x;
}

void Road::change_texture(ResourceManager& resource_manager) {
    this->sprite.setTexture(resource_manager.get_texture(this->get_texture_code()));
}


void Road::change_position(int x) {
    this->position = x;
}

int Road::see_bottom_type() {
    return this->bottom_type;
}

int Road::see_top_type() {
    return this->top_type;
}

void Road::change_dir(int x) {
    this->dir = x;
}


// Vehicle
void Road::set_max_car(int cnt) { max_car = cnt; }

void Road::spawn(ResourceManager& resource_manager)
{
    //std::cout << "OK max" << '\n';
    const int MAX_SPEED = 300;
    srand(time(0));
    if (vehicles.size() == max_car) return;
    if (vehicles.empty())
    {

        int speed = rand() % (MAX_SPEED * 3 / 2) - MAX_SPEED;
        std::vector<int> init_position(3);
        for (int i = 0; i < 3; ++i)
        {
            bool check = false;
            while (!check)
            {
                check = true;
                int index = rand() % 10;
                for (int _i = 0; _i < i; ++_i)
                    if (index == init_position[_i]) 
                        check = false;
                if (check) init_position[i] = index;
            }
        }
        sort(init_position.begin(), init_position.end());
        for (int i = 0; i <= 2; ++i)
        {
            //srand(time(NULL));
            add_vehicle(resource_manager, speed, init_position[i] * 100);
        }
            
    }
    else if (vehicles.size() < max_car) 
        add_vehicle(resource_manager, vehicles[0]->see_velocity(), -100);
}

void Road::add_vehicle(ResourceManager& resource_manager, int speed, int pos_x) {
    //srand(time(0));
    Vehicle* new_vehicle = new Vehicle(resource_manager, dir, speed, sprite.getPosition().y);
    new_vehicle->go_to_position(pos_x, sprite.getPosition().y + 25 );
    this->vehicles.push_back(new_vehicle);
}


*/


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

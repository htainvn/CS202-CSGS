//
//  Road.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Road.hpp"
#include <string>
#include <algorithm>

int Road::get_lane_type() {
    return ROAD_TYPE;
}

std::string Road::get_texture_code() {
    //td::cout << this->position << " " << this->dir << " " << this->bottom_type << " " << this->top_type << "\n";
    std::string res = "ROAD_";
    res += ((this->dir == 0) ? "LEFT_" : "RIGHT_");
    if (this->bottom_type == 0 && this->top_type == 0) {
        res += "NOLINE";
        //std::cout << "texture = " << res << "\n";
        return res;
    }
    else {
        switch(this->bottom_type) {
            case 0: {
                switch(this->top_type) {
                    case 1:
                        res += "TOPDASH";
                        break;
                    case 2:
                        res += "NODASH";
                        break;
                }
                break;
            }
            case 1: {
                switch(this->top_type) {
                    case 0:
                        res += "BOTTOMDASH";
                        break;
                    case 1:
                        res += "FULLDASH";
                        break;
                    case 2:
                        res += "BOTTOMDASH";
                        break;
                }
                break;
            }
            case 2: {
                switch(this->top_type) {
                    case 0:
                        res += "NODASH";
                        break;
                    case 1:
                        res += "TOPDASH";
                        break;
                    case 2:
                        res += "NODASH";
                        break;
                }
                break;
            }
        }
    }
    switch(position) {
        case 0:
            res += "_BOTTOM";
            break;
        case 1:
            res += "_NORMAL";
            break;
        case 2:
            res += "_TOP";
            break;
    }
    //std::cout << "texture = " <<  res << "\n";
    return res;
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
    srand((int) time(0));
    this->position = 1;
    this->dir = rand() % 2;
    if (this->dir == another_dir) {
        this->bottom_type = 1;
        this->change_texture(resource_manager);
    }
    else {
        this->bottom_type = 2;
        this->change_texture(resource_manager);
    }
    changed_type = this->bottom_type;
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
            add_vehicle(resource_manager, speed, init_position[i] * 100);
    }
    else if (vehicles.size() < max_car) 
        add_vehicle(resource_manager, vehicles[0]->see_velocity(), -100);
}

void Road::add_vehicle(ResourceManager& resource_manager, int speed, int pos_x) {
    Vehicle* new_vehicle = new Vehicle(resource_manager, dir, speed, sprite.getPosition().y);
    new_vehicle->go_to_position(pos_x, sprite.getPosition().y + 25 );
    this->vehicles.push_back(new_vehicle);
}
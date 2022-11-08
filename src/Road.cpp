//
//  Road.cpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#include "src/Road.hpp"
#include <string>

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

void Road::allocate_lane_position(float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
}

void Road::adjust_objects() {
    
}

std::vector<sf::Sprite> Road::all_relative_object() {
    std::vector<sf::Sprite> res;
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

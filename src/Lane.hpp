//
//  Lane.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Lane_hpp
#define Lane_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "src/definition_library.hpp"
#include "src/ResourceManager.hpp"
#include "src/Vehicle.hpp"
#include "src/Animal.hpp"

class Lane {
public:
    sf::Sprite sprite;
    virtual int get_lane_type() { return 0; }
    virtual void allocate_lane_position( ResourceManager& resource_manager, float x, float y) { }
    virtual void adjust_objects() {}
    virtual std::vector<sf::Sprite> all_relative_object() { return std::vector<sf::Sprite>(0); }
    
    virtual void update_traffic(ResourceManager& resource_manager, int status, sf::Clock& clock, sf::CircleShape& shape) {}
    virtual void stop_traffic() {}
    
    //for road only
    virtual int see_position() { return 0; }
    virtual int see_dir() { return 0; }
    virtual int see_bottom_type() { return 0; }
    virtual int see_top_type() { return 0;  }
    virtual std::string get_texture_code() {return "";}
    virtual void change_dir(int x) {}
    virtual void change_position(int x) {}
    virtual void change_bottom_type(int x) {}
    virtual void change_top_type(int x) {}
    virtual void change_texture(ResourceManager& resource_manager) {}
    virtual void add_vehicle(Vehicle*& vehicle) {}
    //
    
    
    // for river only
    virtual void add_log(Log*& log) {}
    virtual void add_animal(Animal*& animal) {}
    //
    
    virtual ~Lane() {}
};

#endif /* Lane_hpp */

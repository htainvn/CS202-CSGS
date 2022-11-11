//
//  Road.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include "src/Lane.hpp"

#include "src/Vehicle.hpp"

class Road : public Lane {
private:

    int position = 0; //0 is bottom, 1 is normal, 2 is top
    int dir = 0; //0 is left, 1 is right
    int bottom_type = 0; //0 is nothing, 1 is dash, 2 is line
    int top_type = 0; //0 is nothing, 1 is dash, 2 is line
    int max_car = 5;
    std::vector<Vehicle*> vehicles;
    
public:
    Road(ResourceManager& resource_manager);
    Road(ResourceManager& resource_manager, int another_dir, int& changed_type);
    int get_lane_type();
    void allocate_lane_position(ResourceManager& resource_manager, float x, float y);
    std::string get_texture_code();
    void adjust_objects();
    std::vector<sf::Sprite> all_relative_object();
    int see_position();
    int see_dir();
    int see_bottom_type();
    int see_top_type();
    void change_position(int x);
    void change_dir(int x);
    void change_bottom_type(int x);
    void change_top_type(int x);
    void change_texture(ResourceManager& resource_manager);
    
    //undone
    void set_max_car(int cnt);
    void spawn(ResourceManager& resource_manager);
    void add_vehicle(ResourceManager& resource_manager, int speed, int pos_x);
    void stop_traffic() {}
    //
    
    ~Road() {}
};

#endif /* Road_hpp */

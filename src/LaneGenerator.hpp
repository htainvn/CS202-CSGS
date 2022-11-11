//
//  Background.hpp
//  CROSSING_ROAD
//
//  Created by Hoang The Anh on 01/11/2022.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>

#include <vector>

#include "src/ResourceManager.hpp"
#include "src/Lane.hpp"
#include "src/Pathway.hpp"
#include "src/River.hpp"
#include "src/Road.hpp"
//#include "src/People.hpp"

class LaneGenerator {
    
private:
    
    int level;
    
    int path_left = 0;
    
    int road_left = 0;
    
    std::vector<Lane*> lanes;
    
    std::vector<Lane*> prediction;
    
    float multi_base = 1.0;
    
    int cutoff_time = 0;
    
public:
    
    void add_lane(ResourceManager& resource_manager, float oy, int type_of_lane);
    
    void add_prediction(ResourceManager& resource_manager, int type_of_lane);
    
    void delete_bottom_lane();
    
    void updating(float moving_speed, sf::Clock& clock, int& isShifting, bool& has_shifted, ResourceManager& resource_manager, bool is_green, int& real_level);
    
    int counting_lanes();
    
    Lane*& operator[](const int index);
    
    Lane*& get_prediction(int index);
    
    int get_prediction_type();
    
    void set_level(int x);
    
    void set_level(int x, int path_left, int road_left);
    
    void inc_multi_base();
    
    void reset_base();
    
    float get_base();
    
    void set_cutoff(int time_x);
    
    int get_cutoff();
    
    ~LaneGenerator();
};

#endif /* Background_hpp */
